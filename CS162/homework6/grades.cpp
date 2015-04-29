/********************************************************************* 
 * ** Program Filename: grades.cpp
 * ** Author: Megan Conley
 * ** Date: 2/15/2014
 * ** Description: Lab 3
 * ** Input: Contents of file "input.txt"
 * ** Output: Calculates average grade using input file, prints formatted
 * output to "output.txt", then copies contents of output file to input file.
 * *********************************************************************/

#include<iomanip>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

/********************************************************************* 
 * ** Function: findAverage
 * ** Description: Reads the input file to find the average of the
 * scores listed. If there are less than 10 scores, it outputs 00
 * to keep the line lengths the same. Then it prints the average score.
 * ** Parameters: Ifstream, ofstream
 * ** Pre-Conditions: Input file is formatted with at least two strings
 * ** Post-Conditions: Prints input line to output file, appends 00 to
 * bring the number of ints per line to 10 if necessary, then appends the
 * average score per line.
 * *********************************************************************/ 

void findAverage(std::ifstream& ifs, std::ofstream& ofs) {

	ofs.open("output.txt", std::ofstream::out | std::ofstream::app);
        std::stringstream ss;
        std::string str;
        std::string name;
        std::string name2;
        int temp;
        int total = 0;
        int count = 0;

        while(getline(ifs, str)) {
                ss << str;
                ofs << str;
                ss >> name;
                while (getline(ss, str, ' ')) {
                        ss >> name2;
                        while (ss >> temp) {
                                count++;
                                total +=temp;
                        }
                        double avg = (double)total/10;
                        while (count < 10) {
                                ofs << " 00";
                                count++;
                        }
                        ofs << std::setw(8) << avg << std::endl;
                }
                ss.clear();
                total = 0;
                count = 0;
        }

	ofs.close();
}

/********************************************************************* 
 * ** Function: explainOutput
 * ** Description: Writes a header to the output file to label the 
 * columns.
 * ** Parameters: Ofstream
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates output file (if necessary) and prints
 * a formatted header.
 * *********************************************************************/ 

void explainOutput(std::ofstream& ofs) {

	ofs.open("output.txt");
	ofs << std::setw(20) << "TEST SCORES" << std::endl;
	ofs << "NAME";
	ofs << std::setw(15) << "SCORES";
	ofs << std::setw(25) << "AVERAGE" << std::endl;
	ofs.close();
}

/********************************************************************* 
 * ** Function: copyFile
 * ** Description: Copies contents out output file to input file
 * ** Parameters: Ofstream, ifstream
 * ** Pre-Conditions: Output file has some content
 * ** Post-Conditions: Input file is overwritten to contain the contents
 * of the output file.
 * *********************************************************************/ 

void copyFile(std::ofstream& ofs, std::ifstream& ifs) {

	ifs.open("output.txt");
	ofs.open("input.txt");
	std::string str;
	while (getline(ifs, str)) {
		ofs << str << std::endl;
	}

	ifs.close();
	ofs.close();
}
		

int main() {

	std::ifstream ifs("input.txt");
	std::ofstream ofs;

	explainOutput(ofs);
	findAverage(ifs, ofs);
	
	ifs.close();

	copyFile(ofs, ifs);

	return 0;
}

