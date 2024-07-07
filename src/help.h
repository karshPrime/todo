
// help.h

#pragma once

// todo --help
const char* HELP_OVERVIEW = ""
"Usage:\n"
"  $ todo [OPTIONS] [ARGS]\n"
"\n"
"Meta Options:\n"
"  -h, --help {cmd|syntax}   Show list of command-line options\n"
"  -C, --config              Configure default operations\n"
"  -v, --version             Show version of todo"
"";


// todo --help command
const char* HELP_COMMAND = ""
"Usage:\n"
"  $ todo [OPTIONS] [ARGS]\n"
"\n"
"Managing Options:\n"
"  -n, --new                 Create new todo file\n"
"  -d, --delete              Delete todo\n"
"  -l, --local               Maintain todo in current project directory\n"
"  -L, --unlocal             Move todo to centralised location\n"
"  -i, --ignore              Mark an unignore todo as ignored\n"
"  -I, --unignore            Mark an ignored todo as unignore\n"
"\n"
"Display Options:\n"
"  -p, --priority [level]    Print all (or certain level) priorities\n"
"  -c, --count [level]       Get counts for all (or certain level) priorities\n"
"  -H, --highest             Print the highest priority items\n"
"  -P, --print               Print raw TODO file\n"
"\n"
"Examples:\n"
"  1. Create a local todo and add it to .gitignore\n"
"     $ todo -nli\n"
"\n"
"  2. Move currently local todo to centralised location\n"
"     $ todo -L\n"
"\n"
"  3. Unignore existing ignored TODO\n"
"     $ todo -I\n"
"\n"
"  4. Print all highest priority TODOs\n"
"     $ todo -H\n"
"\n"
"  5. Print all TODOs with !! priority\n"
"     $ todo -p !!"
"";

// todo --help syntax
const char* HELP_SYNTAX = ""
"";

