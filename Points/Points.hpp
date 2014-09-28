#ifndef POINTS_HPP
#define POINTS_HPP

#include <GL/glut.h>

class myPoint{
	GLdouble x, y;

public:
	myPoint() : x(0), y(0){}

	myPoint(GLdouble rhsX, GLdouble rhsY) : x(rhsX), y(rhsY)
	{}

	myPoint(myPoint& rhs){
		x = rhs.getX();
		y = rhs.getY();
	}

	/*myPoint operator=(const myPoint& rhs){
		if (this != &rhs)
		{
			this->setX(rhs.getX());
			this->setY(rhs.getY());
		}
	}*/

	GLdouble getX(){
		return x;
	}

	GLdouble getY(){
		return y;
	}

	void setX(GLdouble& rhsx){
		x = rhsx;
	}

	void setY(GLdouble& rhsy){
		y = rhsy;
	}

	void display(){
		glBegin(GL_POINTS);
		glVertex2d(x, y);
		glEnd();
	}

	bool operator==(myPoint& rhs){
		if (this->getX() == rhs.getX() && this->getY() == rhs.getY())
			return true;
		return false;
	}

	myPoint operator*(double rhs){
		return myPoint(rhs*this->getX(), rhs*this->getY());
	}

};



#endif