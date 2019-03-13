#include "Monom.h"
int main()
{
	TMonom Ar(2, 4, 6, 8.3);
	TMonom Br(1, 4, 6, -9.7);
	TMonom Cr(3, 5, 11, 33);
	TMonom Dr(1, 5, 6, -0.2);
	TMonom Er(6, 5, 4, 14);
	List A;
	A.insertf(Ar);
	A.insertf(Br);
	A.insertf(Cr);
	A.show();
	A.show();
	string str1 = "12x^12+10x^9y^4-1.5x^7+2.5y^4z^3+7z^8-9z^1";
	string str2 = "-3.5x^7+2.5y^4z^3+8z^8-19z^3";
	List Ex1, Ex2;
	cout << "First Polinom:\n";
	Ex1 = *parser(str1);
	cout << "Second Polinom:\n";
	Ex2 = *parser(str2);
	cout << "Parser of 1:\n";
	Ex1.show();
	cout << "\n";
	cout << "Parser of 2:\n";
	Ex2.show();
	cout << "\n";
	List FinalValue;
	//FinalValue = Ex1 + Ex2;
	/*cout << "\nAddResult:  ";
	FinalValue.show();
	cout << "\n\nAddResult Polinom:  ";
	rep(FinalValue);*/
	//FinalValue = Ex1 - Ex2;
	/*cout << "\nSubtractResult:  ";
	FinalValue.show();
	cout << "\n\nSubtractResult Polinom:  ";
	rep(FinalValue);*/
	FinalValue = Ex1 * Ex2;
	/*cout << "\nMultiplyResult:  ";
	FinalValue.show();
	cout << "\n\nMultiplyResult Polinom:  ";
	rep(FinalValue);*/
	return 0;
}
