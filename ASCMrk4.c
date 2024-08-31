//
//  ASCMrk4.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "ASCMrk4.h"
struct RK1 ASCMrk4(double R0[], double V0[],  double dt, double U, double g[], double RM[], double T,double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4])
{
    struct RK1 result;
    double x[6];
    int j=1;
    double cha = 0;
    char FileName[50];
    double r[3];
    int p;
    double t;
    double xc[3], vc[3];
    double  U_lap =0;
   
  //  printf("rk4能进");
  //  printf("%f, %f, %f\n", g[0], g[1], g[2]);
  //  for(int i = 0; i < 6; i++)
 //   {
 //       x[i] = y[i];
  //  }
 FILE *fileID;
    
    sprintf(FileName, "%f",Ext);
   fileID = fopen(FileName, "a");

    p = T / dt+1;
//printf("%d ", p);
// printf("\n");

   while(j < p)
    {
        //printf("%d ", j);
        
          //  for (int i = 0; i < 6; i++)
          //  {
          //      printf("%f ",  y[i]);
          //}
         //   printf("\n");
        struct RKST1 rkst=ASCMrk4step(R0,V0, dt,U, g);
        r[0] = rkst.y[0];
        r[1] = rkst.y[1];
        r[2] = rkst.y[2];
    char FileName[100];
    int i = 0;
   t=j*dt;
 fprintf(fileID, "%f %f %f %f %f %f %f\n", t, r[0], r[1], r[2],rkst.y[3],rkst.y[4],rkst.y[5]);
    
        struct ASCMgravity gra=ASCMgravity(r, Ext,p_data,f_data,e_data,len_data,ne_data,nf_data);
        U=gra.u;
    
        g[0]=gra.g[0];
        g[1]=gra.g[1];
        g[2]=gra.g[2];
        
            for (int i = 0; i < 3; i++)
            {
                R0[i] =rkst.y[i];
                result.zuihou[i]=rkst.y[i];
            }
            for (int i = 0; i < 3; i++)
            {
                V0[i] =rkst.y[i+3];
              result.zuihou[i+3]= V0[i];
            }
            

               j=j+1;
    }
fclose(fileID);
    return result;
}
