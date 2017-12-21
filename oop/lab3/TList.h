#ifndef TLIST_H
#define TLIST_H 
#include "FSquare.h"
#include "TListItem.h" 
#include "Triangle.h" 
#include "Rectangle.h" 

class TList {
public:
	TList();
	void Insert(std::shared_ptr<Figure> &obj);
	bool IsEmpty() const;
	std::shared_ptr<Figure> Delete();
	friend std::ostream& operator<<(std::ostream& os, const TList& list);
	virtual ~TList();
	int GetSize();
private:
	std::shared_ptr<TListItem> head;
	int size;

	void PushFirst(std::shared_ptr<Figure> &obj);
	void PushLast(std::shared_ptr<Figure> &obj);
	void PushAtIndex(std::shared_ptr<Figure> &obj, int n);
	std::shared_ptr<Figure> PopFirst();
	std::shared_ptr<Figure> PopLast();
	std::shared_ptr<Figure> PopAtIndex(int n);
};
#endif
