class Neuron{
private:
	double val;
public:
	Neuron();
	Neuron(double);
	bool activationFunc();
	double retVal();
};

Neuron::Neuron(double v){
	val = v;
}

Neuron::Neuron(){
	val = 0;
}

bool Neuron:: activationFunc(){

	/*code for activation function*/

	return true;
}

double Neuron::retVal(){
	return val;
}