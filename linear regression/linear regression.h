#include "../csv/csv.h"

/*PERFORM LINEAR REGRESSION ON GIVEN DATA AND EVEN PREDICT ACCORDINGLY*/

class simpleLinearRegression{
private:
	std::vector<double> X;
	std::vector<double> Y;
	int N;
	double slope;
	double intercept;

public:
	void readData(std::string filename);		//read data from csv file

	int checkData();		//check for data inconsistency

	void runAlgo();		//calc slope and intercept

	void plot();		//plot the data graph (TODO)

	double predict(double x);		//perform prediction based on the data

	void displayReadData();		//display data read
};

void simpleLinearRegression::readData(std::string filename){
	csv CSV;
	std::vector<std::vector<double>> data = CSV.read(filename);

	for(int a=0;a<data.size();a++){			//read X values
		X.push_back(data[a][0]);
	}
	for(int a=0;a<data.size();a++){			//read Y values
		Y.push_back(data[a][1]);
	}

	if(!checkData()){
		system("pause");
		system("exit");
	}

	N=X.size();
}

int simpleLinearRegression::checkData(){
	if(X.size()!=Y.size()){					//check for unequal size
		std::cout<<"\n\n---------INVALID DATA--------";
		std::cout<<"\nData size not equal";
		return 0;
	}
	return 1;
}

void simpleLinearRegression::runAlgo(){
	double sigmaY=0;
	double sigmaX=0;
	double sigmaX2=0;
	double sigmaXY=0;

	for(int a=0;a<N;a++){
		sigmaY+=Y[a];
		sigmaX+=X[a];
		sigmaX2+=X[a]*X[a];
		sigmaXY+=X[a]*Y[a];
	}

	intercept = ((sigmaY*sigmaX2)-(sigmaX*sigmaXY))/((sigmaX2)-(sigmaX*sigmaX));		//calc intercept
	slope = (N*(sigmaXY)-(sigmaX*sigmaY))/((N*sigmaX2)-(sigmaX*sigmaX));				//calc slope
}	

double simpleLinearRegression::predict(double x){
	return (slope*x)+intercept;			//return predicted value
}

void simpleLinearRegression::displayReadData(){		
	std::cout<<"X: ";
	for(int a=0;a<X.size();a++){			//display X data
		std::cout<<X[a]<<" ";
	}

	std::cout<<"\n\n";
	std::cout<<"Y: ";
	for(int a=0;a<Y.size();a++){			//display Y data
		std::cout<<Y[a]<<" ";
	}
}