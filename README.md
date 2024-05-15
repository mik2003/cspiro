# cspiro
Welcome to cspiro, a command-line tool for making spirographs.
The mathematical basis of the program follows the definitions laid out in the [Spirograph Wikipedia page](https://en.wikipedia.org/wiki/Spirograph#Mathematical_basis)
Some important definitions:
- C_o : Fixed outer circle.
- C_i : Smaller inner circle that rolls inside C_o without slipping.
- R : Radius of C_o.
- r : Radius of C_i.
- A : Location of the drawing head. Physically, this should be within C_i.
- rho : Distance from A to center of C_i.
- l : Ratio between rho and r. Physically must follow 0<l<1, but mathematically can exceed these bounds. Negative values will result in equivalent spirographs. Values larger than 1 will exceed the size of the output SVG.
- k : Ratio between r and R. Must follow 0<k<1. In order for the spirograph to be periodic (thus not eventually be just a filled disk), this value must be a rational fraction, thus numerator and denominator are input seperatly as integers.

## Usage
Build the program using the `make` command. This builds the executable within the bin directory.
To run the program use `.\bin\cspiro.exe`.
