// Step1.cpp: определяет точку входа для приложения.
// A simple program that computes the square root of a number
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Step3config.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{

		fprintf(stdout, " Version %d.%d\n",
			Tutorial_VERSION_MAJOR,
			Tutorial_VERSION_MINOR);
		fprintf(stdout, "Usage: %s number\n", argv[0]);

	int inputValue = atoi (argv[0]);

#ifdef USE_MYMATH
	double outputValue = mysqrt(inputValue);
#else
	double outputValue = sqrt(inputValue);
#endif

	fprintf(stdout, "The square root of %i is %g\n",
		inputValue, outputValue);
	return 0;
}