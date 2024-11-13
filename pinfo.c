/********************************************************************
 *  Filename: pinfo.c
 *  Description: Provides a program for stats based on PIDs
 *  Author: Krueger 'Mac' Williams
 *  Date:  11/11/2024
 *  Note: compile with make
 *******************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sched.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int pid;
    if (argc > 1) {
        pid = atoi(argv[1]); // Get supplied PID
        if (kill(pid, 0) != 0) {
            printf("PID Does Not Exist\n");
            return 1;
        }
    } else {
        pid = getpid(); // Get current process PID
    }

    printf("Information for PID: %d\n",pid);
    printf("---------------------------------------\n\n");

    int priority = getpriority(PRIO_PROCESS,pid); // Get process priority
    if (priority == -1) {
        printf("Priority: Error\n");
    } else {
        printf("Priority: %d\n",priority);
    }

    int policy = sched_getscheduler(pid); // Get process scheduling policy
    if (policy == -1) {
        printf("Scheduling Policy: Error\n");
    } else {
        switch (policy) // Check the scheduling method and print it
        {
        case SCHED_OTHER:
            printf("Scheduling Policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Scheduling Policy: SCHED_RR\n");
            break;
        case SCHED_BATCH:
            printf("Scheduling Policy: SCHED_BATCH\n");
            break;
        case SCHED_IDLE:
            printf("Scheduling Policy: SCHED_IDLE\n");
            break;
        default:
            printf("Scheduling Policy: Unknown\n");
            break;
        }
    }
    
    
    printf("\n---------------------------------------\n");
    return 0;
}