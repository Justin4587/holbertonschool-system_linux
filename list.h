#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>

int proc_dir(char *usr_path);

#endif /* LIST_H */
