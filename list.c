#include "list.h"

/**
* main - lets see if it compiles
* @argc: num
* @argv: args
*
*Return: Something
*/

int main(int argc, char **argv) {

    if (argc != 2)
        return (proc_dir("."));
    
    return (proc_dir(argv[1]));

}

int proc_dir(char *usr_path) {

    struct dirent *dir_info;
    DIR *stream = opendir(usr_path);

    while ((dir_info = readdir(stream)) != NULL) {
        printf("%s\n", dir_info->d_name);
    }

    closedir(stream);
    return(0);

}
