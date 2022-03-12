#include "../csv/csv.h"

class NeuralNetwork{
private:
	std::string filename;
public:
	std::vector<std::vector<int>> data;

	NeuralNetwork(std::string);
	void readData();		//read data from csv file
	void printData();
};

NeuralNetwork::NeuralNetwork(std::string datafile){
	filename = datafile;
}

void NeuralNetwork::readData(){
	csv CSV;
	std::vector<std::vector<std::string>> data = CSV.readTableMulCol(filename);

	for(int a=0;a<data.size();a++){
		for(int b=0;b<data[a].size();b++){
			std::cout<<data[a][b]<<" ";
		}
		std::cout<<"\n";
	}
}