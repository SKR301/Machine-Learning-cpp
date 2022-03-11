#include "neuron.h"
#include "path.h"

class NeuralNetwork{
private:
	std::vector<Neuron> inputLayer;
	std::vector<std::vector<Path>> pathInputOutput;
	std::vector<Neuron> outputLayer;
	int output;

	int inputLayerSize;
	int outputLayerSize;
	int pathInputOutputSize;

public:
	NeuralNetwork(std::vector<std::vector<int>>);
	void setInputLayer(std::vector<std::vector<int>>);
	void run();
	int retOutput();
};

NeuralNetwork::NeuralNetwork(std::vector<std::vector<int>> input){
	int inputLayerSize = input.size() * input[0].size();
	int outputLayerSize = 2;
	int pathInputOutputSize = inputLayerSize * outputLayerSize;

	setInputLayer(input);
}

void NeuralNetwork::setInputLayer(std::vector<std::vector<int>> input){
	for(int a=0;a<input.size();a++){
		for(int b=0;b<input[a].size();b++){
			Neuron neuronNode(input[a][b]);
			inputLayer.push_back(neuronNode);
		}
	}
}

void NeuralNetwork::run(){
	/*Run the network*/
}

int NeuralNetwork::retOutput(){
	return output;
}



