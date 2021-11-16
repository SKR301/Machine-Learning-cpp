#include "../csv/csv.h"
#include "../gnu/gnu.h"

/*PERFORM NAIVE BAYES ON GIVEN DATA AND EVEN PREDICT ACCORDINGLY*/

class NaiveBayes{
private:
	std::map<std::string, std::vector<int>> matrix;
	double Ones;
	double Zeros;
	double Totals;
	std::string filename;

public:
	NaiveBayes(std::string dataFile);	

	void readData();		//read data from csv file

	void runAlgo(std::string);			//predict outcome

	void displayMatrix();	//display matrix
};

NaiveBayes::NaiveBayes(std::string dataFile){
	filename=dataFile;
	Ones=0;
	Zeros=0;
	Totals=0;
}

void NaiveBayes::readData(){
	csv CSV;
	std::vector<std::vector<std::string>> data = CSV.readTable2Col(filename);

	for(int a=0;a<data.size();a++){
		std::map<std::string, std::vector<int>>::iterator it = matrix.find(data[a][0]);
		
		if(it == matrix.end()){
			std::vector<int> temp = {0,0};

			if(data[a][1] == "yes"){
				temp[1]++;
				Ones++;
			} else {
				temp[0]++;
				Zeros++;
			}

			matrix[data[a][0]] = temp;
		} else {
			if(data[a][1] == "yes"){
				++matrix[data[a][0]][1];
				Ones++;
			} else{
				++matrix[data[a][0]][0];
				Zeros++;
			}
		}
	}

	int total = Ones + Zeros;
}

void NaiveBayes::runAlgo(std::string key){
	int total = Ones + Zeros;

	double P_key_1 = matrix[key][1] / Ones;
	double P_key_0 = matrix[key][0] / Zeros;

	double P_1 = Ones / (Ones + Zeros);
	double P_0 = Zeros / (Ones + Zeros);

	double P_key = (matrix[key][1] + matrix[key][0]) / (Ones + Zeros);

	double P_0_key = (P_key_0 * P_0)/(P_key);
	double P_1_key = (P_key_1 * P_1)/(P_key);

	std::cout<<"\n1 => "<<P_1_key<<"\t0 => "<<P_0_key;							//Print 1/0 probablity

	std::cout<<"\n\n\nFINAL PREDICTION:";
	(P_1_key > P_0_key)?std::cout<<" 1":std::cout<<" 0";						//Print prediction
}	

void NaiveBayes::displayMatrix(){
	std::cout<<"\n\nMATRIX\n\n";
	std::map<std::string, std::vector<int>>::iterator it = matrix.begin();

	std::cout<<"Index"<<"\t\t"<<"1s"<<"\t\t"<<"0s"<<"\n";
	for (it=matrix.begin(); it!=matrix.end(); ++it)
    	std::cout<<it->first<<"\t\t"<<it->second[1]<<"\t\t"<<it->second[0]<<"\n";
}