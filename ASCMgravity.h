//
//  ASCMgravity.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCMgravity_h
#define ASCMgravity_h

#include <stdio.h>
#include <math.h>
#include "astgravity_preload.h"
#include "tuoqiugravity.h"
struct ASCMgravity  {
    double g[3];
    double u;

} ;
struct ASCMgravity ASCMgravity(double r[],double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]);
#endif /* ASCMgravity_h */
