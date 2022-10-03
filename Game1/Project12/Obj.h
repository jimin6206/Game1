#pragma once
#include "Include.h"
class Obj
{
public:
	BulletType bulletType;
protected:
	Info info;
public:
	int x_size;
	int y_size;
	bool player_item;    //player가 별 아이템 먹으면 true
	Info GetInfo() { return info; }
	void SetInfo(bool _act) { info.act = _act; }
	void SetInfo(int _x, int _y)
	{
		info.x = _x; info.y = _y;

		info.rect.Left = info.x;
		info.rect.Top = info.y;
		info.rect.Right = info.x + x_size;
		info.rect.Bottom = info.y + y_size;
	}
	void SetInfo(const char* shape0, const char* shape1, const char* shape2)
	{
		info.shape[0] = shape0;
		info.shape[1] = shape1;
		info.shape[2] = shape2;
	}

	void SetInfo(const char** _shape)
	{
		info.shape[0] = _shape[0];
		info.shape[1] = _shape[1];
		info.shape[2] = _shape[2];
	}
	void SetInfo(Color _color) { info.color = _color; }
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

};

