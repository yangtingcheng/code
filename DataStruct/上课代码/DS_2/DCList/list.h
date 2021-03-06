#ifndef _LIST_H
#define _LIST_H

#include"../utili.h"

#define ElemType int

template<class Type>
class List;

template<class Type>
class ListNode
{
	friend class List<Type>;
public:
	ListNode():data(Type()),prev(NULL),next(NULL)
	{}
	ListNode(Type d, ListNode<Type>*p=NULL, ListNode<Type> *n=NULL)
		:data(d),prev(p),next(n)
	{}
	~ListNode()
	{}
	///////////////////////////////////////////////
	Type& GetData();
	const Type& GetData()const;
private:
	Type data;
	ListNode<Type> *prev;
	ListNode<Type> *next;
};

template<class Type>
class List
{
public:
	List()
	{
		first = last = new ListNode<Type>;
		first->prev = last;
		last->next = first;
		size = 0;
	}
public:
	void push_back(const Type &x)
	{
		ListNode<Type> *s = new ListNode<Type>(x);
		s->next = first;
		s->prev = last;
		last->next = s;
		first->prev = s;
		last = s;
		size++;
	}
	void push_front(const Type &x)
	{
		ListNode<Type> *s = new ListNode<Type>(x);
		s->next = first->next;
		s->prev = first;
		first->next->prev = s;
		first->next = s;
		if(size == 0)
			last = s;
		size++;
	}
	void show_list()const
	{
		ListNode<Type> *p = first->next;
		while(p != first)
		{
			cout<<p->data<<"-->";
			p = p->next;
		}
		cout<<"Over."<<endl;
	}
	void resver()
	{
		ListNode<Type> *p = first->next;
		ListNode<Type> *t = p->next;

		last->next = NULL;
		last = p;
		last->next = first;
		first->prev = last;

		while(t != NULL)
		{
			p = t;
			t = p->next;
			p->next = first->next;
			p->prev = first;
			first->next->prev = p;
			first->next = p;
		}
	}
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t          size;
};
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           