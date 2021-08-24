// check for slope and intercept

#include<bits/stdc++.h>
#include "logistic regression.h"

int main(int argc, char const *argv[])
{
	simpleLogisticRegression SLR("data.csv");
	
	SLR.readData();		

	SLR.displayReadData();
	
	SLR.runAlgo();	

	double testCase=SLR.predict(0.5);
	std::cout<<"\n\n"<<testCase;
	 testCase=SLR.predict(5);
	std::cout<<"\n\n"<<testCase;
	 testCase=SLR.predict(11);
	std::cout<<"\n\n"<<testCase;

	SLR.plot();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}