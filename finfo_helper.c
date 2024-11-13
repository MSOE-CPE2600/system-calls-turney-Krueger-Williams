/********************************************************************
 *  Filename: finfo_helper.c
 *  Description: Provides helper functions for finfo.c
 *  Author: Krueger 'Mac' Williams
 *  Date:  11/13/2024
 *******************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void print_permissions(mode_t mode) {
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}