#include <iostream>
#include <sstream>

using namespace std;

double Convert(string simbol)
{
	double a;
	stringstream ss(simbol);
	ss >> a;
	return a;
}

string slovo(string all_text, string search_simbol)
{
	size_t x1 = all_text.find(search_simbol);
	string b1 = all_text.substr(x1 + 3);
	size_t end2 = b1.find(' ');
	string endb2 = all_text.substr(x1 + 3, end2);
	return endb2;
}

bool isParam(string line)
{
	char* p;
	strtol(line.c_str(), &p, 10);
	return *p == 0;
}

int main()
{
	double a;
	double b;
	double summa;
	char o;
	string s1;
	cout << ">";
	getline(cin, s1);
	string s2 = slovo(s1, "-a");
	string s3 = slovo(s1, "-b");
	string s4 = s1.substr(s1.find("-o") + 3, 1);
	string s5 = s1.substr(0, 6);
	a = Convert(s2);
	b = Convert(s3);

	stringstream ss4(s4);
	ss4 >> o;


	if (s5 == "--help")
	{
		cout << "\tHelp" << endl;
		cout << " -a - 1 Number;\n -b - 2 Number;\n -o - act(*|/|+|-);" << endl;
		cout << "Example: calc -a 4 -b 5 -o +" << endl;
	}

	else if (s5 == "calc -" && (a >= 0 || a <= 0) && (b >= 0 || b <= 0) && (s4 == "*" || s4 == "/" || s4 == "-" || s4 == "+"))
	{

		/*cout << fixed;
		cout.precision(6);*/

		switch (o)
		{
		case '*': summa = a*b;
			cout << ">";
			cout << summa << endl;
			break;
		case '/':
			if (a == 0)
			{
				cout << ">";
				cout << "0 can not be divided" << endl;
			}
			else if (a > 0 || a < 0)
			{
				summa = a / b;
				cout << ">";
				cout << summa << endl;
			}
			break;
		case '+': summa = a + b;
			cout << ">";
			cout << summa << endl;
			break;
		case '-': summa = a - b;
			cout << ">";
			cout << summa << endl;
			break;

		default:
			cout << ">";
			cout << "Do you not act!!!" << endl;
			break;
		}


	}

	return 0;
}

