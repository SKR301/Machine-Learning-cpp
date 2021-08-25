#include<bits/stdc++.h>
#include "apriori algorithm.h"

int main(int argc, char const *argv[])
{
	int minSupport = 2;
	int minConfidence = 2;

	aprioriAlgorithm AA("data.csv",2,50);
	
	AA.readData();		

	AA.displayReadData();

	AA.countDataItem();

	AA.displayItemCount();

	AA.runAlgo();

	AA.displayPass1Data();

	AA.displayPass2Data();

	AA.displayPass3Data();

	AA.displayPass3Data();

	AA.displayFinalRules();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}
