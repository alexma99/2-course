#ifndef TLISTITEM_H
#define TLISTITEM_H

#include <memory>
#include "FSquare.h"
#include "Triangle.h" 
#include "Rectangle.h" 


class TListItem {
public:
	TListItem(const std::shared_ptr<Figure> &obj);
	std::shared_ptr<TListItem> GetNext();
	std::shared_ptr<TListItem> GetPrev();
	void SetNext(std::shared_ptr<TListItem> item);
	void SetPrev(std::shared_ptr<TListItem> prev);
	//friend std::ostream& operator<<(std::ostream &os, const TListItem &obj);
	std::shared_ptr<Figure> GetFigure() const;
	virtual ~TListItem(){};
private:
	std::shared_ptr<Figure> item;
	std::shared_ptr<TListItem> next;
	std::shared_ptr<TListItem> prev;
};

#endif

