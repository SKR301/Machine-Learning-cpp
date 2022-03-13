#include<bits/stdc++.h>
#include "neural network.h"

int main(int argc, char const *argv[]){

	NeuralNetwork NN("train_data.csv");

	NN.readData();
	NN.printModel();
	for(int a=0;a<30;a++){
		NN.initInputOutput(0);
		NN.forwardPropagation();
		NN.printTrainOutput();
		NN.backwardPropagation();
		NN.updateParam();
	}
	NN.printModel();
	
	std::cout<<"\n\n";
	system("pause");
	return 0;
}
