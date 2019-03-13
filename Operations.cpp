#include "Monom.h"
List & List:: operator+(const List &b)
{
	List Result;
	Link *temp1;
	Link *temp2;
	temp1 = h;
	temp2 = b.h;
	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->value < temp2->value)
		{
			Result.insertf(temp1->value);
			temp1 = temp1->n;
			continue;
		}
		if (temp1->value > temp2->value)
		{
			Result.insertf(temp2->value);
			temp2 = temp2->n;
			continue;
		}
		if (temp1->value == temp2->value)
		{
			double tmp;
			int kl;
			kl = temp1->value.GetIndex();
			tmp = temp1->value.GetCoeff() + temp2->value.GetCoeff();
			if (tmp == 0.0)
			{
				temp1 = temp1->n;
				temp2 = temp2->n;
				continue;
			}
			TMonom cur;
			cur.SetCoeff(tmp);
			cur.SetIndex(kl);
			Result.insertf(cur);
			temp1 = temp1->n;
			temp2 = temp2->n;
			continue;
		}
	}
	while (temp1 != NULL)
	{
		Result.insertf(temp1->value);
		temp1 = temp1->n;
		continue;
	}
	while (temp2 != NULL)
	{
		Result.insertf(temp2->value);
		temp2 = temp2->n;
		continue;
	}
	cout << "Add:\n";
	cout << "Intermediate result:\n";
	Result.show();
	cout << "\n";
	cout << "Intermediate result polinom:\n";
	rep(Result);
	cout << "\n";
	return Result;
}
List & List:: operator-(const List &b)
{
	List Result;
	Link *temp1;
	Link *temp2;
	temp1 = h;
	temp2 = b.h;
	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->value < temp2->value)
		{
			Result.insertf(temp1->value);
			temp1 = temp1->n;
			continue;
		}
		if (temp1->value > temp2->value)
		{
			Result.insertf(temp2->value);
			temp2 = temp2->n;
			continue;
		}
		if (temp1->value == temp2->value)
		{
			double tmp;
			int kl;
			kl = temp1->value.GetIndex();
			tmp = temp1->value.GetCoeff() - temp2->value.GetCoeff();
			if (tmp == 0.0)
			{
				temp1 = temp1->n;
				temp2 = temp2->n;
				continue;
			}
			TMonom cur;
			cur.SetCoeff(tmp);
			cur.SetIndex(kl);
			Result.insertf(cur);
			temp1 = temp1->n;
			temp2 = temp2->n;
			continue;
		}
	}
	while (temp1 != NULL)
	{
		Result.insertf(temp1->value);
		temp1 = temp1->n;
		continue;
	}
	while (temp2 != NULL)
	{
		Result.insertf(temp2->value);
		temp2 = temp2->n;
		continue;
	}
	cout << "Subtract:\n";
	cout << "Intermediate result:\n";
	Result.show();
	cout << "\n";
	cout << "Intermediate result polinom:\n";
	rep(Result);
	cout << "\n";
	return Result;
}
List & List:: operator*(const List &b)
{
	List Result;
	Link *temp1;
	Link *temp2;
	temp1 = h;
	temp2 = b.h;
	int i = 0;
	while ((temp1 != NULL) && (temp2 != NULL))
	{
		while (temp2 != NULL)
		{
			double tmp;
			int kl;
			kl = temp1->value.GetIndex() + temp2->value.GetIndex();
			tmp = temp1->value.GetCoeff() * temp2->value.GetCoeff();
			TMonom cur;
			cur.SetCoeff(tmp);
			cur.SetIndex(kl);
			Result.insertf(cur);
			temp2 = temp2->n;
		}
		temp1 = temp1->n;
		temp2 = b.h;
	}
	cout << "Multiply:\n";
	cout << "Intermediate result:\n";
	Result.show();
	cout << "\n";
	cout << "Intermediate result polinom:\n";
	rep(Result);
	cout << "\n";
	return Result;
}
