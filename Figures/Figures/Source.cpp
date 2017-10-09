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
		cout << "Side: ";
		cin >> val;
		this->width = val; 
	}

	int getWidth() { return this->width; }

	void setPosition()
	{
		cout << "X: ";
		cin >> this->position.x;
		cout << " ,Y: ";
		cin >> this->position.y;
	}
};

//----------------------------------------------------------------
class Color : public Figure
{
protected:
	short Cred;
	short Cgreen;
	short Cblue;

public:

	void getColor()
	{
		cout << hex;

		this->Cred == 0 ? (cout << '0' << this->Cred) : cout << this->Cred;
		this->Cgreen == 0 ? (cout << '0' << this->Cgreen) : cout << this->Cgreen;
		this->Cblue == 0 ? (cout << '0' << this->Cblue) : cout << this->Cblue;

		cout << dec;
	}

	void setColor()
	{
		int red, int green, int blue;
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

	void setDefaultBackGroundColor()
	{
		this->Cred = 0x00;
		this->Cgreen = 0x00;
		this->Cblue = 0x00;
	}

	void setDefaultForeGroundColor()
	{
		this->Cred = 0xFF;
		this->Cgreen = 0xFF;
		this->Cblue = 0xFF;
	}

	void lighten() 
	{ 
		
		Cred++; 
		Cgreen++; 
		Cblue++; 
	}
	
	void darken() { Cred--; Cgreen--; Cblue--;	}
};

//----------------------------------------------------------------
class Square : public Figure, public Color
{
public:

	void setSide() { Figure::setWidth(); }

	void setPosition() { Figure::setPosition(); }

	void setColor() { Color::setColor(); }

	void lighten() { Color::lighten(); }

	void draw()
	{
		cout << endl << "Type: Square" << endl;
		cout << "Width: " << Figure::getWidth() << endl;
		cout << "Height: " << Figure::getWidth() << endl;
		cout << "Position: " << Figure::position.x << " x " << Figure::position.y << endl;
		Color::setDefaultBackGroundColor(); 
		cout << "Background Color: #";
		Color::getColor();
		Color::setDefaultForeGroundColor();
		cout << "\nForeground Color: #";
		Color::getColor();
	}
};

//----------------------------------------------------------------
class Rectangle : public Figure, public Color
{
	int height = 0;
public:
	void draw()
	{
		cout << endl << "Type: Rectangle" << endl;
		cout << "Width: " << Figure::getWidth() << endl;
		cout << "Height: " << this->height << endl;
		cout << "Position: " << Figure::position.x << " x " << Figure::position.y << endl;
		Color::setDefaultBackGroundColor();
		cout << "Background Color: #";
		Color::getColor();
		Color::setDefaultForeGroundColor();
		cout << "\nForground Color: #";
		Color::getColor();
	}
};

//----------------------------------------------------------------
class Circle : public Figure, public Color
{
	int radius = 0;
public:


	void draw()
	{
		cout << endl << "Type: Circle" << endl;
		cout << "Raduis: " << this->radius << endl;
		cout << "Position: " << Figure::position.x << " x " << Figure::position.y << endl;
		Color::setDefaultBackGroundColor();
		cout << "Background Color: #";
		Color::getColor();
		Color::setDefaultForeGroundColor();
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
	bool conti = true;

	cout << "Select figure:"
		"\n1: Squeare"
		"\n2: Rectangle"
		"\n3: Circle"
		"\nChoice: ";
	cin >> choiceFig;

	system("cls");

	cout << "----------------------DRAW----------------------";
	switch (choiceFig)
	{
		case 1:
			sq.draw();
			cout << endl;

			cout << "What u want to cange:"
				"1. Side"
				"2. Position"
				"3. Change color"
				"4. Lighten color"
				"5. Darken color"
				"Choice: ";
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
				sq.setColor();
				break;
			case 4:

			}

			cout << endl;
				
			break;
		case 2:
			rec.draw();
			cout << endl;

			cout << "What u want to cange:"
				"1. Width"
				"2. Height"
				"3. Position"
				"4. Change color"
				"5. Lighten color"
				"6. Darken color"
				"Choice: ";

			break;
		case 3:
			cir.draw();
			cout << endl;

			cout << "What u want to cange:"
				"1. Radius"
				"2. Position"
				"3. Change color"
				"4. Lighten color"
				"5. Darken color"
				"Choice: ";

	}

	cout << endl;
	system("pause");
}