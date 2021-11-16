/*READ FROM THE CSV FILE AND 2D VECTOR AS X,Y values*/


class csv{
public:
	std::vector<std::vector<double>> readPoint(std::string fileName);	//read from file return points
	std::vector<std::vector<std::string>> readTable2Col(std::string fileName);	//read from file return string values
	std::vector<std::string> readTable(std::string fileName);			//read from file return table value
};

std::vector<std::vector<double>> csv::readPoint(std::string fileName){
	std::fstream file(fileName);
	std::string line;
	std::vector<std::vector<double>> result;
	std::vector<double> temp;
	double i;

	while (std::getline(file, line))		//read a line
	{
		char *token = strtok(const_cast<char*>(line.c_str()), ",");

	    while (token != nullptr)
	    {
	    	temp.clear();
	    	temp.push_back(std::atof(token));	//extract X
	        
	        token = strtok(nullptr, ",");
	    	
	    	temp.push_back(std::atof(token));	//extract y	
	    
	        token = strtok(nullptr, ",");
	    }
	    result.push_back(temp);
	}
	return result;
}

std::vector<std::string> csv::readTable(std::string fileName){
	std::fstream file(fileName);
	std::string line;
	std::vector<std::string> result;

	while (std::getline(file, line))		//read a line
	{
		result.push_back(line);
	}

	return result;
}

std::vector<std::vector<std::string>> csv::readTable2Col(std::string fileName){
	std::fstream file(fileName);
	std::string line;
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> temp;
	std::string i;

	while (std::getline(file, line))		//read a line
	{
		char *token = strtok(const_cast<char*>(line.c_str()), ",");

	    while (token != nullptr)
	    {
	    	temp.clear();
	    	temp.push_back(token);	//extract X
	        
	        token = strtok(nullptr, ",");
	    	
	    	temp.push_back(token);	//extract y	
	    
	        token = strtok(nullptr, ",");
	    }
	    result.push_back(temp);
	}
	return result;
}