
/* manage.h
 *
 * contains code to manage the todo file itself, and not the content within it.
 * includes operations like creating new todo, moving it to local, pushing to
 * git, etc.
 * */

#pragma once

#include <stdbool.h>

bool no_todo_found();

void new_todo(bool aLocal, bool aIgnore);
void open_todo();
void delete_todo();

void make_local();
void make_unlocal();

void make_ignored();
void make_unignored();

void config_init();
void config_open();

