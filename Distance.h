//Nathanael Fixx
//CSS 342
//4.5 hours
//Cygwin
//
//This class allows for the creation of Distance objects
//the distance objects have feet and inches. These values
//can be edited. The operators +, -, *, /, and << can all
//be used on the objects.

#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
using namespace std;

class Distance
{
public:
	//Constructors
	Distance();
	Distance(int feet, int inches);
	//Getters and Setters
	int getFeet() const;
	int getInches() const;
	void setDistance(int feet, int inches);
	//Overloading
	friend ostream& operator<<(ostream &outstream, const Distance &dist);
	Distance operator+(const Distance &dist) const;
	Distance operator-(const Distance &dist) const;
	Distance operator*(int num);
	Distance operator/(int num);



private:
	int feet;
	int inches;
	int feetInInches = 12;
	double rounder = .5;
};

#endif
