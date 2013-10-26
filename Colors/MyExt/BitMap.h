#pragma once
#include <vector>
class BitMap{
public:
	BitMap()
	{
		maxSize =0;
	}
	unsigned int getBlockId(unsigned int index)
	{
		return index / (sizeof(unsigned int) * 8) ;
	}
	unsigned int getOffset(unsigned int index)
	{
		return index % (sizeof(unsigned int) * 8) ;
	}
	void set(unsigned int index)
	{
		int blockid = getBlockId(index);
		if (blockid >= tags.size()) tags.resize(blockid + 1);
		int offset = getOffset(index);
		tags[blockid] |= (1 << offset);
		if (index > maxSize) maxSize = index;
	}
	void set(unsigned int startindex,unsigned int size,unsigned int value)
	{
		// 一个低效的办法
		for (unsigned int index = 0 ; index < sizeof(unsigned int ) * 8 && index < size;index++)
		{
			if ((value >> index) & 1)
			{
				set(startindex + index);
			}
			else
				reset(startindex + index);
		}
	}
	unsigned get(unsigned int startindex,unsigned int size)
	{
		// 一个低效的办法
		int value = 0;
		for (unsigned int index = startindex; index < startindex + size;index++)
		{
			if (test(index))
			{
				value |= 1 << (index - startindex);
			}
		}
		return value;
	}
	void reset(unsigned int index)
	{
		int blockid = getBlockId(index);
		if (blockid >= tags.size()) tags.resize(blockid + 1);
		int offset = getOffset(index);
		tags[blockid] &= ~(1 << offset);
		if (index > maxSize) maxSize = index;
	}
	bool test(unsigned int index)
	{
		int blockid = getBlockId(index);
		if (blockid >= tags.size()) tags.resize(blockid + 1);
		int offset = getOffset(index);
		if (index > maxSize) maxSize = index;
		return (tags[blockid] & (1<<offset));
	}
	void clear()
	{
		for (int i = 0; i < tags.size();i++)
		{
			tags[i] = 0;
		}
	}
	unsigned int capacity()
	{
		return tags.size() * sizeof(unsigned int ) * 8;
	}
	unsigned int size()
	{
		return maxSize;
	}
    std::vector<unsigned int> tags;
	unsigned int maxSize;
};