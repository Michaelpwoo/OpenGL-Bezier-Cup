#include "Vector4.h"

#include <math.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;


Vector4::Vector4()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
	w = 1.0;
}

Vector4::Vector4(float x0, float y0, float z0) 
{
	x = x0;
	y = y0;
	z = z0;
	w = 1.0;
}

Vector4::Vector4(float x0, float y0, float z0, float w0)
{
	x = x0;
	y = y0;
	z = z0;
	w = w0;
}

void Vector4::set(float x0, float y0, float z0, float w0)
{
	x = x0;
	y = y0;
	z = z0;
	w = w0;
}

void Vector4::setX(float x0)
{
	x = x0;
}

void Vector4::setY(float y0)
{
	y = y0;
}

void Vector4::setZ(float z0)
{
	z = z0;
}

void Vector4::setW(float w0)
{
	w = w0;
}

float Vector4::get(int index)
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else if (index == 2)
		return z;
	else
		return w;
}

float Vector4::getX()
{
	return x;
}

float Vector4::getY()
{
	return y;
}

float Vector4::getZ()
{
	return z;
}

float Vector4::getW()
{
	return w;
}

float Vector4::operator[] (const int i) {
	return this->get(i);
}

void Vector4::add(Vector4 &a) {
	x+=a.x;
	y+=a.y;
	z+=a.z;
	w+=a.w;
}

void Vector4::add(Vector4 &a, Vector4 &b) {
	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
	w = a.w + b.w;
}

void Vector4::scale(float s)
{
	x*=s;
	y*=s;
	z*=s;
	w*=s;
}

void Vector4::scale(float s, Vector4 &a)
{
	x = s * a.x;
	y = s * a.y;
	z = s * a.z;
	w = s * a.w;
}

float Vector4::magnitude()
{

	//cout << "mag: " << x << ',' << y << ',' << z;
	return sqrt(x*x + y*y + z*z + w*w);
}

void Vector4::normalize()
{
	scale(float(1.0)/magnitude());
}

Vector4 Vector4::operator+(const Vector4 &other) const
{
	return Vector4(this->x + other.x, this->y + other.y, 
		this->z + other.z, this->w + other.w);
}

void Vector4::subtract(Vector4 &a)
{
	x-=a.x;
	y-=a.y;
	z-=a.z;
	w-=a.w;
}

void Vector4::subtract(Vector4 &a, Vector4 &b)
{
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	w = a.w - b.w;
}

Vector4 Vector4::operator-(const Vector4 &other) const
{
	return Vector4(this->x - other.x, this->y - other.y, 
		this->z - other.z, this->w - other.w);
}

void Vector4::dehomogenize() {
	if (w != 0.0) {
		float denom = 1.0/w;
		x*=denom;
		y*=denom;
		z*=denom;
		w = 1.0;
	}
}

void Vector4::print()
{
	cout << setprecision(2) << fixed;
	cout << "(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")\n";
}

string Vector4::toString() {
	ostringstream ss;
	ss << "(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")";
	return ss.str();
}
