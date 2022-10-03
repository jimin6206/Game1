#pragma once
#include "Obj.h"

class ObjectFactory
{
private:
	static ObjectFactory* pInst;
public:
	static ObjectFactory* GetInst()
	{
		if (pInst == nullptr)
		{
			pInst = new ObjectFactory;
		}

		return pInst;
	}
public:
	Obj* CreateObj(Object id);
};
