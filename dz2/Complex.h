#pragma once
#include <cstdio>
#include <cmath>

class Complex {
public:
	virtual ~Complex() = default;
	virtual double geT() const = 0;
	virtual double abs() const = 0;
	void print_2() const {
		double radius = abs();
		double alpha = geT();
		printf("ALGEBRA: %.2f + %.2fi ; TRIGAN: %.2f * (cos(%.2f) + i * sin(%.2f))\n", radius * cos(alpha), radius * sin(alpha), radius, alpha,alpha);
	}
};

class Complex_AL : public Complex {
private:
	double Re, Im;
public:
	Complex_AL(double Re, double Im);
	~Complex_AL() override;
	double abs() const override;
	double geT() const override;
	double get_Re() const;
	double get_Im() const;
	Complex_AL addition(const Complex_AL& other) const;
	Complex_AL multiply(const Complex_AL& other) const;
};

class Complex_TR : public Complex {
private:
	double radius, alpha;
public:
	Complex_TR(double radius, double alpha);
	~Complex_TR() override;
	double abs() const override;
	double geT() const override;
	double get_R() const;
	double get_A() const;
	Complex_TR addition(const Complex_TR& other) const;
	Complex_TR multiply(const Complex_TR& other) const;
};
