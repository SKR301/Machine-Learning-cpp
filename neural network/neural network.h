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
	// std::vector<double> hiddenLayer1Bias;
	// std::vector<double> outputLayerBias;
	std::vector<std::vector<double>> oneHot;
	int expectedOutput;
	int output;
	std::vector<std::vector<double>> inputHidden1WeightError;
	std::vector<std::vector<double>> hidden1OutputWeightError;
	// std::vector<double> hiddenLayer1BiasError;
	// std::vector<double> outputLayerBiasError;

	int inputLayerSize;
	int outputLayerSize;
	int hiddenLayer1Size;
	double alpha;

public:
	int correctCount;
	NeuralNetwork(std::string);
	void readData();		//read data from csv file
	void printData();		//print read data
	void initInputOutput(int);		//initialize the input layer with provided row data
	void printInputLayerData();		//print input layer data
	void printHiddenLayer1Data();		//print hidden layer1 data
	void printOutputLayerData();		//print output layer data
	void printModel();		//print weights and bias
	void printTrainOutput();		//print expected and actual output
	void forwardPropagation(); 		//run the NN forward (generates an output)
	void backwardPropagation(); 		//run the NN backward (updates for errors)
	std::vector<double> calcDotProductAddBias(std::vector<std::vector<double>>, std::vector<double>, std::vector<double>, int, int);	//calculate W.V+B
	std::vector<double> calcDotProduct(std::vector<std::vector<double>>, std::vector<double>, int, int);	//calculate W.V+B
	std::vector<double> softMax(std::vector<double>, int);		// return softMax vector for input vector
	std::vector<double> ReLU(std::vector<double>, int);		// return ReLU vector for input vector
	std::vector<double> ReLUDeriv(std::vector<double>, int);		// return ReLU_derivative for input vector
	std::vector<double> vectorSubtraction(std::vector<double>, std::vector<double>, int);		// subtract 2 vectors A-B
	std::vector<std::vector<double>> calcDotProductAvg(std::vector<double>, std::vector<double>, int, int);		// calculate A.B/m
	std::vector<double> calcDotMultiplyReLUInv(std::vector<std::vector<double>>, std::vector<double>, std::vector<double>, int, int);		// returns A.B*C
	std::vector<std::vector<double>> updateWeight(std::vector<std::vector<double>>, std::vector<std::vector<double>>, int, int);	//update the input vector by given error
	int calcOutput();		//calculate output
	void updateParam();		//updates parameters
};

NeuralNetwork::NeuralNetwork(std::string datafile){
	filename = datafile;

	inputLayerSize = 9;
	hiddenLayer1Size = 9;
	outputLayerSize = 2;
	alpha = 0.2;
	correctCount=0;

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
	// for(int a=0;a<hiddenLayer1Size;a++){
	// 	hiddenLayer1Bias.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
	// }
	for(int a=0;a<outputLayerSize;a++){
		std::vector<double> temp;
		for(int b=0;b<hiddenLayer1Size;b++){
			temp.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
		}
		hidden1OutputWeight.push_back(temp);
	}
	// for(int a=0;a<outputLayerSize;a++){
	// 	outputLayerBias.push_back(((double)(rand() % 1000)/ 1000) - 0.5);
	// }
	for(int a=0;a<outputLayerSize;a++){
		std::vector<double> temp;
		for(int b=0;b<outputLayerSize;b++){
			(a==b)?temp.push_back(1):temp.push_back(0);
		}
		oneHot.push_back(temp);
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

	expectedOutput = data[row][0];
}

void NeuralNetwork::printData(){
	std::cout<<"\n\nDATA SET:\n\n";
	for(int a=0;a<data.size();a++){
		for(int b=0;b<data[a].size();b++){
			std::cout<<data[a][b]<<"\t";
		}
		std::cout<<"\n";
	}
}

void NeuralNetwork::printInputLayerData(){
	std::cout<<"\n\nINPUT LAYER DATA:\n\n";
	for(int a=0;a<inputLayerSize;a++){
		std::cout<<inputLayer[a]<<"\t";
	}
}

void NeuralNetwork::printHiddenLayer1Data(){
	std::cout<<"\n\nHIDDEN LAYER 1 DATA:\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		std::cout<<hiddenLayer1[a]<<"\t";
	}
}

void NeuralNetwork::printOutputLayerData(){
	std::cout<<"\n\nOUTPUT LAYER DATA:\n\n";
	for(int a=0;a<outputLayerSize;a++){
		std::cout<<outputLayer[a]<<"\t";
	}
}

void NeuralNetwork::printModel(){
	std::cout<<"\n\n--------------MODEL-----------:\n\n";
	std::cout<<"\n\nINPUT_HIDDEN1_WEIGHT:\n\n";
	for(int a=0;a<hiddenLayer1Size;a++){
		for(int b=0;b<inputLayerSize;b++){
			std::cout<<inputHidden1Weight[a][b]<<"\t";
		}
		std::cout<<"\n";
	}

	// std::cout<<"\n\nHIDDEN1_BIAS:\n\n";
	// for(int a=0;a<hiddenLayer1Size;a++){
	// 	std::cout<<hiddenLayer1Bias[a]<<"\n";
	// }

	std::cout<<"\n\nHIDDEN1_OUTPUT_WEIGHT:\n\n";
	for(int a=0;a<outputLayerSize;a++){
		for(int b=0;b<hiddenLayer1Size;b++){
			std::cout<<hidden1OutputWeight[a][b]<<"\t";
		}
		std::cout<<"\n";
	}

	// std::cout<<"\n\nOUTPUT_BIAS:\n\n";
	// for(int a=0;a<outputLayerSize;a++){
	// 	std::cout<<outputLayerBias[a]<<"\n";
	// }
	std::cout<<"\n\n------------------------------:\n\n";
}

void NeuralNetwork::printTrainOutput(){
	std::cout<<"\n\nActual\tExpected:";
	std::cout<<"\n"<<output<<"\t"<<expectedOutput;
	if(output==expectedOutput){correctCount++;}
}

void NeuralNetwork::forwardPropagation(){
	// hiddenLayer1 = calcDotProductAddBias(inputHidden1Weight, inputLayer, hiddenLayer1Bias, hiddenLayer1Size, inputLayerSize);
	hiddenLayer1 = calcDotProduct(inputHidden1Weight, inputLayer, hiddenLayer1Size, inputLayerSize);
	hiddenLayer1 = ReLU(hiddenLayer1, hiddenLayer1Size);
	// outputLayer = calcDotProductAddBias(hidden1OutputWeight, hiddenLayer1, outputLayerBias, outputLayerSize, hiddenLayer1Size);
	outputLayer = calcDotProduct(hidden1OutputWeight, hiddenLayer1, outputLayerSize, hiddenLayer1Size);
	outputLayer = softMax(outputLayer, outputLayerSize);
	output = calcOutput();
}

int NeuralNetwork::calcOutput(){
	int pos = 0;
	for(int a=0;a<outputLayerSize;a++){
		if(outputLayer[pos]<outputLayer[a]){
			pos = a;
		}
	}
	return pos;
}

void NeuralNetwork::backwardPropagation(){
	std::vector<double> outputLayerError = vectorSubtraction(outputLayer, oneHot[expectedOutput], outputLayerSize);
	hidden1OutputWeightError = calcDotProductAvg(outputLayerError, hiddenLayer1, outputLayerSize, hiddenLayer1Size);
	std::vector<double> ReLUInv = ReLUDeriv(hiddenLayer1, hiddenLayer1Size);
	std::vector<double> hiddenLayer1Error = calcDotMultiplyReLUInv(hidden1OutputWeight, outputLayerError, ReLUInv, outputLayerSize, hiddenLayer1Size);
	inputHidden1WeightError = calcDotProductAvg(hiddenLayer1Error, inputLayer, hiddenLayer1Size, inputLayerSize);
}

void NeuralNetwork::updateParam(){
	inputHidden1Weight = updateWeight(inputHidden1Weight, inputHidden1WeightError, hiddenLayer1Size, inputLayerSize);
	hidden1OutputWeight = updateWeight(hidden1OutputWeight, hidden1OutputWeightError, outputLayerSize, hiddenLayer1Size);
}

std::vector<std::vector<double>> NeuralNetwork::updateWeight(std::vector<std::vector<double>> vec, std::vector<std::vector<double>> update, int row, int col){
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			vec[a][b] = vec[a][b] - alpha * update[a][b];
		}
	}
	return vec;
}

std::vector<double> NeuralNetwork::vectorSubtraction(std::vector<double> A, std::vector<double> B, int size){
	std::vector<double> output;
	for(int a=0;a<size;a++){
		output.push_back(A[a]-B[a]);
	}
	return output;
}

std::vector<double> NeuralNetwork::ReLU(std::vector<double> vec, int size){
	for(int a=0;a<size;a++){
		vec[a] = std::max(0.0,vec[a]);
	}
	return vec;
}

std::vector<double> NeuralNetwork::ReLUDeriv(std::vector<double> vec, int size){
	for(int a=0;a<size;a++){
		vec[a] = (vec[a]<=0)?0:1;
	}
	return vec;
}

std::vector<double> NeuralNetwork::softMax(std::vector<double> vec, int size){
	double sumExp = 0;
	for(int a=0;a<size;a++){
		sumExp += exp(vec[a]);
	}
	for(int a=0;a<size;a++){
		vec[a] = exp(vec[a]) / sumExp;
	}
	return vec;
}

std::vector<double> NeuralNetwork::calcDotProductAddBias(std::vector<std::vector<double>> weight, std::vector<double> val, std::vector<double> bias, int row, int col){
	std::vector<double> res(row,0.0);

	for(int a=0;a<row;a++){
		double temp = 0;
		for(int b=0;b<col;b++){
			temp += weight[a][b] * val[b];
		}
		res[a] = temp + bias[a];
	}
	return res;
}

std::vector<double> NeuralNetwork::calcDotProduct(std::vector<std::vector<double>> weight, std::vector<double> val, int row, int col){
	std::vector<double> res(row,0.0);

	for(int a=0;a<row;a++){
		double temp = 0;
		for(int b=0;b<col;b++){
			temp += weight[a][b] * val[b];
		}
		res[a] = temp;
	}
	return res;
}

std::vector<std::vector<double>> NeuralNetwork::calcDotProductAvg(std::vector<double> error, std::vector<double> val, int row, int col){
	std::vector<std::vector<double>> res(row, std::vector<double>(col, 0.0));

	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			res[a][b] = error[a] * val[b] / col;
		}
	}
	return res;
}

std::vector<double> NeuralNetwork::calcDotMultiplyReLUInv(std::vector<std::vector<double>> weight, std::vector<double> error, std::vector<double> ReLUInv, int row, int col){
	std::vector<double> output;

	for(int a=0;a<col;a++){
		double sum = 0;
		for(int b=0;b<row;b++){
			sum += weight[b][a] * error[b];
		}
		output.push_back(sum * ReLUInv[a]);
	}

	return output;
}