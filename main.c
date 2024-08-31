#include "ASCMgravity.h"
#include "ASCM.h"
#include <stdio.h>
int main()
{

    double Vref[3];
    double Rref[3];
    double g[3];
    double U;
    double v0ellpre0[4];
    double extend;
    double valellpre0;
     double V0extend[3];
     FILE* fid1 = fopen("初始速度", "r");
    float v_data[31][3];
    for (int i = 0; i < 31; i++)
    {
        fscanf(fid1, "%f %f %f ", &v_data[i][0], &v_data[i][1], &v_data[i][2]);
       //printf("%f ", v_data[i][1]);
    }
   // printf("文件能读取3");
    fclose(fid1);
     
     FILE* fid2 = fopen("初始位置", "r");
    float ll_data[31][3];
    for (int i = 0; i < 31; i++)
    {
        fscanf(fid2, "%f %f %f ", &ll_data[i][0], &ll_data[i][1], &ll_data[i][2]);
       // printf("%f ", ll_data[i][2]);
    }
   // printf("文件能读取3");
    fclose(fid2);
  double R1[3] = {13428,-1540,3549};//{8302, -8213, 1478};// {13428,-1540,3549};//{9302, -6213, 1478};
  double V1[3] = {-5.66965602600000	,-2.01565780500000	,0.0533106390000000};//{9302, -6213, 1478};
   for (int i = 0; i < 3; i++) {
       // Vref[i] = V0[i];
        Rref[i] = R1[i];
    };
    double T = 4000;
for (int i = 0; i < 1; i++)
{
    double v0ellpre2[3];
    for (int  j = 0; j < 3; j++)
    {
      v0ellpre2[j]=v_data[i][j];
      printf("%f ", v0ellpre2[j]);
    };

    double R0[3];
    for (int  j = 0; j < 3; j++)
    {
      R0[j]=ll_data[i][j];
      printf("%f ", R0[j]);
    };



    //double V0[3];
    // for (int  j = 3; j < 6; j++)
    //{
     // V0[j]=VVV[i][j];
   // };
   
   //struct ASCMgravity ast=ASCMgravity(R0,1);
   // U=ast.u;
   // g[0]=ast.g[0];
   // g[1]=ast.g[1];
   // g[2]=ast.g[2];
// printf("引力势能最终算为：");
 //   printf("%f ", U);
 // printf("\n");
 //printf("引力最终算为：");
 //for(int i = 0; i < 3; i++) {
      
  //   printf("%f ", g[i]);
    // printf("%f ", v0ellpre2[i]);
// }
    int N_p=5078;
    int N_f=10152;
    int N_e=15228;
     
   FILE* fid = fopen("pdata.txt", "r");

    float p_data[N_p][4];
    for (int i = 0; i < N_p; i++) 
    {
        fscanf(fid, "%f %f %f %f", &p_data[i][0], &p_data[i][1], &p_data[i][2], &p_data[i][3]);
    }
   // printf("文件能读取2");
    fclose(fid);

   free(p_data);

    FILE* fid1 = fopen("fdata.txt", "r");
    int f_data[N_f][4];
    for (int i = 0; i < N_f; i++)
    {
        fscanf(fid1, "%d %d %d %d", &f_data[i][0], &f_data[i][1], &f_data[i][2], &f_data[i][3]);
    }
   // printf("文件能读取3");
    fclose(fid1);
  

    FILE* fid2 = fopen("edata.txt", "r");
    int e_data[N_e][5];
    for (int i = 0; i < N_e; i++)
    {
        fscanf(fid2, "%d %d %d %d %d", &e_data[i][0], &e_data[i][1], &e_data[i][2], &e_data[i][3], &e_data[i][4]);
       // printf( "%d %d %d %d %d", e_data[i][0], e_data[i][1], e_data[i][2], e_data[i][3], e_data[i][4]);
       // printf("\n");
    }
   // printf("文件能读取3");
    fclose(fid2);

    FILE* fid3 = fopen("lendata.txt", "r");
    float len_data[N_e][2];
    for (int i = 0; i < N_e; i++)
    {
        fscanf(fid3, "%f %f", &len_data[i][0], &len_data[i][1]);
    }
    //printf("文件能读取4");
    fclose(fid3);

    FILE* fid4 = fopen("nedata.txt", "r");
    float ne_data[N_e][9];
    for (int i = 0; i < N_e; i++)
    {
        fscanf(fid4, "%f %f %f %f %f %f %f %f %f", &ne_data[i][0], & ne_data[i][1], &ne_data[i][2], & ne_data[i][3], &ne_data[i][4], & ne_data[i][5], &ne_data[i][6], & ne_data[i][7], &ne_data[i][8]);
    }
    //printf("文件能读取5");
    fclose(fid4);
     
   
   FILE* fid5 = fopen("nf.txt", "r");
    float nf_data[N_f][4];
    //printf("能到这里吧！");
    for (int i = 0; i < N_f; i++)
    {
       // printf("能到这里吧！");
        fscanf(fid5, "%f %f %f %f", &nf_data[i][0], &nf_data[i][1], &nf_data[i][2], &nf_data[i][3]);
        
    }
   // printf("文件能读取6");
    fclose(fid5);
double dv=0;
double ddv=0;
    struct ASCMResult ascm= ASCM(v0ellpre2,R0,T,Rref,p_data,f_data,e_data,len_data,ne_data,nf_data);
 // struct ASCMhuaraodongResult a= ASCMhuaraodong(v0ellpre2, T, R0, 0.1);
 // struct DELTAX del = deltax(v0ellpre2, R0, T, R1, 0.1);
    extend=ascm.extend;
    V0extend[0]=ascm.V0extend[0];
    V0extend[1]=ascm.V0extend[1];
    V0extend[2]=ascm.V0extend[2];
    for (int i = 0; i < 3; i++) {
     
      printf("%f ", ascm.V0extend[i]);
    }
     printf("\n");
    
    

   // printf("\n");
   // double y[6]={19271, 34799, -37,1,2,3};
   // double hh[3]={1,1,1};

  //  struct ORB1 orb=ASCMorbequ(y,hh);
 //   for (int i = 0; i < 6; i++) {
 //      printf("%f ",orb.yp[i]);
 //   }

}

    
 
    return 0;
    }