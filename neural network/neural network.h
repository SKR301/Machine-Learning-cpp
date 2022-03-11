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
	std::vector<Neuron> setInputLayer(std::vector<std::vector<int>>);
	void run();
	int retOutput();
};

NeuralNetwork::NeuralNetwork(std::vector<std::vector<int>> input){
	int inputLayerSize = input.size() * input[0].size();
	int outputLayerSize = 2;
	int pathInputOutputSize = inputLayerSize * outputLayerSize;

	std::cout<<inputLayerSize<<" "<<outputLayerSize<<" "<<pathInputOutputSize;
	// inputLayer = setInputLayer(input);
}

std::vector<Neuron> NeuralNetwork::setInputLayer(std::vector<std::vector<int>> input){
	/*Feed data from input matrix to inputLayer*/
	std::vector<Neuron> v;
	return v;
}

void NeuralNetwork::run(){
	/*Run the network*/
}

int NeuralNetwork::retOutput(){
	return output;
}



