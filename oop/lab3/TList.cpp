#include "TList.h"
#include <iostream>

TList::TList() :head(nullptr), size(0) {
}

void TList::Insert(std::shared_ptr<Figure> &obj) {
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

void TList::PushAtIndex(std::shared_ptr<Figure> &obj, int n) {
	std::shared_ptr<TListItem> p = std::make_shared<TListItem>(obj);
	std::shared_ptr<TListItem> tmp = this->head;
	for (int i = 1;i < n;i++) {
		tmp = tmp->GetNext();
	}
	p->SetNext(tmp->GetNext());
	p->SetPrev(tmp);
	tmp->SetNext(p);
	tmp->GetNext()->SetPrev(p);
}

void TList::PushLast(std::shared_ptr<Figure> &obj)
{
	std::shared_ptr<TListItem> newItem = std::make_shared<TListItem>(obj);
	std::shared_ptr<TListItem> tmp = this->head;

	while (tmp->GetNext() != nullptr) {
		tmp = tmp->GetNext();
	}
	tmp->SetNext(newItem);
	newItem->SetPrev(tmp);
	newItem->SetNext(nullptr);
}

void TList::PushFirst(std::shared_ptr<Figure> &obj)
{
	std::shared_ptr<TListItem> newItem = std::make_shared<TListItem>(obj);
	std::shared_ptr<TListItem> oldHead = this->head;
	this->head = newItem;
	if (oldHead != nullptr) {
		newItem->SetNext(oldHead);
		oldHead->SetPrev(newItem);
	}
}

int TList::GetSize()
{
	return this->size;
}

bool TList::IsEmpty() const
{
	return head == nullptr;
}

std::shared_ptr<Figure> TList::Delete()
{
	int n = 0;
	std::shared_ptr<Figure> f;
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

std::shared_ptr<Figure> TList::PopAtIndex(int n)
{
	std::shared_ptr<TListItem> tmp = this->head;
	for (int i = 0; i < n - 1; ++i) {
		tmp = tmp->GetNext();
	}
	std::shared_ptr<TListItem> rem = tmp->GetNext();
	std::shared_ptr<Figure> res = rem->GetFigure();
	std::shared_ptr<TListItem> nextItem = rem->GetNext();
	tmp->SetNext(nextItem);
	nextItem->SetPrev(tmp);
	return res;
}

std::shared_ptr<Figure> TList::PopFirst()
{
	if (this->GetSize() == 1) {
		std::shared_ptr<Figure> res = this->head->GetFigure();
		this->head = nullptr;
		return res;
	}
	std::shared_ptr<TListItem> tmp = this->head;
	std::shared_ptr<Figure> res = tmp->GetFigure();
	this->head = this->head->GetNext();
	this->head->SetPrev(nullptr);
	return res;
}

std::shared_ptr<Figure> TList::PopLast()
{
	if (this->GetSize() == 1) {
		std::shared_ptr<Figure> res = this->head->GetFigure();
		this->head = nullptr;
		return res;
	}
	std::shared_ptr<TListItem> tmp = this->head;
	while (tmp->GetNext()->GetNext()) {
		tmp = tmp->GetNext();
	}
	std::shared_ptr<TListItem> rem = tmp->GetNext();
	std::shared_ptr<Figure> res = rem->GetFigure();
	tmp->SetNext(rem->GetNext());
	return res;
}

std::ostream& operator<<(std::ostream& os, const TList& list) {
	if (list.IsEmpty())
	{
		os << "Список пуст." << std::endl;
		return os;
	}
	std::shared_ptr<TListItem> item = list.head;
	for (int i = 0;item;++i) {
		item->GetFigure()->Print();
		os << std::endl;
		item = item->GetNext();
	}
	/*while (item != nullptr) {
		os << item->GetFigure();
		item = item->GetNext();
	}*/
	return os;
}

TList::~TList() 
	{
		while (!this->IsEmpty()) {
			this->PopFirst();
			--size;
		}
	}
