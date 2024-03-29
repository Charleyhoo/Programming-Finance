#ifndef POLYNOMIAL_ChangHuang_H
#define POLYNOMIAL_ChangHuang_H
#include<string>
class Polynomial
{
public:
	Polynomial();
	~Polynomial();
    void Polynomial_term_set();
	int Polynomial_term_get();
	void Exponent_set();
	int Exponent_get();
	void Coefficient_set();
	int Coefficient_get();
	void Coefficient_and_Exponent_set();
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	Polynomial operator+=(const Polynomial&);
	Polynomial operator-=(const Polynomial&);
	Polynomial operator*=(const Polynomial&);
	Polynomial operator=(const Polynomial&);
	friend std::ostream &operator<<(std::ostream&, const Polynomial &);
private:
    int Polynomial_term;
	int Exponent;
	int Coefficient;
	int a[7];
	int b[7][7];
	int c[13];
};
#endif
