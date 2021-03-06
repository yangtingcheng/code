#pragma once

template<typename T>
class ListItem
{
public:
	T value() const {return _value;}
	ListItem* next() const {return _next;}
private:
	T _value;
	ListItem* _next;
};

template<typename T>
class List
{
public:
	void insert_front(T value);
	void insert_end(T value);
	void display() const;
private:
	ListItem<T>* _end;
	ListItem<T>* _front;
	long _size;
};

template<typename T>
void List<T>::insert_front(T value)
{
	
}

template<typename T>
void List<T>::insert_end(T value)
{

}


template<typename T>
void List<T>::display()const
{
	
}
