#include<bits/stdc++.h>
#include "apriori algorithm.h"

int main(int argc, char const *argv[])
{
	apprioriAlgorithm AA("data.csv");
	
	AA.readData();		

	AA.displayReadData();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}