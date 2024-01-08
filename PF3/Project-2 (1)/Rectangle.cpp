/** @file Rectangle.cpp */

#include "Rectangle.h"

Rectangle::Rectangle()
{
	Rectangle::length = 1.0;
  Rectangle::width = 1.0;
}

bool Rectangle::set(double newLength, double newWidth)
{
	if (newLength > 0.0 || newWidth > 0.0)
	{
		Rectangle::length = newLength;
    Rectangle::width = newWidth;
    return true;
	}
  else
    return false;
}

double Rectangle::getLength() const
{
	return Rectangle::length;
}

double Rectangle::getWidth() const
{
	return Rectangle::width;
}

double Rectangle::getArea() const
{
  return Rectangle::length * Rectangle::width;
}