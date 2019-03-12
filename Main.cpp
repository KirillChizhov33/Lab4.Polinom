#include "Monom.h"

int main()
{
	TMonom Ar(2, 4, 6, 8);
	TMonom Br(1, 4, 6, 9);
	TMonom Cr(3, 5, 11, 8);
	TMonom Dr(1, 5, 6, 2);
	TMonom Er(6, 5, 4, 14);
	List A, B; //B(A);
	int k;
	cout << "Original list:\n";
	A.insertf(Ar);
	A.insertf(Br);
	A.insertf(Cr);
	A.insertf(Dr);
	A.show();
	int s = A.GetSize();
	cout << s;
	//B = A;
	cout << "\n\n";
	cout << "Can assign B = A:\n";
	B.show();
	cout << "\n";
	cout << "\n\n";
	cout << "Can insert last element: \n";
	A.insertl(Er);
	A.show();
	cout << "\n\n";
	cout << "Can delete first element: \n";
	A.deletef();
	A.deletef();
	A.deletef();
	A.show();
	cout << "\n\n";
	cout << "Can delete last element: \n";
	A.deletel();
	A.show();
	cout << "\n";
	cout << "Can delete all elements\n";
	A.~List();
	A.show();
	List Ex;
	Ex = *parser();
	cout << "Parser:\n";
	Ex.show();
	return 0;
}
