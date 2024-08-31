//
//  deltax(.h
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#ifndef deltax__h
#define deltax__h

#include <stdio.h>
#include <math.h>
#include "ASCMhuaraodong.h"
#include "inv.h"
struct DELTAX{
    double V0ext[3];
};
struct DELTAX deltax(double V0[], double R0[], double T, double Rref[], double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]);
#endif /* deltax__h */
