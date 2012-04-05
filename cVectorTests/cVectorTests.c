//
//  main.c
//  cVectorTests
//
//  Created by Muff Darren on 03/04/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MVector.h"
#define PI 3.1415927

int main (int argc, const char * argv[])
{
    printf("Hello, World!\n");
    printf("\n    MVector Version %d Test Harness\n\n",MVECTOR_VERSION_NUM);
    
    VectorH a;
    VectorH b;
    VectorH c;
    VectorH ans;
    double dans;
    
    a = vectCreate(1,2,3);
    b = vectCreate(4,5,6);
    if(vectEquals(a, a)){
        printf("vectEquals: Test passed\n");
    }else{
        printf("vectEquals: Test Failed\n");
        exit(0);
    }
    
    if(vectNotEqual(a, b)){
        printf("vectNotEqual: Test passed\n");
    }else{
        printf("vectNotEqual: Test Failed\n");
        exit(0);
    }
       
    c = vectAdd(a, b);
    ans = vectCreate(5, 7, 9);
    if(vectEquals(c, ans)){
        printf("vectEquals: Test passed\n");
    }else{
        printf("vectEquals: Test Failed\n");
        exit(0);
    }

    ans = vectCreate(11, 12, 13);
    c = vectAddScaler(a, 10);
    if(vectEquals(c, ans)){
        printf("vectAddScaler: Test passed\n");
    }else{
        printf("vectAddScaler: Test Failed\n");
        exit(0);
    }
    
    ans = vectCreate(3, 3, 3);
    c = vectSub(b, a);
    if(vectEquals(c, ans)){
        printf("vectSub: Test passed\n");
    }else{
        printf("vectSub: Test Failed\n");
        exit(0);
    }
    
    ans = vectCreate(2, 3, 4);
    c = vectSubScaler(b, 2);
    if(vectEquals(c, ans)){
        printf("vectSubScaler: Test passed\n");
    }else{
        printf("vectSubScaler: Test Failed\n");
        exit(0);
    }
    
    ans = vectCreate(8, 10, 12);
    c = vectMult(b, 2);
    if(vectEquals(c, ans)){
        printf("vectMult: Test passed\n");
    }else{
        printf("vectMult: Test Failed\n");
        exit(0);
    }
    
    ans = vectDiv(ans, 2);
    if(vectEquals(b, ans)){
        printf("vectDiv: Test passed\n");
    }else{
        printf("vectDiv: Test Failed\n");
        exit(0);
    }
    
    ans = vectCreate(-1, -2, -3);
    c = vectMinus(a);
    if(vectEquals(c, ans)){
        printf("vectMinus: Test passed\n");
    }else{
        printf("vectMinus: Test Failed\n");
        exit(0);
    }
    
    dans = sqrt(4*4+5*5+6*6);
    if ( vectMag(b) == dans){
        printf("vectMag: Test passed\n");
    }else{
        printf("vectMag: Test Failed\n");
        exit(0);
    }

    ans = vectDiv(b, dans);
    c = vectNorm(b);
    if(vectEquals(c,ans)){
        printf("vectNorm: Test passed\n");
    }else{
        printf("vectNorm: Test Failed\n");
        exit(0);
    }
    
    dans = b.x*a.x + a.y*b.y + a.z*b.z;
    if(vectDot(a, b) == dans){
        printf("vectDot: Test passed\n");
    }else{
        printf("vectDot: Test Failed\n");
        exit(0);
    }
    
    a=vectCreate(1, 0, 0);
    b=vectCreate(0, 1, 0);
    ans = vectCreate(0, 0, 1);
    c = vectCross(a, b);
    if(vectEquals(c, ans)){
        printf("vectCross: Test passed\n");
    }else{
        printf("vectCross: Test Failed\n");
        exit(0);
    }
    
    c = vectRotatex(ans, -1*PI/2);
    if(vectEquals(c, b)){
        printf("vectRotatex: Test passed\n");
    }else{
        printf("vectRotatex: Test Failed\n");
        exit(0);
    }    
    
    ans = vectCreate(0, 0, 1);
    c = vectRotatey(a, -PI/2);
    if(vectEquals(c, ans)){
        printf("vectRotatey: Test passed\n");
    }else{
        printf("vectRotatey: Test Failed\n");
        exit(0);
    } 
    
    c = vectRotatez(a, PI/2);
    if(vectEquals(c, b)){
        printf("vectRotatez: Test passed\n");
    }else{
        printf("vectRotatez: Test Failed\n");
        exit(0);
    } 
    
    c = vectRotateAxis(a, ans, PI/2);
    if(vectEquals(c, b)){
        printf("vectRotateAxis: Test passed\n");
    }else{
        printf("vectRotateAxis: Test Failed\n");
        exit(0);
    } 
    
    return 0;
}

