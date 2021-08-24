#include "../csv/csv.h"
#include "../gnu/gnu.h"

/*PERFORM LINEAR REGRESSION ON GIVEN DATA AND EVEN PREDICT ACCORDINGLY*/

class apprioriAlgorithm{
private:
	std::vector<std::string> ROW;
	int N;
	std::string filename;

public:
	apprioriAlgorithm(std::string dataFile);	

	void readData();		//read data from csv file

	void runAlgo();		//calc slope and intercept

	void displayReadData();		//display data read
};

apprioriAlgorithm::apprioriAlgorithm(std::string dataFile){
	filename=dataFile;
}

void apprioriAlgorithm::readData(){
	csv CSV;
	std::vector<std::string> data = CSV.readTable(filename);

	for(int a=0;a<data.size();a++){			//read X values
		ROW.push_back(data[a]);
	}

	N=ROW.size();
}

void apprioriAlgorithm::displayReadData(){
	std::cout<<"\n\n";
	std::cout<<"Table Content:\n";
	for(int a=0;a<N;a++){
		std::cout<<ROW[a]<<"\n";
	}
}

