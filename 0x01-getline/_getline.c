#include "_getline.h"
#include <stdio.h>
/**
* _getline - function for stuff
* @fd: id
* Return: line
*/

char *_getline(const int fd)
{
    static fd_t *head;
    fd_t *copy = NULL;

    if (fd == -1)
        return(NULL);

    copy = file_stuffer(&head, fd);
    


    while (copy && copy->structed_fd <= fd)
        copy = copy->next;
    printf("%i", fd);
    /*
    *if (fd <= copy->structed_fd)
    *    head->structed_fd = fd;
    */
    if (fd == -1)
        return(NULL);

    if (copy && copy->structed_fd == fd)
    {
        return (the_line(copy->file_buf, copy->line_index, copy->bytes_read));
    }
    
    return (NULL);

}

/**
* the_line - function for stuff
* @file_buffer: file pointer
* @line_index: id
* @bytes_read: num
* Return: file in struct
*/
char *the_line(char *file_buffer, size_t line_index, size_t bytes_read)
{
    size_t start = line_index, counter;
    char *out;
    printf("out");
    if (bytes_read == 0)
        return (NULL);
    
    while (file_buffer[start] != '\n' && bytes_read > line_index)
    {
        counter++;
        start++;
    }
    
    out = malloc(sizeof(char) * counter);
    if (out == NULL)
        return (NULL);
    line_index = start;
    start = counter = 0;

    while (file_buffer[start] != '\n' && bytes_read > line_index)
    {
        out[counter] = file_buffer[start];
        counter++;
        start++;
    }
    printf("%lu", line_index);
    
    
    return (out);
}

/**
* file_add - function for stuff
* @head: file pointer
* @fd: id
* Return: file in struct
*/
fd_t *file_stuffer(fd_t **head, const int fd)
{
    char *buffer;
    fd_t *add, *neat;
    size_t buffer_read;
    size_t total_read = 0;

    add = malloc(sizeof(fd_t));
    if (add == NULL)
        return (NULL);

    add->structed_fd = fd;
    add->line_index = 0;
    add->next = NULL;
    buffer = malloc(sizeof(char) * READ_SIZE);
    if (buffer == NULL)
    {
        free(add);
        return (NULL);
    }

    buffer_read = read(fd, buffer, READ_SIZE);
    printf("%lu", buffer_read);
    printf("%i", READ_SIZE);
    while (buffer_read)
    {
        total_read = total_read + READ_SIZE;
        printf("%s", buffer);
        buffer = realloc(buffer, total_read + READ_SIZE);
        printf("%lu", buffer_read);
        buffer_read = read(fd, buffer + total_read, READ_SIZE);
    } 
    printf("FUCK^^^^^^");
    add->file_buf = buffer;
    add->bytes_read = total_read;
    
    if (*head)
    {
        neat = *head;
        while (neat && neat->next)
            neat = neat->next;
        neat->next = add;
    }
    else
        *head = add;

    return(*head);



}

/**
* _getline - function for stuff
* @fd: id
* Return: line
*/
void snuff_them(fd_t **head)
{
    fd_t *copy = NULL, *copy1 = NULL;

    copy = *head;

    while (copy != NULL)
	{
		copy1 = copy;
	    copy1 = copy1->next;
        if (copy->file_buf)
            free(copy->file_buf);
        free(copy);
        copy = copy->next;
	}	
}
