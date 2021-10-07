// main.cpp
//
// Numerical methods
// lab 1 (Kalinin, Pimenova, Smirnova)
// math funcs' calculation using Taylor series



#pragma warning (disable : 4996)

#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include "conio.h"
#include "consts.h"
#include "taylor_funcs.h"

using namespace std;



int main() {

	// command (which function to calculate)
	CHAR cmd;
	// x variable string
	string cmd1;
	// x variaxle true
	DOUBLE x;
	// function result
	DOUBLE y;

	// functions class member
	lpTaylor Tlr = new Taylor;
	

	// main actions
	do {

		system("cls");

		cout << CHOOSE_FUNC_MSG;
		cmd = _getch();
		cout << cmd;
		if (cmd != 'g') {
			cout << "\n" << INPUT_X_MSG;
			cin >> cmd1;

			UINT a, b;
			CHAR c[30];
			a = cmd1.find('g');
			if (a != -1) {
				// grad
				size_t l = cmd1.copy(c, a, 0);
				c[l] = '\0';
				x = atof(c);
				// min
				b = cmd1.find('m');
				if (b != -1) {
					l = cmd1.copy(c, b - a, a + 1);
					c[l] = '\0';
					x += atof(c) / 60;
					// sec
					a = cmd1.find('s');
					if (b != -1) {
						l = cmd1.copy(c, a - b, b + 1);
						c[l] = '\0';
						x += atof(c) / 3600;
					}
				}
				x = extFuncs::Grad2Rad(x);
			} else {
				x = atof(cmd1.c_str());
			}

		}

		try {
			switch (cmd) {

			// set accuracy
			case 'a': {
				Tlr->setAccuracy(x);
				throw "done";
			} break;
			// get accuracy
			case 'g': {
				Accuracy a = Tlr->getAccuracy();
				throw a.Eps;
			} break;

			// sin
			case '1': {
				y = Tlr->sin(x);
			} break;

			// cos
			case '2': {
				y = Tlr->cos(x);
			} break;

			// ln
			case '3': {
				y = Tlr->ln(x);
			} break;

			// sh
			case '4': {
				y = Tlr->sh(x);
			} break;

			default: {
				throw "\n!! unexpexted function";
			} break;

			}

			cout << endl << "y(x) = ";
			Accuracy accur = Tlr->getAccuracy();
			cout.precision(accur.DigitCount);
			cout << fixed << y << " +- " << accur.Eps;

		} catch (const char* e) {
			cout << "!! " << e;
		} catch (const char& e) {
			cout << "!! " << e;
		} catch (DOUBLE e) {
			cout << '\n' << e;
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
