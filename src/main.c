
#include <stdio.h>
#include <getopt.h>

#include "manage.h"
#include "display.h"

int main (int argc, char** argv)
{
    int flag = 0;
    bool lCreateNew = false, lMakeLocal = false, lMakeIgnored = false;
    bool lOpenTodo = true; // open todo file in $EDITOR

    while (1)
    {
        static struct option opts[] = {
            {"new"      , no_argument,  0, 'n'},
            {"local"    , no_argument,  0, 'l'},
            {"unlocal"  , no_argument,  0, 'L'},
            {"ignore"   , no_argument,  0, 'i'},
            {"unignore" , no_argument,  0, 'I'},
            {"print"    , no_argument,  0, 'P'},
            {"highest"  , no_argument,  0, 'H'},
            {"count"    , required_argument,  0, 'c'},
            {"priority" , required_argument,  0, 'p'},
            {"config"   , required_argument,  0, 'C'},
            {"help"     , required_argument,  0, 'h'},
            {0, 0, 0, 0}
        };

        int opt_indx = 0;
        flag = getopt_long(argc, argv, ":nlLiIPHc:p:C:h:", opts, &opt_indx);
        if (flag == -1) break;

        switch (flag)
        {
            case 'n': lCreateNew = true; break;
            case 'l': lMakeLocal = true; break;
            case 'i': lMakeIgnored = true; break;

            case ':': // when called without arguments
                if (no_config_found())
                    return 1;

                switch (optopt)
                {
                    case 'c': count_all(); break;
                    case 'p': priority_all(); break;
                    case 'C': config_open(); break;
                    case 'h': help_overview(); break;
                }
                break;

            case '?':
                fprintf(stderr, "Unknown option: %c\n", optopt);
                break;

            default:
                if (no_config_found())
                    return 1;

                switch (flag)
                {
                    case 'L': make_unlocal(); break;
                    case 'I': make_unignored(); break;
                    case 'P': print_raw(); break;
                    case 'H': print_highest(); break;
                    case 'c': count_specific(optarg); break;
                    case 'p': priority_specific(optarg); break;
                    case 'C': config_set(optarg); break;
                    case 'h': help_specific(optarg); break;
                }
                break;
        }
        lOpenTodo = false;
    }

    if (lCreateNew)
    {
        create_new(lMakeLocal, lMakeIgnored);
        return 0;
    }

    if (no_config_found())
        return 1;

    if (lMakeIgnored)
        make_ignored();

    if (lMakeLocal)
        make_local();

    if (lOpenTodo) 
        open_todo();

    return 0;
}

