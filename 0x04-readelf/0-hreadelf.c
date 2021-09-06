#include "elf_rights.h"
/**
* main - file things
*
* @argc: arg counts
* @argv: aRRRgggs
* Return: 0 good other bad
*/

int main(int argc, char **argv)
{
    FILE *file = NULL;
    char magic[EI_NIDENT];

    if (argc != 2)
    {
        printf("Incorrect usage.\n");
        return (100);
    }

    file = fopen(argv[1], "rb");
    if (file == NULL)
        return (100);
    fread(&magic, sizeof(magic), 1, file);
    fseek(file, 0, SEEK_SET);
    if (magic[EI_CLASS] != ELFCLASS64)
        printf("I dont want to help phase out 32\n");
    else if (magic[EI_CLASS] == ELFCLASS64)
        elf_head_64(file);
    fclose(file);
    return (0);
}
