#include "Menu.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "KeyManager.h"

void Menu::Initialize()
{
	arrow.x = 20;
	arrow.y = 20;
	arrow.shpae = "¢º";
	arrow.color = ¹àÀº³ë¶õ»ö;


	menu[0].x = 22;
	menu[0].y = 20;
	menu[0].shpae = "START";
	menu[0].color = ¹àÀº³ë¶õ»ö;

	menu[1].x = 22;
	menu[1].y = 21;
	menu[1].shpae = "OPTION";
	menu[1].color = Èò»ö;

	menu[2].x = 22;
	menu[2].y = 22;
	menu[2].shpae = "EXIT";
	menu[2].color = Èò»ö;

	id = START;
	index = 0;
}

void Menu::Progress()
{
	DWORD dwKey = KeyManager::GetInst()->GetKey();

	if (dwKey & KEY_DOWN)
	{
		if (index < 2)
		{
			arrow.y++;
			menu[index].color = Èò»ö;
			index++;
			menu[index].color = ¹àÀº³ë¶õ»ö;
		}
	}

	if (dwKey & KEY_UP)
	{
		if (index > 0)
		{
			arrow.y--;
			menu[index].color = Èò»ö;
			index--;
			menu[index].color = ¹àÀº³ë¶õ»ö;
		}
	}

	if (dwKey & KEY_RETURN)
	{
		id = (MENU_ID)index;

		switch (id)
		{
		case START:
			SceneManager::GetInst()->SetScene(STAGE);
			break;
		case OPTION:
			break;
		case EXIT:
			break;
		default:
			break;
		}
	}
}

void Menu::Render()
{
	DoubleBuffer::GetInst()->WriteBuffer(arrow.x, arrow.y, arrow.shpae, arrow.color);
	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::GetInst()->WriteBuffer(menu[i].x, menu[i].y, menu[i].shpae, menu[i].color);
	}
}

void Menu::Release()
{
}
