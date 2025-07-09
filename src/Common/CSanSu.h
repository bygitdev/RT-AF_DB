#ifndef _CSANSU_H_
#define _CSANSU_H_

#include <windows.h>

#define _USE_MATH_DEFINES 

#define RadsToDegrees( radian ) ((radian) * (180.0f / M_PI))
#define DegreesToRads( degrees ) ((degrees) * (M_PI/ 180.0f))


namespace SANSU
{
	enum PTXYT
	{
		_X_	= 0,
		_Y_ = 1,
		_T_ = 2,
	};

	// XY 구조체..
	typedef struct _PTXY
	{
		double dX;
		double dY;

		_PTXY operator+(const _PTXY& p2)
		{
			_PTXY tmp;

			tmp.dX = this->dX + p2.dX;
			tmp.dY = this->dY + p2.dY;

			return (tmp);
		}

		_PTXY operator-(const _PTXY& p2)
		{
			_PTXY tmp;

			tmp.dX = this->dX - p2.dX;
			tmp.dY = this->dY - p2.dY;

			return (tmp);
		}
		_PTXY operator*(double dScala)
		{
			_PTXY tmp;
			tmp.dX = this->dX * dScala;
			tmp.dY = this->dY * dScala;

			return (tmp);
		}

		_PTXY operator/(double dScala)
		{
			_PTXY tmp;
			tmp.dX = this->dX / dScala;
			tmp.dY = this->dY / dScala;

			return (tmp);
		}
	}POINT2D;


	// XYT구조체..
	typedef union _XYT
	{
		POINT2D _ptXY;
		double dVal[3];
	}XYT;

	typedef struct _cntXY
	{
		int nX;
		int nY;
	}CNTXY;


	// Function declaration
	double Rad2Deg(double dRad);
	double Deg2Rad(double dDeg);
	double GetTheta(double dAdjacent, double dOppsite);
	double GetSlope(POINT2D p1, POINT2D p2);
	POINT2D   GetIntersect(POINT2D pt1, double dSlope1, POINT2D pt2, double dSlope2);
	BOOL   GetIntersect(POINT2D& ptA1, POINT2D& ptA2, POINT2D& ptB1, POINT2D& ptB2, POINT2D* pResult);
	double GetDist(POINT2D p1, POINT2D p2);
	double GetDist(double dX, double dY);
	POINT2D   GetCen(POINT2D p1, POINT2D p2);
	POINT2D   Rotate(POINT2D ptXY, double dTheta);
	POINT2D   Rotate(POINT2D xyZero, POINT2D xyObj, double dTheta);
	POINT2D   Swap(POINT2D ptXY);
	BOOL   InRect(POINT2D ptXY, POINT2D ptCen, POINT2D ptSearch);
	
	BOOL	CircumCircle(POINT2D pt1, POINT2D pt2, POINT2D pt3, POINT2D* pPtCen, double* pRadius);
	BOOL	CircleFit(POINT2D* pt, int N, POINT2D* pPtCen, double* pRadius);


	// double ceil(double x);  올림
	// double floor(double x); 내림

	BOOL Between(int nNo, int nMin, int nMax);
	BOOL AND(BOOL b1 = TRUE, BOOL b2 = TRUE, BOOL b3 = TRUE, BOOL b4 = TRUE, BOOL b5 = TRUE);
	BOOL OR(BOOL b1 = FALSE, BOOL b2 = FALSE, BOOL b3 = FALSE, BOOL b4 = FALSE, BOOL b5 = FALSE);

}

using namespace SANSU;




#endif //_CSANSU_H_

