#include "Gameover.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "KeyManager.h"

void Gameover::Initialize()
{
	gameover[0] = " .oOOOo.     Oo    Oo      oO o.OOoOoo        .oOOOo.  o      'O o.OOoOoo `OooOOo. ";
	gameover[1] = ".O     o    o  O   O O    o o  O             .O     o. O       o  O        o     `o";
	gameover[2] = "o          O    o  o  o  O  O  o             O       o o       O  o        O      O";
	gameover[3] = "O         oOooOoOo O   Oo   O  ooOO          o       O o       o  ooOO     o     .O";
	gameover[4] = "O   .oOOo o      O O        o  O             O       o O      O'  O        OOooOO' ";
	gameover[5] = "o.      O O      o o        O  o             o       O `o    o    o        o    o  ";
	gameover[6] = " O.    oO o      O o        O  O             `o     O'  `o  O     O        O     O ";
	gameover[7] = "  `OooO'  O.     O O        o ooOooOoO        `OoooO'    `o'     ooOooOoO  O      o";

}

void Gameover::Progress()
{
	DWORD dwKey = KeyManager::GetInst()->GetKey();

	if (dwKey & KEY_RETURN)
	{
		SceneManager::GetInst()->SetScene(LOGO);
	}
}

void Gameover::Render()
{
	for (int i = 0; i < 8; i++)
	{
		DoubleBuffer::GetInst()->WriteBuffer(3, 10 + i, gameover[i], Èò»ö);
	}
}

void Gameover::Release()
{
}
