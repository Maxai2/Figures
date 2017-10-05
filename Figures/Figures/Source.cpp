#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

class Figure
{
	int width;
public:
		
};

class Color : Figure
{
	short red;
	short green;
	short blue;

public:
	void lghten() {	red++; green++; blue++;	}

	void darken() { red--; green--; blue--;	}
};

class Square : Figure
{
public:
	void draw()
	{

	}
};
class Rectangle : Figure
{
	int height;
public:
	void draw()
	{

	}
};

class Circle : Figure
{
	int height;
public:
	void draw()
	{

	}
};

void main()
{
	
}