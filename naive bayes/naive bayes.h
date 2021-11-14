#include "../csv/csv.h"
#include "../gnu/gnu.h"

/*PERFORM NAIVE BAYES ON GIVEN DATA AND EVEN PREDICT ACCORDINGLY*/

class NaiveBayes{
private:
	std::map<std::string, std::vector<int>> matrix;
	std::string filename;

public:
	NaiveBayes(std::string dataFile);	

	void readData();		//read data from csv file

	void runAlgo();			//predict outcome

	void displayMatrix();	//display matrix
};

NaiveBayes::NaiveBayes(std::string dataFile){
	filename=dataFile;
}

void NaiveBayes::readData(){
	csv CSV;
	std::vector<std::vector<std::string>> data = CSV.readTable2Col(filename);

	for(int a=0;a<data.size();a++){
		
		std::map<std::string, std::vector<int>>::iterator it = matrix.find(data[a][0]);
		
		if(it == matrix.end()){
			std::vector<int> temp = {0,0};

			if(data[a][1] == "yes"){
				temp[0]++;
			} else {
				temp[1]++;
			}

			matrix[data[a][0]] = temp;
		} else {
			if(data[a][1] == "yes"){
				++matrix[data[a][0]][0];
			} else{
				++matrix[data[a][0]][1];
			}
		}
	}
}

void NaiveBayes::runAlgo(){

}	

void NaiveBayes::displayMatrix(){
	std::cout<<"\n\n---MATRIX---\n\n";
	std::map<std::string, std::vector<int>>::iterator it = matrix.begin();

	std::cout<<"Index"<<"\t\t"<<"1s"<<"\t\t"<<"0s"<<"\n";
	for (it=matrix.begin(); it!=matrix.end(); ++it)
    	std::cout<<it->first<<"\t\t"<<it->second[0]<<"\t\t"<<it->second[1]<<"\n";
}