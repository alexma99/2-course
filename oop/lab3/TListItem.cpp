#include <iostream>
#include "TListItem.h"

TListItem::TListItem(const std::shared_ptr<Figure> &obj) {
	this->item = obj;
	this->next = nullptr;
	this->prev = nullptr;
	std::cout << "Список создан" << std::endl;
}

std::shared_ptr<TListItem> TListItem::GetNext() {
	return this->next;
}

std::shared_ptr<TListItem> TListItem::GetPrev()
{
	return this->prev;
}

void TListItem::SetNext(std::shared_ptr<TListItem> item) {
	this->next = item;
}

void TListItem::SetPrev(std::shared_ptr<TListItem> prev)
{
	this->prev = prev;
}

std::shared_ptr<Figure> TListItem::GetFigure() const {
	return this->item;
}

//std::ostream& operator<<(std::ostream &os, const TListItem &obj)
//{
//	os << obj.item << std::endl;
//	return os;
//}



