#include "Utils.h"
#include <algorithm>


Utils::Utils()
{
}

string Utils::int2binary(int num, int nBits)
{
	string ans;
	if (num == 0) {
		ans += "0";
		nBits--;
	}
	else {
		int x = 0;
		while (num > 0)
		{
			x = num % 2;
			num /= 2;
			ans += ('0' + x);
			nBits--;
		}
	}
	reverse(ans.begin(), ans.end());
	while (nBits--)
	{
		ans = "0" + ans;
	}
	return ans;
}

// function to convert decimal to hexadecimal
void Utils::decToHexa(int n, ofstream &file)
{
	// char array to store hexadecimal number
	char hexaDeciNum[100];

	// counter for hexadecimal number array
	int i = 0;
	while (n != 0)
	{
		// temporary variable to store remainder
		int temp = 0;

		// storing remainder in temp variable.
		temp = n % 16;

		// check if temp < 10
		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}

	// printing hexadecimal number array in reverse order
	bool f = false;
	for (int j = i - 1; j >= 0; j--) {
		if (hexaDeciNum[j] >= 'A'&& hexaDeciNum[j] <= 'F') {
			char ch = tolower(hexaDeciNum[j]);
			file << ch;
		}
		else
			file << hexaDeciNum[j];
		f = true;
	}
	if (!f)file << '0';
}


Utils::~Utils()
{
}
