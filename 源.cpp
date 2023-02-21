#include<easyx.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
enum data {
	passby_num = 5,
	range_x = 20,
	range_y = 20,
};
struct window
{
	int width = 520;
	int height = 520;
}screen;
struct
{
	float x = 520;
	float y = 3344;
}point[520], border_point[1314];
const float PI = 3.14159;
int k = 60;
void drawlove()
{
	struct
	{
		int num = 0;
	}border, inside;
	for (float x = -2; x < 2; x += rand() % 600 * 0.0001)
	{
		border_point[border.num].x = x * k;
		border_point[border.num].y = -sqrt(fabs(1 - (fabs(x) - 1) * (fabs(x) - 1))) * k;
		if (border_point[border.num].x < 0)
		{

			for (int i = 0; i < passby_num; i++)
			{
				inside.num++;
				point[inside.num].x = border_point[border.num].x + rand() % range_x;

				point[inside.num].y = border_point[border.num].y + rand() % range_y;

			}
		}
		else {
			for (int i = 0; i < passby_num; i++)
			{
				inside.num++;
				point[inside.num].x = border_point[border.num].x - rand() % range_x;
				point[inside.num].y = border_point[border.num].y + rand() % range_y;
			}
		}
		border.num++;
		inside.num++;
	}
	srand((unsigned)time(NULL));
	for (float x = -2; x < 2; x += rand() % 600 * 0.0001)
	{
		border_point[border.num].x = x * k;
		border_point[border.num].y = -(acos(1 - fabs(x)) - PI) * k;
		if (border_point[border.num].x > 0)
		{
			for (int i = 0; i < passby_num; i++)
			{
				inside.num++;
				point[inside.num].x = border_point[border.num].x - rand() % range_x;
				point[inside.num].y = border_point[border.num].y - rand() % range_y;
			}
		}
		else {
			for (int i = 0; i < passby_num; i++)
			{
				inside.num++;
				point[inside.num].x = border_point[border.num].x + rand() % range_x;
				point[inside.num].y = border_point[border.num].y - rand() % range_y;
			}
		}
		border.num++;
		inside.num++;
	}
	for (int i = 0; i < inside.num; i++)
	{
		setfillcolor(RGB(128, 0, 128));
		solidcircle(point[i].x, point[i].y, 1);

	}
	Sleep(30);
	k = (k + 1) % 20 + 60;
	FlushBatchDraw();
}
int main()
{
	initgraph(screen.width, screen.height);
	setorigin(screen.width / 2, screen.height / 2 - 50);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		drawlove();
	}
	return 0;
}