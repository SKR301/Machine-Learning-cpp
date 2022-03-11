class Path{
private:
	double weight;
	double bias;
public:
	Path();
	Path(double, double);
	double retOutput(double);
	double retWeight();
	double retBias();
	void setWeight(double);
	void setBias(double);
};

Path::Path(){
	weight = 1;
	bias = 0;
}

Path::Path(double w, double b){
	weight = w;
	bias = b;
}

double Path::retOutput(double input){
	return weight * input + bias;
}

double Path::retWeight(){
	return weight;
}

double Path::retBias(){
	return bias;
}

void Path::setWeight(double w){
	weight = w;
}	

void Path::setBias(double b){
	bias = b;
}
