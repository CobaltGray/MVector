/***************************************************************************
 *
 * Copyright Crown (c) 2012. All rights reserved.
 *
 * Module: MVector.cpp
 *
 * Description: Mathmatical Vector c++ class definition
 *
 * Original Author: Darren Muff
 * 					(Ported from a JAVA module written by Matt Nottingham)
 * 					(original code written in MATLAB by Ralph Fiedler)
 *
 *
 *		Functions in this class:
 * 			Vector minus()              : Vector negation.
 * 			double mag()                : Magnitude of vector.
 * 			Vector norm()               : Normalise vector.
 * 			double dot(vector)          : Dot product. 
 * 			Vector cross(Vector)        : Cross Product.
 * 			Vector rotatex(double angle): rotate around x axis by theta.
 * 			Vector rotatey(double angle): rotate around y axis by theta.
 * 			Vector rotatez(double angle): rotate around z axis by theta.
 *			Vector rotateAxis(Vector axis, double angle): rotate one vector
 *			around another by angle
 * 			string toString()           : Convert to string
 * 		Overloaded operators
 * 			+ : Vector addition. (Vector=Vector+Vector)
 * 			- : Vector subtract. (Vector=Vector-Vector)
 *          - : Scalar subtract. (Vector=Vector-scalar)
 *			- : Negate.			 (-Vector=Vector-)
 * 			* : scaler multiply. (Vector=Vector*scalar)
 *			* : scalar multiply. (Vector=scalar*Vector)
 * 			/ : scaler divide.	 (Vector=Vector/scalar)
 *			^ : cross product.   (Vector=Vector^Vector)
 *          << : write Vector to lhs stream
 *          != : Vector not equal test (bool Vector!=Vector)
 *          == : Vector eqal test (bool Vector==Vector)
 *
 * CLASSIFICATION        :  UNCLASSIFIED
 * Date of CLASSN        :  3rd April 2012
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * THE SOFTWARE IN ITS ENTIRETY OR ANY SUBSTANTIAL PORTION SHOULD NOT BE
 * USED AS A WHOLE OR COMPONENT PART OF DERIVATIVE SOFTWARE THAT IS BEING
 * SOLD TO THE GOVERNMENT OF THE UNITED KINGDOM OF GREAT BRITAIN AND NORTHERN
 * IRELAND.
 *
 ***************************************************************************/

#include "MVector.h"

using namespace std;
namespace MVector {
	
	// Constructors
	Vector::Vector(){ x=y=z=0;}
	Vector::Vector(double a,double b,double c){x=a; y=b; z=c;}
    Vector::Vector(VectorH v) : x(v.x), y(v.y), z(v.z){}
	
	// Overload operators here	
	Vector Vector::operator+(const Vector &v) const{
		Vector ans(x+v.x,y+v.y,z+v.z);
		return(ans);
	}
	
	Vector Vector::operator+(double val) const {
		Vector ans(x+val, y+val, z+val);
		return(ans);
	}
	
	Vector Vector::operator-(const Vector &v) const{
		Vector ans(x-v.x,y-v.y,z-v.z);
		return (ans);
	}
	
	Vector Vector::operator-(double val) const{
		Vector ans(x-val, y-val, z-val);
		return (ans);
	}
	
	Vector Vector::operator-() const {
		return Vector(-x,-y,-z);
	}
	
	Vector Vector::operator*(double val) const {
		Vector ans(x*val,y*val,z*val);
		return (ans);
	}
	
	Vector Vector::operator/(double val) const {
		Vector ans(x/val,y/val,z/val);
		return(ans);
	}
	
	bool Vector::operator!=(const Vector &v) const{
		if( (fabs(v.x - x) > 1e-6) ||
		   (fabs(v.y - y) > 1e-6) ||
		   (fabs(v.z - z) > 1e-6)){
			return(true);
		}else{
			return(false);
		}		
	}
	
	bool Vector::operator==(const Vector &v) const{
		if( (fabs(v.x - x) < 1e-6) &&
			(fabs(v.y - y) < 1e-6) &&
		   (fabs(v.z - z) < 1e-6)){
			return(true);
		}else{
			return(false);
		}
	}
	
    /* Cross operator */
	Vector Vector::operator^(const Vector &v) const{
		Vector ans(y*v.z - z*v.y,z*v.x - x*v.z,x*v.y - y*v.x);
		return(ans);
	}

	// Class functions here
	Vector Vector::minus() const { return (Vector(-x,-y,-z));}
	
	double Vector::mag() const {return(sqrt((x*x)+(y*y)+(z*z)));}
	
	Vector Vector::norm() const {
		double m = mag();
		Vector ans(x/m,y/m,z/m);
		return (ans);
	}
	
	double Vector::dot(const Vector &v) const {return(v.x*x + v.y*y + v.z*z);}
	
	Vector Vector::cross(const Vector &v) const {
		Vector ans(y*v.z - z*v.y,z*v.x - x*v.z,x*v.y - y*v.x);
		return(ans);
	}
	
	// Rotate around x axis by angle 'angle' 
	// angle is specified in radians
	Vector Vector::rotatex(double angle) const {
		double c = cos(angle);
		double s = sin(angle);
		Vector rotated(x,y*c - z*s, s*y + c*z);
		return (rotated);
	}
	
	Vector Vector::rotatey(double angle) const {
		double c = cos(angle);
		double s = sin(angle);
		Vector rotated(c*x+s*z, y, c*z - x*s);
		return(rotated);
	}
	
	Vector Vector::rotatez(double angle) const {
		double c = cos(angle);
		double s = sin(angle);
		Vector rotated(c*x-s*y, s*x+c*y, z);
		return(rotated);
	}
	
	/* Rotate this mvector about the vector axis by an amount theta */
	/* the rotation Axis is assumed to be a direction from the origin */
	/* ie this vector has already been translated */
	Vector Vector::rotateAxis(Vector axis, double theta){
		Vector ans;
		if(axis.x == 0 && axis.y == 0 ){
			ans = rotatez(theta);
		}else if(axis.x == 0 && axis.z == 0){
			ans = rotatey(theta);
		}else if(axis.y == 0 && axis.z == 0){
			ans = rotatex(theta);
		}else{
			double thetaz = atan(axis.y/axis.x);
			double thetay = atan( sqrt( (axis.x * axis.x) + (axis.y * axis.y)) / axis.z );

			// First rotate around the z axis
			ans = rotatez(-thetaz);
			
			// Now rotate around y axis
			ans = ans.rotatey(-thetay);
			
			// now rotate around z by the required angle theta
			ans = ans.rotatez(theta);
			
			// Now add on the rotation axis around y and z to get back to the original reference frame
			ans = ans.rotatey(thetay);
			ans = ans.rotatez(thetaz);
		}
		return(ans);
	}
	
    string Vector::toString(){
		string s;
		{
			ostringstream ss;
			ss.precision(9);
			ss << "[" << x << "," << y << "," << z << "]";
			s = ss.str();
		}
		return(s);
	}
    
    VectorH Vector::cstub(){
        VectorH ans;
        VECT_CREATE(x, y, z, ans);
        return(ans);
    }
	
	// Friend methods
	
	// multiply double val by vector v
	Vector operator*(double val, const Vector &v){
		return (v*val);
	}
	
	// Allow for std::ostream output
	std::ostream & operator<<(std::ostream &os, const Vector &v){
		os << "[" << v.x << "," << v.y << "," << v.z << "]";
		return(os);
	}
	
}
