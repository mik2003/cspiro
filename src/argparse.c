#include "argparse.h"
#include "util.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int argparse(int argc,                                                             // Number of strings in array argv
             char *argv[],                                                         // Array of command-line argument strings
             char **envp,                                                          // Array of environment variable strings
             int *mode, int *cli_mode, int *precision, int *size,                  // General variables
             float *l, int *k_n, int *k_d,                                         // Spirograph variables
             float *period, int *n, float **radius, float **speed, float **angle_i // Epicycle variables
)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-?") == 0)
        {
            output_help();
        }
        else if (strcmp(argv[1], "-x") == 0 || strcmp(argv[1], "--no-cli") == 0)
        {
            if (argc > 3 && (strcmp(argv[2], "-m") == 0 || strcmp(argv[2], "--mode") == 0))
            {
                if (argc == 9 && strcmp(argv[3], "0") == 0)
                {
                    // Spirograph mode
                    *mode = 0;

                    char *endptr;
                    *l = strtof(argv[4], &endptr);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for l.\n");
                        return -1;
                    }

                    *k_n = strtol(argv[5], &endptr, 10);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for k_n.\n");
                        return -1;
                    }

                    *k_d = strtol(argv[6], &endptr, 10);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for k_d.\n");
                        return -1;
                    }

                    *precision = strtol(argv[7], &endptr, 10);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for precision.\n");
                        return -1;
                    }

                    *size = strtol(argv[8], &endptr, 10);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for size.\n");
                        return -1;
                    }
                }
                else if (argc == 9 && strcmp(argv[3], "1") == 0)
                {
                    // Epicycle mode
                    *mode = 1;

                    char *endptr;
                    *n = strtol(argv[4], &endptr, 10);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for n.\n");
                        return -1;
                    }

                    *radius = realloc(*radius, *n * sizeof(float));
                    *speed = realloc(*speed, *n * sizeof(float));
                    *angle_i = realloc(*angle_i, *n * sizeof(float));
                    if (*radius == NULL || *speed == NULL || *angle_i == NULL)
                    {
                        return -1;
                    }

                    // Tokenize the string and convert to floats
                    char *token;
                    char *input;
                    int i;

                    // radius
                    i = 0;
                    input = strdup(argv[5]);
                    token = strtok(input, ",");
                    while (token != NULL && i < *n)
                    {
                        (*radius)[i] = strtof(token, &endptr);
                        if (*endptr != '\0')
                        {
                            printf("Invalid float: %s\n", token);
                            return -1;
                        }
                        i++;
                        token = strtok(NULL, ",");
                    }
                    if (i != *n)
                    {
                        printf("Expected %d floats for radius, but parsed %d\n", *n, i);
                        return -1;
                    }

                    // speed
                    i = 0;
                    input = strdup(argv[6]);
                    token = strtok(input, ",");
                    while (token != NULL && i < *n)
                    {
                        (*speed)[i] = strtof(token, &endptr);
                        if (*endptr != '\0')
                        {
                            printf("Invalid float: %s\n", token);
                            return -1;
                        }
                        i++;
                        token = strtok(NULL, ",");
                    }
                    if (i != *n)
                    {
                        printf("Expected %d floats for speed, but parsed %d\n", *n, i);
                        return -1;
                    }

                    // angle_i
                    i = 0;
                    input = strdup(argv[7]);
                    token = strtok(input, ",");
                    while (token != NULL && i < *n)
                    {
                        (*angle_i)[i] = strtof(token, &endptr);
                        if (*endptr != '\0')
                        {
                            printf("Invalid float: %s\n", token);
                            return -1;
                        }
                        i++;
                        token = strtok(NULL, ",");
                    }
                    if (i != *n)
                    {
                        printf("Expected %d floats for angle_i, but parsed %d\n", *n, i);
                        return -1;
                    }

                    // *precision = strtol(argv[7], &endptr, 10);
                    // if (*endptr != '\0')
                    // {
                    //     printf("Wrong argument for precision.\n");
                    //     return -1;
                    // }

                    *size = strtol(argv[8], &endptr, 10);
                    if (*endptr != '\0')
                    {
                        printf("Wrong argument for size.\n");
                        return -1;
                    }

                    if (check_rational_relations_and_period(*n, *speed, period))
                    {
                        printf("All angular velocities are rationally related.\n");
                        printf("The period of the epicycle is: %f seconds\n\n", *period);
                    }
                    else
                    {
                        printf("Some angular velocities are not rationally related. Input new values.\n\n");
                    }
                }
                else
                {
                    printf("Unknown mode value: %s\n", argv[3]);
                    return -1;
                }
            }
            else
            {
                output_wrong_arguments();
                return -1;
            }
        }

        *cli_mode = 0;
    }
    else
    {
        *cli_mode = 1;
    }

    return 0;
}

void output_help()
{
    printf(".\n");
}

void output_wrong_arguments()
{
    printf("Wrong arguments. Use -h for help.\n");
}
