//
// taylor_funcs.h
//
// math funtions' interpritation using Taylor



#include "windows.h"



// default calculation accuracy
#define EPS 0.0001

namespace extFuncs {

	int factorial(int arguement);
	double degree(double arguement, int degree);
	double degree(int arguement, int degree);
	short int negOneDeg(int degree);

}

typedef class tagTaylor {

private:

	DOUBLE Eps;


public:

	tagTaylor(DOUBLE epsilon = EPS);
	tagTaylor(tagTaylor*) = delete;
	~tagTaylor() = default;


	void setAccuracy(DOUBLE epsilon);
	DOUBLE getAccuracy();

	double sin(DOUBLE arguement);
	double cos(DOUBLE arguement);
	double ln(DOUBLE arguement);
	double sh(DOUBLE arguement);

} Taylor, * lpTaylor;
