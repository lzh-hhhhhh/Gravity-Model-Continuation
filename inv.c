//
//  inv.c
//  转c
//
//  Created by 刘子晗 on 2023/11/8.
//
#include "inv.h"

/**
*A表示输入的矩阵
*B表示输出的逆矩阵
*n表示秩的大小
*/

struct INV inv(double matrix11,double matrix12,double matrix13,double matrix21,double matrix22,double matrix23,double matrix31,double matrix32,double matrix33)
{
    struct INV result;
    double matrix[3][3];
    matrix[0][0]=matrix11;
    matrix[0][1]=matrix12;
    matrix[0][2]=matrix13;
    matrix[1][0]=matrix21;
    matrix[1][1]=matrix22;
    matrix[1][2]=matrix23;
    matrix[2][0]=matrix31;
    matrix[2][1]=matrix32;
    matrix[2][2]=matrix33;
    
    double newMat[3][3];
    Gauss(matrix, newMat, 3);//3*3矩阵
    for (int i = 0; i < 3; i++) {
        result.invf[0][i] = newMat[0][i];
        result.invf[1][i] = newMat[1][i];
        result.invf[2][i] = newMat[2][i];
    }
    
    /***输出函数****/
    return result;

}

