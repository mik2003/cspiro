#ifndef ARGPARSE_H
#define ARGPARSE_H

/**
 * Function for parsing command-line arguments.
 *
 * Parameters
 * ----------
 * argc : int
 *     Number of command-line arguments (size of array argv).
 * argv[] : char *
 *     Array of command-line argument strings.
 * envp : char **
 *     Array of environment variable strings.
 *
 * For a detailed description of the following parameters see
 * the CLI implementation or look at the help message,
 * for argument parsing their pointers are passed in order to
 * keep the variables in scope when the function is returned to main.
 * General variables:
 *   mode : int *
 *   cli_mode : int *
 *   precision : int *
 *   size : int *
 * Spirograph variables:
 *   l : float *
 *   k_n : int *
 *   k_d : int *
 * Epicycle variables:
 *   period : float *
 *   n : int *
 *   radius : float **
 *   speed : float **
 *   angle_i : float **
 *
 * Returns
 * -------
 * int
 *     0  if argument parsing is successful,
 *     -1 otherwise.
 */
int argparse(int argc,
             char *argv[],
             char **envp,
             int *mode, int *cli_mode, int *precision, int *size,
             float *l, int *k_n, int *k_d,
             float *period, int *n, float **radius, float **speed, float **angle_i);

/**
 * Function to print the help message.
 */
void output_help();

/**
 * Function to print error message when wrong arguments are used.
 */
void output_wrong_arguments();

#endif /* ARGPARSE_H */