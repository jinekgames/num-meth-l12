// main.cpp
//
// Numerical methods
// lab 1 (Kalinin, Pimenova, Smirnova)
// math funcs' calculation using Taylor series



#include <windows.h>
#include <iostream>
#include "conio.h"
#include "consts.h"
#include "taylor_funcs.h"

using namespace std;



int main() {

	//lpTaylor Tlr = new Taylor;
	//Tlr->setAccuracy(0.001);
	//cout << Tlr->sin(1.57);


	//_getch();



	// command (which function to calculate)
	WORD cmd;
	// x variable
	DOUBLE x;
	// function result
	DOUBLE y;

	// functions class member
	lpTaylor Tlr = new Taylor;
	Tlr->setAccuracy(0.0001);
	

	// main actions
	do {

		system("cls");

		cout << CHOOSE_FUNC_MSG;
		cin >> cmd;
		cout << "\n" << INPUT_X_MSG;
		cin >> x;

		try {
			switch (cmd) {

			// sin
			case 1: {
				y = Tlr->sin(x);
			} break;

			// cos
			case 2: {
				y = Tlr->cos(x);
			} break;

			// ln
			case 3: {
				y = Tlr->ln(x);
			} break;

			// sh
			case 4: {
				y = Tlr->sh(x);
			} break;

			default: {
				throw "\n!! unexpexted function";
			} break;

			}

			cout << endl << "y(x) = " << y;

		} catch (const char* e) {
			cout << "!! " << e;
		}

		cout << EXIT_MSG;
		cmd = _getch();

	} while (cmd != ESCAPE_BUT_CODE);


	// bye
	system("cls");
	cout << BYE_MSG;
	Sleep(1000);


	delete Tlr;

	return 0;

}