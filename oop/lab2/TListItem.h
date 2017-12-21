#ifndef TLISTITEM_H
#define TLISTITEM_H

#include "Triangle.h"

class TListItem {
public:
	TListItem(const Triangle& triangle);
	TListItem* GetNext();
	TListItem* GetPrev();
	void SetNext(TListItem* item);
	void SetPrev(TListItem* prev);
	Triangle GetTriangle() const;
	virtual ~TListItem();
private:
	Triangle triangle;
	TListItem *next;
	TListItem *prev;
};

#endif
