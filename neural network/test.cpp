#include<bits/stdc++.h>
#include "neural network.h"

int main(int argc, char const *argv[]){

	std::vector<std::vector<int>> matrix {{1,0,0},{0,1,0},{0,0,1}};

	NeuralNetwork NN(matrix);
	NN.run();


	std::cout<<"\n\n";
	system("pause");
	return 0;
}
