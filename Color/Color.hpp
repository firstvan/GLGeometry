#ifndef MYCOLOR_HPP
#define MYCOLOR_HPP

#include <GL/glut.h>

enum ColorName{
	BLACK, BLUE, GRAY, GREEN, PURPLE, BROWN, RED, PINK, YELLOW, ORANGE, WHITE
};

class myColor{
	GLdouble r;
	GLdouble g;
	GLdouble b;

	
public:
	myColor(): r(0.0), g(0.0), b(0.0)
	{}

	myColor(GLdouble rr, GLdouble rg, GLdouble rb): r(rr), g(rg), b(rb)
	{}

	myColor(ColorName name){
	
		GLdouble rgb[][3] =
		{
			{ 0.0, 0.0, 0.0 },							//BLACK
			{ 1.0, 0, 0 },								//BLUE
			{ 128 / 255.0, 128 / 255.0, 128 / 255.0 },	//GRAY
			{ 0.0, 1.0, 0.0	},							//GREEN
			{ 128 / 255.0, 0.0, 128 / 255.0 },			//PURPLE
			{ 165 / 255.0, 42 / 255.0, 42 / 255.0 },	//BROWN
			{ 1.0, 0.0, 0.0 },							//RED
			{ 1.0, 192 / 255.0, 203 / 255.0 },			//PINK
			{ 1.0, 1.0, 0.0 },							//YELLOW
			{ 1.0, 165 / 255.0, 0.0 },					//ORANGE
			{ 1.0, 1.0, 1.0 }							//WHITE
		};

		r = rgb[name][0];
		g = rgb[name][1];
		b = rgb[name][2];
	}

	GLdouble getR() const{
		return r;
	}

	GLdouble getG() const{
		return g;
	}

	GLdouble getB() const{
		return b;
	}

	void doColor(){
		glColor3d(r, g, b);
	}
};




#endif