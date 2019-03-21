
#include "Monom.h"
List::List()
{
	h = nullptr;
}
List::List(const List &b)
{
	if (b.h == nullptr)
	{
		throw - 1;
	}
	Link * k;
	k = b.h;
	while (k != nullptr)
	{
		this->insertf(k->value);
		k = k->n;
	}
}
List::~List()
{
	while (h != nullptr)
	{
		deletef();
	}
}
void List::insertf(TMonom value)
{
	Link * k;
	k = new Link;
	k->value = value;
	k->n = h;
	h = k;
}
void List::show()
{
	Link * p;
	p = h;
	while (p != nullptr)
	{
		cout << "Coeff: " << p->value.GetCoeff() << "  ";
		cout << "Index: " << p->value.GetIndex() << endl;
		p = p->n;
	}
}
TMonom List::deletef()
{
	if (h == nullptr)
	{
		return NULL;
	}
	TMonom K;
	Link * p;
	p = h;
	K = p->value;
	h = h->n;
	delete p;
	return K;
}
void List::insertl(TMonom value)
{
	Link * p;
	p = new Link;
	p->value = value;
	p->n = nullptr;
	Link * t;
	if (h == nullptr)
	{
		h = p;
		return;
	}
	t = h;
	while (t->n != nullptr)
	{
		t = t->n;
	}
	t->n = p;
}
TMonom List::deletel()
{
	if (h == nullptr)
	{
		return NULL;
	}
	if (h->n == nullptr)
	{
		delete h;
		return NULL;
	}
	TMonom K;
	Link * p;
	p = h;
	while (p->n->n != nullptr)
	{
		p = p->n;
	}
	K = p->value;
	delete p->n;
	p->n = nullptr;
	return K;
}
TMonom & List:: operator [](int index)
{
	if (index < 0)
	{
		throw - 1;
	}
	Link * t = h;
	int i = 0;
	while ((t != nullptr) && (i < index))
	{
		i++;
		t = t->n;
	}
	if (t == nullptr)
	{
		throw - 1;
	}
	else
		return t->value;
}
int List::GetSize()
{
	Link * t = h;
	int size = 0;
	while (t != NULL)
	{
		size++;
		t = t->n;
	}
	return size;
}
bool List::IsListEmpty()
{
	if (h == NULL)
	{
		return false;
	}
	return true;
}
