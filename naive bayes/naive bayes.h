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

	std::cout << "MATRIX:\n";
	std::map<std::string, std::vector<int>>::iterator it = matrix.begin();
	for (it=matrix.begin(); it!=matrix.end(); ++it)
    	std::cout << it->first << " => " << it->second[0] << " => " << it->second[1] << '\n';
}

void NaiveBayes::runAlgo(){

}	