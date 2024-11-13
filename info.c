/********************************************************************
 *  Filename: info.c
 *  Description: 
 *  Author: Krueger 'Mac' Williams
 *  Date:  09/30/2024
 *  Note: A basic program demonstrating system calls
 *******************************************************************/

#include <time.h>
#include <stdio.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Print System Time
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) == 0) {
        long nanoseconds = ts.tv_sec * 1e9L + ts.tv_nsec;
        long seconds_in_day = 1e9l * 3600 * 24;
        printf("Current Time in Nanoseconds: %ld\n",nanoseconds % seconds_in_day);
    } else {
        printf("Nanoseconds: \n");
    }

    long numberOfProcessors = sysconf(_SC_NPROCESSORS_ONLN);

    // System information
    struct utsname sys_info;
    struct sysinfo info;
    
    if (uname(&sys_info) == 0 && sysinfo(&info) == 0) {
        printf("Network Hostname: %s\n",sys_info.nodename);
        printf("System Name: %s\n",sys_info.sysname);
        printf("OS: %s\n",sys_info.release);
        printf("OS Release and Version: %s\n",sys_info.version);
        printf("Number of Processors: %ld\n",numberOfProcessors);
        printf("Physical Memory (Bytes): %lu\n",info.totalram);
        printf("Physical Memory Available (Bytes): %lu\n", info.freeram);
    } else {
        perror("uname");
        printf("Network Hostname: \n");
        printf("System Name: \n");
        printf("OS: \n");
        printf("OS Release and Version: \n");
        printf("Number of Processors: \n");
        printf("Physical Memory (Bytes): \n");
        printf("Physical Memory Available (Bytes): \n");
    }
    return 0;
}