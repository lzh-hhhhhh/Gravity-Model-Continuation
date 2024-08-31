//
//  ASCMorbequ.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCMorbequ_h
#define ASCMorbequ_h

//#include "cross.h"
#include <stdio.h>
#include <math.h>
struct ORB1{
    double yp[6];
};
struct ORB1 ASCMorbequ(double y[], double g[]);

#endif /* ASCMorbequ_h */
