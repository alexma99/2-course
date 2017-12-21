#include "TList.h"
#include <iostream>
#include "Figure.h"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream &out, const TList<Figure> &obj);

template<class T>
TList<T>::TList() :head(nullptr), size(0) {
}

template<class T>
void TList<T>::Insert(std::shared_ptr<T> &obj) {
	int n;
	std::cout << "Введите индекс: ";
	std::cin >> n;
	if (n < 0 || n > this->GetSize()) {
		std::cout << "Такого индекса нет.\n";
		return;
	}
	if (n == 0) {
		this->PushFirst(obj);
	}
	else if (n == this->GetSize() - 1) {
		this->PushLast(obj);
	}
	else {
		this->PushAtIndex(obj, n);
	}
	++size;
}

template<class T>
void TList<T>::PushAtIndex(std::shared_ptr<T> &obj, int n) {
	std::shared_ptr<TListItem<T>> p = std::make_shared<TListItem<T>>(obj);
	std::shared_ptr<TListItem<T>> tmp = this->head;
	for (int i = 1;i < n;i++) {
		tmp = tmp->GetNext();
	}
	p->SetNext(tmp->GetNext());
	p->SetPrev(tmp);
	tmp->SetNext(p);
	tmp->GetNext()->SetPrev(p);
}

template<class T>
void TList<T>::PushLast(std::shared_ptr<T> &obj)
{
	std::shared_ptr<TListItem<T>> newItem = std::make_shared<TListItem<T>>(obj);
	std::shared_ptr<TListItem<T>> tmp = this->head;

	while (tmp->GetNext() != nullptr) {
		tmp = tmp->GetNext();
	}
	tmp->SetNext(newItem);
	newItem->SetPrev(tmp);
	newItem->SetNext(nullptr);
}

template<class T>
void TList<T>::PushFirst(std::shared_ptr<T> &obj)
{
	std::shared_ptr<TListItem<T>> newItem = std::make_shared<TListItem<T>>(obj);
	std::shared_ptr<TListItem<T>> oldHead = this->head;
	this->head = newItem;
	if (oldHead != nullptr) {
		newItem->SetNext(oldHead);
		oldHead->SetPrev(newItem);
	}
}

template<class T>
int TList<T>::GetSize()
{
	return this->size;
}

template<class T>
bool TList<T>::IsEmpty() const
{
	return head == nullptr;
}

template<class T>
std::shared_ptr<T> TList<T>::Delete()
{
	int n = 0;
	std::shared_ptr<T> f;
	std::cout << "Введите индекс: ";
	std::cin >> n;
	if (n > this->GetSize() - 1 || n < 0 || this->IsEmpty()) {
		std::cout << "Неверный ввод.\n";
		return f;
	}
	if (n == 0) {
		f = this->PopFirst();
	}
	else if (n == this->GetSize() - 1) {
		f = this->PopLast();
	}
	else {
		f = this->PopAtIndex(n);
	}
	--size;
	return f;
}

template<class T>
std::shared_ptr<T> TList<T>::PopAtIndex(int n)
{
	std::shared_ptr<TListItem<T>> tmp = this->head;
	for (int i = 0; i < n - 1; ++i) {
		tmp = tmp->GetNext();
	}
	std::shared_ptr<TListItem<T>> rem = tmp->GetNext();
	std::shared_ptr<T> res = rem->GetFigure();
	std::shared_ptr<TListItem<T>> nextItem = rem->GetNext();
	tmp->SetNext(nextItem);
	nextItem->SetPrev(tmp);
	return res;
}

template<class T>
std::shared_ptr<T> TList<T>::PopFirst()
{
	if (this->GetSize() == 1) {
		std::shared_ptr<T> res = this->head->GetFigure();
		this->head = nullptr;
		return res;
	}
	std::shared_ptr<TListItem<T>> tmp = this->head;
	std::shared_ptr<T> res = tmp->GetFigure();
	this->head = this->head->GetNext();
	this->head->SetPrev(nullptr);
	return res;
}

template<class T>
std::shared_ptr<T> TList<T>::PopLast()
{
	if (this->GetSize() == 1) {
		std::shared_ptr<T> res = this->head->GetFigure();
		this->head = nullptr;
		return res;
	}
	std::shared_ptr<TListItem<T>> tmp = this->head;
	while (tmp->GetNext()->GetNext()) {
		tmp = tmp->GetNext();
	}
	std::shared_ptr<TListItem<T>> rem = tmp->GetNext();
	std::shared_ptr<T> res = rem->GetFigure();
	tmp->SetNext(rem->GetNext());
	return res;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TList<T> &list) {
	if (list.IsEmpty())
	{
		os << "Список пуст." << std::endl;
		return os;
	}
	std::shared_ptr<TListItem<T>> item = list.head;
	for (int i = 0;item;++i) {
		item->GetFigure()->Print();
		os << std::endl;
		item = item->GetNext();
	}
	return os;
}


template<class T>
TList<T>::~TList()
{
	while (!this->IsEmpty()) {
		this->PopFirst();
		--size;
	}
}

template <class T>
TIterator<TListItem<T>, T> TList<T>::begin()
{
	return TIterator<TListItem<T>, T>(head);
}

template <class T>
TIterator<TListItem<T>, T> TList<T>::end()
{
	return TIterator<TListItem<T>, T>(nullptr);
}

