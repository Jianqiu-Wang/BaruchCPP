// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options. 
// Check answers with Haug 2007 book on option pricing.
//
// (C) Datasim Component Technology BV 2003-20011
//

#include "EuropeanOption.hpp"
#include "PerpetualAmericanOption.hpp"
#include <iostream>
#include <random>
/* Cost of carry factor b must be included in formulae depending on the
   derivative type. These are used in the generalised Black-Scholes formula. 
   If r is the risk-free interest and q is the continuous dividend yield then 
   the cost-of-carry b per derivative type is:

	a) Black-Scholes (1973) stock option model: b = r
	b) b = r - q Merton (1973) stock option model with continuous dividend yield
	c) b = 0 Black (1976) futures option model
	d) b = r - rf Garman and Kohlhagen (1983) currency option model, where rf is the 
	   'foreign' interest rate
*/


int main()
{
	// initializes parameters array
	vector<double> maturity_array = {0.25, 1.0, 1.0, 30.0};
	vector<double> strike_price_array = {65, 100, 10, 100.0};
	vector<double> volatility_array = {0.30, 0.2, 0.50, 0.30};
	vector<double> rate_array = {0.08, 0.0, 0.12, 0.08};
	vector<double> asset_price_array = {60, 100, 5, 100.0};
	vector<double> carry_array = rate_array;

	// Group A - Exact Solutions of One-Factor Plain Option
	// a) & b) check 4 batches with BS formula, Put Call parity price
	for (int i=0; i < maturity_array.size(); i++)
	{

		EuropeanOption option(rate_array[i], volatility_array[i], strike_price_array[i],
			maturity_array[i], carry_array[i], asset_price_array[i], "C");

		double call_price = option.Price();
		option.toggle();  // put option
		double put_price = option.Price();
		
		cout << "Batch " << i << endl;
		cout << "C = " << call_price << ", P = " << put_price << endl;
		cout << "Using put-call parity:" << endl;
		option.toggle(); // switch to call 
		cout << "P = " << option.GetParityOptionPrice(call_price) << ", "; 
		option.toggle(); // switch to put again
		cout <<	"C = " << option.GetParityOptionPrice(put_price) << endl;
		cout << "Verify put-call parity:" << endl;
		cout << "Verifed result: " << option.VerifyPutCallParity(call_price, put_price) << endl;

	}
	
	// c) generate underlying asset price array
	asset_price_array = GenerateMeshArray(10, 50, 1);
	vector<double> call_array;
	vector<double> put_array;
	for (vector<double>::iterator it = asset_price_array.begin(); it < asset_price_array.end(); it++)
	{
		EuropeanOption call_option(0.08, 0.30, 20, 0.25, 0.08, *it, "C");
		call_array.push_back(call_option.Price());
	}
	for (vector<double>::iterator it = call_array.begin(); it < call_array.end(); it++)
	{
		cout << *it << endl;
	}

	// d) test price with parameter matrix
	rate_array = GenerateMeshArray(0.02, 0.08, 0.02);
	maturity_array = GenerateMeshArray(0.25, 2, 0.25);
	volatility_array = GenerateMeshArray(0.1, 0.5, 0.05);
	strike_price_array = GenerateMeshArray(50, 100, 10);
	asset_price_array = GenerateMeshArray(50, 60, 1);
	
	vector<vector<double>> parameter_matrix;
	int kNumOptions = 20;
	parameter_matrix.resize(kNumOptions); // allocates 20 empty row vectors
	double rate;
	// generate option parameters randomly from mesh array
	for (int i=0; i<kNumOptions; i++)
	{
		rate = rate_array[rand() % rate_array.size()];
		parameter_matrix[i].push_back(rate);
		parameter_matrix[i].push_back(volatility_array[rand() % volatility_array.size()]);
		parameter_matrix[i].push_back(strike_price_array[rand() % 4]);
		parameter_matrix[i].push_back(maturity_array[rand() % 4]);
		parameter_matrix[i].push_back(rate); // carry
		parameter_matrix[i].push_back(asset_price_array[rand() % 4]);
	};

	EuropeanOption option_matrix(parameter_matrix, "C");
	option_matrix.PriceWithMatrix();
	option_matrix.CalculateGreeksMatrix("Delta", 0);
	option_matrix.CalculateGreeksMatrix("Gamma", 0);
	option_matrix.ShowMatrixPriceResult();
	option_matrix.toggle(); // switch to put option
	option_matrix.PriceWithMatrix();
	option_matrix.CalculateGreeksMatrix("Delta", 0);
	option_matrix.CalculateGreeksMatrix("Gamma", 0);
	option_matrix.ShowMatrixPriceResult();


	// Group A - Option Sensitivities, aka the Greeks
	cout << "\nGroupA - Option Sensitivities, aka the Greeks";
	// a) call and put future option greeks
	cout << "\na) call and put future option greeks" << endl;
	EuropeanOption option(0.1, 0.36, 100, 0.5, 0, 105, "C");
	cout << "Call option Delta and Gamma " << option.Delta(0) << " "  << option.Gamma(0) << endl;
	option.toggle(); // switch to put option
	cout << "Put option Delta and Gamma " << option.Delta(0) << " "  << option.Gamma(0) << endl;

	// b) d) calculate delta for muliple underlying value
	// test with difference h size to find optimal value
	asset_price_array = GenerateMeshArray(10, 50, 1);
	
	vector<double> difference_array = {1, 0.1, 0.01, 0.001, 0.0001};
	vector<double> call_delta_array;
	vector<double> put_delta_array;	

	cout << "\nA2 d) Delta - Compare analytical solution with various diffence h" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "  Analytical |   h = 1     |   h = 0.1   |   h = 0.01  |  h = 0.001  | h = 0.0001    " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (vector<double>::iterator it = asset_price_array.begin(); it < asset_price_array.end(); it++)
	{
		// Set option exercise price as K = 25
		EuropeanOption call_option(0.1, 0.36, *it, 0.5, 0, 25, "C");
		cout << setw(12) << call_option.Delta(0) << " | ";
		for (double h: difference_array)
		{
			cout << setw(12) << call_option.Delta(h) << "| "; 
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------------------------------" << endl;	

	cout << "\nA2 d) Gamma - Compare analytical solution with various diffence h" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "  Analytical |   h = 1     |   h = 0.1   |   h = 0.01  |  h = 0.001  | h = 0.0001    " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (vector<double>::iterator it = asset_price_array.begin(); it < asset_price_array.end(); it++)
	{
		// Set option exercise price as K = 25
		EuropeanOption call_option(0.1, 0.36, *it, 0.5, 0, 25, "C");
		cout << setw(12) << call_option.Gamma(0) << " | ";
		for (double h: difference_array)
		{
			cout << setw(12) << call_option.Gamma(h) << "| "; 
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------------------------------" << endl;	

	// d) Use h = 0.0001, calculate Greeks matrix again
	cout << "\n A2 d) Use finite difference calculate again" << endl;
	double h = 0.0001;
	option_matrix.PriceWithMatrix();
	option_matrix.CalculateGreeksMatrix("Delta", h);
	option_matrix.CalculateGreeksMatrix("Gamma", h);
	option_matrix.ShowMatrixPriceResult();
	option_matrix.toggle(); // switch to put option
	option_matrix.PriceWithMatrix();
	option_matrix.CalculateGreeksMatrix("Delta", h);
	option_matrix.CalculateGreeksMatrix("Gamma", h);
	option_matrix.ShowMatrixPriceResult();


	// Group B 
	// b) TestthedatawithK=100,sig=0.1,r=0.1,b=0.02,S=110(checkC=18.5035,P=3.03106).
	cout << "\nB b) Test Perpetual American Option pricing engine" << endl;
	PerpetualAmericanOption american_option(0.1, 0.1, 100, 0.02, 110, "C");
	american_option.Price();
	american_option.ShowPriceResult();
 	american_option.toggle();  // put option
	american_option.Price();
	american_option.ShowPriceResult();

	// c)
	cout << "\nB c) Test for a range of underlying S" << endl;	
	asset_price_array = GenerateMeshArray(90, 110, 1);
	for (vector<double>::iterator it = asset_price_array.begin(); it < asset_price_array.end(); it++)
	{
		PerpetualAmericanOption call_american_option(0.1, 0.1, 100, 0.02, *it, "C");
		call_array.push_back(call_american_option.Price());
	}
	for (vector<double>::iterator it = call_array.begin(); it < call_array.end(); it++)
	{
		cout << *it << endl;
	}

	// d) test with number options
	vector<vector<double>> parameter_matrix2;
	parameter_matrix2.resize(kNumOptions); // allocates 20 empty row vectors
	asset_price_array = {105, 110, 115, 120};
	volatility_array = {0.1, 0.2, 0.25, 0.15};
	rate_array = {0.025, 0.05, 0.075, 0.1};
	strike_price_array = {90, 92, 94, 96};

	// generate option parameters randomly from mesh array
	for (int i=0; i<kNumOptions; i++)
	{
		rate = rate_array[rand() % rate_array.size()];
		parameter_matrix2[i].push_back(rate);
		parameter_matrix2[i].push_back(volatility_array[rand() % volatility_array.size()]);
		parameter_matrix2[i].push_back(strike_price_array[rand() % 4]);
		parameter_matrix2[i].push_back(rate/5); // carry
		parameter_matrix2[i].push_back(asset_price_array[rand() % 4]);
	};


	PerpetualAmericanOption american_option_matrix(parameter_matrix2, "C");
	american_option_matrix.PriceWithMatrix();
	american_option_matrix.ShowMatrixPriceResult();
	american_option_matrix.toggle(); // switch to put option
	american_option_matrix.PriceWithMatrix();
	american_option_matrix.ShowMatrixPriceResult();



	return 0;
}

