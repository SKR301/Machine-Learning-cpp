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
	int output;

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
	void forwardPropagation(); 		//run the NN forward (generates an output)
	void backwardPropagation(); 		//run the NN backward (updates for errors)
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
	for(int a=0;a<hiddenLayer1Size;a++){
		std::vector<double> temp;
		for(int b=0;b<inputLayerSize;b++){
			temp.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
		}
		inputHidden1Weight.push_back(temp);
	}
	for(int a=0;a<hiddenLayer1Size;a++){
		hiddenLayer1Bias.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
	}
	for(int a=0;a<outputLayerSize;a++){
		std::vector<double> temp;
		for(int b=0;b<hiddenLayer1Size;b++){
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
	for(int a=0;a<hiddenLayer1Size;a++){
		for(int b=0;b<inputLayerSize;b++){
			std::cout<<inputHidden1Weight[a][b]<<"\t";
		}
		std::cout<<"\n";
	}

	std::cout<<"\n\nHIDDEN1_BIAS:\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		std::cout<<hiddenLayer1Bias[a]<<"\n";
	}

	std::cout<<"\n\nHIDDEN1_OUTPUT_WEIGHT:\n\n";
	for(int a=0;a<outputLayerSize;a++){
		for(int b=0;b<hiddenLayer1Size;b++){
			std::cout<<hidden1OutputWeight[a][b]<<"\t";
		}
		std::cout<<"\n";
	}

	std::cout<<"\n\nOUTPUT_BIAS:\n\n";
	for(int a=0;a<outputLayerSize;a++){
		std::cout<<outputLayerBias[a]<<"\n";
	}
}

void NeuralNetwork::forwardPropagation(){
	std::cout<<"\n\n--------------------------------:\n\n";
	// input-hidden1
	for(int a=0;a<hiddenLayer1Size;a++){
		double val = 0;
		for(int b=0;b<inputLayerSize;b++){
			val += inputHidden1Weight[a][b] * inputLayer[b];
		}
		hiddenLayer1[a] = val + hiddenLayer1Bias[a];
	}

	std::cout<<"\n\nFORWARD_PROPAGATION(hidden1):\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		std::cout<<hiddenLayer1[a]<<"\t";
	}

	//reLU on hidden1
	for(int a=0;a<hiddenLayer1Size;a++){
		hiddenLayer1[a] = std::max(0.0,hiddenLayer1[a]);
	}

	std::cout<<"\n\nFORWARD_PROPAGATION(hidden1 ACTIVATED):\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		std::cout<<hiddenLayer1[a]<<"\t";
	}

	// hidden1-output
	for(int a=0;a<outputLayerSize;a++){
		double val = 0;
		for(int b=0;b<hiddenLayer1Size;b++){
			val += hidden1OutputWeight[a][b] * hiddenLayer1[b];
		}
		outputLayer[a] = val + outputLayerBias[a];
	}

	std::cout<<"\n\nFORWARD_PROPAGATION(output):\n\n";
	for(int a=0;a<outputLayerSize;a++){
		std::cout<<outputLayer[a]<<"\t";
	}

	//softMax on output
	double sumExp = 0;
	for(int a=0;a<outputLayerSize;a++){
		sumExp += exp(outputLayer[a]);
	}
	for(int a=0;a<outputLayerSize;a++){
		outputLayer[a] = exp(outputLayer[a]) / sumExp;
	}

	std::cout<<"\n\nFORWARD_PROPAGATION(output ACTIVATED):\n\n";
	for(int a=0;a<outputLayerSize;a++){
		std::cout<<outputLayer[a]<<"\t";
	}
}