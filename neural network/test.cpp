#include<bits/stdc++.h>
#include "neural network.h"

int main(int argc, char const *argv[]){

	NeuralNetwork NN("train_data.csv");

	NN.readData();
	// NN.initInputOutput(1);

	// NN.printData();
	// NN.printInputLayerData();
	NN.printModel();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}
