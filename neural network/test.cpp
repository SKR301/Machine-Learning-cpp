#include<bits/stdc++.h>
#include "neural network.h"

int main(int argc, char const *argv[]){

	NeuralNetwork NN("train_data.csv");

	NN.readData();
	// NN.printModel();
	for(int a=0;a<20;a++){
		NN.initInputOutput(a);
		NN.forwardPropagation();
		NN.printTrainOutput();
		NN.backwardPropagation();
		NN.updateParam();
		std::cout<<"\n"<<a<<": "<<(double)NN.correctCount/(double)(a+1);
	}
	// NN.printModel();
	
	std::cout<<"\n\n";
	system("pause");
	return 0;
}
