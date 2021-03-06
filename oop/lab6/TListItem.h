#ifndef TLISTITEM_H
#define TLISTITEM_H

#include <memory>
#include "FSquare.h"
#include "Triangle.h" 
#include "Rectangle.h" 
#include "TAllocationBlock.h"

template <class T>
class TListItem {
public:
	TListItem(const std::shared_ptr<T> &obj);
	std::shared_ptr<TListItem<T>> GetNext();
	std::shared_ptr<TListItem<T>> GetPrev();
	void SetNext(std::shared_ptr<TListItem<T>> item);
	void SetPrev(std::shared_ptr<TListItem<T>> prev);
	template <class A> friend std::ostream& operator<<(std::ostream &os, const TListItem<A> &obj);
	std::shared_ptr<T> GetFigure() const;

	void *operator new(size_t size);
	void operator delete(void *ptr);

	virtual ~TListItem() {};
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TListItem<T>> next;
	std::shared_ptr<TListItem<T>> prev;

	static AllocationBlock allocator;
};

#endif

