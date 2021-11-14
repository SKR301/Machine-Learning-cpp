#include "../csv/csv.h"
#include "../gnu/gnu.h"

/*PERFORM NAIVE BAYES ON GIVEN DATA AND EVEN PREDICT ACCORDINGLY*/

class NaiveBayes{
private:
	std::string filename;

public:
	NaiveBayes(std::string dataFile);	

	void readData();		//read data from csv file

	void runAlgo();			//predict outcome
};

NaiveBayes::NaiveBayes(std::string dataFile){
	filename=dataFile;
}

void NaiveBayes::readData(){
	csv CSV;
	std::vector<std::vector<std::string>> data = CSV.readTable2Col(filename);

	for(int a=0;a<data.size();a++){
		for(int b=0;b<data[a].size();b++){
			std::cout<<data[a][b]<<" ";
		}
		std::cout<<"\n";
	}
}

void NaiveBayes::runAlgo(){

}	