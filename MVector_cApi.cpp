/***************************************************************************
 *
 * Copyright Crown (c) 2012. All rights reserved.
 *
 * Module: MVector_cApi.cpp
 *
 * Description: Mathmatical Vector code cstubs so that class functions can 
 *              be called by c.
 *
 * Original Author: Darren Muff
 * 					(Ported from a JAVA module written by Matt Nottingham)
 * 					(original code written in MATLAB by Ralph Fiedler)
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



#include <iostream>
#include "MVector.h"
using namespace MVector;

extern "C" {
    
    VectorH vectCreate(REAL a, REAL b, REAL c){
        MVector::Vector v(a,b,c);
        return(v.cstub());
    }
    
    int vectEquals(VectorH a, VectorH b){
        MVector::Vector A(a);
        MVector::Vector B(b);
        if(A==B)return(1);
        else return (0);
    }
    
    int vectNotEqual(VectorH a, VectorH b){
        MVector::Vector A(a);
        MVector::Vector B(b);
        if(A!=B)return(1);
        else return(0);
    }
    
    VectorH vectAdd(VectorH a, VectorH b){
        MVector::Vector A(a);
        MVector::Vector B(b);
        return ((A+B).cstub());
    }
    
    VectorH vectAddScaler(VectorH a, REAL b){
        MVector::Vector A(a);
        return ((A+b).cstub());
    }
    
    VectorH vectSub(VectorH a, VectorH b){
        MVector::Vector A(a);
        MVector::Vector B(b);
        return ((A-B).cstub());
    }
    
    VectorH vectSubScaler(VectorH a, REAL b){
        MVector::Vector A(a);
        return ((A-b).cstub());
    }
    
    VectorH vectMult(VectorH v, REAL sc){
        MVector::Vector a(v);
        return ((a*sc).cstub());
    }

    VectorH vectDiv(VectorH v, REAL sc){
        MVector::Vector a(v);
        return((a/sc).cstub());
    }
    
    VectorH vectMinus(VectorH v){
        MVector::Vector a(v);
        return(a.minus().cstub());
    }
    
    REAL vectMag(VectorH v){
        MVector::Vector a(v);
        return (a.mag());
    } 
    
    VectorH vectNorm(VectorH v){
        MVector::Vector a(v);
        return(a.norm().cstub());
    }
    
    REAL vectDot(VectorH a, VectorH b){
        MVector::Vector va(a);
        MVector::Vector vb(b);
        return(va.dot(vb));
    }
    
    VectorH vectCross(VectorH a, VectorH b){
        MVector::Vector va(a);
        MVector::Vector vb(b);
        return ((va^vb).cstub());
    }
    
    VectorH vectRotatex(VectorH v, REAL angle){
        MVector::Vector a(v);
        return(a.rotatex(angle).cstub());
    }
    
    VectorH vectRotatey(VectorH v, REAL angle){
        MVector::Vector a(v);
        return(a.rotatey(angle).cstub());
    }
    
    VectorH vectRotatez(VectorH v, REAL angle){
        MVector::Vector a(v);
        return(a.rotatez(angle).cstub());
    }
    
    VectorH vectRotateAxis(VectorH v, VectorH axis, REAL angle){
        MVector::Vector a(v);
        MVector::Vector ax(axis);
        return(a.rotateAxis(ax, angle).cstub());
    }
    
}

