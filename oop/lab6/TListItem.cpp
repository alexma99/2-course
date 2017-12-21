#include <iostream>
#include "TListItem.h"

template <class T>
TListItem<T>::TListItem(const std::shared_ptr<T> &obj) {
	this->item = obj;
	this->next = nullptr;
	this->prev = nullptr;
	std::cout << "Список создан" << std::endl;
}

template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() {
	return this->next;
}

template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetPrev()
{
	return this->prev;
}

template <class T>
void TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> item) {
	this->next = item;
}

template <class T>
void TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> prev)
{
	this->prev = prev;
}

template <class T>
std::shared_ptr<T> TListItem<T>::GetFigure() const {
	return this->item;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TListItem<T> &obj)
{
	os << obj.item << std::endl;
	return os;
}


template <class T> AllocationBlock TListItem<T>::allocator(sizeof(TListItem<T>), 100);

template <class T>
void *TListItem<T>::operator new (size_t size)
{
	return allocator.allocate();
}

template <class T>
void TListItem<T>::operator delete (void* p)
{
	allocator.deallocate(p);
}

#include "Figure.h"
template class TListItem <Figure>;
template std::ostream& operator<<(std::ostream &out, const TListItem<Figure> &obj);


