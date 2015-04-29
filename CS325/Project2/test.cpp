#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <climits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::ifstream;
using std::ofstream;

//coin change algorithm
void changedp(const vector<int> &array_v, int change, ofstream &output);
//prints results to file
void print(const vector<int> &array_o, ofstream &output);

int main(int argc, char* argv[]) {
    string input_file;
    string output_file;
    string line;
    vector <int> array_v;

    if (argc == 2){
        input_file = string(argv[1]);
        output_file = string(argv[1]);
        output_file.insert(input_file.find(".txt"),"_change");
    }
    else{
        cout << "No file specified." << endl;
        exit (EXIT_FAILURE);
    }

    ifstream input(input_file.c_str());
    ofstream output(output_file.c_str());

    //get array of coins
    getline(input, line);
    stringstream ss(line);
    int entry;

    if (ss.peek() == '[')
        ss.ignore();

    while (ss >> entry){
        array_v.push_back(entry);

        if (ss.peek() == ',')
            ss.ignore();
    }

    //get various change amounts
    while (getline(input, line)){
        stringstream ss(line);
        int change;

        ss >> change;
        changedp(array_v, change, output);
    }
    output.close();
    cout << "Results printed to " << output_file << "." << endl;

    return 0;
}

void changedp(const vector<int> &array_v, int change, ofstream &output){
    vector<int> array_o;
    vector<int> array_t;
    vector<int> array_c;
    int min;
    int coin;

    //initialize dp table and coins as zeros
    array_t.push_back(0);
    array_c.push_back(0);

    //initialize array O with zeros at each coin value
    for (int i = 0; i < (int)array_v.size(); i++)
        array_o.push_back(0);

    //construct dynamic programming table
    for (int i = 1; i <= change; i++){
        min = INT_MAX;
        for(int j = 0; j < (int)array_v.size(); j++){
            if (array_v[j] <= i){
                if(array_t[i-array_v[j]] + 1 < min){
                    min = array_t[i-array_v[j]] + 1;
                    coin = j;
                }
            }
        }
        array_t.push_back(min);
        array_c.push_back(coin);
    }

    //fill coin array O with coin values
    while (change > 0){
        //increments coin position for current change value
        array_o[array_c[change]]++;
        //decrease change by the coin value
        change -= array_v[array_c[change]];
    }
    print(array_o, output);
}

void print(const vector<int> &array_o, ofstream &output){
    //prints results
    output << "[";
    for (int i = 0; i < (int)array_o.size(); i++){
        output << array_o[i];
        if (i != (int)array_o.size() - 1)
            output << ",";
    }
    output << "]" << endl;
}
