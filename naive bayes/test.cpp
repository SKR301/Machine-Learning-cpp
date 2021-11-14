#include<bits/stdc++.h>
#include "naive bayes.h"

int main(int argc, char const *argv[])
{
	NaiveBayes NB("data.csv");
	
	NB.readData();
	NB.displayMatrix();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}