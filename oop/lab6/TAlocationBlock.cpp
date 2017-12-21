#include "TAllocationBlock.h"
#include <iostream>

AllocationBlock::AllocationBlock() : size(0), count(0), used_blocks(0), free_blocks(0), free_count(0) {}

AllocationBlock::AllocationBlock(size_t s, size_t c) : size(s), count(c)
{
	used_blocks = (char*)malloc(size*count); // выделили память под указанное число блоков размера size
	free_blocks = (void**)malloc(sizeof(void*)*count); // создали указатели
	for (int i = 0; i < count; i++)
		free_blocks[i] = used_blocks + i*size; 
	free_count = count; 
	std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void *AllocationBlock::allocate()
{
	void *result = nullptr;
	if (free_count > 0)
	{
		result = free_blocks[free_count - 1];
		free_count--;
		std::cout << "AllocationBlock: Allocate " << (count - free_count) << " of " << count << std::endl;
	}
	else
	{
		std::cout << "TAllocationBlock: No memory exception :-)" << std::endl;
	}
	return result;
}

void AllocationBlock::deallocate(void *pointer)
{
	std::cout << "TAllocationBlock: Deallocate block " << std::endl;
	free_blocks[free_count] = pointer;
	free_count++;
}

bool AllocationBlock::HasFreeBlocks()
{
	return free_count>0;
}

AllocationBlock::~AllocationBlock()
{
	if (free_count<count)
		std::cout << "TAllocationBlock: Memory leak?" << std::endl;
	else
		std::cout << "TAllocationBlock: Memory freed" << std::endl;
	delete free_blocks;
	delete used_blocks;
}
