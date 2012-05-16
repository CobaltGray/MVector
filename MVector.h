/***************************************************************************
 *
 * Copyright Crown (c) 2012. All rights reserved.
 *
 * Module: MVector.h
 *
 * Description: Mathmatical Vector code Header file
 *
 * Original Author: Darren Muff
 * 					(Ported from a JAVA module written by Matt Nottingham)
 * 					(original code written in MATLAB by Ralph Fiedler)
 *
 *
 *		Functions in this class:
 * 			Vector minus()              : Vector negation.
 * 			real mag()                : Magnitude of vector.
 * 			Vector norm()               : Normalise vector.
 * 			real dot(vector)          : Dot product. 
 * 			Vector cross(Vector)        : Cross Product.
 * 			Vector rotatex(real angle): rotate around x axis by theta.
 * 			Vector rotatey(real angle): rotate around y axis by theta.
 * 			Vector rotatez(real angle): rotate around z axis by theta.
 *			Vector rotateAxis(Vector axis, real angle): rotate one vector
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

#ifndef _MVECTOR_H_
#define _MVECTOR_H_
#include "MVector_version.h"
#ifndef real
#define real double
#endif

#ifndef MTLIB_H__
// Inherited inline macros from MTLIB
#define VECT_CREATE(a,b,c,vect) {vect.x = a; vect.y = b; vect.z = c;}
#define VECT_SCMULT(vect,sc,out) {out.x = (vect.x)*sc; out.y = (vect.y)*sc; out.z = (vect.z)*sc;}
#define VECT_SUB(a,b,out) {out.x = a.x - b.x; out.y = a.y - b.y; out.z = a.z - b.z;}
#define VECT_ADD(a,b,out) {out.x = a.x + b.x; out.y = a.y + b.y; out.z = a.z + b.z;}
#define VECT_MOD(a) (sqrt (a.x*a.x + a.y*a.y + a.z*a.z)) 
#define VECT_DOT(a,b) (a.x*b.x + a.y*b.y + a.z*b.z)
#define VECT_CROSS(a,b,out) {out.x = a.y*b.z - a.z*b.y; out.y = a.z*b.x - a.x*b.z; out.z = a.x*b.y - a.y*b.x}
#define VECT_UNIT(a,out) {real vect_unit_tmp = VECT_MOD(a); out.x = a.x/vect_unit_tmp; out.y = a.y/vect_unit_tmp; out.z = a.z/vect_unit_tmp;}
#define VECT_PROJ(vect, norm, out) {SPVector tmp; real dot = VECT_DOT(vect, norm); tmp.x = vect.x - dot*norm.x; tmp.y = vect.y - dot*norm.y; tmp.z = vect.z - dot*norm.z; VECT_UNIT(tmp, out);}  
// Deprecated SPVector used in MTLib. Use VectorH as a the C stub.
typedef struct {           
    real x;
    real y;
    real z;
} SPVector;
#endif

// Use VectorH as C stub for C++ vector functions
typedef SPVector VectorH;

// Define C stubs for C++ Vector functions here. Dont forget 
// to extern them only to the c++ compiler to remove c++ name
// mangling caused by ability to overload functions
#ifdef __cplusplus
extern "C" {
#endif
    VectorH vectCreate(real a, real b, real c);
    int vectEquals(VectorH v1, VectorH v2);
    int vectNotEqual(VectorH v1, VectorH v2);
    VectorH vectAdd(VectorH v1, VectorH v2);
    VectorH vectAddScaler(VectorH v1, real scaler);
    VectorH vectSub(VectorH v1, VectorH v2);
    VectorH vectSubScaler(VectorH v1, real scaler);
    VectorH vectMult(VectorH v1, real scaler);
    VectorH vectDiv(VectorH v1, real scaler);
    VectorH vectMinus(VectorH v);
    real vectMag(VectorH v);
    VectorH vectNorm(VectorH v);
    real vectDot(VectorH v1, VectorH v2);
    VectorH vectCross(VectorH v1, VectorH v2);
    VectorH vectRotatex(VectorH v, real angle);
    VectorH vectRotatey(VectorH v, real angle);
    VectorH vectRotatez(VectorH v, real angle);
    VectorH vectRotateAxis(VectorH v, VectorH axis, real angle);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

// Define namespace for MVector so that we can use Vector as the typedef
namespace MVector {
    
    class Vector {
	private:
		
	public: 
		
        union
        {
            struct { real x, y, z; };
            struct { real r, g, b; };
            struct { real cell[3]; };
            struct { real R, theta, phi; };
        };
		
		// Constructors first
		Vector();
		Vector(real a, real b, real c);
        Vector(VectorH);
		
		// Now overload scalar operators
		Vector operator+(const Vector &v) const;
		Vector operator+(real val) const;
		Vector operator-(const Vector &v) const;
		Vector operator-( real val) const;
		Vector operator-() const;
		Vector operator*(real val) const;
		Vector operator/(real val) const;
		bool operator!=(const Vector &v) const;
		bool operator==(const Vector &v) const;
		Vector operator^(const Vector &v) const;
		
		// friends
		friend Vector operator*(const real val, const Vector &v);
		friend std::ostream & operator <<(std::ostream &os, const Vector &v);
		
		// Now class functions
		Vector minus() const;
		real mag() const;
		Vector norm() const;
		real dot(const Vector &v) const;
		Vector cross(const Vector &v) const;
		Vector rotatex(real angle) const;
		Vector rotatey(real angle) const;
		Vector rotatez(real angle) const;
        std::string toString();
		Vector rotateAxis(Vector axis, real angle);
        VectorH cstub();
		
    };
}
#endif
#endif

