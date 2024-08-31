//
//  ASCM.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "ASCM.h"
 

struct ASCMResult ASCM(double V0[], double R0[], double T, double Rref[],float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]) {
        
    struct ASCMResult result;
    double Ext1 = 0;
    double p = 1;
    int i = 0;
    double dExt[1000];
    double dRref = 0;
    double V0ext[3];
    result.V0ext1[0][0] = V0[0];
    result.V0ext1[0][1] = V0[1];
    result.V0ext1[0][2] = V0[2];
    result.extension[0]=1;
   double RR1[3];
  double RR2[3];
double dR=111110;
   //while (Ext1 < 1) 
    while (dR >15000) 
    {
         RR1[0]=R0[0];
          RR1[1]= R0[1];
           RR1[2]=R0[2];
          RR2[0]=R0[0];
          RR2[1]= R0[1];
           RR2[2]=R0[2];
        
        if (p == -0.5) {
            dExt[i] = p * dExt[i];
        }
        if (p == 1) {
            if (result.extension[i] < 0.8) {
                dExt[i] = 0.05;
                dRref = 1000000000000;
            }
            if (result.extension[i] >= 0.8 && result.extension[i] < 0.9) {
                dExt[i] = 0.05;
                dRref = 2500000000;
            }
            if (result.extension[i] >= 0.9 && result.extension[i] < 0.95) {
                dExt[i] = 0.05;
                dRref = 1000000000;
            }
            if (result.extension[i] >= 0.95 && result.extension[i] < 0.99) {
                dExt[i] = 0.05;
                dRref = 100000000;
            }
             if (result.extension[i] >= 0.99 && result.extension[i] < 1) {
                dExt[i] = 0.0001;
                dRref = 10000009;
            }
             if (result.extension[i] >=1 && result.extension[i] < 9995) {
                dExt[i] = 0.00;
                dRref =  1000000;
            }

        }

       double Ext = result.extension[i] + dExt[i];

       struct DELTAX del = deltax(V0, R0, T, Rref, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);


       for (int j = 0; j < 3; j++)
            {
             V0ext[j] = del.V0ext[j]; 
            }
//
       printf("初速度最终算为：");
      //  for (int i = 0; i < 3; i++) 
       // {
     //     printf("%f ", V0ext[i]);
   // }
   //  printf("\n ");
   

        double Yext[3];
        double YY[6];
        printf("%f, %f, %f\n", V0ext[0], V0ext[1], V0ext[2]);
        struct ASCMhuaraodongResult ascmhua=  ASCMhuaraodong(V0ext, T, RR1, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
        
        for(int j = 0; j < 6; j++) {
            YY[j] = ascmhua.Y[j];
        }

          for(int j = 0; j < 3; j++) {
            Yext[j] =YY[j];
        }
        
        double Rq[3];
        for (int j = 0; j < 3; j++) {
            Rq[j] = Yext[j];
        }
        
        //double dR;
        dR=(Rq[0]-Rref[0])*(Rq[0]-Rref[0])+(Rq[1]-Rref[1])*(Rq[1]-Rref[1])+(Rq[2]-Rref[2])*(Rq[2]-Rref[2]);
          
          for (int i = 0; i < 1; i++) 
        {
          printf("误差平方：");
          printf("%f ", dR);
     printf("\n ");
     }

        if (dR < dRref)
         {
            i = i + 1;
            result.extension[i] = Ext;
            printf("延拓步长：");
            printf("%f ", result.extension[i]);
           printf("\n ");
          //  printf("下一步速度：");
            for (int j = 0; j < 3; j++)
            {
                 V0[j] = del.V0ext[j];
              //    printf("%f ", V0[j]);
            }
            p = 1;
            for (int j = 0; j < 3; j++)
            {
                 result.V0ext1[i][j] = V0ext[j];
            }
            
           
        } 
        else
        {
            p = -0.5;
for (int j = 0; j < 3; j++)
            {
                 V0[j] = del.V0ext[j];
              //    printf("%f ", V0[j]);
            }
        }

        Ext1 = result.extension[i];
        for (int j = 0; j < 3; j++)
            {
                   result.V0extend[j] = result.V0ext1[i][j]; 
            }
        result.DRend=dR;
        result.extend = result.extension[i];
         R0[0]=RR2[0];
      //printf("%f ", R0[0]);
     R0[1]=RR2[1];
     R0[2] =RR2[2];
    }
    for (int j = 0; j < 3; j++)
            {
                    result.V0[j] =V0[j]; 
            }
    return result;
    
}
