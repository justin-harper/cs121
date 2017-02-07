/*	Name: Justin Harper
	Date:
*/

#include <stdio.h>


int main (void)
{
	double mass = 0.0;
	double acceleration = 0.0;
	double force = 0.0;

	printf("Please enter mass and accelertion (as decimal): ");
	scanf("%lf%lf",&mass,&acceleration);

	force = mass * acceleration;

	printf("force = mass * acceleration = %.3lf = %.3lf * %.3lf\n", force, mass, acceleration);

	return 0;
}