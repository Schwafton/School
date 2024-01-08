#ifndef RECTANGLE_INTERFACE_
#define RECTANGLE_INTERFACE_

/** @file RectangleInterface.h */

class RectangleInterface
{
  public:
  /** Set length and width values
  @param newLength  User sets new length value.
  @param newWidth   User sets new width value.
  @pre newLength and newWidth must both be greater than 0.0.
  @post sets length and width to newLength and newWidth.
  @return true if precondition is met, else returns false. */
    virtual bool set(double newLength, double newWidth) = 0;
	
  /** Get length
  @post Changes nothing.
  @return value stored in length. */
	  virtual double getLength() const = 0;
	
  /** Get width
  @post Changes nothing.
  @return value stored in width. */
	  virtual double getWidth() const = 0;

  /** Get area
  @post Multiplies length and width to get area.
  @return area. */
    virtual double getArea() const = 0;

	/** Destroys this Rectangle and frees its assigned memory. */
	  virtual ~RectangleInterface() {}
};
#endif