#include "../csv/csv.h"

class NeuralNetwork{
private:
	std::string filename;
	std::vector<std::vector<int>> data;

	std::vector<double> inputLayer;
	std::vector<double> hiddenLayer1;
	std::vector<double> outputLayer;
	std::vector<std::vector<double>> inputHidden1Weight;
	std::vector<std::vector<double>> hidden1OutputWeight;
	std::vector<double> hiddenLayer1Bias;
	std::vector<double> outputLayerBias;
	int actualOutput;

	int inputLayerSize;
	int outputLayerSize;
	int hiddenLayer1Size;

public:
	NeuralNetwork(std::string);
	void readData();		//read data from csv file
	void printData();		//print read data
	void initInputOutput(int);		//initialize the input layer with provided row data
	void printInputLayerData();		//print input layer data
	void printModel();		//print weights and bias
};

NeuralNetwork::NeuralNetwork(std::string datafile){
	filename = datafile;

	inputLayerSize = 9;
	hiddenLayer1Size = 9;
	outputLayerSize = 2;

	for(int a=0;a<inputLayerSize;a++){
		inputLayer.push_back(0);
	}
	for(int a=0;a<hiddenLayer1Size;a++){
		hiddenLayer1.push_back(0);
	}
	for(int a=0;a<outputLayerSize;a++){
		outputLayer.push_back(0);
	}

  	srand (time(NULL));
	for(int a=0;a<inputLayerSize;a++){
		std::vector<double> temp;
		for(int b=0;b<hiddenLayer1Size;b++){
			temp.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
		}
		inputHidden1Weight.push_back(temp);
	}
	for(int a=0;a<hiddenLayer1Size;a++){
		hiddenLayer1Bias.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
	}
	for(int a=0;a<hiddenLayer1Size;a++){
		std::vector<double> temp;
		for(int b=0;b<outputLayerSize;b++){
			temp.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
		}
		hidden1OutputWeight.push_back(temp);
	}
	for(int a=0;a<outputLayerSize;a++){
		outputLayerBias.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
	}
}

void NeuralNetwork::readData(){
	csv CSV;
	data = CSV.readTableMulColIntData(filename);
}

void NeuralNetwork::initInputOutput(int row){
	inputLayer.clear();

	for(int a=0;a<inputLayerSize;a++){
		inputLayer.push_back((double)data[row][a+1]);
	}

	actualOutput = data[row][0];
}

void NeuralNetwork::printData(){
	std::cout<<"\n\nDATA SET:\n\n";
	for(int a=0;a<data.size();a++){
		for(int b=0;b<data[a].size();b++){
			std::cout<<data[a][b]<<" ";
		}
		std::cout<<"\n";
	}
}

void NeuralNetwork::printInputLayerData(){
	std::cout<<"\n\nINPUT LAYER DATA:\n\n";
	for(int a=0;a<inputLayerSize;a++){
		std::cout<<inputLayer[a]<<" ";
	}
}

void NeuralNetwork::printModel(){
	std::cout<<"\n\nINPUT_HIDDEN1_WEIGHT:\n\n";
	for(int a=0;a<inputLayerSize;a++){
		for(int b=0;b<hiddenLayer1Size;b++){
			std::cout<<inputHidden1Weight[a][b]<<"\t";
		}
		std::cout<<"\n";
	}

	std::cout<<"\n\nHIDDEN1_BIAS:\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		std::cout<<hiddenLayer1Bias[a]<<"\t";
	}

	std::cout<<"\n\nHIDDEN1_OUTPUT_WEIGHT:\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		for(int b=0;b<outputLayerSize;b++){
			std::cout<<hidden1OutputWeight[a][b]<<"\t";
		}
		std::cout<<"\n";
	}

	std::cout<<"\n\nOUTPUT_BIAS:\n\n";
	for(int a=0;a<outputLayerSize;a++){
		std::cout<<outputLayerBias[a]<<"\t";
	}
}