
#define HOJA
#include "terms.h"
#include <iostream>
using namespace std;

terms::terms(double c = 0, double e = 0)
{
	coeff = c;
	exp = e;

}
double terms::getcoeff()
{
	return coeff;
}
double terms::getexp()
{
	return exp;
}
void terms::addcoeff(double c)
{
	coeff = c;
}
void terms::addexp(double e)
{
	exp = e;
}

void terms::addterm(double c, double e)
{
	coeff = c;
	exp = e;
}