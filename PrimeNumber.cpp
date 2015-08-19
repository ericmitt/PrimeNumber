// PrimeNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <windows.h>
#include <ppl.h>


#include <iostream>

using namespace concurrency;
using namespace std;


long nbCall = 0;
int cptDisplay = 0;
concurrency::critical_section cs;

bool PrimeTest(long x){

	nbCall++;
	long div = 2;
	long max = sqrt(x) + 1;
	while (div < max)
	{
		if (x%div == 0)
			return false;
		div++;
	}
	return true;
}
void GeneratePrimeNumbers()
{
	long cptPrime = 0;
	int size = 100;
	int step = 1;
	for (long i = 0; i <= 999999999; i++){
	//parallel_for(0, 99999999, 1, [&](long i)
	//	{

			if (i % 2 != 0)
			{
				if (PrimeTest(i))
				{
					cptPrime++;
					cptDisplay++;
					//if (cptDisplay > 100000)
					//{
						cptDisplay = 0;
						cs.lock();
						std::cout << i << "  #Prime " << cptPrime << std::endl;
						cs.unlock();
					//}
				}
			}

		}
//	});
	std::cout << "nbPrime  " << cptPrime << std::endl;
	std::cout << "nbCall  " << nbCall << std::endl;
}

double r = 4.00;
int nbIter = 1000;
double GenerateLogisticSerie()
{
	// x_{n+1} = r x_n (1-x_n) 
	//for (double r = 0.0; r < 4; r++){
	
	double x = 0.01;
	
	for (long i = 0; i <= nbIter; i++){
		x = r * x*(1 - x);
		if (i > nbIter*0.8)
			cout << x << " ";
	}
	
	cout << x << endl;
	return x;
}

int _tmain(int argc, _TCHAR* argv[])
{
	GeneratePrimeNumbers();
	GenerateLogisticSerie();

	return 0;
}

