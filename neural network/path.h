class Path{
private:
public:
	double weight;
	double bias;
	Path();
	Path(double, double);
	double retOutput(double);
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
	double output = 0;

	/*calculate output for this path*/

	return output;
}