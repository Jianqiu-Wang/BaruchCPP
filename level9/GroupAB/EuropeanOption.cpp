// EurpeanOption.cpp
// Author: Jianqiu Wang

#include "EuropeanOption.hpp"
#include <cmath>
#include <iostream>
#include <vector>


EuropeanOption::EuropeanOption() 
{ // Default call option

	init();
}

// Construct from r, sig, K, T, S
EuropeanOption::EuropeanOption(double r, double sig, double K, double T, double b, double S):r(r), sig(sig), K(K), T(T), b(b), S(S)
{
}

// Construct from r, sig, K, T, S
EuropeanOption::EuropeanOption(double r, double sig, double K, double T, double b, double S, string opt_type):r(r), sig(sig), K(K), T(T), b(b), S(S), opt_type(opt_type)
{
}

// Construct from matrix
EuropeanOption::EuropeanOption(const vector<vector<double>> parameter_matrix, string opt_type):parameter_matrix_(parameter_matrix), opt_type(opt_type)
{
} 
//////////// Gaussian functions /////////////////////////////////

// In general, we would use similar functions in Boost::Math Toolkit

double EuropeanOption::n(double x) const
{ 
	double A = 1.0/sqrt(2.0 * 3.1415);
	return A * exp(-x*x*0.5);
}

// Returns cdf of Gaussian Distribution using boost
double EuropeanOption::N(double x) const
{ 
	normal_distribution<> my_normal;
	return cdf(my_normal, x);
}

// Kernel Functions (Haug)
double EuropeanOption::CallPrice()
{
	double tmp = sig * sqrt(T);
	double d1 = (log(S/K) + (b+ (sig*sig)*0.5 ) * T)/ tmp;
	double d2 = d1 - tmp;
	price_ = (S * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));
	return price_;
}

double EuropeanOption::PutPrice()
{

	double tmp = sig * sqrt(T);
	double d1 = (log(S/K) + (b+ (sig*sig)*0.5) * T )/ tmp;
	double d2 = d1 - tmp;
	price_ = (K * exp(-r * T)* N(-d2)) - (S * exp((b-r)*T) * N(-d1));
	return price_;

}

double EuropeanOption::CallDelta()
{
	double tmp = sig * sqrt(T);
	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	delta_ = exp((b-r)*T) * N(d1);
	return delta_;
}

// Returns delta of European put option
double EuropeanOption::PutDelta()
{
	double tmp = sig * sqrt(T);
	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T ) / tmp;
	delta_ = exp((b-r)*T) * (N(d1) - 1.0);
	return delta_;
}

void EuropeanOption::init()
{	// Initialise all default values
	// Default values
	r = 0.05;
	sig= 0.2;
	K = 110.0;
	T = 0.5;
	b = r;			// Black and Scholes stock option model (1973)
	opt_type = "C"; // European Call Option (this is the default type)
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;	
	opt_type = o2.opt_type;
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor
	copy(o2);
}

EuropeanOption::EuropeanOption(const string& option_type)
{	// Create option type

	init();
	opt_type = option_type;

	if (opt_type == "c")
		opt_type = "C";
}

EuropeanOption::~EuropeanOption()
{
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{
	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price()
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
vector<double> EuropeanOption::PriceWithMatrix()
{
	price_vector_ = {};
	for (vector<double> row: parameter_matrix_)
	{
		EuropeanOption option(row[0], row[1], row[2], row[3], row[4], row[5], opt_type);
		price_vector_.push_back(option.Price());		
	}
	return price_vector_;
}

// Calculates option Delta
// h <= 0, use analytical solution
// h > 0, use difference method
double EuropeanOption::Delta(double h)
{
	if (h > 0) // positve step length
	{
		EuropeanOption option1(r, sig, K, T, b, S + h, opt_type);
		EuropeanOption option2(r, sig, K, T, b, S - h, opt_type);
		delta_ = (option1.Price() - option2.Price()) / 2 / h;
		return delta_;
	}
	else
	{
		if (opt_type == "C")
			return CallDelta();
		else
			return PutDelta();
	}
	
	
}

// Calculates option Gamma
double EuropeanOption::Gamma(double h)
{
	if (h > 0)
	{
		EuropeanOption option1(r, sig, K, T, b, S + h, opt_type);
		EuropeanOption option2(r, sig, K, T, b, S - h, opt_type);
		price_ = this->Price();
		gamma_ = (option1.Price() - 2 * price_ + option2.Price()) / h / h;
	}
	else // analytical solution
	{
		double tmp = sig * sqrt(T);
		double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / tmp;
		gamma_ = n(d1) * exp((b-r) * T) / (S * sig * sqrt(T)) ;
	}
	return gamma_;
}

// Calculates Delta or Gamma matrix
vector<double> EuropeanOption::CalculateGreeksMatrix(const string& greek, double h)
{
	if (greek == "Delta")
	{
		delta_vector_ = DeltaMatrix(h);
		return delta_vector_;
	}
	else if (greek == "Gamma")
	{
		gamma_vector_ = GammaMatrix(h);
		return gamma_vector_;
	}
	return vector<double>(parameter_matrix_.size(), 0);
}

vector<double> EuropeanOption::DeltaMatrix(double h)
{
	delta_vector_ = {};
	for (vector<double> row: parameter_matrix_)
	{
		EuropeanOption option(row[0], row[1], row[2], row[3], row[4], row[5], opt_type);
		delta_vector_.push_back(option.Delta(h));
	}
	return delta_vector_;	
}

vector<double> EuropeanOption::GammaMatrix(double h)
{
	gamma_vector_ = {};
	for (vector<double> row: parameter_matrix_)
	{
		EuropeanOption option(row[0], row[1], row[2], row[3], row[4], row[5], opt_type);
		gamma_vector_.push_back(option.Gamma(h));
	}
	return gamma_vector_;	
}
// Calculates option price by using put call parity formula
double EuropeanOption::GetParityOptionPrice(double option_price) const
{
	double kert = K * exp((-r)*T); 
	if (opt_type == "C")
	{
		return option_price + kert - S;
	}
	else
	{
		return option_price - kert + S;	
	}
}

// Verify put-call parity by comparing LHS and RHS
bool EuropeanOption::VerifyPutCallParity(double call_price, double put_price) const
{
	double lhs = call_price + K * exp((-r)*T);
	double rhs = S + put_price;
	cout << "LHS: " << lhs << ", RHS: " << rhs << endl;
	return abs(lhs - rhs) < 1e-6;
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)
	if (opt_type == "C")
		opt_type = "P";
	else
		opt_type = "C";
}

// Show single option price result
void EuropeanOption::ShowPriceResult()
{
	cout << "----------------------------------------------------------------" << endl;
	cout << "  C/P |   S   |   K   |   T   |  sig  |   r   |   b   |  price  " << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << setw(4) << opt_type << "  |"
	     << setw(5) << S << "  |"
		 << setw(5) << K << "  |"
		 << setw(5) << T << "  |" 
		 << setw(5) << sig << "  |" 
		 << setw(5) << r << "  |"
		 << setw(5) << b << "  |"
		 << setw(8) << price_ << endl;
	cout << "----------------------------------------------------------------" << endl;
}

// Print a table of option prices
void EuropeanOption::ShowMatrixPriceResult()
{
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "  C/P |   S   |   K   |   T   |  sig  |   r   |   b   |   price      |    Delta     |   Gamma  " << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < parameter_matrix_.size(); i++)
	{
		cout << setw(4) << opt_type << "  |"
			<< setw(5) << parameter_matrix_[i][5] << "  |"
			<< setw(5) << parameter_matrix_[i][2] << "  |"
			<< setw(5) << parameter_matrix_[i][3] << "  |" 
			<< setw(5) << parameter_matrix_[i][1] << "  |" 
			<< setw(5) << parameter_matrix_[i][0] << "  |"
			<< setw(5) << parameter_matrix_[i][4] << "  |"
			<< setw(12) << price_vector_[i] << "  |" 
			<< setw(12) << delta_vector_[i] << "  |"
			<< setw(12) << gamma_vector_[i] << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
}

