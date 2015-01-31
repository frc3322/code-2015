#include <stdio.h>
#include <stdarg.h>
#include "Task.h"
#include <semaphore.h>
#include "SmartDashboard/SendableChooser.h"
#include "SmartDashboard/SmartDashboard.h"

#define DIAG_LINE_SIZE 2048
#define DIAG_SIZE 32*DIAG_LINE_SIZE
#define DIAG_ERROR -1

int startLogging();		//returns ERROR if something goes wrong
int flushToDisk();
int bufferPrintf(const char* format, ...);
//int DashPrintf(const char* key, const char* format, ...);
