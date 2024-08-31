//
//  tuoqiugravity.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef tuoqiugravity_h
#define tuoqiugravity_h

#include <stdio.h>
#include<math.h>

struct GravityResult{
    double u;
    double g[3];
} ;

struct GravityResult tuoqiugravity(double r[])  ;
double calculateU(double* r, double a, double b, double c, double m, double G) ;
#endif /* tuoqiugravity_h */
