#pragma once
#include "Obj.h"
class Player : public Obj
{
public :
	int itemcount;   //�������� ���ӽð�
	int heartcount;  //��Ʈ������ ��
	bool enemy_collision;   //������ �浹
	bool heart_collision;    //��Ʈ�����۰��� �浹
	
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

