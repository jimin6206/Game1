#include "Logo.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "KeyManager.h"

void Logo::Initialize()
{
	logo[0]  = "  .        .       .       .           .            .            .";
	logo[1]  = "               .              .::.           .         .";
	logo[2]  = "      .                    .:'  .:   .                           .";
	logo[3]  = "                 ,MMM8&&&.:'   .:'        .                .";
	logo[4]  = "   .            MMMMM88&&&&  .:'                    .          ";
	logo[5]  = "          .    MMMMM88&&&&&&:'	   .            .                 ";
	logo[6]  = "      .        MMMMM88&&&&&&   .                            . ";
	logo[7]  = "          .  .:MMMMM88&&&&&&	            .       .        .";
	logo[8]  = " .         .:'  MMMMM88&&&&      .";
	logo[9]  = "       . .:'   .:'MMM8&&&'		         .             .       ";
	logo[10] = "         :'  .:'          .	               .                      .";
	logo[11] = "   .     '::'                  .                            .";
	logo[12] = "        .      .				           .          .";

	start = "G A M E  S T A R T";


}

void Logo::Progress()
{
	DWORD dwKey = KeyManager::GetInst()->GetKey();

	if (dwKey & KEY_RETURN)
	{
		SceneManager::GetInst()->SetScene(MENU);
	}
}

void Logo::Render()
{
	for (int i = 0; i < 13; i++)
	{
		DoubleBuffer::GetInst()->WriteBuffer(5, 10 + i, logo[i], Èò»ö);
	}

	DoubleBuffer::GetInst()->WriteBuffer(25, 19 , start , ¹àÀº¿Á»ö);
}

void Logo::Release()
{
}
