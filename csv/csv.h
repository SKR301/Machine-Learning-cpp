/*READ FROM THE CSV FILE AND 2D VECTOR AS X,Y values*/


class csv{
public:
	std::vector<std::vector<double>> read(std::string fileName);	//read from file
};

std::vector<std::vector<double>> csv::read(std::string fileName){
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