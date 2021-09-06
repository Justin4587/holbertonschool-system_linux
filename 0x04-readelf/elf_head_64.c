#include "elf_rights.h"
/**
* elf_head_64 - elf head details
*
* @elfie: file
* Return: 0 good other bad
*/
int elf_head_64(FILE *elfie)
{
    Elf64_Ehdr header;

    fread(&header, sizeof(header), 1, elfie);
    fseek(elfie, header.e_phoff, SEEK_SET);
    printf("ELF Stuff?:");
    printf("%i\n", header.e_machine);


    return (0);
}

/**
*
*for (i = 0; i < header.e_phnum; i++)
*
*/