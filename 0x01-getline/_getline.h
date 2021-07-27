#ifndef _GETLINE_H
#define _GETLINE_H


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define READ_SIZE 16

/**
* struct car - lets see if it compiles
* @structed_fd: num
* @file_buf: args
* @bytes_read: bytes_read
* @line_index: num
* @next: next file
*/

typedef struct fd_s
{
	int structed_fd;
    char *file_buf;
	size_t bytes_read;
	size_t line_index;
	struct fd_s *next;
} fd_t;

char *_getline(const int fd);
fd_t *file_stuffer(fd_t **head, const int fd);
char *the_line(char *file_buffer, size_t line_index, size_t bytes_read);
void snuff_them(fd_t **head);



#endif /* _GETLINE_H */
