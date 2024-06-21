/* display.h
 *
 * contains code to read todo file and print its content in the desired format.
 * */

#pragma once

#include <stdint.h>

void help_overview();
void help_specific(char* aSection);

void print_highest();
void print_raw();

void priority_all();
void priority_specific(char* aLevel);

void count_all();
void count_specific(char* aLevel);

