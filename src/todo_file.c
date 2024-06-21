
#include <stdio.h>

#include "manage.h"

bool no_todo_found()
{
    fprintf(stderr, "No TODO found. Create new with -n flag.\n");
    return true;
}

void new_todo(bool aLocal, bool aIgnore)
{
    printf("new_todo. local=%d, ignore=%d\n", aLocal, aIgnore);
}

void open_todo()
{
    printf("$EDITOR todo\n");
}

void delete_todo()
{
    
}

