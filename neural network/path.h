class Path{
private:
	double weight;
	double bias;
public:
	Path(double, double);
	Path();
	double getRes();
}

Path::Path(){
	weight = 0;
	bias = 0;
}

Path::Path(double w, double b){
	weight = w;
	bias = b;
}

double Path::getRes(double input){
	double output = 0;

	/*calculate output for this path*/

	return output;
}