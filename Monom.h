#pragma once
#include <iostream>
using namespace std;
class TMonom
{
	double Coeff; // коэффициент монома
	int Index; // индекс (свертка степеней)
public:
	/*TMonom(int cval = 1, int ival = 0)
	{
		if (ival > 999)
		{
			throw - 1;
		}
		Coeff = cval; Index = ival;
	};*/

	TMonom(int dx = 1, int dy = 0, int dz = 2, double _coeff = 3)
	{
		if ((dx > 19) || (dx < 0) || (dy > 19) || (dy < 0) || (dz > 19) || (dz < 0))
		{
			throw - 1;
		}
		Index = dx * 400 + dy * 20 + dz;
		Coeff = _coeff;
	}
	void SetCoeff(double cval) { Coeff = cval; }
	double GetCoeff(void) { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int GetIndex(void) { return Index; }
	TMonom & operator=(const TMonom &tm)
	{
		Coeff = tm.Coeff; Index = tm.Index;
		return *this;
	}
	bool operator==(const TMonom &tm)
	{
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	bool operator<(const TMonom &tm)
	{
		return Index < tm.Index;
	}
	bool operator>(const TMonom &tm)
	{
		return Index > tm.Index;
	}
};

struct Link
{
	TMonom value;
	Link * n;
};
class List
{
	Link * h; // Указатель на голову
public:
	List();
	List(const List &b);
	~List();
	void insertf(TMonom value);
	void show();
	void deletef();
	void insertl(TMonom value);
	void deletel();
	TMonom & operator [](int index);
	int GetSize(void);
	List& operator+(const List &b);
	List& operator-(const List &b);
	List& operator*(const List &b);
};
List *parser();
