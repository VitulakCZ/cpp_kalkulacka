#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

string zaokrouhlit_cislo(float cislo) {
	return roundf(cislo) == cislo ? to_string((int)cislo) : to_string(cislo);
}

string scitani(int cislo1, int cislo2, float& cislo) {
	cislo = cislo1 + cislo2;
	string cislo_str = zaokrouhlit_cislo(cislo);
	return "Výsledek je: " + cislo_str;
}

string odcitani(int cislo1, int cislo2, float& cislo) {
	cislo = cislo1 - cislo2;
	string cislo_str = zaokrouhlit_cislo(cislo);
	return "Výsledek je: " + cislo_str;
}

string nasobeni(int cislo1, int cislo2, float& cislo) {
	cislo = cislo1 * cislo2;
	string cislo_str = zaokrouhlit_cislo(cislo);
	return "Výsledek je: " + cislo_str;
}

string deleni(float cislo1, float cislo2, float& cislo) {
	if (cislo2 == 0)
		return "ERROR: Nelze dělit nulou!";
  
	cislo = cislo1 / cislo2;
	string cislo_str = zaokrouhlit_cislo(cislo);
	return "Výsledek je: " + cislo_str;
}

struct historie
{
	vector<string> historie_vector;
};


int main() {
	historie historie1;

	for (; true; ) {
		string input;
		int input_int;
		const int vyber = 6;
		cout << "1 pro sčítání, 2 pro odčítání, 3 pro násobení, 4 pro dělení, 5 pro historii, 6 pro ukončení: ";
		cin >> input;

		if (!is_number(input))
		{
			cout << "ERROR: Nesprávné zadání!" << endl;
			continue;
		}

		input_int = stoi(input);

		if (input_int < 1 || input_int > vyber)
		{
			cout << "ERROR: Nesprávné zadání!" << endl;
			continue;
		}

		switch (input_int)
		{
		case 5:
			for (auto i = historie1.historie_vector.begin(); i != historie1.historie_vector.end(); ++i)
			cout << *i << endl;
			continue;

		case 6:
			goto nashledanou;
		}

		string cislo1;
		string cislo2;
		bool cislo1_zaporne = false;
		bool cislo2_zaporne = false;
		cout << "cislo1: ";
		cin >> cislo1;
		cout << "cislo2: ";
		cin >> cislo2;

		if (!is_number(cislo1) || !is_number(cislo2))
		{
			if (cislo1[0] == '-' && is_number(cislo1.erase(0, 1)))
			{
				cislo1_zaporne = true;
				goto test;
			}

			if (cislo2[0] == '-' && is_number(cislo2.erase(0, 1)))
			{
				cislo2_zaporne = true;
				goto test;
			}
			cout << "ERROR: Nesprávné zadání!" << endl;
			continue;
		}

		test:
		int cislo1_int = cislo1_zaporne ? -stoi(cislo1) : stoi(cislo1);
		int cislo2_int = cislo2_zaporne ? -stoi(cislo2) : stoi(cislo2);
		float cislo;
		char output_char;

		switch (input_int)
		{
			case 1:
				cout << scitani(cislo1_int, cislo2_int, cislo) << endl;
				output_char = '+';
				break;
			case 2:
				cout << odcitani(cislo1_int, cislo2_int, cislo) << endl;
				output_char = '-';
				break;
			case 3:
				cout << nasobeni(cislo1_int, cislo2_int, cislo) << endl;
				output_char = '*';
				break;
			case 4:
				string div = deleni(cislo1_int, cislo2_int, cislo);
				cout << div << endl;
				if (div[0] == 'E')
					continue;
			output_char = '/';
			break;
		}
		string cislo_str = zaokrouhlit_cislo(cislo);
		historie1.historie_vector.push_back(to_string(cislo1_int) + " " + output_char + " " + to_string(cislo2_int) + " = " + cislo_str);
	}
	nashledanou:
	return 0;
}
