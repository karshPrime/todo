
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "manage.h"
#include "display.h"

static int verbose_flag;

int
main (int argc, char** argv)
{
    int flag = 0;
    bool lMakeNew, lMakeLocal, lMakeIgnored = false;

    while ( flag != -1 )
    {
        static struct option opts[] = {
            {"verbose"  , no_argument,  &verbose_flag, 1},
            {"breif"    , no_argument,  &verbose_flag, 0},
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

        if (verbose_flag)
            puts ("verbose flag is set");

        int opt_indx = 0;
        flag = getopt_long(argc, argv, "nlLiIPHc:p:C:h:", opts, &opt_indx);

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
                printf("passed parameter: ?\n");
                break;

            default:
                printf("no?\n");
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

