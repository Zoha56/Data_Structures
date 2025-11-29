#ifndef PATANAI
#define PATANAI


#include<iostream>
#include "terms.h"
using namespace std;
class Polynomial
{
public:
	Polynomial();
	~Polynomial();
	Polynomial(int d);
	void addterm(terms t1);
	void setcoefficient(double c, double e);
	double getcoefficient();
	int getdegree();
	Polynomial operator=(Polynomial& other);
	Polynomial operator+(Polynomial& other);
	Polynomial operator-(Polynomial& other);
	Polynomial operator*(Polynomial& other);
	Polynomial derivative();
	Polynomial antiderivative();
	friend ofstream& operator<<(ofstream& oss, Polynomial& p);



protected:
	terms *t;
	int degree;
};

#endif // !PATANAI


