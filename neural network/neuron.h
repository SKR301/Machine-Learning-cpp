class Neuron{
private:
	double val;
public:
	Neuron();
	Neuron(double);
	bool activationFunc();
	double retVal();
	void setVal(double);
};

Neuron::Neuron(){
	val = 0;
}

Neuron::Neuron(double v){
	val = v;
}

bool Neuron:: activationFunc(){
	return (val >= 0.5);
}

double Neuron::retVal(){
	return val;
}

void Neuron::setVal(double v){
	val = v;
}
