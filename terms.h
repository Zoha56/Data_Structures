#pragma once
#ifndef DEBUG
#define DEBUG

class terms
{
protected:
	double coeff;
	double exp;
public:
	terms(double c, double e);
	void addcoeff(double);
	double getcoeff();
	double getexp();
	void addexp(double);
	void addterm(double, double);
};

#endif // DEBUG