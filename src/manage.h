
/* manage.h
 *
 * contains code to manage the todo file itself, and not the content within it.
 * includes operations like creating new todo, moving it to local, pushing to
 * git, etc.
 * */

#pragma once

#include <stdbool.h>

void create_new(bool aLocal, bool aIgnore);

void make_local();
void make_unlocal();

void make_ignored();
void make_unignored();

void config_open();
void config_set(char* aSetting);

