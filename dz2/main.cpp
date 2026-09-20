#include "Complex.h"
#include <iostream>
#include <cmath>

void solve(double a, double b, double c) {
	if (a == 0) {
		if (b == 0) {
			printf("No solutions\n");
		} else {
			double x = -c / b;
			printf("solution: x = %.2f\n", x);
		}
		return;
	}
	double D = b*b - 4 * a * c;
	if (D >= 0) {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		printf("x1 = %.2f\n", x1);
		printf("x2 = %.2f\n", x2);
	} else {
		double real = -b / (2 * a);
		double image = sqrt(-D) / (2 * a);
		Complex_AL x1(real, image);
		Complex_AL x2(real, image);
		printf("x1 = %.2f + %.2fi\n", real, image);
		printf("x2 = %.2f + %.2fi\n", real, -image);
		/*printf("x1 = ");
		x1.print_2();
		printf("\n");
		printf("x2 =");
		x2.print_2();
		printf("\n");*/
	}
}
										

int main() {
	double a, b, c;
	printf("Input coefficients a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	solve(a, b, c);
	/*if (a == 0) {
		printf("Not squared\n");
		return 1;
	}
	double D = b*b - 4 * a * c;
	if (D >= 0) {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		printf("x1 = %.2f\n", x1);
		printf("x2 = %.2f\n", x2);
	} else {
		double real = -b / (2 * a);
		double image = sqrt(-D) / (2 * a);
		Complex_AL x1(real, image);
		Complex_AL x2(real, image);
		printf("x1 = ");
		x1.print_2();
		printf("\n");
		printf("x2 = ");
		x2.print_2();
		printf("\n");
	}*/
	
	return 0;
}

