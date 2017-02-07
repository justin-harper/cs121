// Name: JH12

//Description: Volume of cone

//preproseor directive...happnes before compiling
#include <stdio.h>
#define PI 3.14159


int main(void)
{
	int radius = 0;
	int height = 0;
	double volume = 0.0;
	printf("Enter radius as an integer: ");
	scanf("%d", &radius);
	printf("Enter height as integer: ");
	scanf("%d", &height);

	volume = ((double)1/3)*(PI)*(radius)*(radius)*(height);

	printf("volume of cone: %lf\n", volume);

	return 0;


}

