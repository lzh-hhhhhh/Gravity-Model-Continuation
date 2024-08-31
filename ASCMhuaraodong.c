//
//  ASCMhuaraodong.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "ASCMhuaraodong.h"
struct ASCMhuaraodongResult ASCMhuaraodong(double V0[], double T, double R0[], double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4])
{
   //printf("huaraodong能进");
    struct ASCMhuaraodongResult result;
    double RM[3] = {R0[0], R0[1], R0[2]};
    double inicon[6] ;
    double g[3], U;

    struct ASCMgravity gra=ASCMgravity(R0, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
        
        U=gra.u;
        g[0]=gra.g[0];
        g[1]=gra.g[1];
        g[2]=gra.g[2];
   // printf("%lf, %lf, %lf\n", V0[0], V0[1], V0[2]);

                double U_lap = 0;
                double zuihou[6];
               //  printf("%f, %f, %f\n", inicon[0], inicon[1], inicon[2]);
                struct ZhouQiResult1 ZH=ASCMzhouqiguidaoqiujie(R0,V0,U,g,RM,T,Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);

                for (int i = 0; i < 6; i++) {
                     zuihou[i]= ZH.zuihou[i];
                }

                for (int i = 0; i < 6; i++) {
                    result.Y[i] = zuihou[i];
                 //    printf("%f", result.Y[i] );
                }
                
    return result;
}
