
#include "Monom.h"
#include <stdio.h>
#include <string>
List* parser(string s)
{
	List* R = new List;
	cout << s << "\n" << endl;
	s += '+';
	int size = s.size();
	double coef = 0.0;
	int x = 0, y = 0, z = 0;
	int i = 0;
	int st = 0;
	string tmp = "";
	if ((s[i] == '+') || (s[i] == '-'))
	{
		tmp += s[i];
		i++;
	}
	for (; i < size; i++)
	{
		if (st == 0)
		{
			coef = atof(tmp.c_str());
		}
		if (st == 1)
		{
			x = atoi(tmp.c_str());
		}
		if (st == 2)
		{
			y = atoi(tmp.c_str());
		}
		if (st == 3)
		{
			z = atoi(tmp.c_str());
		}
		if ((s[i] == '+') || (s[i] == '-'))
		{
			//cout << "Monom:" << coef << " " << x << y << z << endl;
			TMonom Cnt(x, y, z, coef);
			(*R).insertf(Cnt);
			tmp = s[i];
			x = y = z = 0;
			coef = 0.0;
			st = 0;
		}
		else
		{
			if ((s[i] == 'x') || (s[i] == 'y') || (s[i] == 'z'))
			{
				tmp = "";
				if (s[i] == 'x')
				{
					st = 1;
				}
				if (s[i] == 'y')
				{
					st = 2;
				}
				if (s[i] == 'z')
				{
					st = 3;
				}
				i++;
			}
			else
			{
				tmp += s[i];
			}
		}
	}
	return R;
}
void rep(List A)
{
	TMonom Ml;
	int xx, yy, zz;
	double coeff;
	int help;
	int i = 0;
	while (A.IsListEmpty())   //while (A.GetSize() != 0)???
	{
		Ml = A.deletef();
		coeff = Ml.GetCoeff();
		help = Ml.GetIndex();
		zz = help % 20;
		yy = ((help - zz)/20) % 20;
		xx = (help - zz - 20 * yy) / 400;
		if ((i == 0) && (coeff > 0))
		{
			if ((xx != 0) && (yy != 0) && (zz != 0))
			{
				cout << coeff << "x^" << xx << "y^" << yy << "z^" << zz;
			}
			if ((xx == 0) && (yy != 0) && (zz != 0))
			{
				cout << coeff << "y^" << yy << "z^" << zz;
			}
			if ((xx != 0) && (yy == 0) && (zz != 0))
			{
				cout << coeff << "x^" << xx << "z^" << zz;
			}
			if ((xx != 0) && (yy != 0) && (zz == 0))
			{
				cout << coeff << "x^" << xx << "y^" << yy;
			}
			if ((xx == 0) && (yy == 0) && (zz != 0))
			{
				cout << coeff << "z^" << zz;
			}
			if ((xx == 0) && (yy != 0) && (zz == 0))
			{
				cout << coeff << "y^" << yy;
			}
			if ((xx != 0) && (yy == 0) && (zz == 0))
			{
				cout << coeff << "x^" << xx;
			}
			if ((xx == 0) && (yy == 0) && (zz == 0))
			{
				cout << coeff;
			}
		}
		if ((i != 0) && (coeff > 0))
		{
			if ((xx != 0) && (yy != 0) && (zz != 0))
			{
				cout << "+" << coeff << "x^" << xx << "y^" << yy << "z^" << zz;
			}
			if ((xx == 0) && (yy != 0) && (zz != 0))
			{
				cout << "+" << coeff << "y^" << yy << "z^" << zz;
			}
			if ((xx != 0) && (yy == 0) && (zz != 0))
			{
				cout << "+" << coeff << "x^" << xx << "z^" << zz;
			}
			if ((xx != 0) && (yy != 0) && (zz == 0))
			{
				cout << "+" << coeff << "x^" << xx << "y^" << yy;
			}
			if ((xx == 0) && (yy == 0) && (zz != 0))
			{
				cout << "+" << coeff << "z^" << zz;
			}
			if ((xx == 0) && (yy != 0) && (zz == 0))
			{
				cout << "+" << coeff << "y^" << yy;
			}
			if ((xx != 0) && (yy == 0) && (zz == 0))
			{
				cout << "+" << coeff << "x^" << xx;
			}
			if ((xx == 0) && (yy == 0) && (zz == 0))
			{
				cout << "+" << coeff;
			}
		}
		if (coeff < 0)
		{
			if ((xx != 0) && (yy != 0) && (zz != 0))
			{
				cout << coeff << "x^" << xx << "y^" << yy << "z^" << zz;
			}
			if ((xx == 0) && (yy != 0) && (zz != 0))
			{
				cout << coeff << "y^" << yy << "z^" << zz;
			}
			if ((xx != 0) && (yy == 0) && (zz != 0))
			{
				cout << coeff << "x^" << xx << "z^" << zz;
			}
			if ((xx != 0) && (yy != 0) && (zz == 0))
			{
				cout << coeff << "x^" << xx << "y^" << yy;
			}
			if ((xx == 0) && (yy == 0) && (zz != 0))
			{
				cout << coeff << "z^" << zz;
			}
			if ((xx == 0) && (yy != 0) && (zz == 0))
			{
				cout << coeff << "y^" << yy;
			}
			if ((xx != 0) && (yy == 0) && (zz == 0))
			{
				cout << coeff << "x^" << xx;
			}
			if ((xx == 0) && (yy == 0) && (zz == 0))
			{
				cout << coeff;
			}
			i++;
		}
	}
}
