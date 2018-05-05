#pragma once
#include<fstream>
#include<string>
using namespace std;

class Utils
{
public:
	Utils();
	static string int2binary(int num, int nBits);
	static void decToHexa(int n, ofstream &file);
	~Utils();
};

