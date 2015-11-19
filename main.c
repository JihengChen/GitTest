/*
 * main.c
 *
 *  Created on: Oct 2, 2015
 *      Author: Jiheng Chen
 */

#include <stdio.h>
#include <math.h>

static double E = 20;
static double L = 5;
static double R = 10;
static double h = 0.01;

double dydx( double t, double I )						//  Differential Equation: dydx( t, I ) = f( t, I ) = dI/dt
{
	return E / L - ( R / L ) * I;
}

double predcorr( double t, double I )				// Predictor Correcotr Method
{
	double I_p, I_i1;											// I_p:  estimated value of current
																		// I_i1: new value of current at next time step
	I_p = I + h * dydx( t, I );								// Predictor Formula

	I_i1 = I + 5 * h * ( dydx( t, I ) + dydx( t + h, I_p ) );	// Corrector Formula

	return I_i1;
}

int main()
{
	double I = 0.0;												// The initial value of current is 0 A
	double current_time = 0.0;							// at time = 0s.
	unsigned short Loop_times, i;						// Loop_times: number of times the 'for' loop will run
																		// i: counting variables of 'for' loop
	Loop_times = 1.0 / h;										// One second divided by the step

	for( i = 0 ; i < Loop_times  ; i++ )
	{
		current_time += h;									// Time steps up at each time
		I = predcorr( current_time, I );					// To get new current value by entering the previous current value into predcorr()
		printf("At t=%lf s, I=%lf A\n",current_time,I);	// "%lf" is the specifier to print values in 'double' format.
	}

	return 0;
}

