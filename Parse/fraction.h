#pragma once
#include "common.h"
#include <numeric>

class Fraction
{
private:
	int nominator;
	int denominator;
public:
	Fraction(int nominator, int denominator);
	std::string ToString() const;
	static Fraction Parse(std::string data);
	static Fraction FromDouble(double data);
	double ToDouble() const;
	bool IsEqual(const Fraction& other) const;
	bool IsEquavalent(const Fraction& other) const;
	Fraction GetSiplified() const;
	int CompareTo(const Fraction& other);
	void SetNominator(int nominator);
	int GetNominator() const;
	void SetDenominator(int denominator);
	int GetDenominator() const;

	Fraction Add(const Fraction& other) const;
	Fraction Sub(const Fraction& other) const;
	Fraction Mult(const Fraction& other) const;
	Fraction Mult(int value) const;
	Fraction Div(const Fraction& other) const;
	Fraction Div(int value) const;

	__declspec(property(put = SetNominator, get = GetNominator)) int Nominator;
	__declspec(property(put = SetDenominator, get = GetDenominator)) int Denominator;
};