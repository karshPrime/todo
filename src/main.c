
#include <stdio.h>
#include <getopt.h>

#include "manage.h"
#include "display.h"

int main (int argc, char** argv)
{
    int flag = 0;
    bool lMakeNew = false, lMakeLocal = false, lMakeIgnored = false;

    while (1)
    {
        if (flag == -1) break;

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

        switch (flag)
        {
            case 'n': lMakeNew = true; break;
            case 'l': lMakeLocal = true; break;
            case 'L': make_unlocal(); break;
            case 'i': lMakeIgnored = true; break;
            case 'I': make_unignored(); break;
            case 'P': print_raw(); break;
            case 'H': print_highest(); break;
            case 'c': count_specific(optarg); break;
            case 'p': priority_specific(optarg); break;
            case 'C': config_set(optarg); break;
            case 'h': help_specific(optarg); break;

            case ':': // when called without arguments
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
                break;
        }
    }

    if (lMakeNew)
        create_new(lMakeLocal, lMakeIgnored);
    else if (lMakeIgnored)
        make_ignored();
    else if (lMakeLocal)
        make_local();

    return 0;
}

