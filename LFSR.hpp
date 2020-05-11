#ifndef LFSR_HPP 
#define LFSR_HPP
#include <iostream>
#include <string>
using namespace std;
class LFSR {
	
public:
	LFSR(string seed,int t); 	//constructor to create LFSR with the given initial seed and tap 
	int generate(int k);				//simulate one step and return the new bit as 0 or 1
	int step();							//simulate k steps and return k-bit integer
	
	friend ostream& operator<< (std::ostream &out, const LFSR &lfsr);
  
private:							
	string seed;
	int tap;		
};
#endif
