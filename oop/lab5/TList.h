#ifndef TLIST_H
#define TLIST_H 
#include "FSquare.h"
#include "TListItem.h" 
#include "Triangle.h" 
#include "Rectangle.h" 
#include "TIterator.h"

template<class T>
class TList {
public:
	TList();
	void Insert(std::shared_ptr<T> &obj);
	bool IsEmpty() const;
	std::shared_ptr<T> Delete();
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TList<A> &list);
	virtual ~TList();
	int GetSize();

	TIterator<TListItem<T>,T> begin();
	TIterator<TListItem<T>,T> end();

private:
	std::shared_ptr<TListItem<T>> head;
	int size;

	void PushFirst(std::shared_ptr<T> &obj);
	void PushLast(std::shared_ptr<T> &obj);
	void PushAtIndex(std::shared_ptr<T> &obj, int n);
	std::shared_ptr<T> PopFirst();
	std::shared_ptr<T> PopLast();
	std::shared_ptr<T> PopAtIndex(int n);
};
#endif
