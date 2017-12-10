//Nathanael Fixx
//CSS 342
//4.5 hours
//Cygwin

#include "Distance.h"
using namespace std;

Distance::Distance()
{
	feet = 0;
	inches = 0;
}

Distance::Distance(int feet, int inches)
{
       	int newInches = (feet * feetInInches) + inches;

	feet = newInches / feetInInches;	//converts inches > 12 into feet				   
	inches = newInches % feetInInches;

	this->feet = feet;
	this->inches = inches;

}

int Distance::getFeet() const
{
	return feet;
}

int Distance::getInches() const
{
	return inches;
}

void Distance::setDistance(int feet, int inches)
{
	int newInches = (feet * feetInInches) + inches;  
	feet = newInches / feetInInches;   //converts inches > 12 into feet
	inches = newInches % feetInInches;

	this->feet = feet;
	this->inches = inches;

}

ostream& operator<<(ostream &outstream, const Distance &dist)	//sends to
{  							  //console window
	outstream << dist.feet << "/" << dist.inches;

	return outstream;
}

Distance Distance::operator+(const Distance &dist) const  
{
	int f;
	int i;
	f = feet + dist.feet;
	i = inches + dist.inches;
	Distance finalDist = Distance(f, i);
	return finalDist;
}

Distance Distance::operator-(const Distance &dist) const
{
	int f;
	int i;

	f = feet - dist.feet;
	i = inches - dist.inches;
	Distance finalDist = Distance(f, i);
	return finalDist;
}

Distance Distance::operator*(int num)
{
	int newInches = (feet * feetInInches) + inches;	
	newInches *= num;
	feet = newInches / feetInInches;    //converts inches > 12 into feet
	inches = newInches % feetInInches;

	Distance finalDist = Distance(feet, inches);
	return finalDist;
}

Distance Distance::operator/(int num)
{
	double newInches = (feet * feetInInches) + inches;
	newInches /= num;
	newInches += rounder;		//rounds to the nearest inch

	int finalInches = newInches;

	feet = finalInches / feetInInches;   //converts inches > 12 into feet
	inches = finalInches % feetInInches;

	Distance finalDist = Distance(feet, inches);
	return finalDist;

}


