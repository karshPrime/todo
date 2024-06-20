
// manage.c

#include "manage.h"

bool no_config_found()
{
    fprintf(stderr, "No TODO found. Create new with -n flag.\n");
    return true;
}

void create_new(bool aLocal, bool aIgnore)
{
    printf("create_new. local=%d, ignore=%d\n", aLocal, aIgnore);
}

void open_todo()
{
    printf("$EDITOR todo\n");
}

void make_local()
{
    printf("make_local\n");
}

void make_unlocal()
{
    printf("make_unlocal\n");
}

void make_unignored()
{
    printf("make_unignored\n");
}

void make_ignored()
{
    printf("make_ignored\n");
}

void config_open()
{
    printf("config_open\n");
}

void config_set(char* aSetting)
{
    printf("config_set, %s\n", aSetting);
}

