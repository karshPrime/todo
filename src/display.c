
// display.h

#include <string.h>

#include "display.h"
#include "help.h"

void help_overview()
{
    printf("%s\n", HELP_OVERVIEW);
}

void help_specific(char* aSection)
{
    if (!strcmp(aSection, "command"))
        printf("%s\n", HELP_COMMAND);

    else if (!strcmp(aSection, "syntax"))
        printf("%s\n", HELP_SYNTAX);

    else
        printf("Error: Invalid option.\n");
}

void print_highest()
{
    printf("print_highest\n");
}

void print_raw()
{
    printf("print_raw\n");
}

void priority_all()
{
 printf("void priority_all\n");
}

void priority_specific(char* aLevel)
{
    printf("priority_specific, %s\n", aLevel);
}

void count_all()
{
    printf("count_all\n");
}

void count_specific(char* aLevel)
{
    printf("count_specific, %s\n", aLevel);
}

