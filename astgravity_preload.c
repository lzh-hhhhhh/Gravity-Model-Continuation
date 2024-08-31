//
//  astgravity_preload.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "astgravity_preload.h"


struct ASGR astgravity_preload(double fp[],char* filename,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4])
 {
    struct ASGR result;
 //  printf("astgra能进来");
    int N_p=5078;
    int N_f=10152;
    int N_e=15228;
    //double center={-315.20048,-105.18787,90.18953} ;


    

    
    
     // 引力常数
     //printf("能到这里吧！");
    int sigma = 2670;
    // printf("能到这里吧2");
    float tmp5[N_p][3];
     //printf("能到这里吧3");
    float fp_data[N_p][4];
    //printf("能到这里吧！");
    for (int i = 0; i < N_p; i++) 
    {
        tmp5[i][0] = p_data[i][1] - fp[0];
        tmp5[i][1] = p_data[i][2] - fp[1];
        tmp5[i][2] = p_data[i][3] - fp[2];
        
        fp_data[i][0] = tmp5[i][0];
        fp_data[i][1] = tmp5[i][1];
        fp_data[i][2] = tmp5[i][2];
        fp_data[i][3] = sqrt(tmp5[i][0] * tmp5[i][0] + tmp5[i][1] * tmp5[i][1] + tmp5[i][2] * tmp5[i][2]);
    }

   //for (int i = 0; i < N_p; i++)
// {
// printf("fp最终算为：");
// printf( "%f %f %f %f ", fp_data[i][0], fp_data[i][1],fp_data[i][2], fp_data[i][3]);
// printf("\n");
//}
    // printf("能到这里吧4！");
    float omegaf[N_f]; // 记录每一个三角形单元对应的立体角
    float Frof[N_f][3];

     //printf("能到这里吧4！");
    float U2 = 0.0; // 势能
    //float dF2[3][3]; // 引力梯度

// 初始化数组
    for (int i = 0; i < N_f; i++)
    {
    omegaf[i] = 0;
    Frof[i][0] = 0;
    Frof[i][1] = 0;
    Frof[i][2] = 0;
    }

   //printf("能到这里吧5！");
    for (int i = 0; i < N_f; i++)
     {
   float tmp6[3][4];
    tmp6[0][0] = fp_data[f_data[i][1]-1][0];
    tmp6[0][1] = fp_data[f_data[i][1]-1][1];
    tmp6[0][2] = fp_data[f_data[i][1]-1][2];
    tmp6[0][3] = fp_data[f_data[i][1]-1][3];
    tmp6[1][0] = fp_data[f_data[i][2]-1][0];
    tmp6[1][1] = fp_data[f_data[i][2]-1][1];
    tmp6[1][2] = fp_data[f_data[i][2]-1][2];
    tmp6[1][3] = fp_data[f_data[i][2]-1][3];
    tmp6[2][0] = fp_data[f_data[i][3]-1][0];
    tmp6[2][1] = fp_data[f_data[i][3]-1][1];
    tmp6[2][2] = fp_data[f_data[i][3]-1][2];
    tmp6[2][3] = fp_data[f_data[i][3]-1][3];
    
    //没问题printf("r最终算为：");
   //printf( "%f %f %f ", tmp6[0][0] , tmp6[0][1]  ,tmp6[0][2]);
   // printf("\n");
    float r[3][3];
    r[0][0] = tmp6[0][0] / tmp6[0][3];
    r[0][1] = tmp6[0][1] / tmp6[0][3];
    r[0][2] = tmp6[0][2] / tmp6[0][3];
    r[1][0] = tmp6[1][0] / tmp6[1][3];
    r[1][1] = tmp6[1][1] / tmp6[1][3];
    r[1][2] = tmp6[1][2] / tmp6[1][3];
    r[2][0] = tmp6[2][0] / tmp6[2][3];
    r[2][1] = tmp6[2][1] / tmp6[2][3];
    r[2][2] = tmp6[2][2] / tmp6[2][3];

    omegaf[i] = 2 * atan2((r[1][0] * r[2][1] - r[1][1] * r[2][0]) * r[0][2] + (r[1][2] * r[2][0] - r[1][0] * r[2][2]) * r[0][1] + (r[1][1] * r[2][2] - r[1][2] * r[2][1]) * r[0][0], 1 + r[0][0] * r[1][0] + r[0][1] * r[1][1] + r[0][2] * r[1][2] + r[0][0] * r[2][0] + r[0][1] * r[2][1] + r[0][2] * r[2][2] + r[1][0] * r[2][0] + r[1][1] * r[2][1] + r[1][2] * r[2][2]);
   
    if (isfinite(omegaf[i])) 
    {
        omegaf[i] = omegaf[i];
    } else {
        omegaf[i] = 0;
    }
    float rf[3];
    rf[0] = tmp6[0][0];
    rf[1] = tmp6[0][1];
    rf[2] = tmp6[0][2];
    
    Frof[i][0] = (nf_data[i][1] * nf_data[i][1] * rf[0]) + (nf_data[i][1] * nf_data[i][2] * rf[1]) + (nf_data[i][1] * nf_data[i][3] * rf[2]);
    Frof[i][1] = (nf_data[i][2] * nf_data[i][1] * rf[0]) + (nf_data[i][2] * nf_data[i][2] * rf[1]) + (nf_data[i][2] * nf_data[i][3] * rf[2]);
    Frof[i][2] = (nf_data[i][3] * nf_data[i][1] * rf[0]) + (nf_data[i][3] * nf_data[i][2] * rf[1]) + (nf_data[i][3] * nf_data[i][3] * rf[2]);
    
    Frof[i][0] = Frof[i][0] * omegaf[i];
    Frof[i][1] = Frof[i][1] * omegaf[i];
    Frof[i][2] = Frof[i][2] * omegaf[i];
    
     //  printf("frof最终算为：");
  // printf( "%f %f %f ",Frof[i][0] ,Frof[i][1] ,Frof[i][2]);
   //printf("\n");
    U2 = U2 +rf[0]* Frof[i][0]+rf[1]* Frof[i][1]+rf[2]* Frof[i][2];
   // if (i > 0) {
   //     omegaf[i] = omegaf[i] + omegaf[i - 1];
   // }
 
   //printf( "%f ", omegaf[i]);
   // printf("\n");
}
//printf("u2最终算为：");
 //printf("%f",U2);
float F2[3] = {0, 0, 0};
for (int i = 0; i < N_f; i++) {
    F2[0] += Frof[i][0];
    F2[1] += Frof[i][1];
    F2[2] += Frof[i][2];
  
}
//printf("能到这里吧6");
float ErLe[N_e][3];
float U1 = 0.0;
//float dF1[3][3] = {0.0};

for (int i = 0; i < N_e; i++) 
{
    float tmp6[2] = { fp_data[e_data[i][1]-1][3], fp_data[e_data[i][2]-1][3] };

    int a=ne_data[i][1];
    int b=ne_data[i][5];
    float Le = log((tmp6[0] + tmp6[1] + len_data[i][1]) / (tmp6[0]+tmp6[1]  - len_data[i][1]));
    if (isfinite(Le))
    {
        Le = Le;
    }
     else
     {
        Le = 0;
    }
   // printf( "%f ",Le);
   //printf("\n");
        float re[3] = { fp_data[e_data[i][1]-1][0], fp_data[e_data[i][1]-1][1], fp_data[e_data[i][1]-1][2] };
       // printf("re最终算为：");
   // printf( "%f %f %f", re[0] ,re[1] ,re[2] );
  // printf("\n");
        float tmp_E[3][3] ;
        tmp_E[0][0] = nf_data[a-1][1] * ne_data[i][2] + nf_data[b-1][1] * ne_data[i][6];
        tmp_E[0][1] = nf_data[a-1][1] * ne_data[i][3] + nf_data[b-1][1] * ne_data[i][7];
        tmp_E[0][2] = nf_data[a-1][1] * ne_data[i][4] + nf_data[b-1][1] * ne_data[i][8];
        tmp_E[1][0] = nf_data[a-1][2] * ne_data[i][2] + nf_data[b-1][2] * ne_data[i][6];
        tmp_E[1][1] = nf_data[a-1][2] * ne_data[i][3] + nf_data[b-1][2] * ne_data[i][7];
        tmp_E[1][2] = nf_data[a-1][2] * ne_data[i][4] + nf_data[b-1][2] * ne_data[i][8];
        tmp_E[2][0] = nf_data[a-1][3] * ne_data[i][2] + nf_data[b-1][3] * ne_data[i][6];
        tmp_E[2][1] = nf_data[a-1][3] * ne_data[i][3] + nf_data[b-1][3] * ne_data[i][7];
        tmp_E[2][2] = nf_data[a-1][3] * ne_data[i][4] + nf_data[b-1][3] * ne_data[i][8];
          
      
      
        ErLe[i][0] = (tmp_E[0][0] * re[0] + tmp_E[0][1] * re[1] + tmp_E[0][2] * re[2]) * Le;
        ErLe[i][1] = (tmp_E[1][0] * re[0] + tmp_E[1][1] * re[1] + tmp_E[1][2] * re[2]) * Le;
        ErLe[i][2] = (tmp_E[2][0] * re[0] + tmp_E[2][1] * re[1] + tmp_E[2][2] * re[2]) * Le;

        U1 += ErLe[i][0]*re[0]+ ErLe[i][1]*re[1]+ ErLe[i][2]*re[2];
    
    
}
//printf("u1最终算为：");
 //printf("%f",U1);

//printf("能到这里吧8");
    float F1[3] = {0, 0, 0};
    for (int i = 0; i < N_e; i++) {
    F1[0] += ErLe[i][0];
    F1[1] += ErLe[i][1];
    F1[2] += ErLe[i][2];
}
   // printf("re最终算为：");
   // printf( "%f %f %f",F1[0] ,F1[1] ,F1[2] );
   // printf("\n");
    double G = 6.67428e-11;
    result.U = -0.5 * G * sigma * (U1 - U2);
//printf("u最终算为：");
// printf("%f",result.U);
    result.g[0]= -G * sigma * (F1[0] - F2[0]);
    result.g[1]= -G * sigma * (F1[1] - F2[1]);
    result.g[2]=  -G * sigma * (F1[2] - F2[2]);
     //printf("re最终算为：");
   //printf( "%f %f %f",result.g[0] ,result.g[1] ,result.g[2]);
  // printf("\n");
    return result;
}
    



