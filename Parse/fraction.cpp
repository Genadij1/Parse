#include "fraction.h"

Fraction::Fraction(int nominator, int denominator)
{
	this->Nominator = nominator;
	this->Denominator = denominator;
}

std::string Fraction::ToString() const
{
	return std::format("({}/{})", this->Nominator, this->Denominator);
}

Fraction Fraction::Parse(std::string data)
{
	int slashPosition = data.find('/');
	return Fraction(
		std::stoi(data.substr(0, slashPosition)),
		std::stoi(data.substr(slashPosition + 1))
	);
}

Fraction Fraction::FromDouble(double data)
{
	return Fraction(0, 0);
}

double Fraction::ToDouble() const
{
	return this->Nominator / (double)this->Denominator;
}

bool Fraction::IsEqual(const Fraction& other) const
{
	return this->Nominator == other.Nominator && this->Denominator == other.Denominator;
}

bool Fraction::IsEquavalent(const Fraction& other) const
{
	return this->GetSiplified().IsEqual(other.GetSiplified());
}

Fraction Fraction::GetSiplified() const
{
	int gcd = std::gcd(this->Nominator, this->Denominator);
	return Fraction(this->Nominator / gcd, this->Denominator / gcd);
}

int Fraction::CompareTo(const Fraction& other)
{
	int first = this->Nominator * other.Denominator;
	int second = other.Nominator * this->Denominator;
	return (first == second) ? 0 : (first < second) ? -1 : 1;
}

void Fraction::SetNominator(int nominator)
{
	this->nominator = nominator;
}

int Fraction::GetNominator() const
{
	return this->nominator;
}

void Fraction::SetDenominator(int denominator)
{
	if (denominator == 0)
		denominator = 1;
	this->denominator = denominator;
}

int Fraction::GetDenominator() const
{
	return this->denominator;
}

Fraction Fraction::Add(const Fraction& other) const
{
	return Fraction(
		this->Nominator * other.Denominator + other.Nominator * this->denominator,
		this->Denominator * other.Denominator
	).GetSiplified();
}

Fraction Fraction::Sub(const Fraction& other) const
{
	return Fraction(
		this->Nominator * other.Denominator - other.Nominator * this->denominator,
		this->Denominator * other.Denominator
	).GetSiplified();
}

Fraction Fraction::Mult(const Fraction& other) const
{
	return Fraction(
		this->Nominator * other.Nominator,
		this->Denominator * other.Denominator
	).GetSiplified();
}

Fraction Fraction::Mult(int value) const
{
	return this->Mult(Fraction(value, 1));
}

Fraction Fraction::Div(const Fraction& other) const
{
	return this->Mult(Fraction(other.Denominator, other.Nominator));
}

Fraction Fraction::Div(int value) const
{
	return Fraction(this->Nominator, this->Denominator * value).GetSiplified();
}
