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

	// command (which function to calculate)
	WORD cmd;
	// x variable
	DOUBLE x;
	// function result
	DOUBLE y;

	// functions class member
	lpTaylor Tlr = new Taylor;
	

	// main actions
	do {

		system("cls");

		cout << CHOOSE_FUNC_MSG;
		cin >> cmd;
		cout << "\n" << INPUT_X_MSG;
		cin >> x;

		try {
			switch (cmd) {

			// accuracy
			case 0u: {
				Tlr->setAccuracy(x);
				throw "done";
			} break;

			// sin
			case 1u: {
				y = Tlr->sin(x);
			} break;

			// cos
			case 2u: {
				y = Tlr->cos(x);
			} break;

			// ln
			case 3u: {
				y = Tlr->ln(x);
			} break;

			// sh
			case 4u: {
				y = Tlr->sh(x);
			} break;

			default: {
				throw "\n!! unexpexted function";
			} break;

			}

			cout << endl << "y(x) = " << fixed << y;

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
