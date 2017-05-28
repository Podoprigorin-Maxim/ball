#include "ball.h"

const double PI=3.1415926535;

Ball::Ball(double x, double y, double z, double r)
{
	if(r < 0)
		r = 0;
	
	_x = x;
	_y = y;
	_z = z;
	_r = r;
}
Ball::~Ball()
{}
double Ball::getCenterX()
{
	return _x;
}
double Ball::getCenterY()
{
	return _y;
}
double Ball::getCenterZ()
{
	return _z;
}
double Ball::getRadius()
{
	return _r;
}
void Ball::move(double dx,double dy,double dz)
{
	_z += dz;
	_y += dy;
	_x += dx;
}
void Ball::scale(double k)
{
	_r *= k;
}
double Ball::calculateArea()
{
	return PI*_r*_r*_r*(4.0/3) ;
}
