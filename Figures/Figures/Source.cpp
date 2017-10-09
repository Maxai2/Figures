#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

//----------------------------------------------------------------

class Figure
{
	struct Point
	{
		int x = 0;
		int y = 0;
	}; 

	int width = 0;

protected:
	Point position;

public:
	void setWidth() 
	{
		int val;
		cout << "Width: ";
		cin >> val;
		this->width = val; 
	}

	int getWidth() { return this->width; }

	void setPosition()
	{
		cout << "X: ";
		cin >> this->position.x;
		cout << "Y: ";
		cin >> this->position.y;
	}
};

//----------------------------------------------------------------
class Color : public Figure
{
public:
	short Cred;
	short Cgreen;
	short Cblue;

	void getColor()
	{
		cout << hex;

		this->Cred == 0 ? (cout << '0' << this->Cred) : cout << this->Cred;
		this->Cgreen == 0 ? (cout << '0' << this->Cgreen) : cout << this->Cgreen;
		this->Cblue == 0 ? (cout << '0' << this->Cblue) : cout << this->Cblue;

		cout << dec;
	}

	void setColor(char foreBack)
	{
		int red, green, blue;

		if (foreBack == 'f')
		{
			this->Cred = 255;
			this->Cgreen = 255;
			this->Cblue = 255;
		}
		else
		if (foreBack == 'b')
		{
			this->Cred = 0;
			this->Cgreen = 0;
			this->Cblue = 0;
		}
		else
		{
			cout << "Red(0-255): ";
			cin >> red;
			this->Cred = red;
			cout << "\nGreen(0-255): ";
			cin >> green;
			this->Cgreen = green;
			cout << "\nBlue(0-255): ";
			cin >> blue;
			this->Cblue = blue;
		}
	}

	void lighten() 
	{ 
		int num = 0;

		cout << "How much upper: ";
		cin >> num;

		if (this->Cred < 255)
			Cred += num; 

		if (this->Cgreen < 255)
			Cgreen += num;

		if (this->Cblue < 255)
			Cblue += num;

	}
	
	void darken() 
	{ 

		int num = 0;

		cout << "How much lower: ";
		cin >> num;

		if (this->Cred > 0)
			Cred -= num;

		if (this->Cgreen < 255)
			Cgreen -= num;

		if (this->Cblue < 255)
			Cblue -= num;
	}
};

//----------------------------------------------------------------
class Square : public Figure, public Color
{
public:

	void setSide() { Figure::setWidth(); }

	void setPosition() { Figure::setPosition(); }

	void draw()
	{
		cout << endl << "Type: Square" << endl;
		cout << "Width: " << Figure::getWidth() << endl;
		cout << "Height: " << Figure::getWidth() << endl;
		cout << "Position: " << Figure::position.x << " x " << Figure::position.y << endl;
		cout << "Background Color: #";
		Color::getColor();
		cout << "\nForeground Color: #";
		Color::getColor();
	}
};

//----------------------------------------------------------------
class Rectangle : public Figure, public Color
{
	int height = 0;
public:

	void setWidth() { Figure::setWidth(); }

	void setHeight() 
	{
		int val;
		cout << "Height: ";
		cin >> val;
		this->height = val;
	}

	void setPosition() { Figure::setPosition(); }

	void draw()
	{
		cout << endl << "Type: Rectangle" << endl;
		cout << "Width: " << Figure::getWidth() << endl;
		cout << "Height: " << this->height << endl;
		cout << "Position: " << Figure::position.x << " x " << Figure::position.y << endl;
		cout << "Background Color: #";
		Color::getColor();
		cout << "\nForground Color: #";
		Color::getColor();
	}
};

//----------------------------------------------------------------
class Circle : public Figure, public Color
{
	int radius = 0;
public:

	void setRadius()
	{
		int val;
		cout << "Radius: ";
		cin >> val;
		this->radius = val;
	}

	void setPosition() { Figure::setPosition(); }

	void draw()
	{
		cout << endl << "Type: Circle" << endl;
		cout << "Raduis: " << this->radius << endl;
		cout << "Position: " << Figure::position.x << " x " << Figure::position.y << endl;
		cout << "Background Color: #";
		Color::getColor();
		cout << "\nForground Color: #";
		Color::getColor();
	}
};

//----------------------------------------------------------------
void main()
{
	Square sq;
	Rectangle rec;
	Circle cir;

	int choiceFig = 0, choiceEdit = 0;
	char conti;

	BEGIN:
	cout << "Select figure:"
		"\n1: Squeare"
		"\n2: Rectangle"
		"\n3: Circle"
		"\nChoice: ";
	cin >> choiceFig;
	AGAIN:
	system("cls");

	cout << "----------------------DRAW----------------------";
	switch (choiceFig)
	{
		case 1:
			sq.draw();
			cout << endl;

			cout << "\nWhat u want to cange:"
				"\n1. Side"
				"\n2. Position"
				"\n3. Change color"
				"\n4. Lighten color"
				"\n5. Darken color"
				"\nChoice: ";
			cin >> choiceEdit;

			switch (choiceEdit)
			{
			case 1:
				sq.setSide();
				break;
			case 2:
				sq.setPosition();
				break;
			case 3:
				sq.setColor('c');
				break;
			case 4:
				sq.lighten();
				break;
			case 5:
				sq.darken();
			}
			
			sq.draw();
			cout << endl;
				
			break;
		case 2:
			rec.draw();
			cout << endl;

			cout << "\nWhat u want to cange:"
				"\n1. Width"
				"\n2. Height"
				"\n3. Position"
				"\n4. Change color"
				"\n5. Lighten color"
				"\n6. Darken color"
				"\nChoice: ";

			cin >> choiceEdit;

			switch (choiceEdit)
			{
			case 1:
				rec.setWidth();
				break;
			case 2:
				rec.setHeight();
				break;
			case 3:
				rec.setPosition();
				break;
			case 4:
				rec.setColor('c');
				break;
			case 5:
				rec.lighten();
				break;
			case 6:
				rec.darken();
			}

			rec.draw();
			cout << endl;

			break;
		case 3:
			cir.draw();
			cout << endl;

			cout << "\nWhat u want to cange:"
				"\n1. Radius"
				"\n2. Position"
				"\n3. Change color"
				"\n4. Lighten color"
				"\n5. Darken color"
				"\nChoice: ";
			cin >> choiceEdit;

			switch (choiceEdit)
			{
			case 1:
				cir.setRadius();
				break;
			case 2:
				cir.setPosition();
				break;
			case 3:
				cir.setColor('c');
				break;
			case 4:
				cir.lighten();
				break;
			case 5:
				cir.darken();
			}
			
	}

	cout << "\nAnoter figure or this edit?(y/n): ";
	cin >> conti;
	if (conti == 'y')
	{
		system("cls");
		goto BEGIN;
	}
	else			
		goto AGAIN;
			
	cout << endl;

	cout << endl;
	system("pause");
}