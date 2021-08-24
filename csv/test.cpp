#include<bits/stdc++.h>
#include "csv.h"

int main(int argc, char const *argv[])
{
	csv CSV;
	std::vector<std::vector<double>> resultPoint = CSV.readPoint("dataPoint.csv");		//data file

	std::cout<<"X: ";
	for(int a=0;a<resultPoint.size();a++){
		std::cout<<resultPoint[a][0]<<" ";
	}

	std::cout<<"\n\n";
	std::cout<<"Y: ";
	for(int a=0;a<resultPoint.size();a++){
		std::cout<<resultPoint[a][1]<<" ";
	}

	std::vector<std::string> resultTable = CSV.readTable("dataTable.csv");		//data file

	std::cout<<"\n\n";
	std::cout<<"Table Content: ";
	for(int a=0;a<resultTable.size();a++){
		std::cout<<resultTable[a]<<" ";
	}

	std::cout<<"\n\n";
	system("pause");
	return 0;
}