#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
{
		if(s == 0){
			std::random_device rd;
			seed = rd();
		}
		
		rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& vect, double lower, double upper)
{
		std::uniform_real_distribution<double> duniform(lower, upper);
		
		for(size_t i(0); i < vect.size(); ++i){
			vect[i] = duniform(rng);
		}
	}
	
double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> duniform(lower, upper);
	
	return duniform(rng);
}
	
void RandomNumbers::normal(std::vector<double>& vect, double mean, double sd)
{
	std::normal_distribution<double> dnormal(mean, sd);
	
		for(size_t i(0); i < vect.size(); ++i){
			vect[i] = dnormal(rng);
	
	}
}
	
double RandomNumbers::normal(double mean, double sd)
{
		std::normal_distribution<double> dnormal(mean, sd);
		
		return dnormal(rng);
}
	
void RandomNumbers::poisson(std::vector<int>& vect, double mean)
{
	std::poisson_distribution<int> dpoisson(mean);
	
	for(size_t i(0); i < vect.size(); ++i){
			vect[i] = dpoisson(rng);
	}
}
	
int RandomNumbers::poisson(double mean)
{
		std::poisson_distribution<int> dpoisson(mean);
		return dpoisson(rng);
		}
	
