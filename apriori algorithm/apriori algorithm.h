#include "../csv/csv.h"

/*PERFORM APRIORI ALGORITHM AND GENERATES SUPPORT AND CONFIDENCE FOR 3 PASS*/

class aprioriAlgorithm{
private:
	std::vector<std::string> dataROW;
	std::map<std::string,int> itemCount;
	
	std::map<std::string,int> pass1Data;
	std::map<std::string,int> pass2Data;
	std::map<std::string,int> pass3Data;
	std::map<std::string,double> finalRules;

	int ROW;
	std::string filename;
	double minSupport;
	double minConfidence;

public:
	aprioriAlgorithm(std::string dataFile, double, double);	

	void readData();		//read data from csv file

	void countDataItem();	//count total items

	void runAlgo();		//calc slope and intercept

	std::map<std::string,int> pass1();		//run pass1 (count and filter)

	std::map<std::string,int> pass2();		//run pass2 (count and filter)

	std::map<std::string,int> pass3();		//run pass3 (count and filter)

	void calcStrongRules();		//calculate strong rules

	std::vector<std::string> getFinalItems(std::string);		//return items from 3rd pass

	double getInputSupport(std::vector<std::string>);			//get support for given item

	void displayReadData();		//display data read

	void displayItemCount();	//display item count

	void displayPass1Data();	//display data after 1st pass

	void displayPass2Data();	//display data after 2nd pass

	void displayPass3Data();	//display data after 3rd pass

	void displayFinalRules();	//display final confident rules
};

aprioriAlgorithm::aprioriAlgorithm(std::string dataFile, double minSupport, double minConfidence){
	filename=dataFile;
	this->minSupport=minSupport;
	this->minConfidence=minConfidence;
}

void aprioriAlgorithm::readData(){
	csv CSV;
	std::vector<std::string> data = CSV.readTable(filename);

	for(int a=0;a<data.size();a++){			//read rows from data
		dataROW.push_back(data[a]);
	}

	ROW=dataROW.size();
}

void aprioriAlgorithm::countDataItem(){
	for(int a=0;a<ROW;a++){
		char *token = strtok(const_cast<char*>(dataROW[a].c_str()), ",");

	    while (token != nullptr)
	    {	
	    	itemCount[token]++;
	        token = strtok(nullptr, ",");
	    }
	}
}

void aprioriAlgorithm::runAlgo(){
	pass1Data = pass1();
	pass2Data = pass2();
	pass3Data = pass3();

	calcStrongRules();
}

std::map<std::string,int> aprioriAlgorithm::pass1(){
	//count
	std::map<std::string,int> data = itemCount;

	//filter
	for (std::map<std::string, int>::iterator itr = itemCount.begin(); itr != itemCount.end(); ++itr) {
        if(itr->second < minSupport){																		
        	data.erase(itr->first);							//remove items with support < min
        }
	}
    return data;
}

std::map<std::string,int> aprioriAlgorithm::pass2(){
	std::map<std::string,int> data;
	int count=0;

	//count
	for (std::map<std::string, int>::iterator itr1 = itemCount.begin(); itr1 != itemCount.end(); ++itr1){
		for (std::map<std::string, int>::iterator itr2 = std::next(itr1,1); itr2 != itemCount.end(); ++itr2){
			count = 0;
			for(int a=0;a<ROW;a++){
				if((dataROW[a].find(itr1->first) != std::string::npos) && (dataROW[a].find(itr2->first)!= std::string::npos)){
					count++;									//count item pair for 2nd pass
				}
			}
			data.insert({itr1->first+","+itr2->first,count});
		}
	}

	//filter
	std::map<std::string,int> result = data;
	for (std::map<std::string, int>::iterator itr = data.begin(); itr != data.end(); ++itr) {
		if(itr->second < minSupport){
			result.erase(itr->first);							//remove items with support < min
		}
    }

	return result;
}

std::map<std::string,int> aprioriAlgorithm::pass3(){
	std::map<std::string,int> data;
	int count=0;

	//count
	for (std::map<std::string, int>::iterator itr1 = itemCount.begin(); itr1 != itemCount.end(); ++itr1){
		for (std::map<std::string, int>::iterator itr2 = std::next(itr1,1); itr2 != itemCount.end(); ++itr2){
			for (std::map<std::string, int>::iterator itr3 = std::next(itr2,1); itr3 != itemCount.end(); ++itr3){
				count = 0;
				for(int a=0;a<ROW;a++){
					if((dataROW[a].find(itr1->first) != std::string::npos) && (dataROW[a].find(itr2->first)!= std::string::npos) && (dataROW[a].find(itr3->first)!= std::string::npos)){
						count++;								// count item triplet for 3rd pass
					}
				}
				data.insert({itr1->first+","+itr2->first+","+itr3->first,count});
			}
		}
	}

	//filter
	std::map<std::string,int> result = data;
	for (std::map<std::string, int>::iterator itr = data.begin(); itr != data.end(); ++itr) {
		if(itr->second < minSupport){
			result.erase(itr->first);							//remove items with support < min
		}
    }

	return result;
}

void aprioriAlgorithm::calcStrongRules(){
	//calc Rules
	std::map<std::string,double> rules;
	
	for (std::map<std::string, int>::iterator itr = pass3Data.begin(); itr != pass3Data.end(); ++itr) {
		std::vector<std::string> items = getFinalItems(itr->first);

		double confidence;
		std::vector<std::string> input;
		std::vector<std::string> output;

		// 1st confidence
		input.clear();
		output.clear();
		input.push_back(items[0]);
		input.push_back(items[1]);
		output.push_back(items[2]);
		confidence = ((double)(itr->second) / getInputSupport(input))*100;
		rules.insert({input[0]+","+input[1]+"->"+output[0],confidence});

		// 2nd confidence
		input.clear();
		output.clear();
		input.push_back(items[1]);
		input.push_back(items[2]);
		output.push_back(items[0]);
		confidence = ((double)(itr->second) / getInputSupport(input))*100;
		rules.insert({input[0]+","+input[1]+"->"+output[0],confidence});

		// 3rd confidence
		input.clear();
		output.clear();
		input.push_back(items[0]);
		input.push_back(items[2]);
		output.push_back(items[1]);
		confidence = ((double)(itr->second) / getInputSupport(input))*100;
		rules.insert({input[0]+","+input[1]+"->"+output[0],confidence});

		// 4th confidence
		input.clear();
		output.clear();
		input.push_back(items[2]);
		output.push_back(items[0]);
		output.push_back(items[1]);
		confidence = ((double)(itr->second) / getInputSupport(input))*100;
		rules.insert({input[0]+"->"+output[1]+","+output[0],confidence});

		// 5th confidence
		input.clear();
		output.clear();
		input.push_back(items[0]);
		output.push_back(items[1]);
		output.push_back(items[2]);
		confidence = ((double)(itr->second) / getInputSupport(input))*100;
		rules.insert({input[0]+"->"+output[1]+","+output[0],confidence});

		// 6th confidence
		input.clear();
		output.clear();
		input.push_back(items[1]);
		output.push_back(items[0]);
		output.push_back(items[2]);
		confidence = ((double)(itr->second) / getInputSupport(input))*100;
		rules.insert({input[0]+"->"+output[1]+","+output[0],confidence});
    }

    finalRules = rules;
    //filter
    for (std::map<std::string, double>::iterator itr = rules.begin(); itr != rules.end(); ++itr) {
        if(itr->second < minConfidence){
        	finalRules.erase(itr->first);			//remove rules with confidence < min
        }
    }
}

std::vector<std::string> aprioriAlgorithm::getFinalItems(std::string itemList){
	std::vector<std::string> items;
	char *token = strtok(const_cast<char*>(itemList.c_str()), ",");
	int ind=0;
    while (token != nullptr)
    {	
    	items.push_back(token);
        token = strtok(nullptr, ",");
    }

    return items;
}

double aprioriAlgorithm::getInputSupport(std::vector<std::string> input){
	if(input.size() == 2){
		return (double)pass2Data[input[0]+","+input[1]];
	}
	return (double)pass1Data[input[0]];
}

void aprioriAlgorithm::displayReadData(){
	std::cout<<"\n\n";
	std::cout<<"Table Content:\n";
	for(int a=0;a<ROW;a++){
		std::cout<<dataROW[a]<<"\n";
	}

	std::cout<<"\nMinimum Support: "<<minSupport;
	std::cout<<"\nMinimum Confidence: "<<minConfidence;
}

void aprioriAlgorithm::displayItemCount(){
	std::cout<<"\n\n";
	std::cout<<"Item Count:\n";
    for (std::map<std::string, int>::iterator itr = itemCount.begin(); itr != itemCount.end(); ++itr) {
        std::cout<< itr->first<<'\t'<<itr->second<<'\n';
    }
}

void aprioriAlgorithm::displayPass1Data(){
	std::cout<<"\n\n";
	std::cout<<"Pass1 Output:\n";
    for (std::map<std::string, int>::iterator itr = pass1Data.begin(); itr != pass1Data.end(); ++itr) {
        std::cout<< itr->first<<'\t'<<itr->second<<'\n';
    }
}

void aprioriAlgorithm::displayPass2Data(){
	std::cout<<"\n\n";
	std::cout<<"Pass2 Output:\n";
    for (std::map<std::string, int>::iterator itr = pass2Data.begin(); itr != pass2Data.end(); ++itr) {
        std::cout<< itr->first<<'\t'<<itr->second<<'\n';
    }
}

void aprioriAlgorithm::displayPass3Data(){
	std::cout<<"\n\n";
	std::cout<<"Pass3 Output:\n";
    for (std::map<std::string, int>::iterator itr = pass3Data.begin(); itr != pass3Data.end(); ++itr) {
        std::cout<< itr->first<<'\t'<<itr->second<<'\n';
    }
}

void aprioriAlgorithm::displayFinalRules(){
	std::cout<<"\n\n";
	std::cout<<"Final Rules:\n";
    for (std::map<std::string, double>::iterator itr = finalRules.begin(); itr != finalRules.end(); ++itr) {
        std::cout<< itr->first<<'\t'<<itr->second<<'\n';
    }
}