#include <iostream>
using namespace std;

bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string scitani(int cislo1, int cislo2) {
  int cislo = cislo1 + cislo2;
  string cislo_str = to_string(cislo);
  return "Výsledek je: " + cislo_str;
}

string odcitani(int cislo1, int cislo2) {
  int cislo = cislo1 - cislo2;
  string cislo_str = to_string(cislo);
  return "Výsledek je: " + cislo_str;
}

string nasobeni(int cislo1, int cislo2) {
  int cislo = cislo1 * cislo2;
  string cislo_str = to_string(cislo);
  return "Výsledek je: " + cislo_str;
}

string deleni(float cislo1, float cislo2) {
  if (cislo2 == 0)
  {
    return "ERROR: Nelze dělit nulou!";
  }
  float cislo = cislo1 / cislo2;
  string cislo_str = to_string(cislo);
  return "Výsledek je: " + cislo_str;
}

int main() {
  for (; true; ){
    string input;
    int input_int;
    const int vyber = 5;
    cout << "1 pro sčítání, 2 pro odčítání, 3 pro násobení, 4 pro dělení, 5 pro ukončení: ";
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
    
    if (input_int == 5)
      break;

    string cislo1;
    string cislo2;
    cout << "cislo1: ";
    cin >> cislo1;
    cout << "cislo2: ";
    cin >> cislo2;

    if (!is_number(cislo1) || !is_number(cislo2))
    {
      cout << "ERROR: Nesprávné zadání!" << endl;
      continue;
    }

    int cislo1_int = stoi(cislo1);
    int cislo2_int = stoi(cislo2);
    switch (input_int)
    {
      case 1:
        cout << scitani(cislo1_int, cislo2_int) << endl;
        break;
      case 2:
        cout << odcitani(cislo1_int, cislo2_int) << endl;
        break;
      case 3:
        cout << nasobeni(cislo1_int, cislo2_int) << endl;
        break;
      case 4:
        cout << deleni(cislo1_int, cislo2_int) << endl;
        break;
    }
  }
  return 0;
}
