#ifndef ASSEMBLER_2_MYASSEMBLER_H
#define ASSEMBLER_2_MYASSEMBLER_H

#include "Utils.h"
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
using namespace std;


class MyAssembler {

	ifstream codeFile; // the file which contains the source code
	string codeFilePath;

	ofstream dataFile; 
	string dataFilePath;

	ofstream instrFile;
	string instrFilePath;

	map<string, string>instrTable; // codes of instructions
	map<int, string>registerTable; // codes of registers
	vector<string>DataMem;
	vector<string>instrMem;

	bool syntaxError; // boolean to check if there is a syntax error or not
	int readDataSegment;
	int numLine;      // the current line which is been decoding
	int codePointer;  /* pointer to the address that will be filled by the next
					  instruction in the RAM
					  */
	int dataPointer; 
	void generateTables(); // Build all tables
	void lineParsing(string sLine);

public:
	MyAssembler(string cfPath, string dfPath,string ifPath); 
	void run(); // run the Assembler :D
	int stoi(string str);
	void convertToMemFile(string instrfpath, string datafpath);
	bool get_syntaxError(); // getter of syntaxError
	~MyAssembler();

};


#endif //ASSEMBLER_2_MYASSEMBLER_H