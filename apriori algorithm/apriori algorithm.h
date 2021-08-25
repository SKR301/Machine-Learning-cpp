#include "../csv/csv.h"
#include "../gnu/gnu.h"

/*PERFORM LINEAR REGRESSION ON GIVEN DATA AND EVEN PREDICT ACCORDINGLY*/

class apprioriAlgorithm{
private:
	std::vector<std::string> dataROW;
	std::map<std::string,int> itemCount;
	int ROW;
	int N;
	std::string filename;
	double minSupport;
	double minConfidence;

public:
	apprioriAlgorithm(std::string dataFile, double, double);	

	void readData();		//read data from csv file

	void countDataItem();	//count total items

	void runAlgo();		//calc slope and intercept

	std::map<std::string,int> pass1();		//run pass1

	void displayReadData();		//display data read

	void displayItemCount();	//display item count
};

apprioriAlgorithm::apprioriAlgorithm(std::string dataFile, double minSupport, double minConfidence){
	filename=dataFile;
	this->minSupport=minSupport;
	this->minConfidence=minConfidence;
}

void apprioriAlgorithm::readData(){
	csv CSV;
	std::vector<std::string> data = CSV.readTable(filename);

	for(int a=0;a<data.size();a++){			//read row values
		dataROW.push_back(data[a]);
	}

	ROW=dataROW.size();
}

void apprioriAlgorithm::countDataItem(){
	for(int a=0;a<ROW;a++){
		char *token = strtok(const_cast<char*>(dataROW[a].c_str()), ",");

	    while (token != nullptr)
	    {	
	    	itemCount[token]++;
	        token = strtok(nullptr, ",");
	    }
	}

	N = itemCount.size();
}

void apprioriAlgorithm::runAlgo(){
	countDataItem();
	std::map<std::string,int> pass1Output = pass1();

	std::cout<<"\n\nPASS1 output\n";
	for (std::map<std::string, int>::iterator itr = pass1Output.begin(); itr != pass1Output.end(); ++itr) {
	    std::cout<< itr->first<<'\t'<<itr->second<<'\n';
	}
}

std::map<std::string,int> apprioriAlgorithm::pass1(){
	std::map<std::string,int> pass1data = itemCount;
	for (std::map<std::string, int>::iterator itr = pass1data.begin(); itr != pass1data.end(); ++itr) {
        if(itr->second < minSupport){
        	pass1data.erase(itr);
        }
    }

    return pass1data;
}

void apprioriAlgorithm::displayReadData(){
	std::cout<<"\n\n";
	std::cout<<"Table Content:\n";
	for(int a=0;a<ROW;a++){
		std::cout<<dataROW[a]<<"\n";
	}

	std::cout<<"\nMinimum Support: "<<minSupport;
	std::cout<<"\nMinimum Confidence: "<<minConfidence;

}

void apprioriAlgorithm::displayItemCount(){
	std::cout<<"\n\n";
	std::cout<<"Item Count:\n";
    for (std::map<std::string, int>::iterator itr = itemCount.begin(); itr != itemCount.end(); ++itr) {
        std::cout<< itr->first<<'\t'<<itr->second<<'\n';
    }
}
