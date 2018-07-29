#include "rng.c"
#include "rng.h"
#include <bits/stdc++.h>

using namespace std;

int rvga ()
{
	double u = Random();
	cout << "u = " << u << endl;
	//cout << "u² = " << pow(u, 2) << endl;
	return ceil(3.0 + 2.0 * pow(u, 2));
}

int main () 
{
	long seed = time(NULL);
	for (int i=0; i<20; i++)
	{
		seed*=2;
		PutSeed(seed);		
		cout << "RVGA = " << rvga() << endl;
	}
	
	return 0;
}
