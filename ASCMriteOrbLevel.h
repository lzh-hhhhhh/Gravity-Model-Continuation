//
//  ASCMriteOrbLevel.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCMriteOrbLevel_h
#define ASCMriteOrbLevel_h

#include <stdio.h>
#include <math.h>
#include "ASCMrk4.h"

struct WRI1{
    double zuihou[6];
};
struct WRI1 ASCMwriteOrbLevel(double R0[], double V0[],  double dt, double U, double g[], double RM[], double T,double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]) ;
#endif /* ASCMriteOrbLevel_h */
