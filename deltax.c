//
//  deltax(.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "deltax.h"
struct DELTAX deltax(double V[], double R[], double T, double Rref[], double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]) {

   // printf("deltax能进");
    struct DELTAX result;
    double Y[6];
    double Yr[3];
  //  double RR[3];
    //printf("第一次 ");
    //printf("\n");
     double inicon1[3] = {V[0] + 0.000001, V[1], V[2]};
     double inicon2[3] ={V[0], V[1] + 0.000001, V[2]};
     double inicon3[3] ={V[0], V[1] , V[2]+ 0.000001};
     double V0[3]={V[0] , V[1], V[2]};
       double R1[3]={R[0] , R[1], R[2]}; 
          double R2[3]={R[0] , R[1], R[2]};     
           double R3[3]={R[0] , R[1], R[2]}; 
    struct ASCMhuaraodongResult ascmhua=ASCMhuaraodong(V, T, R, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
     // for (int i = 0; i < 6; i++)
    //{
       //printf("%f ", ascmhua.Y[i]);
    //}
   // printf("\n");
    for(int j = 0; j < 6; j++) {
       Y[j] = ascmhua.Y[j];
    }
 
      for(int j = 0; j < 3; j++) {
        Yr[j] =Y[j];
    }
    double Rr[3] = {Rref[0], Rref[1], Rref[2]};
    double pax[3][3];
    double Y1[6];
    double Y1r[3];
   // for (int i = 0; i < 3; i++)
   // {
     //   printf("%f ", R1[i]);
   // }
   // printf("\n");
 //printf("第二次 ");
    //}
    //printf("\n");
   
    
    //for (int i = 0; i < 3; i++)
   // {
    //    printf("%f ", inicon1[i]);
    //}
   struct ASCMhuaraodongResult ascmhua1=ASCMhuaraodong(inicon1, T, R1, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
    for(int j = 0; j < 6; j++) {
        Y1[j] = ascmhua1.Y[j];
    }

      for(int j = 0; j < 3; j++) {
        Y1r[j] =Y1[j];
    }
    for(int i = 0; i < 3; i++) {
        pax[i][0] = (Y1r[i] - Yr[i]) / 0.000001;
    }

  
   struct ASCMhuaraodongResult ascmhua2=ASCMhuaraodong(inicon2, T, R2, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
   //for (int i = 0; i < 6; i++)
   // {
   //     printf("%f ", ascmhua2.Y[i]);
   // }
   // printf("\n");
   for(int j = 0; j < 6; j++) {
        Y1[j] = ascmhua2.Y[j];
    }

      for(int j = 0; j < 3; j++) {
        Y1r[j] =Y1[j];
    }
  
    for(int i = 0; i < 3; i++) {
        pax[i][1] = (Y1r[i] - Yr[i]) / 0.000001;
    }

   struct ASCMhuaraodongResult ascmhua3=ASCMhuaraodong(inicon3, T, R3, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
// for (int i = 0; i < 6; i++)
  // {
    //   printf("%f ", ascmhua3.Y[i]);
  // }
    //printf("\n");
    for(int j = 0; j < 6; j++) {
        Y1[j] = ascmhua3.Y[j];
    }
//Y1[0]=13570.004795;
//Y1[1]=-1594.376744;
//Y1[2]=3564.060544;
      for(int j = 0; j < 3; j++) {
        Y1r[j] =Y1[j];
    }
    for(int i = 0; i < 3; i++) {
        pax[i][2] = (Y1r[i] - Yr[i]) / 0.000001;
    }

  //for (int i = 0; i < 3; i++)
   // {
     //  printf("%f ", pax[i][0]);
     //  printf("%f ", pax[i][1]); printf("%f ", pax[i][2]); printf("\n");

  // }
    double P[3][3];
    struct INV inva=inv(pax[0][0],pax[0][1],pax[0][2],pax[1][0],pax[1][1],pax[1][2],pax[2][0],pax[2][1],pax[2][2]);
    for (int i = 0; i < 3; i++) {
         P[0][i]=inva.invf[0][i];
         P[1][i]=inva.invf[1][i];
         P[2][i]=inva.invf[2][i];
    }
   // for (int i = 0; i < 3; i++)
   // {
    //   printf("%f ", P[i][0]);
    //   printf("%f ", P[i][1]); printf("%f ", P[i][2]); printf("\n");
   //}
    double deltaV1[3];
    for(int i = 0; i < 3; i++) {
        deltaV1[i] = P[i][0] * (Rr[0] - Yr[0]) + P[i][1] * (Rr[1] - Yr[1]) + P[i][2] * (Rr[2] - Yr[2]);
    }

    for(int i = 0; i < 3; i++) {
        result.V0ext[i] = V0[i] + 0.1*deltaV1[i];
    }
    return result;
}

