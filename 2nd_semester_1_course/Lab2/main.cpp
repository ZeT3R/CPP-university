#include <iostream>
#include <conio.h>
#include "func.h"

using namespace std;


int main(){
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите первую дробь: ";
	int chisl1, znamen1;
	cin >> chisl1 >> znamen1;
	cout << "¬ведите вторую дробь: ";
	int chisl2, znamen2;
	cin >> chisl2 >> znamen2;
	output_tabl();
	bool over;
	while(!over)
	if (_kbhit()){
		switch (_getch()){
			case '1':
				cout << (Fraction(chisl1, znamen1) + Fraction(chisl2, znamen2)) << endl;	
				break;
											
			case '2':
				cout << (Fraction(chisl1, znamen1) - Fraction(chisl2, znamen2)) << endl;
				break;
												
			case '3':
				cout << (Fraction(chisl1, znamen1) * Fraction(chisl2, znamen2)) << endl;
				break;
															
			case '4':
				cout << (Fraction(chisl1, znamen1) / Fraction(chisl2, znamen2)) << endl;
				break;
				
			case '5':
				cout << (Fraction(chisl1, znamen1) > Fraction(chisl2, znamen2)) << endl;
				break;
			case '6':
				cout << (Fraction(chisl1, znamen1) < Fraction(chisl2, znamen2)) << endl;
				break;
			case '7':
				cout << (Fraction(chisl1, znamen1) == Fraction(chisl2, znamen2)) << endl;
				break;
			case '8':
				cout << "¬ведите числитель и знаменатель первой дроби: ";
				cin >> chisl1 >> znamen1;
				break;
			case '9':
				cout << "¬ведите числитель и знаменатель второй дроби: ";
				cin >> chisl2 >> znamen2;
				break;
			case '0':
			over = true;
			break;								
		}
	}
	cout << (Fraction(chisl1, znamen1) != (Fraction(chisl2, znamen2)));
	float chisl;
	double znamen;
	cout << "¬ведите числитель и знаменатель дл€ первой дроби: ";
	cin >> chisl >> znamen;
	float chisltest;
	double znamentest;
	cout << "¬ведите числитель и знаменатель дл€ второй дроби: ";
	cin >> chisltest >> znamentest;
	cout << (-Fraction(chisl, znamen) + Fraction(chisltest, znamentest)) << endl;
	cout << (Fraction(chisl, znamen) - Fraction(chisltest, znamentest)) << endl;
	cout << (-Fraction(chisl, znamen) * Fraction(chisltest, znamentest)) << endl;
	cout << (Fraction(chisl, znamen) / Fraction(chisltest, znamentest)) << endl;
	cout << "\n\n\n";
	
	cout << Fraction(chisl, znamen) << endl;
	cout << "\n\n\n";
	
	cout << Fraction(chisltest, znamentest) << endl;
	cout << Fraction(chisltest, znamentest) + Fraction(1) << endl;
	cout << Fraction(chisltest, znamentest) + Fraction(9) << endl;
	cout << Fraction(chisltest, znamentest) - Fraction(9) << endl;
	cout << "\n\n\n";
	
	// chisltest = 2, znamentest = 3;
	chisltest += 5; // chisltest = 7;
	znamentest *= 7; // znamentest = 21
	cout << Fraction(chisltest, znamentest); // 7/21 => 1/3
	cout << "\n\n\n";
	Fraction(chisltest, znamentest) += 3;
	cout << Fraction(chisltest, znamentest);
	Fraction a = Fraction(chisltest, znamentest);
	cout << a << endl;
	cout << a + 1 << endl;
	cout << 5 + a << endl;
	cout << "\n\n\n";
	
	cout << a << endl;
	cout << a - 5 << endl;
	cout << 3 - a << endl;
	
	
    return 0;
}
