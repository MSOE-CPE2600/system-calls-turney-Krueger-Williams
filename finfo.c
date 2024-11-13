/********************************************************************
 *  Filename: finfo.c
 *  Description: Provides a program for printing file information
 *  Author: Krueger 'Mac' Williams
 *  Date:  11/13/2024
 *  Note: compile with make
 *******************************************************************/

#include "finfo_helper.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Please supply a file path.\n");
        return 1;
    }

    printf("Information for Path: %s\n",argv[1]);
    printf("---------------------------------------\n\n");

    const char *file_path = argv[1]; // File path pointer

    int fd = open(file_path, O_RDONLY); // Open file for path

    if (fd == -1) { // Check if able to open file
        printf("Error opening file.\n");
        return 1;
    }

    struct stat file_information; // Struct to hold file info
    if (fstat(fd, &file_information) == -1) { // Check if stats found
        printf("Error obtaining file information.\n");
        return -1;
    }

    // Determine the file type
    if (S_ISREG(file_information.st_mode)) {
        printf("File Type: Regular File\n");
    } else if (S_ISDIR(file_information.st_mode)) {
        printf("File Type: Directory\n");
    } else if (S_ISCHR(file_information.st_mode)) {
        printf("File Type: Character Device\n");
    } else if (S_ISBLK(file_information.st_mode)) {
        printf("File Type: Block Device\n");
    } else if (S_ISFIFO(file_information.st_mode)) {
        printf("File Type: FIFO\n");
    } else if (S_ISLNK(file_information.st_mode)) {
        printf("File Type: Symbolic Link\n");
    } else if (S_ISSOCK(file_information.st_mode)) {
        printf("File Type: Socket\n");
    } else {
        printf("File Type: Uknown");
    }

    // Determine the file permissions
    printf("File Permissions: ");
    print_permissions(file_information.st_mode);

    printf("Owner: %d\n", file_information.st_uid); // Print owner
    printf("Filesize: %ld\n", file_information.st_size); // Print filesize
    
    // Create a time structure
    struct tm *tm_info;
    tm_info = localtime(&file_information.st_mtime); // Convert last modified

    char date[26]; // Storage for date string
    strftime(date, 26,"%Y-%m-%d %H:%M:%S", tm_info); // Create date string
    printf("Last modified: %s\n", date);

    printf("\n---------------------------------------\n");

    return 0;
}