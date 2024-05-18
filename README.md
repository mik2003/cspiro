# cspiro
Welcome to cspiro, a command-line tool for making spirographs.
The mathematical basis of the program follows the definitions laid out in the [Spirograph Wikipedia page](https://en.wikipedia.org/wiki/Spirograph#Mathematical_basis)

There are two different drawing modes, spirograph and epicycle. An epicycle is a more general version of a spirograph and gives the user more control, its mathematical basis can be found on the [Epicycle Wikipedia page](https://en.wikipedia.org/wiki/Deferent_and_epicycle#Mathematical_formalism).

## Spirograph
Some important definitions:
- C_o : Fixed outer circle.
- C_i : Smaller inner circle that rolls inside C_o without slipping.
- R : Radius of C_o.
- r : Radius of C_i.
- A : Location of the drawing head. Physically, this should be within C_i.
- rho : Distance from A to center of C_i.
- l : Ratio between rho and r. Physically must follow 0<l<1, but mathematically can exceed these bounds. Negative values will result in equivalent spirographs. Values larger than 1 will exceed the size of the output SVG.
- k : Ratio between r and R. Must follow 0<k<1. In order for the spirograph to be periodic (thus not eventually be just a filled disk), this value must be a rational fraction, thus numerator and denominator are input seperatly as integers.

## Epicycle
An epicycle is constructed from a set of circles, where the firs circle's center is fixed at the origin and each next circle is connected to a point on the previous circle's circumference. Each circle accepts three variables, the radius, the angular velocity, and the initial rotation.

## Usage
Build the program using the `make` command. This builds the executable within the bin directory.
To run the program use `.\bin\cspiro.exe`.

Below the output of the help message.
```
Usage: cspiro [options]
Options:
  -h, --help, -?        Print this message and exit.
  -x, --no-cli, -?      Use app without command line interface. Must specify other arguments.
If previous option is set:
  -m, --mode, -?        Set drawing mode for the --no-cli option.
                        int : 0 for spirograph, 1 for epicycle.
If spirograph (see README for detailed description):
                        float : l, ratio between rho and R.
                        int : k_n, numerator of k.
                        int : k_d, denominator of k.
                        int : precision.
                        int : size, output SVG size.
If epicycle:
                        int : n, number of construction circles, must be at least 2.
                        float,... : radius, comma separated list of circle radii [px], must be of length n.
                        float,... : speed, comma separated list of circle angular velocities [rad/s], must be of length n.
                        float,... : angle_i, comma separated list of circle initial angles [rad], must be of length n.
                        int : size, output SVG size.
```