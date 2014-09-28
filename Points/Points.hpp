#ifndef POINTS_HPP
#define POINTS_HPP

#include <GL/glut.h>

class myPoint{
	GLint x, y;

public:
	myPoint() : x(0), y(0){}

	myPoint(GLint rhsX, GLint rhsY) : x(rhsX), y(rhsY)
	{}
	
	GLint getX(){
		return x;
	}

	GLint getY(){
		return y;
	}

	void setX(GLint rhsx){
		x = rhsx;
	}

	void setY(GLint rhsy){
		y = rhsy;
	}

	

};



#endif