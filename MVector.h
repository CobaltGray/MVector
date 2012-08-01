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
#ifndef REAL
#define REAL double
#endif
#ifndef EPSILON
#define EPSILON 0.0000001
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
#define VECT_UNIT(a,out) {REAL vect_unit_tmp = VECT_MOD(a); out.x = a.x/vect_unit_tmp; out.y = a.y/vect_unit_tmp; out.z = a.z/vect_unit_tmp;}
#define VECT_PROJ(vect, norm, out) {SPVector tmp; REAL dot = VECT_DOT(vect, norm); tmp.x = vect.x - dot*norm.x; tmp.y = vect.y - dot*norm.y; tmp.z = vect.z - dot*norm.z; VECT_UNIT(tmp, out);}  
// Deprecated SPVector used in MTLib. Use VectorH as a the C stub.

typedef union {
    struct { REAL x, y, z; };
    struct { REAL r, g, b; };
    struct { REAL cell[3]; };
    struct { REAL R, theta, phi; };
    struct { REAL lat, lon, alt; };

}SPVector;

/*typedef struct {           
    REAL x;
    REAL y;
    REAL z;
} SPVector;*/

#endif

// Use VectorH as C stub for C++ vector functions
typedef SPVector VectorH;

// Define C stubs for C++ Vector functions here. Dont forget 
// to extern them only to the c++ compiler to remove c++ name
// mangling caused by ability to overload functions
#ifdef __cplusplus
extern "C" {
#endif
    VectorH vectCreate(REAL a, REAL b, REAL c);
    int vectEquals(VectorH v1, VectorH v2);
    int vectNotEqual(VectorH v1, VectorH v2);
    VectorH vectAdd(VectorH v1, VectorH v2);
    VectorH vectAddScaler(VectorH v1, REAL scaler);
    VectorH vectSub(VectorH v1, VectorH v2);
    VectorH vectSubScaler(VectorH v1, REAL scaler);
    VectorH vectMult(VectorH v1, REAL scaler);
    VectorH vectDiv(VectorH v1, REAL scaler);
    VectorH vectMinus(VectorH v);
    REAL vectMag(VectorH v);
    VectorH vectNorm(VectorH v);
    REAL vectDot(VectorH v1, VectorH v2);
    VectorH vectCross(VectorH v1, VectorH v2);
    VectorH vectRotatex(VectorH v, REAL angle);
    VectorH vectRotatey(VectorH v, REAL angle);
    VectorH vectRotatez(VectorH v, REAL angle);
    VectorH vectRotateAxis(VectorH v, VectorH axis, REAL angle);
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
            struct { REAL x, y, z; };
            struct { REAL r, g, b; };
            struct { REAL cell[3]; };
            struct { REAL R, theta, phi; };
            struct { REAL lat, lon, alt; };
        };
		
        Vector() : x( 0.0f), y(0.0f), z(0.0f) {};
		Vector(REAL a, REAL b, REAL c) : x(a), y(b), z(c) {};
        Vector(VectorH v) : x(v.x), y(v.y), z(v.z){};
        void Set( REAL a, REAL b, REAL c ) { x = a; y = b; z = c; }
        REAL Length() const { return (REAL)sqrt( x * x + y * y + z * z ); }
        REAL mag() const {return Length(); };
        void Normalise() { REAL l = 1.0f / Length(); x *= l; y *= l; z *= l; }
        Vector norm() const { REAL l = 1.0f / Length(); return Vector (x*l, y*l, z*l); }
        REAL SqrLength() { return x * x + y * y + z * z; }
        REAL dot(const Vector &v) const {return(v.x*x + v.y*y + v.z*z);}
        REAL Dot(const Vector &v) const {return(v.x*x + v.y*y + v.z*z);}
        Vector cross(const Vector &v) const { return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); }
        Vector Cross(const Vector &v) const { return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); }
        void Negate() { x *= -1; y *= -1; z *= -1; }
        Vector Minus() const {return Vector(-x, -y, -z); }
        Vector minus() const {return Vector(-x, -y, -z); }
        void operator += ( Vector& a_V ) { x += a_V.x; y += a_V.y; z += a_V.z; }
        void operator += ( Vector* a_V ) { x += a_V->x; y += a_V->y; z += a_V->z; }
        void operator -= ( Vector& a_V ) { x -= a_V.x; y -= a_V.y; z -= a_V.z; }
        void operator -= ( Vector* a_V ) { x -= a_V->x; y -= a_V->y; z -= a_V->z; }
        void operator *= ( REAL f ) { x *= f; y *= f; z *= f; }
        void operator *= ( Vector& a_V ) { x *= a_V.x; y *= a_V.y; z *= a_V.z; }
        void operator *= ( Vector* a_V ) { x *= a_V->x; y *= a_V->y; z *= a_V->z; }
        Vector operator- () const { return Vector( -x, -y, -z ); }
        friend Vector operator + ( const Vector& v1, const Vector& v2 ) { return Vector( v1.x + v2.x, v1.y + v2.y, v1.z + v2.z ); }
        friend Vector operator + ( const Vector& v1, Vector* v2 ) { return Vector( v1.x + v2->x, v1.y + v2->y, v1.z + v2->z ); }
        friend Vector operator + ( const Vector& v1, REAL f ) { return Vector(v1.x+f, v1.y+f, v1.z+f); }
        friend Vector operator - ( const Vector& v1, const Vector& v2 ) { return Vector( v1.x - v2.x, v1.y - v2.y, v1.z - v2.z ); }
        friend Vector operator - ( const Vector& v1, Vector* v2 ) { return Vector( v1.x - v2->x, v1.y - v2->y, v1.z - v2->z ); }
        friend Vector operator - ( const Vector& v1, REAL f ) { return Vector(v1.x-f, v1.y-f, v1.z-f); }
        friend Vector operator * ( const Vector& v, REAL f ) { return Vector( v.x * f, v.y * f, v.z * f ); }
        friend Vector operator * ( const Vector& v1, Vector& v2 ) { return Vector( v1.x * v2.x, v1.y * v2.y, v1.z * v2.z ); }
        friend Vector operator * ( REAL f, const Vector& v ) { return Vector( v.x * f, v.y * f, v.z * f ); }
        friend Vector operator / ( const Vector& v, REAL f ) { return Vector( v.x / f, v.y / f, v.z / f ); }
        friend bool operator != ( const Vector& v1, const Vector& v2 ) { return (fabs(v1.x-v2.x)>EPSILON||fabs(v1.y-v2.y)>EPSILON||fabs(v1.z-v2.z)>EPSILON); }
        friend bool operator == ( const Vector& v1, const Vector& v2 ) { return !(fabs(v1.x-v2.x)>EPSILON||fabs(v1.y-v2.y)>EPSILON||fabs(v1.z-v2.z)>EPSILON); }
        friend Vector operator ^ ( const Vector& v1, const Vector&v2 ) { return Vector(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x); }
        friend std::ostream & operator << (std::ostream &os, const Vector &v) { os << "[" << v.x << "," << v.y << "," << v.z << "]"; return(os); }
        Vector rotatex(REAL a) const { REAL c = cos(a); REAL s = sin(a); return Vector(x,y*c - z*s, s*y + c*z); }
        Vector RotateX(REAL a) const { REAL c = cos(a); REAL s = sin(a); return Vector(x,y*c - z*s, s*y + c*z); }
        Vector rotatey(REAL a) const { REAL c = cos(a); REAL s = sin(a); return Vector(c*x+s*z, y, c*z - x*s); }
        Vector RotateY(REAL a) const { REAL c = cos(a); REAL s = sin(a); return Vector(c*x+s*z, y, c*z - x*s); }
        Vector rotatez(REAL angle) const { REAL c = cos(angle); REAL s = sin(angle); return Vector(c*x-s*y, s*x+c*y, z); }
        Vector RotateZ(REAL angle) const { REAL c = cos(angle); REAL s = sin(angle); return Vector(c*x-s*y, s*x+c*y, z); }
        VectorH cstub(){VectorH ans; VECT_CREATE(x, y, z, ans); return(ans); }
        
        
        /* Rotate this mvector about the vector axis by an amount theta */
        /* the rotation Axis is assumed to be a direction from the origin */
        /* ie this vector has already been translated */
        Vector rotateAxis(Vector axis, REAL theta){
            Vector ans;
            if(axis.x == 0 && axis.y == 0 ){
                ans = rotatez(theta);
            }else if(axis.x == 0 && axis.z == 0){
                ans = rotatey(theta);
            }else if(axis.y == 0 && axis.z == 0){
                ans = rotatex(theta);
            }else{
                REAL thetaz = atan(axis.y/axis.x);
                REAL thetay = atan( sqrt( (axis.x * axis.x) + (axis.y * axis.y)) / axis.z );
                
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
        
        std::string toString(){
            std::string s;
            {
                std::ostringstream ss;
                ss.precision(9);
                ss << "[" << x << "," << y << "," << z << "]";
                s = ss.str();
            }
            return(s);
        }

        //std::string toString();
		//Vector rotateAxis(Vector axis, real angle);
		
    };
}
#endif
#endif

