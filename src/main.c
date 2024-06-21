
#include <stdio.h>
#include <getopt.h>

#include "manage.h"
#include "display.h"

int main (int argc, char** argv)
{
    int flag = 0;
    bool lCreateNew = false, lMakeLocal = false, lMakeIgnored = false;
    bool lOpenTodo = true; // open todo file in $EDITOR

    config_init();

    while (1)
    {
        static struct option opts[] = {
            {"new"      , no_argument,  0, 'n'},
            {"delete"   , no_argument,  0, 'd'},
            {"local"    , no_argument,  0, 'l'},
            {"unlocal"  , no_argument,  0, 'L'},
            {"ignore"   , no_argument,  0, 'i'},
            {"unignore" , no_argument,  0, 'I'},
            {"print"    , no_argument,  0, 'P'},
            {"highest"  , no_argument,  0, 'H'},
            {"config"   , no_argument,  0, 'C'},
            {"count"    , required_argument,  0, 'c'},
            {"priority" , required_argument,  0, 'p'},
            {"help"     , required_argument,  0, 'h'},
            {0, 0, 0, 0}
        };

        int opt_indx = 0;
        flag = getopt_long(argc, argv, ":nlLiIPHCc:p:h:", opts, &opt_indx);
        if (flag == -1) break;

        switch (flag)
        {
            case 'n': lCreateNew = true; break;
            case 'l': lMakeLocal = true; break;
            case 'i': lMakeIgnored = true; break;
            case 'h': help_specific(optarg); return 0;
            case 'C': config_open(); return 0;

            case ':': // when called without arguments
                if (optopt == 'h') {
                    help_overview();
                    return 0;
                }

                if (no_todo_found())
                    return 1;

                if (optopt == 'c')
                    count_all(); 
                
                if (optopt == 'p')
                    priority_all();

                break;

            case '?':
                fprintf(stderr, "Unknown option: %c\n", optopt);
                break;

            default:
                if (no_todo_found())
                    return 1;

                switch (flag)
                {
                    case 'd': delete_record(); break;
                    case 'L': make_unlocal(); break;
                    case 'I': make_unignored(); break;
                    case 'P': print_raw(); break;
                    case 'H': print_highest(); break;
                    case 'c': count_specific(optarg); break;
                    case 'p': priority_specific(optarg); break;
                }
                break;
        }
        lOpenTodo = false;
    }

    if (lCreateNew) {
        create_new(lMakeLocal, lMakeIgnored);
        return 0;
    }

    if (no_todo_found())
        return 1;

    if (lMakeIgnored)
        make_ignored();

    if (lMakeLocal)
        make_local();

    if (lOpenTodo)
        open_todo();

    return 0;
}

