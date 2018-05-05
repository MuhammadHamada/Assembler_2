#include "MyAssembler.h"
#include<iostream>
#include<fstream>
using namespace std;
string codeFilePath = "code.txt";
string dataFilePath = "data.txt";
string instrFilePath = "instr.txt";
string memInstrFilePath = "instr.mem";
string memDataFilePath = "data.mem";

int main() {

	MyAssembler Assembler(codeFilePath, dataFilePath, instrFilePath);
	Assembler.run();
	if (!Assembler.get_syntaxError()) {
		cout << "Converting to mem file , please wait ..." << endl;
		Assembler.convertToMemFile(memInstrFilePath, memDataFilePath);
		cout << "Done -- Have Fun" << endl;
	}
	return 0;
}