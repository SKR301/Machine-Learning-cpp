#include<bits/stdc++.h>
#include "linear regression.h"

int main(int argc, char const *argv[])
{
	simpleLinearRegression SLR("data.csv");
	
	SLR.readData();		

	SLR.displayReadData();
	
	SLR.runAlgo();

	double testCase=SLR.predict(11);

	std::cout<<"\n\n"<<testCase;

	SLR.plot();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}