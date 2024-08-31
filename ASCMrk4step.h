//
//  ASCMrk4step.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCMrk4step_h
#define ASCMrk4step_h

#include <stdio.h>
#include <math.h>
#include "ASCMorbequ.h"
struct RKST1{
    double y[6];
};
struct RKST1 ASCMrk4step(double R0[], double V0[],double dt, double U, double g[]) ;
#endif /* ASCMrk4step_h */
