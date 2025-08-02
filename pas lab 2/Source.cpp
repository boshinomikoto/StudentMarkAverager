#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

string del_space(string& s)
{
	for (int i = 0; i < s.size(); i++) 
	{
		if (isspace(s[i])) 
		{
			int value = (s.rfind(s[i]) - s.find(s[i]));
			s.erase(i, value);
		}
	}
	return s;
}

int main() 
{
	ifstream fin("text.txt");
	ofstream fout("text1.txt");
	ofstream fout1("text2.txt");

	string s;

	while (getline(fin, s)) 
	{
		double n = 0;
		int m = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			if (isdigit(s[i]))
			{
				n += s[i] - '0';
				m++;
				s.erase(i, 1);
			}
		}

		double aric_mean = round((n / m) * 10) / 10;
		if (aric_mean >= 4) 
			fout << del_space(s) << " - " << aric_mean << endl;
		if (aric_mean >= 3) 
			fout1 << del_space(s) << " - " << aric_mean << endl;
	}

	fin.close();
	fout.close();
	fout1.close();

	return 0;

}
