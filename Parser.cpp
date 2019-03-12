#include "Monom.h"
#include <stdio.h>
#include <string>
List* parser()
{
	List* R = new List;
	string s = "-1.5x^7+2.5y^2z^3+7z^2-9";
	s += '+';
	cout << s << endl;
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
			cout << "Monom:" << coef << " " << x << y << z << endl;
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
