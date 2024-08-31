//
//  ASCMhuaraodong.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCMhuaraodong_h
#define ASCMhuaraodong_h

#include <stdio.h>
#include <math.h>
#include "ASCMzhouqiguidaoqiujie.h"
struct ASCMhuaraodongResult  {
    double Y[6];
} ;

struct ASCMhuaraodongResult ASCMhuaraodong(double V0[], double T, double R0[], double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]) ;
#endif /* ASCMhuaraodong_h */
