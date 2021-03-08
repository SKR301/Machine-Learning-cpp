#include<bits/stdc++.h>
#include "linear regression.h"

int main(int argc, char const *argv[])
{
	simpleLinearRegression SLR;
	
	SLR.readData("data.csv");

	SLR.displayReadData();
	
	SLR.runAlgo();

	double testCase=SLR.predict(11);

	std::cout<<"\n\n"<<testCase;

	std::cout<<"\n\n";
	system("pause");
	return 0;
}