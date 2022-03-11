class Neuron{
private:
	double val;
public:
	Neuron();
	Neuron(double);
	bool activationFunc();
}

Neuron::Neuron(double v){
	val = v;
}

Neuron::Neuron(){
	val = 0;
}

bool Neuron:: activationFunc(){
	return (val >= 0.5);
}