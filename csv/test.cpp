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

	std::vector<std::vector<std::string>> resultTable = CSV.readTableMulCol("dataMulCol.csv");		//data file

	std::cout<<"\n\n";
	std::cout<<"Table Content: \n";
	for(int a=0;a<resultTable.size();a++){
		for(int b=0;b<resultTable[a].size();b++){
			std::cout<<resultTable[a][b]<<" ";
		}
		std::cout<<"\n";
	}

	std::vector<std::vector<int>> resultTable = CSV.readTableMulColIntData("dataMulCol.csv");		//data file

	std::cout<<"\n\n";
	std::cout<<"Table Content: \n";
	for(int a=0;a<resultTable.size();a++){
		for(int b=0;b<resultTable[a].size();b++){
			std::cout<<resultTable[a][b]<<" ";
		}
		std::cout<<"\n";
	}

	std::cout<<"\n\n";
	system("pause");
	return 0;
}