#ifndef POINTS_HPP
#define POINTS_HPP

#include <GL/glut.h>
#include "d:\Program Files (x86)\GLGeometry\Color\Color.hpp"

class myPoint{
	GLdouble x, y;

public:
	//pont inicializ�l�sa
	myPoint() : x(0), y(0){}

	//pont l�trehoz�sa x,y pontban
	myPoint(GLdouble rhsX, GLdouble rhsY) : x(rhsX), y(rhsY)
	{}

	//m�sol� konstruktor
	myPoint(myPoint& rhs){
		x = rhs.getX();
		y = rhs.getY();
	}

	//m�sol� �rt�kad�s
	/*myPoint& operator=(const myPoint& rhs){
		if (this != &rhs)
		{
			this->setX(rhs.getX());
			this->setY(rhs.getY());
		}
	
	}*/

	//x visszat�r�t�se
	GLdouble getX() const{
		return x;
	}

	//y visszat�r�t�se
	GLdouble getY() const{
		return y;
	}

	//x be�ll�t�sa
	void setX(GLdouble& rhsx){
		x = rhsx;
	}

	//y be�llyt�sa
	void setY(GLdouble& rhsy){
		y = rhsy;
	}

	//pont kirajzol�sa
	void display() const{
		glBegin(GL_POINTS);
		glVertex2d(x, y);
		glEnd();
	}

	void display(myColor& pc) const{
		pc.doColor();
		glBegin(GL_POINTS);
		glVertex2d(x, y);
		glEnd();
	}

	// pontok egyenl�s�g vizsg�lata
	bool operator==(myPoint& rhs) const{
		if (this->getX() == rhs.getX() && this->getY() == rhs.getY())
			return true;
		return false;
	}

	//pont sz�mmal val� szorz�sa
	myPoint operator*(const double rhs) const{
		return myPoint(rhs*this->getX(), rhs*this->getY());
	}

	//pontok �sszead�sa
	myPoint operator+(const myPoint& rhs){
		return myPoint(this->getX() + rhs.getX(), this->getY() + rhs.getY());
	}



};



#endif