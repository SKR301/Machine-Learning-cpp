#include<bits/stdc++.h>
#include "gnu.h"

int main(int argc, char const *argv[])
{
	int slope=10,intercept=0;
	gnu GNU;

	GNU.plotCmd("plot sin(x)");
	GNU.plotLine(slope,intercept);
	GNU.plotPoints("data.csv");
	GNU.plotGraph("data.csv",slope,intercept);

	system("pause");
	return 0;
}