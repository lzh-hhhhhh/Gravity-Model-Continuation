//
//  ASCMriteOrbLevel.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "ASCMriteOrbLevel.h"
struct WRI1 ASCMwriteOrbLevel(double R0[], double V0[], double dt, double U, double g[], double RM[], double T,double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]) {
   
    struct WRI1 result;
   //printf("writ能进");
 // printf("%f, %f, %f\n", g[0], g[1], g[2]);
    struct RK1 rk= ASCMrk4(R0,V0, dt, U, g, RM, T, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
    for (int i = 0; i < 5; i++) {
        result.zuihou[i] = rk.zuihou[i] ;
    }
    return result;
}
