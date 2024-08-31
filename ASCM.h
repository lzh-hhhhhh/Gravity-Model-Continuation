//
//  ASCM.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef ASCM_h
#define ASCM_h

#include <stdio.h>
#include <math.h>
#include "deltax.h"
#include "ASCMhuaraodong.h"
#include "ASCMcontinuation.h"
#include "ASCMgravity.h"
#include "inv.h"
struct ASCMResult{
    double extend;
    double V0extend[3];
    double V0[3];
    double V0ext1[20][3];
    double extension[20];
    double DRend;
};
struct ASCMResult ASCM(double V0[], double R0[], double T, double Rref[],float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]);
#endif /* ASCM_h */
