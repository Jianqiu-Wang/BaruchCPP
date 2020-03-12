// EurpeanOption.cpp
// Author: Jianqiu Wang

#include "PerpetualAmericanOption.hpp"
#include <cmath>
#include <iostream>
#include <vector>

PerpetualAmericanOption::PerpetualAmericanOption() 
{ // Default call option
	init();
}

// Construct from r, sig, K, S
PerpetualAmericanOption::PerpetualAmericanOption(double r, double sig, double K, double b, double S):r(r), sig(sig), K(K), b(b), S(S)
{
}

// Construct from r, sig, K, S
PerpetualAmericanOption::PerpetualAmericanOption(double r, double sig, double K, double b, double S, string opt_type):r(r), sig(sig), K(K), b(b), S(S), opt_type(opt_type)
{
}

// Construct from matrix
PerpetualAmericanOption::PerpetualAmericanOption(const vector<vector<double>> parameter_matrix, string opt_type):parameter_matrix_(parameter_matrix), opt_type(opt_type)
{
} 

// Calculate y
double PerpetualAmericanOption::y(string opt_type) const
{ 
	double A = b / sig / sig;
	double B = sqrt(pow(A-0.5, 2) + 2 * r / sig /sig);
	if (opt_type == "C")
	{
		return 0.5 - A + B;
	}
	else
	{
		return 0.5 - A - B;
	}
}


// Kernel Functions (Haug)
double PerpetualAmericanOption::CallPrice()
{
	double y1 = y(opt_type);
	price_ = K / (y1 - 1) * pow((y1 -1) / y1 * S / K, y1);
	return price_;
}

double PerpetualAmericanOption::PutPrice()
{

	double y2 = y(opt_type);
	price_ = K / (1 - y2) * pow((y2 -1) / y2 * S / K, y2);
	return price_;
}

void PerpetualAmericanOption::init()
{	// Initialise all default values
	// Default values
	r = 0.1;
	sig= 0.1;
	K = 100.0;
	b = r;			// Black and Scholes stock option model (1973)
	opt_type = "C"; // European Call Option (this is the default type)
}

void PerpetualAmericanOption::copy(const PerpetualAmericanOption& o2)
{
	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	b	= o2.b;	
	opt_type = o2.opt_type;
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& o2)
{ // Copy constructor
	copy(o2);
}

PerpetualAmericanOption::PerpetualAmericanOption(const string& option_type)
{	// Create option type
	init();
	opt_type = option_type;

	if (opt_type == "c")
		opt_type = "C";
}

PerpetualAmericanOption::~PerpetualAmericanOption()
{
}

PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& option2)
{
	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double PerpetualAmericanOption::Price()
{
	if (opt_type == "C")
	{	
		return CallPrice();
	}
	else
	{
		return PutPrice();
	}
}	

// Calculate option prices using parater matrix
vector<double> PerpetualAmericanOption::PriceWithMatrix()
{
	price_vector_ = {};
	for (vector<double> row: parameter_matrix_)
	{
		PerpetualAmericanOption option(row[0], row[1], row[2], row[3], row[4], opt_type);
		price_vector_.push_back(option.Price());		
	}
	return price_vector_;
}

// Modifier functions
void PerpetualAmericanOption::toggle()
{ // Change option type (C/P, P/C)
	if (opt_type == "C")
		opt_type = "P";
	else
		opt_type = "C";
}

// Show single option price result
void PerpetualAmericanOption::ShowPriceResult()
{
	cout << "--------------------------------------------------------" << endl;
	cout << "  C/P |   S   |   K   |  sig  |   r   |   b   |  price  " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << setw(4) << opt_type << "  |"
	     << setw(5) << S << "  |"
		 << setw(5) << K << "  |"
		 << setw(5) << sig << "  |" 
		 << setw(5) << r << "  |"
		 << setw(5) << b << "  |"
		 << setw(8) << price_ << endl;
	cout << "--------------------------------------------------------" << endl;
}

// Print a table of option prices
void PerpetualAmericanOption::ShowMatrixPriceResult()
{
	cout << "--------------------------------------------------------" << endl;
	cout << "  C/P |   S   |   K   |  r  |   sig   |   b   |  price  " << endl;
	cout << "--------------------------------------------------------" << endl;
	for (int i = 0; i < parameter_matrix_.size(); i++)
	{
		cout << setw(4) << opt_type << "  |"
			<< setw(5) << parameter_matrix_[i][4] << "  |"
			<< setw(5) << parameter_matrix_[i][2] << "  |"
			<< setw(5) << parameter_matrix_[i][3] << "  |" 
			<< setw(5) << parameter_matrix_[i][1] << "  |" 
			<< setw(5) << parameter_matrix_[i][0] << "  |"
			<< setw(8) << price_vector_[i] <<  endl;
	}
	cout << "--------------------------------------------------------" << endl;
}

