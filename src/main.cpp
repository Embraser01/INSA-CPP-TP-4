#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cstdlib>

#include "Analog.h"

int main(int argc, char *argv[])
{
    Analog application;


    // Parsing parameters

    AnalogOptions parameters;
    int opt;
    int index;

    // Shut GetOpt error messages down (return '?'):
    opterr = 0;

    // Retrieve the options:
    while (index = optind, (opt = getopt(argc, argv, "g:et:")) != -1)
    {  // for each option...

        if (optind == index + 2 && *optarg == '-')
        {
            optopt = opt;
            opt = ':';
            --optind;
        }

        switch (opt)
        {
            case 'g':
                parameters.graph.first = true;
                parameters.graph.second = optarg;
                break;
            case 'e':
                parameters.exclude = true;
                break;
            case 't':
                parameters.time.first = true;
                try
                {
                    int time;
                    std::stringstream convert;
                    convert << optarg;
                    convert >> time;
                    if (time < 0)
                    {
                        throw std::invalid_argument("received negative value");
                    } else
                    {
                        parameters.time.second = (unsigned int) time;
                    }

                } catch (std::exception &e)
                {
                    fprintf(stderr, "Option -%c requires an unsigned int.\n", optopt);
                    return 1;
                }

                break;
            case ':':
            case '?':
                if (optopt == 'g' || optopt == 't')
                {
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                } else if (isprint(optopt))
                {
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                } else
                {
                    fprintf(stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                }
                return 1;
            default:
                abort();
        }
    }

    // LogFile name

    index = optind;

    if (index == argc)
    {
        printf("Log file name is missing\n");
        return 1;
    } else if (argc - index > 1)
    {
        printf("Too many arguments !");
        return 1;
    } else
    {
        parameters.fileName = argv[index];
    }

    if (!std::ifstream(parameters.fileName))
    {
        std::cout << "Log file does not exist !" << std::endl;
        return 1;
    }

    return application.Run(parameters);
}