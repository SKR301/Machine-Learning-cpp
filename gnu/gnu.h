/*PLOT THE DATA IN GRAPHS*/
// ps=point size
// lc=line colour
// lw=line width
// pt=point type

class gnu
{
private:
	FILE *gnuPipe;

public:
	gnu();

	~gnu();

	void plotCmd(const std::string &command);		// plot a certain command

	void plotLine(int m,int c);						//plot a line given slope(m) and intercept(c)

	void plotPoints(std::string filename);			//plot points from a datafile (comma separated)

	void plotGraph(std::string filename,int m,int c);	//plot points and line
};

gnu::gnu(){
	gnuPipe=popen("gnuplot -persist","w");
	if (!gnuPipe)
	{
		std::cerr<<"GNU not found!!";
	}
	fprintf(gnuPipe, "set datafile separator ','\n");			//change this to set separator for datafile (',' by default)
	fprintf(gnuPipe, "set nokey\n");							//cahnge this to set legend location (disabled by default)
}

gnu::~gnu(){
	fprintf(gnuPipe,"exit\n");
	pclose(gnuPipe);
}

void gnu::plotCmd(const std::string &command){
	fprintf(gnuPipe, "%s\n", command.c_str());
	fflush(gnuPipe);
}

void gnu::plotLine(int m,int c){
	fprintf(gnuPipe, "plot %d*x+%d lw 1.5 lc 'black'\n", m, c);
	fflush(gnuPipe);
}

void gnu::plotPoints(std::string filename){
	fprintf(gnuPipe, "plot '%s' ps 1.5 pt 7 lc 'red'\n", filename.c_str());
	fflush(gnuPipe);
}

void gnu::plotGraph(std::string filename,int m,int c){
	fprintf(gnuPipe, "plot '%s' ps 1.5 pt 7 lc 'red', %d*x+%d lw 1.5 lc 'black'\n" , filename.c_str(),m,c);
	fflush(gnuPipe);
}