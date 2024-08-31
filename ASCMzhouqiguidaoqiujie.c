//
//  ASCMzhouqiguidaoqiujie.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "ASCMzhouqiguidaoqiujie.h"


struct ZhouQiResult1 ASCMzhouqiguidaoqiujie(double R0[], double V0[], double U, double g[], double RM[], double T,double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4])
{
    struct ZhouQiResult1 result;
    int dt = 200;
  // printf("zhouqi能进");
    //printf("%f, %f, %f\n", y[3], y[4], y[5]);
    struct CONTIN1 con= ASCMcontinuation(R0,V0,dt, U, g, RM, T, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);

     for (int i = 0; i < 5; i++) {
         result.zuihou[i] = con.zuihou[i] ;
     }

    return result;
}

