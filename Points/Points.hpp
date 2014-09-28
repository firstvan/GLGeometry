#ifndef POINTS_HPP
#define POINTS_HPP

#include <GL/glut.h>

class myPoint{
	GLdouble x, y;

public:
	myPoint() : x(0), y(0){}

	myPoint(GLdouble rhsX, GLdouble rhsY) : x(rhsX), y(rhsY)
	{}

	GLdouble getX(){
		return x;
	}

	GLdouble getY(){
		return y;
	}

	void setX(GLdouble rhsx){
		x = rhsx;
	}

	void setY(GLdouble rhsy){
		y = rhsy;
	}

	void display(){
		glBegin(GL_POINTS);
		glVertex2d(x, y);
		glEnd();
	}

	bool operator==(myPoint rhs){
		if (this->getX() == rhs.getX() && this->getY() == rhs.getY())
			return true;
		return false;
	}

};



#endif