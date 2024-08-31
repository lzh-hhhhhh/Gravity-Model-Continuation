//
//  astgravity_preload.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef astgravity_preload_h
#define astgravity_preload_h
#include <stdio.h>
#include <math.h>
#include "sort.h"
#include <stdlib.h>
struct ASGR{
    double U;
    double g[3];
};


struct ASGR astgravity_preload(double fp[],char* filename,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]);

#endif /* astgravity_preload_h */
