#pragma once
#include <iostream>
using namespace std;
#pragma once
class TMonom
{
	int Coeff; // коэффициент монома
	int Index; // индекс (свертка степеней)
public:
	TMonom(int cval = 1, int ival = 0)
	{
		if (ival > 999)
		{
			throw - 1;
		}
		Coeff = cval; Index = ival;
	};
	void SetCoeff(int cval) { Coeff = cval; }
	int GetCoeff(void) { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int GetIndex(void) { return Index; }
	TMonom & operator=(const TMonom &tm)
	{
		Coeff = tm.Coeff; Index = tm.Index;
		return *this;
	}
	int operator==(const TMonom &tm)
	{
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	int operator<(const TMonom &tm)
	{
		return Index < tm.Index;
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
	List sum(List A, List B)
	{

	}
};
class Polinom
{
public:
	Polinom & operator+(const Polinom &q);
	Polinom & operator*(const Polinom &q);
};


