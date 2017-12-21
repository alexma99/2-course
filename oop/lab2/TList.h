#ifndef TLIST_H
#define TLIST_H 
#include "Triangle.h"
#include "TListItem.h" 
class TList { 
public:     
	TList();
	void Insert(Triangle &triangle);
	bool IsEmpty() const;
	Triangle Delete();
	friend std::ostream& operator<<(std::ostream& os, const TList& stack);
	virtual ~TList();
	int GetSize();
private:        
	TListItem *head; 
	int size;

	void PushFirst(Triangle &tr);
	void PushLast(Triangle &tr);
	void PushAtIndex(Triangle &tr, int n);
	Triangle PopFirst();
	Triangle PopLast();
	Triangle PopAtIndex(int n);
};
#endif
