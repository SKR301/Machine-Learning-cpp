#include<bits/stdc++.h>
#include "csv.h"

int main(int argc, char const *argv[])
{
	csv CSV;
	std::vector<std::vector<double>> result = CSV.read("data.csv");

	std::cout<<"X: ";
	for(int a=0;a<result.size();a++){
		std::cout<<result[a][0]<<" ";
	}

	std::cout<<"\n\n";
	std::cout<<"Y: ";
	for(int a=0;a<result.size();a++){
		std::cout<<result[a][1]<<" ";
	}

	std::cout<<"\n\n";
	system("pause");
	return 0;
}