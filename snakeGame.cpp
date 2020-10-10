#include <iostream>
using namespace std;
bool gameOver;
const int height = 20;
const int width = 40;
int x, y,fruitX,fruitY,score;
enum eDirection {STOP =0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
#include<conio.h>
#include <string>


void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls"); //"clear"
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)

		{

			if (j == 0  or j == width - 1)
			{
				cout << "#";
			}

			if (i == y && j == x)
			{
				cout << "@";
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}

			else   cout << " ";
			
		}
			
cout << endl;
	}
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "score:   " << score << endl;
	cout << "X:  " << x << "\tY:  " << y << endl;
	cout << "fruitX : " << fruitX << "\tfruitY: " << fruitY << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'q':
			gameOver = true;


		}
	}

}

void status()
{
	if (x == 0 or x == width+3 or y==-1 or y==height+1)
	{
		gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score += 10;

	fruitX = rand() % width;
	fruitY = rand() % height;

	}

}


void Logic()
{	switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case DOWN:
			y++;
			break;
		case UP:
			y--;
			break;
		default:
			break;
		
		}


}

void run()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		status();
	}

}









int main()
{
	cout << "Do you want to start the game" << endl;
	
	string keyin;
	cin >> keyin;
	while (keyin != "q")
	{run();
	cin.clear();
	cin.ignore();
	system("cls");
			
		cout << "Press q to quit, press other key to restart" << endl;
		getline(cin, keyin);

	}


}
