#include "LFSR.hpp"
#include <cmath>

LFSR::LFSR(string seed, int t)
{
	this->seed = seed;
	this->tap = seed.size() - 1 - t;
}

int LFSR::step()
{
	char tapBit = seed[tap];
	char bakBit = seed[0];
	char lastBit = 'x';
	
	for(int i = 0;i < seed.size()-1;i++)
	{
		seed[i] = seed[i+1];
	}
	
	if(bakBit == tapBit)
	{
		lastBit = '0';
	}
	else 
	{
		lastBit = '1';
	}
	seed[seed.size()-1] = lastBit;
	return (lastBit-48);
}
int LFSR::generate (int k)
{
	int total = 0;
	
    for(int i = k - 1; i >= 0 ; i--)
    {
        total = total + (pow(2, i) * step());
    }
	return total;
}
std::ostream& operator<< (std::ostream &out, const LFSR &lfsr) {
        int tap = lfsr.seed.size() - 1 - lfsr.tap; 
        out << "Seed: " << lfsr.seed << "\n Tap: " << tap  << "\n";
    return out;

}
