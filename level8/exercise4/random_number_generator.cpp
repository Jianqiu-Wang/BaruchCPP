// random_number_generator.cpp
// Author: Jianqiu Wang

#include <boost/random.hpp>
#include <map>

using namespace std;

int main()
{
    // Throwing dice.
    // Mersenne Twister. 
    boost::random::mt19937 myRng;

    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t> (std::time(0))); // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);

    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome; // Current outcome

	// initializes statistics
	for (int i=1; i < 7; i++)
		statistics[i] = 0;

	// record every experiment
    for (int i=0; i < 1e6; i++)
    {
        outcome = six(myRng);
		statistics[outcome]++;
	}

	// output result
	cout << "How many trials? 1000000" << endl;
	for (int i=1; i < 7; i++)
		cout << "Trial " << i << " has " << statistics[i]/1e4 << "% outcomes" << endl;
}