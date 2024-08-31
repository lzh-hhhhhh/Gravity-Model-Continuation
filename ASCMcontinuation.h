//
//  ASCMcontinuation.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCMcontinuation_h
#define ASCMcontinuation_h

#include <stdio.h>
#include <math.h>
#include "ASCMriteOrbLevel.h"
struct CONTIN1{
    double zuihou[6];
};
struct CONTIN1 ASCMcontinuation(double R0[], double V0[], double dt, double U, double g[], double RM[],  double T, double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]);
#endif /* ASCMcontinuation_h */
