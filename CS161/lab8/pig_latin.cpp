/******************************************************
 *  * ** Author: Megan Conley
 *  * ** Date: 11/23/2013
 *  * ** Description: Lab 8
 *  * ** Input: String via command line input
 *  * ** Output: The string in pig latin
 * * ******************************************************/



#include <iostream>
#include <string>

using namespace std;

void convertSentence(string sentence);
string pigLatinWord(string input);
bool isVowel(string input);

int main(int argc, char* argv[]) {

	if(argc != 2) {
		cout << "USAGE: " << argv[0] << " \"[sentence]\"" << endl;
	} else {
		string sentence(argv[1]);
		convertSentence(sentence);
	}

	return 0;
}

// This function splits up the sentence input by the user
// and translates one word at a ttime into pig latin,
// then prints the results.

void convertSentence(string sentence) {
	string word = "", remainder = sentence, pigLatin = "";

	for(int i = sentence.find(" ",0); i != string::npos; i = sentence.find(" ",0)) {
		word = sentence.substr(0,i);
		pigLatin += pigLatinWord(word) + " ";
		sentence = sentence.erase(0,i+1);
		i++;
	}

	pigLatin += pigLatinWord(sentence);

	cout << pigLatin << endl;

}

// This function turns a word into pig latin, returning the modified word.

string pigLatinWord(string input) {

	string word = "";

// If the first letter is a vowel, simply add "yay" to the end of it.
	if (isVowel(input)) {
		word = input + "yay";

//If the first letter is a consonant, add the first letter to the end,
//delete the first letter, then add "ay." - Credit to Tyler Sorrels
//CString/String solution post on Piazza. I had issues working with
//substrings, and this ended up being easier to read.
//But I did add a check for words that start with two consonants
//to cover all cases.
	} else {
		input += input.at(0);
		input = input.erase(0,1);
		word = input + "ay";
	}

	return word;

}

// Checks if the first letter of the word is a vowel.
// Returns true if yes, false if no.
bool isVowel(string input) {
	 return ((input[0] == 'a') || (input[0] == 'e') || (input[0] == 'i') || (input[0] == 'o') || (input[0] == 'u'));
}

