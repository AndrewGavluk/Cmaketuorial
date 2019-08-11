// Step1.cpp: определяет точку входа для приложения.
// A simple program that computes the square root of a number
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Step5config.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{
		fprintf(stdout, " Version %d.%d\n",
			Tutorial_VERSION_MAJOR,
			Tutorial_VERSION_MINOR);
		fprintf(stdout, "Usage: %s number\n", argv[0]);

	double inputValue;

	std::cin >> inputValue;

	// if we have both log and exp then use them
	double outputValue;

 #ifdef USE_MYMATH
	outputValue = mysqrt(inputValue);
 #else
	outputValue = sqrt(inputValue);
 #endif

	fprintf(stdout, "The square root of %g is %g\n",
		inputValue, outputValue);
	return 0;
}