#include<bits/stdc++.h>
#include "neural network.h"

int main(int argc, char const *argv[]){

	std::vector<std::vector<int>> matrix {{1,0,0},{0,0,0},{0,0,0}};

	NeuralNetwork NN(matrix);
	NN.run();

	system("pause");
	return 0;
}