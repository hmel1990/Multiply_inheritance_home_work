#include<iostream>
using namespace std;
#include <string>
#include <cmath>

class Figure
{
protected:
	float width;
	float height;
public:

	Figure()
	{
		set_height(1);
		set_width(1);
	}

	void set_width(float width)
	{
		this->width = width;
	}
	float get_width()
	{
		return width;
	}


	void set_height(float height)
	{
		this->height = height;
	}


	float get_height()
	{
		return height;
	}

	float square()
	{
		return height * width;
	}

	float perimetr()
	{
		return (height + width) * 2;
	}
	void draw()
	{
		cout << "\ndrawing figure";
	}
};

class Is_regular //Класс указывающий на то правильной ли формы фигура
{
protected:
	bool regular;
public:
	Is_regular() 
	{
		regular = true;
	}
	void set_regular(bool regular)
	{
		this->regular = regular;
	}

	bool get_regular()
	{
		return regular;
	}
};


class Polygon :public Figure, public Is_regular
{
protected:
	float length;
	float apofema;
public:

	void set_length(float length)
	{
		this->length = length;
	}


	float get_length()
	{
		return length;
	}

	void set_apofema(float apofema)
	{
		this->apofema = apofema;
	}


	float get_apofema()
	{
		return apofema;
	}

	Polygon()
	{
		set_length(5);
	}
	void draw()
	{
		cout << "\ndrawing Polygon";
	}

	double square()
	{
		if (regular) return 0.5* perimetr() * apofema;
	}
	double perimetr()
	{
		return 6 * length;
	}
};


class Triangle : public Polygon, public Is_regular {
	float apofema;
public:
	float get_apofema() = delete;
	void set_apofema(float apofema) = delete;
	
	Triangle()
	{
		length = 1;
	}

	float square() {
		if (Is_regular::regular) // пришлось уточнять))
		{
			float height = sqrt(length * length - (length / 2) * (length / 2));
			return (length * height) / 2;
		}
	}

	float perimetr()
	{
		return 3 * length;
	}

	void draw()
	{
		cout << "\n /\\\n/  \\\n----";
	}
};

int main ()
{
	Triangle tr;
	tr.square();
	tr.draw();
}