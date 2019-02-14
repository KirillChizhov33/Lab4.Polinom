
#include "Header.h"
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
		cout << p->value.GetCoeff() << "  ";
		cout << p->value.GetIndex() << endl;
		p = p->n;
	}
}
void List::deletef()
{
	if (h == nullptr)
	{
		return;
	}
	Link * p;
	p = h;
	h = h->n;
	delete p;
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
void List::deletel()
{
	if (h == nullptr)
	{
		return;
	}
	if (h->n == nullptr)
	{
		delete h;
		return;
	}
	Link * p;
	p = h;
	while (p->n->n != nullptr)
	{
		p = p->n;
	}
	delete p->n;
	p->n = nullptr;
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
int List::GetSize(void)
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
