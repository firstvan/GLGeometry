#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "d:\Program Files (x86)\GLGeometry\Points\Points.hpp"
#include "d:\Program Files (x86)\GLGeometry\Color\Color.hpp"
#include <cmath>


class myVector{
	myPoint a1, a2;

public:
	
	myVector(){
		myPoint a1();
		myPoint a2();
	}

	//vektor létrehozása 2 végpont alapján
	myVector(myPoint rhs1, myPoint rhs2){
		a1 = rhs1;
		a2 = rhs2;
	}

	// vektor létrehozása a 2 pont 4 koordinátája alapján	
	myVector(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2){
		a1.setX(x1);
		a1.setY(y1);
		a2.setX(x2);
		a2.setY(y2);

	}

	/*double getBezartSzog(myVector rhs){
		
	}*/

	//vektor kirajzolása
	void display(){
		glBegin(GL_LINES);
			glVertex2d(a1.getX(), a1.getY());
			glVertex2d(a2.getX(), a2.getY());
		glEnd();
	}

	//vektor kirajzolása + kezdõ és végpont kirajzolása
	void displayWithPoints(){
		
		glBegin(GL_LINES);
			glVertex2d(a1.getX(), a1.getY());
			glVertex2d(a2.getX(), a2.getY());
		glEnd();


		glBegin(GL_POINTS);
		glVertex2d(a1.getX(), a1.getY());
		glVertex2d(a2.getX(), a2.getY());
		glEnd();
	}

	//vektor kirajzolása + kezdõ és végpont kirajzolása
	void displayWithPoints(myColor& a){
		glColor3d(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2d(a1.getX(), a1.getY());
		glVertex2d(a2.getX(), a2.getY());
		glEnd();

		a1.display(a);
		a2.display(a);
	}

	//vektor kirajzolása + kezdõ és végpont kirajzolása
	void displayWithPoints(myColor& l, myColor& a){
		l.doColor();
		glBegin(GL_LINES);
		glVertex2d(a1.getX(), a1.getY());
		glVertex2d(a2.getX(), a2.getY());
		glEnd();

		a1.display(a);
		a2.display(a);
	}


	//vektor hossznégyzetét adja vissza
	GLdouble length2(){
		GLdouble x = a2.getX() - a1.getX();
		GLdouble y = a2.getY() - a1.getY();
		return x*x + y*y;
	}

	//vektor hosszát adja vissza
	GLdouble length(){
		return std::sqrt(this->length2());
	}

	// kezdõpont visszatérítése
	myPoint getP1(){
		return a1;
	}

	// végpont visszatérítése
	myPoint getP2(){
		return a2;
	}

	void setP1(myPoint rhs){
		a1 = rhs;
	}

	void setP2(myPoint rhs){
		a2 = rhs;
	}

	//két vektor összeadása
	myVector operator+(myVector rhs){
		return myVector(this->getP1().getX() + rhs.getP1().getX(), this->getP1().getY() + rhs.getP1().getY(), this->getP2().getX() + rhs.getP2().getX(), this->getP2().getY() + rhs.getP2().getY());
	}

	//Vector eltolása x,y pontal
	void eltolas(GLdouble toX, GLdouble toY){
		GLdouble temp1X = a1.getX() + toX;
		GLdouble temp1Y = a1.getY() + toY;
		GLdouble temp2X = a2.getX() + toX;
		GLdouble temp2Y = a2.getY() + toY;
		
		
		this->a1.setX(temp1X);
		this->a1.setY(temp1Y);
		this->a2.setX(temp2X);
		this->a2.setY(temp2Y);
	}

	void felosztas(int n){
		for (int i = 1; i < n; i++)
		{
			myPoint temp(a1);
			temp = (temp * ((n - i) / (double)n));
			temp = temp + a2 * (i / (double)n);
			temp.display(myColor(RED));
		}
	}


};


#endif