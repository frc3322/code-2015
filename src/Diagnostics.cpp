#include <semaphore.h>
#include <pthread.h>
#include "Diagnostics.h"
#include "time.h"
char* m_buf;
char m_buf_a[DIAG_SIZE];
char m_buf_b[DIAG_SIZE];
int m_buf_len;

FILE* m_log = NULL;
pthread_t m_task;
sem_t m_flushing;
sem_t m_writing;
int returnValue;
unsigned int lastLinePrinted = 0;
unsigned int lineNumber = 0;

void* run(void* args);
int abort(const char* message) {
	printf("error: %s\n", message);
//	if(m_flushing) {
//		sem_destroy(&m_flushing);
//	}
//	if(m_writing) {
//		sem_destroy(&m_writing);
//	}
//	if(m_task) {
//		//pthread_exit();
//	}
	return DIAG_ERROR;
}
int startLogging() {
	m_buf = m_buf_a;
	m_buf_len = 0;
	lastLinePrinted = 0;
	lineNumber = 0;

	m_log = fopen("/diag.csv", "w");
	if(!m_log) {
		return abort("could not open log file");
	}
	if(sem_init(&m_flushing,0,0)) {
		return abort("could not create semaphore");
	}
	if(sem_init(&m_writing,0,1)) {
		return abort("could not create semaphore");
	}
	if(pthread_create(&m_task, NULL, &run, NULL)) {
		return abort("could not create semaphore");
	}
	return 0;
//	SmartDashboard::init();
}
void* run(void* args) {
	time_t startTime;
	time(&startTime);
	fprintf(m_log,"%s\n", ctime(&startTime));
	fflush(m_log);
	while (true) {
		// Wait for a writer to signal ready to flush the buffer
		sem_wait(&m_flushing);
		fflush(m_log);
		char* temp_buf = m_buf;
		int temp_buf_len;
		// Flip buffers and let the writers continue writing
		sem_wait(&m_writing);
		temp_buf_len = m_buf_len;
		m_buf = (m_buf == m_buf_a) ? m_buf_b : m_buf_a;
		m_buf_len = 0;
		sem_post(&m_writing);

		fflush(m_log);
		// Flush the buffer, then go back to waiting
		fwrite(temp_buf, temp_buf_len, 1, m_log);
		fflush(m_log);
	}
}
int flushToDisk() {
	sem_wait(&m_writing);
	sem_post(&m_flushing);
	sem_post(&m_writing);
}
int bufferPrintf(const char* format,...)
{
	sem_wait(&m_writing);
	lineNumber++;
	if (m_buf_len < DIAG_SIZE - DIAG_LINE_SIZE) {
		// The writer must guarantee never to use more than DIAG_LINE_SIZE bytes.
		// If that amount of buffer space is not available, it means buffer flushing
		// is lagging behind. Skip writing until the buffer flushes. TODO: it's
		// not clear whether new snapshots are more valuable than old -- we could
		// push older snapshots out of the buffer if the buffer is full.
		// ***Posible solution could be useing circular buffers
		if (lastLinePrinted + 1 != lineNumber) {
			m_buf[m_buf_len++] = '*';
			m_buf[m_buf_len++] = '\n';
		}
	    va_list args;
	    va_start(args, format);
	    //now print actual message
	    int len = vsprintf(m_buf + m_buf_len, format, args);
	    //vsprintf returns -1 if it fails. This is to prevent m_buf_len from being decremented
	    if (len > 0) m_buf_len += len;
	    va_end(args);
	    lastLinePrinted = lineNumber;
	    if (m_buf_len > DIAG_SIZE / 2) {
			// If the buffer is full enough, start flushing.
	    	sem_post(&m_flushing);
		}
	    sem_post(&m_writing);
	    return len;
	}
    sem_post(&m_writing);
	return -1;
}
//int Diagnostics::DashPrintf(const char* key, const char* format, ...) {
//	if(!key || !format)return -1;
//    va_list args;
//    va_start(args, format);
//    char buff[256];
//    int len = vsnprintf(buff,256, format, args);
//    SmartDashboard::PutString(key,buff);
//    va_end(args);
//    return len;
//}
