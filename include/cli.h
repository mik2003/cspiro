#ifndef CLI_H
#define CLI_H

#include <time.h>

/**
 * Function to print a general description of the cspiro program.
 */
void description();

/**
 * Function to print a description of spirographs.
 */
void description_spirograph();

/**
 * Function to print a description of epicycles.
 */
void description_epicycle();

/**
 * Function for CLI input of drawing mode.
 *
 * Returns
 * -------
 * int
 *     0 for spirograph,
 *     1 for epicycle.
 */
int select_mode();

/**
 * Function for CLI input of spirograph parameter l.
 *
 * Returns
 * -------
 * float
 *     Spirograph parameter l.
 */
float input_spirograph_l();

/**
 * Function for CLI input of spirograph parameter k_n.
 *
 * Returns
 * -------
 * int
 *     Spirograph parameter k_n.
 */
int input_spirograph_k_n();

/**
 * Function for CLI input of spirograph parameter k_d.
 *
 * Returns
 * -------
 * int
 *     Spirograph parameter k_d.
 */
int input_spirograph_k_d();

/**
 * Function for CLI input of spirograph precision.
 *
 * Returns
 * -------
 * int
 *     Spirograph precision
 */
int input_spirograph_precision();

/**
 * Function for CLI input of epicycle parameter n.
 *
 * Returns
 * -------
 * int
 *     Epicycle parameter n.
 */
int input_epicycle_n();

/**
 * Function for CLI input of epicycle data.
 *
 * Parameters
 * ----------
 * n : int
 *     Number of epicycle construction circles.
 * radius : float *
 *     Pointer to array of circle radii.
 * speed : float *
 *     Pointer to array of circle angular velocities [rad/s].
 * angle_i : float *
 *     Pointer to array of circle initial angles [rad]
 *
 * Returns
 * -------
 * float
 *     Period of the epicycle (see `check_rational_relations_and_period`).
 */
float input_epicycle_data(int n, float *radius, float *speed, float *angle_i);

/**
 * Function for CLI input of svg size.
 *
 * Returns
 * -------
 * int
 *     SVG size [px] (for both height and width).
 */
int input_svg_size();

/**
 * Function to print if SVG parsing was successful.
 *
 * Parameters
 * ----------
 * result : int
 *     0 if successful.
 * filename : char *
 *     Pointer to the filename string.
 */
void output_svg_result(int result, char *filename);

/**
 * Function to print program execution time.
 *
 * Parameters
 * ----------
 * start_time : clock_t
 *     Time at which program was started (skips user inputs).
 */
void output_execution_time(clock_t start_time);

#endif