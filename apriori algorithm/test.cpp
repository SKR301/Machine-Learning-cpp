#include<bits/stdc++.h>
#include "apriori algorithm.h"

int main(int argc, char const *argv[])
{
	apprioriAlgorithm AA("data.csv",2,50);
	
	AA.readData();		

	AA.displayReadData();
	
	AA.runAlgo();

	AA.displayItemCount();


	std::cout<<"\n\n";
	system("pause");
	return 0;
}