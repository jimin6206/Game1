#pragma once
#include "Include.h"

class DoubleBuffer
{
private:
	static DoubleBuffer* pInst;
public:
	static DoubleBuffer* GetInst()
	{
		if (pInst == nullptr)
		{
			pInst = new DoubleBuffer;
		}

		return pInst;
	}
private:
	HANDLE hBuffer[2];
	int screenIndex;
public:

	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
	
	void DestroyBuffer();
};
