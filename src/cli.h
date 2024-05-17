#ifndef CLI_H
#define CLI_H

#include "util.h"

#include <stdio.h>
#include <time.h>

void description();
void description_spirograph();
void description_epicycle();

int select_mode();

float input_spirograph_l();
int input_spirograph_k_n();
int input_spirograph_k_d();
int input_spirograph_precision();

int input_epicycle_n();
float input_epicycle_data(int n, float *radius, float *speed, float *angle_i);

int input_svg_size();
void output_svg_result(int result, char *filename);

void output_execution_time(clock_t start_time);

#endif