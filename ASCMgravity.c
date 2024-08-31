//
//  ASCMgravity.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//
#include "ASCMgravity.h"

struct ASCMgravity ASCMgravity(double r[],double Ext,float p_data[][4],int f_data[][4],int e_data[][5], float len_data[][2],float ne_data[][9],float nf_data[][4]) {
    struct ASCMgravity result;
    double Uast, Uqiu;
    double gast[3];
    double gqiu[3];
    //printf("ASCMgra能进来");
    struct ASGR ast=astgravity_preload(r,"eros5000原始数据.txt",p_data,f_data,e_data,len_data,ne_data,nf_data);
    //printf("astgra能出来");
    Uast=ast.U;
    gast[0]=ast.g[0];
    gast[1]=ast.g[1];
    gast[2]=ast.g[2];
    //printf("re最终算为：");
    //printf( "%f %f %f",gast[0] ,gast[1] ,gast[2]);
    //printf("\n");

    struct GravityResult gra= tuoqiugravity(r);
   // printf("tuogra能出来");

    Uqiu=gra.u;
   // printf("u最终算为：");
//printf( "%f ", Uqiu);
   // printf("\n");
    gqiu[0]=gra.g[0];
    gqiu[1]=gra.g[1];
    gqiu[2]=gra.g[2];
   // printf("re最终算为：");
   // printf( "%f %f %f",gqiu[0] ,gqiu[1] ,gqiu[2]);
   // printf("\n");
    result.u = (1 - Ext) * Uqiu + (Ext) * Uast;
    result.g[0] = (1 - Ext) * gqiu[0] + (Ext) * gast[0];
    result.g[1] = (1 - Ext) * gqiu[1] + (Ext) * gast[1];
    result.g[2] = (1 - Ext) * gqiu[2] + (Ext) * gast[2];
    
    return result;
}
