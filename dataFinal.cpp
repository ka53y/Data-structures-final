#include <iostream>
using std::cout;
using std::cin;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iterator>
using std::istream_iterator;
#include <algorithm>
using std::copy;
#include <cstring>
#include <cstdio>
#include <cctype>
//#include "TimeInterval.h"
#include <chrono>

int getIndexForAsciiValues(string dictionaryWord, int spot) {
	char letter = dictionaryWord.at(spot);
	letter = tolower(letter);
	int asciiValue = (int)letter;
	return asciiValue - 97;
}

int main()
{

	vector<string> dictionaryWords;
	ifstream myfile("Dictionary.txt"); 

	copy(istream_iterator<string>(myfile),
	 istream_iterator<string>(),
         back_inserter(dictionaryWords));
	int indexArray[27][27];
	int indexV = 0;
	int exactI = 0;
	int slot = 0;
	int key = 0;
	//map<key, vector<string>> newHashTable;
	//vector<list<string> > hashTable;
	string dictionaryHash[729][20];
	for(int u = 0; u < 27; u++){
		for(int y = 0; y < 27; y++){
			indexArray[u][y] = indexV;
			indexV++;
		}
	}
        try {
        	for(int x=0; x<dictionaryWords.size(); x++){
			slot = 0;
			if(dictionaryWords.at(x).length() > 1){
				exactI = indexArray[getIndexForAsciiValues(dictionaryWords.at(x), 0)][getIndexForAsciiValues(dictionaryWords.at(x), 1)];
			}
			if(dictionaryWords.at(x).length() == 1){
				exactI = indexArray[getIndexForAsciiValues(dictionaryWords.at(x), 0)][getIndexForAsciiValues(dictionaryWords.at(x), 0)];
			}
			while(dictionaryHash[exactI][slot] != ""){
				slot++;
			}
			dictionaryHash[exactI][slot] = dictionaryWords.at(x);
			//cout<<dictionaryWords.at(x)<<" first letter ascii value: "<<getIndexForAsciiValues(dictionaryWords.at(x), 0)<<"\n";
    		}
	} catch(...) {
		cout << "Data Unavailable\n";
	}
	string inputWord;
	string userInput = "y";
	int a, b, flnum, slnum, c, d, e;
	int userExactI;
	int found=1;
	string userInput2;
	a=0;
	while(userInput == "y"){
		found = 0;
		//TimeInterval::TimeInterval::start();
		//cout<<indexV<<"\n";
		cout<<"Please enter a word you would like to find in the dictionary: ";
		cin>>inputWord;
		auto t1 = std::chrono::high_resolution_clock::now();
		if(inputWord.length() > 1){
			userExactI = indexArray[getIndexForAsciiValues(inputWord, 0)][getIndexForAsciiValues(inputWord, 1)];
		}
		if(inputWord.length() == 1){
			userExactI = indexArray[getIndexForAsciiValues(inputWord, 0)][getIndexForAsciiValues(inputWord, 0)];
		}
		while(inputWord.length() < 1){
			cout<<"Please input a word";
		}
		if(dictionaryHash[userExactI][0] == "" || found == 0){
			cout<<"False"<<"\n";
		} 
		//		
		c = 0;
		while(dictionaryHash[userExactI][c] != ""){
			if(inputWord == dictionaryHash[userExactI][c]){
				found = 1;
			}
			c++;
		}
		if(found == 0 && dictionaryHash[userExactI][0] != ""){
			d = 0;
			cout<<"This was not found in the dictionary did you mean any of the following words?(y/n) \n";
			while(dictionaryHash[userExactI][d] != ""){	
				cout<<dictionaryHash[userExactI][d]<<"\n";
				d++;
			}
			cin>>userInput2;
			if(userInput2 == "y"){
				found = 1;
			}
			if(userInput2 == "n"){
				cout<<"False\n";
				found = 0;
			}

		}
		//	
		if(dictionaryHash[userExactI][0] != "" && found == 1){
			a=0;
			cout<<"True"<<"\n";
			cout<<"Recommended word/words:\n";
			while(dictionaryHash[userExactI][a] != ""){
				
				cout<<dictionaryHash[userExactI][a]<<"\n";
				a++;
			}
		
		}
		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
		cout << duration <<"\n";
		//TimeInterval::TimeInterval::stop();
		//TimeInterval::TimeInterval::GetInterval();
		cout<<"Would you like to type another word (y/n): ";
		cin>>userInput;
		
	}
	/*char fl = 'a';
	char sl = 'n';
	flnum = (int)fl-97;
	slnum = (int)sl-97;
	a = 0;
	cout<<flnum<<" "<<slnum<<"\n";
	b = indexArray[flnum][slnum];
	while(dictionaryHash[b][a] != ""){
		cout<<dictionaryHash[b][a]<<"\n";
		a++;
	}

	cout<<dictionaryHash[b][0];
	*/
}