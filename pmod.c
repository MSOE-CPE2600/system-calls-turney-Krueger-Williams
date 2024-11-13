/********************************************************************
 *  Filename: pmod.case
 *  Description: Program to elevate priority
 *  Author: Krueger 'Mac' Williams
 *  Date:  11/12/2024
 *  Note: compile with make
 *******************************************************************/

#include <unistd.h>
#include <time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    // Create time structures, time is time left, timeRem
    // is for if process gets interrupted, remaining time
    // will be stored here
    struct timespec time, timeRem;

    time.tv_sec = 1;    // Value larger than nanosecond
    time.tv_nsec = 837272638L;

    
    int priority = getpriority(PRIO_PROCESS,0); // Get process priority
    if (priority == -1 && errno != 0) {
        printf("Error getting priority\n");
        return -1;
    }
    priority = nice(priority + 10); // Add 10 to priority

    nanosleep(&time, &timeRem); // Sleep
    printf("\nFinished Waiting, Goodbye.\n");

    return 0;
}