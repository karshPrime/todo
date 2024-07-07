
#include <stdio.h>
#include <stdlib.h>

#include "manage.h"
#include "../lib/toml.h"

void config_init()
{
    FILE *fptr;
    fptr = fopen("~/.config/ptodo/config.toml", "r");

    if(fptr == NULL) {
        printf("Config not found. Creating default at ~/.config/ptodo/config.toml\n");
        fptr = fopen("~/.config/ptodo/config", "w");
    }
    fclose(fptr);

    fptr = fopen("~/.config/ptodo/records.toml", "r");
    if(fptr == NULL) {
        printf("No records found. Creating new record at ~/.config/ptodo/record.toml\n");
        fptr = fopen("~/.config/ptodo/records", "w");
    }
    fclose(fptr);
}

void config_open()
{
    printf("config_open\n");
}

