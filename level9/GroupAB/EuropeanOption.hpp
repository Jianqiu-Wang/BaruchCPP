// EuropeanOption.hpp
#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "BaseOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace boost::math;

class EuropeanOption: public BaseOption
{
private:			
	double r;		// risk-free interest rate
	double sig;		// volatilit
	double S;       // asset price
	double K;		// strike price
	double T;		// expiry date
	double b;		// cost of carry
	double price_;  // option price
	double delta_;
	double gamma_;  // Gamma 
	vector<vector<double>> parameter_matrix_; // parameter matrix

	vector<double> price_vector_; // calculated option price 
	vector<double> delta_vector_;
	vector<double> gamma_vector_;  

	std::string opt_type; // Option name (call, put)
	std::string unam;	  // Name of underlying asset
	
	void init();	// Initialise all default values
	void copy(const EuropeanOption& o2);
	// 'Kernel' functions for option calculations
	double CallPrice();
	double PutPrice();
	double CallDelta();
	double PutDelta();
	// double Gamma();
	vector<double> DeltaMatrix(double h);
	vector<double> GammaMatrix(double h);
	// Gaussian functions
	double n(double x) const;
	double N(double x) const;


public:	// Public functions
	EuropeanOption(); // Default call option
	EuropeanOption(double r, double sig, double K, double T, double b, double S);
	EuropeanOption(double r, double sig, double K, double T, double b, double S, string opt_type);
	EuropeanOption(const EuropeanOption& option2);	// Copy constructor
	EuropeanOption(const string& option_type);	    // Create option type
	EuropeanOption(const vector<vector<double>> parameter_matrix, string opt_type); // construct by matrix
	virtual ~EuropeanOption();

	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and sensitivities
	double Price();
	vector<double> PriceWithMatrix();
	vector<double> CalculateGreeksMatrix(const string& greek, double h);
	double Delta(double h);
	double Gamma(double h);

	double GetParityOptionPrice(double option_price) const;  // calculate option price using PCP formula
	bool VerifyPutCallParity(double call_price, double put_price) const;	
	
	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)

	// helper function: show option price result
	void ShowPriceResult(); 
	void ShowMatrixPriceResult(); 
};

#endif