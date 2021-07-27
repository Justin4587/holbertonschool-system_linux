#include "_getline.h"
/**
* _getline - function for stuff
* @fd: id
* Return: line
*/

char *_getline(const int fd)
{
    static fd_t *head;
    fd_t *copy = NULL, *copy1 = NULL;

    copy = head;

    if (fd == -1)
	{
		while (copy != NULL)
		{
			copy1 = copy;
			copy1 = copy1->next;
            if (copy->file_buf[0])
                free(copy->file_buf[0]);
            if (copy->file_buf[1])
                free(copy->file_buf[1]);
            if (copy->file_buf[2])
                free(copy->file_buf[2]);
			free(copy->file_buf);
            free(copy);
		}
		return (NULL);
	}
    if (!copy)
        copy = file_stuffer(&head, fd);

    while (copy && copy->structed_fd != fd)
        copy = copy->next;

    return (the_line(copy->file_buf[0], *copy->line_index, copy->bytes_read[0]));


    
}

/**
* the_line - function for stuff
* @file_buffer: file pointer
* @line_index: id
* Return: file in struct
*/
char *the_line(char *file_buffer, size_t *line_index, size_t *bytes_read)
{
    size_t start = line_index + 0, counter = 0;
    char *out;

    while (file_buffer[start] != '\n' && bytes_read > line_index)
    {
        counter++;
        start++;
    }
    if (counter == 0)
        return (NULL);
    out = file_buf[line_index:start];
    &line_index = start;
    return (out);
}

/**
* file_add - function for stuff
* @head: file pointer
* @fd: id
* Return: file in struct
*/
fd_t file_stuffer(fd_t *head, const int fd)
{
    char *buffer;
    fd_t *files, *add;
    size_t buffer_read = 1;

    add = malloc(sizeof(struct);
    if (add == NULL)
        return (NULL);

    add->structed_fd = fd;
    add->line_index = 0;
    add->next = NULL;
    buffer = malloc(sizeof(READ_SIZE));
    if (buffer == NULL)
    {
        free(head);
        return (NULL);
    }
    do
    {
        if (add->file_buf[0] == NULL)
        {
            buffer_read = read(fd, buffer, READ_SIZE);
            add->file_buf[0] = malloc(buffer_read));
            memcpy(add->file_buf[0], buffer, buffer_read);
            add->bytes_read[0] = buffer_read;
            free(buffer);
        }
        else
        {
            buffer = malloc(READ_SIZE);
            buffer_read = read(fd, buffer, READ_SIZE);
            add->file_buf[1] = malloc(buffer_read);
            memcpy(add->file_buf[1], buffer, buffer_read);
            add->bytes_read[1] = buffer_read;
            free(buffer);
            add->file_buf[2] = malloc(add->bytes_read[0]);
            memcpy(add->file_buf[2], add->file_buf[0], add->bytes_read[0])
            add->bytes_read[2] = add->bytes_read[0];
            free(add->file_buf[0]);
            add->file_buf[0] = malloc(add->bytes_read[2] + add->bytes_read[1]);
            memcpy(add->file_buf[0], add->file_buf[2], add->bytes_read[2]);
            memcpy(add->file_buf[0], add->file_buf[1], add->bytes_read[1]);
            free(add->file_buf[1]);
            free(add->file_buf[2]);
            add->bytes_read[0] = add->bytes_read[1] + add->bytes_read[2];
        }
    } 
    while (buffer_read > 0);

    return()



}






char *processor(fd_t *head, const int fd);

/**
* processor - function for stuff
* @head: aergf
* @fd: id
* Return: line
*/
char *processor(fd_t *head, const int fd)
{

}

#include "_getline.h"
/**
* _getline - function for stuff
* @fd: id
* Return: line
*/

char *_getline(const int fd)
{
    static fd_t *head;
    fd_t *copy;

    copy = head;
    if (!head)
        {
            copy = file_stuffer(&head, fd);
            copy = head;
        }

    while (head && head->structed_fd != fd)
        head = head->next;

    if (fd == -1)
        return(NULL);
    if (!head)
    {
        printf("--\n");
        copy = file_stuffer(&head, fd);
        printf("**\n");
    }
    printf("%s %lu %lu \n", head->file_buf, head->bytes_read, head->bytes_read);
    printf("%i", head->structed_fd);

    if (head && head->structed_fd == fd)
    {
        printf("here maybe");
        return (the_line(copy->file_buf, copy->line_index, copy->bytes_read));
    }
    else
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
    size_t start = line_index + 0, counter;
    char *out;

    if (bytes_read == 0)
        return (NULL);
    out = malloc(sizeof(char) * READ_SIZE);
    if (out == NULL)
        return (NULL);
    printf("is anything here");
    do
    {
        for (counter = 0; counter < bytes_read; counter++)
        {
            out[counter] = file_buffer[start];
            counter++;
            start++;
        }
    }
    while (file_buffer[start] != '\n' && bytes_read > line_index);
    
    line_index = start;
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
    fd_t *add;
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
    while (buffer_read == READ_SIZE)
    {
        total_read = total_read + READ_SIZE;
        buffer = realloc(buffer, total_read + READ_SIZE);
        buffer_read = read(fd, buffer + total_read, READ_SIZE);
    } 

    add->file_buf = buffer;

    *head = add;
    return(add);



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

