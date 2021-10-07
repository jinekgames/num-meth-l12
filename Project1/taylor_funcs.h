//
// taylor_funcs.h
//
// math funtions' INTerpritation using Taylor



#include "windows.h"



// default calculation accuracy
#define EPS 0.0001

namespace extFuncs {

	INT factorial(INT arguement);
	DOUBLE degree(DOUBLE arguement, INT degree);
	DOUBLE degree(INT arguement, INT degree);
	SHORT negOneDeg(INT degree);
	USHORT DigitAfterPoINT(DOUBLE number);
	DOUBLE Grad2Rad(DOUBLE phi);

}

struct Accuracy {
	DOUBLE Eps;
	USHORT DigitCount;
};

typedef class tagTaylor {

private:

	DOUBLE Eps;
	USHORT EdigitCount;


public:

	tagTaylor(DOUBLE epsilon = EPS);
	tagTaylor(const tagTaylor&) = delete;
	~tagTaylor() = default;


	void setAccuracy(DOUBLE epsilon);
	Accuracy getAccuracy();

	DOUBLE sin(DOUBLE arguement);
	DOUBLE cos(DOUBLE arguement);
	DOUBLE ln(DOUBLE arguement);
	DOUBLE sh(DOUBLE arguement);


private:

	DOUBLE round(DOUBLE arguement);

} Taylor, * lpTaylor;
