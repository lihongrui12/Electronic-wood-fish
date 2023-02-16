#include<stdio.h>
#include<graphics.h>


IMAGE imgMuyu[16];

int textX;
int textY;


void init()
{
	loadimage(&imgMuyu[0], "images/123.jpg");
	int w = imgMuyu[0].getwidth();
	int h = imgMuyu[0].getheight();

	
	for (int i = 1; i < 8; i++)
	{
		double k = 1 - 0.02 * i;
		
		loadimage(&imgMuyu[i], "images/123.jpg", w-i/9, h*k, true);
		
	}
	for (int i = 8; i < 16; i++)
	{
		double k = 0.86 + (i - 8) * 0.02;
		
		loadimage(&imgMuyu[i], "images/123.jpg", w+i/9, h*k, true);
	}

	initgraph(800, 600);

	LOGFONT f;
	gettextstyle(&f);//获取当前字体
	f.lfHeight = 20;
	f.lfWeight = 0;
	
	f.lfQuality = ANTIALIASED_QUALITY;
	setbkmode(TRANSPARENT);
	settextstyle(&f);//把f设置为当前字体



	
}

void updateWindow();
bool keyEvent()
{
	ExMessage msg;
	if (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN)
	{
		textX = msg.x;
		textY = msg.y;
		return true;
	}

	return false;
}
int main()
{
	init();

	int x = 800 / 2 - imgMuyu[0].getheight()/2;
	int y = 600 / 2 - imgMuyu[0].getheight()/2;
	putimage(x, y, &imgMuyu[0]);

	while (1)
	{
		if (keyEvent()){
			updateWindow();
		}
	}
	
	return 0;
}
void updateWindow()
{
	int centx = 800 / 2;
	int centy = 600 / 2;
	int tmpY = textY;

	int color = 0xFFFFFF;
	

	for (int i = 0; i < 16; i++)
	{
		BeginBatchDraw();
		setbkcolor(BLACK); 
		cleardevice();

		int x = centx - imgMuyu[i].getwidth() / 2;
		int y = centy - imgMuyu[i].getheight() / 2;
		
		putimage(x,y,&imgMuyu[i]);

		settextcolor(color);
		color -= 0x111111;
		outtextxy(textX,tmpY,"功德+1");
		tmpY -= 15;



		EndBatchDraw();





		Sleep(30);
	}
}
