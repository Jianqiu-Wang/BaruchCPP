// statistical_functions.cpp
// Author: Jianqiu Wang

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>

#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;
	
	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// exponential distribution
	double scaleParameter = 0.5; // Default type is 'double'
    exponential_distribution<> myExponential(scaleParameter);
    // Distributional properties
	double x = 2;
	cout << "\n***Exponential distribution: \n";
	cout << "Mean:" << mean(myExponential) << endl;
	cout << "Standard deviation: " << standard_deviation(myExponential) << endl;
	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;

	// Poisson Distribution
	double lamda = 3.0;
	poisson_distribution<double> myPoisson(lamda); // Default type is 'double'
	
	cout << "\n***Poisson distribution: \n";
	
	cout << "Mean: " << mean(myPoisson) << endl;
	cout << "Standard deviation: " << standard_deviation(myPoisson) << endl;
	cout << "pdf: " << pdf(myPoisson, x) << endl;
	cout << "cdf: " << cdf(myPoisson, x) << endl;
	cout << "mean: " << mean(myPoisson) << endl;
	cout << "variance: " << variance(myPoisson) << endl;
	cout << "median: " << median(myPoisson) << endl;
	cout << "mode: " << mode(myPoisson) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
	cout << "kurtosis: " << kurtosis(myPoisson) << endl;
	cout << "characteristic function: " << chf(myPoisson, x) << endl;
	cout << "hazard: " << hazard(myPoisson, x) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	double val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myExponential, val));
		cdfList.push_back(cdf(myExponential, val));
		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}
	
	return 0;
}