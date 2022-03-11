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
	void setOutputLayer();
	void setPathInputOutput();
	void run();
	int retOutput();
};

NeuralNetwork::NeuralNetwork(std::vector<std::vector<int>> input){
	inputLayerSize = input.size() * input[0].size();
	outputLayerSize = 2;
	pathInputOutputSize = inputLayerSize * outputLayerSize;

	setInputLayer(input);
	setOutputLayer();
	setPathInputOutput();

}

void NeuralNetwork::setInputLayer(std::vector<std::vector<int>> input){
	for(int a=0;a<input.size();a++){
		for(int b=0;b<input[a].size();b++){
			Neuron neuronNode(input[a][b]);
			inputLayer.push_back(neuronNode);
		}
	}
}

void NeuralNetwork::setOutputLayer(){
	for(int a=0;a<outputLayerSize;a++){
		Neuron neuronNode;
		outputLayer.push_back(neuronNode);
	}
}

void NeuralNetwork::setPathInputOutput(){
	for(int a=0;a<inputLayerSize;a++){
		std::vector<Path> temp;
		for(int b=0;b<outputLayerSize;b++){
			Path pathNode;
			temp.push_back(pathNode);
		}
		pathInputOutput.push_back(temp);
	}
}

void NeuralNetwork::run(){
	/*Run the network*/
	
}

int NeuralNetwork::retOutput(){
	return output;
}



