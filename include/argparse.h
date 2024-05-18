#ifndef ARGPARSE_H
#define ARGPARSE_H

int argparse(int argc,                                                             // Number of strings in array argv
             char *argv[],                                                         // Array of command-line argument strings
             char **envp,                                                          // Array of environment variable strings
             int *mode, int *cli_mode, int *precision, int *size,                  // General variables
             float *l, int *k_n, int *k_d,                                         // Spirograph variables
             float *period, int *n, float **radius, float **speed, float **angle_i // Epicycle variables
);

void output_help();
void output_wrong_arguments();

#endif /* ARGPARSE_H */