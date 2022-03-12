#include<bits/stdc++.h>
#include "neural network.h"

int main(int argc, char const *argv[]){

	NeuralNetwork NN("data.csv");

	NN.readData();

	std::cout<<"\n\n";
	system("pause");
	return 0;
}
