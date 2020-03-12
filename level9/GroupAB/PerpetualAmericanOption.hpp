// PerpetualAmericanOption.hpp
#ifndef PerpetualAmericanOption_hpp
#define PerpetualAmericanOption_hpp

#include "BaseOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace boost::math;


class PerpetualAmericanOption: public BaseOption
{
private:			
	double r;		// risk-free interest rate
	double sig;		// volatilit
	double S;       // asset price
	double K;		// strike price
	double b;		// cost of carry
	double price_;  // option price
	
	vector<vector<double>> parameter_matrix_; // parameter matrix

	vector<double> price_vector_; // calculated option price 

	std::string opt_type; // Option name (call, put)
	std::string unam;	  // Name of underlying asset
	
	void init();	// Initialise all default values
	void copy(const PerpetualAmericanOption& o2);
	// 'Kernel' functions for option calculations
	double CallPrice();
	double PutPrice();

	double y(string opt_type) const;


public:	// Public functions
	PerpetualAmericanOption(); // Default call option
	PerpetualAmericanOption(double r, double sig, double K, double b, double S);
	PerpetualAmericanOption(double r, double sig, double K, double b, double S, string opt_type);
	PerpetualAmericanOption(const PerpetualAmericanOption& option2);	// Copy constructor
	PerpetualAmericanOption(const string& option_type);	    // Create option type
	PerpetualAmericanOption(const vector<vector<double>> parameter_matrix, string opt_type); // construct by matrix
	virtual ~PerpetualAmericanOption();

	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& option2);

	// Functions that calculate option price and sensitivities
	double Price();
	vector<double> PriceWithMatrix();
		
	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)

	// helper function: show option price result
	void ShowPriceResult(); 
	void ShowMatrixPriceResult(); 
};

#endif // PerpetualAmericanOption_HPP