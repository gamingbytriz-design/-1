#include  "Complex.h"
#include <iostream>
#include <cmath>

Complex_AL::Complex_AL(double Re, double Im) : Re(Re), Im(Im) {}
Complex_AL::~Complex_AL() {}

double Complex_AL::abs() const {
	return sqrt(Re * Re + Im * Im);
}

double Complex_AL::geT() const {
	return atan2(Im, Re);
}

double Complex_AL::get_Re() const { return Re;}
double Complex_AL::get_Im() const { return Im;}

Complex_AL Complex_AL::multiply(const Complex_AL& other) const {
	return Complex_AL(Re * other.Re - Im * other.Im, Re * other.Im + Im * other.Re);
}

Complex_TR::Complex_TR(double radius, double alpha) : radius(radius), alpha(alpha) {}
Complex_TR::~Complex_TR() {}

double Complex_TR::abs() const {
	return radius;
}

double Complex_TR::geT() const {
	return alpha;
}

double Complex_TR::get_R() const { return radius;}
double Complex_TR::get_A() const { return alpha; }

Complex_TR Complex_TR::addition(const Complex_TR& other) const {
	double real = radius * cos(alpha);
	double imagiinary = radius * sin(alpha);
	double real_2 = other.radius * cos(other.alpha);
	double imagiinary_2 = other.radius * sin(other.alpha);
	double res1 = real + real_2;
	double res2 = imagiinary + imagiinary_2;
	double new_radius = sqrt(res1 * res1 + res2 * res2);
	double new_alpha = atan2(res2, res1);
	return Complex_TR(new_radius, new_alpha);
}

Complex_TR Complex_TR::multiply(const Complex_TR& other) const {
	return Complex_TR(radius * other.radius, alpha + other.alpha);
}



