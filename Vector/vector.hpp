#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "d:\Program Files (x86)\GLGeometry\Points\Points.hpp"
#include <cmath>


class myVector{
	myPoint a1, a2;

public:
	myVector(){
		myPoint a1();
		myPoint a2();
	}

	myVector(myPoint rhs1, myPoint rhs2){
		a1 = rhs1;
		a2 = rhs2;
	}

	myVector(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2){
		a1.setX(x1);
		a1.setY(y1);
		a2.setX(x2);
		a2.setY(y2);

	}

	
	void display(){
		glBegin(GL_LINES);
			glVertex2d(a1.getX(), a1.getY());
			glVertex2d(a2.getX(), a2.getY());
		glEnd();
	}

	GLdouble length2(){
		GLdouble x = a2.getX() - a1.getX();
		GLdouble y = a2.getY() - a1.getY();
		return x*x + y*y;
	}

	GLdouble length(){
		return std::sqrt(this->length2());
	}

	myPoint getP1(){
		return a1;
	}

	myPoint getP2(){
		return a2;
	}

	
};


#endif