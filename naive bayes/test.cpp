#include<bits/stdc++.h>
#include "naive bayes.h"

int main(int argc, char const *argv[])
{
	NaiveBayes NB("data.csv");
	
	NB.readData();
	NB.runAlgo("rainy");					// predict outcome as 1/0 for given "key" parameter
	NB.displayMatrix();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}