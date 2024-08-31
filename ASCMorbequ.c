//
//  ASCMorbequ.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//


#include "ASCMorbequ.h"

#define G 6.67428e-11
#define Mo 1.98892e30
#define AU 149597870700
#define beta 3.37e-4

void rd(double *RD) {
    double dt = 11.0 / 180.0 * M_PI;
    double be = 17.0 / 180.0 * M_PI;
    double a = 1.457837275948 * AU;
    double e = 0.222667732203018;
    double i = 10.82872662501955 / 180.0 * M_PI;
    double w = 178.7912204366847 / 180.0 * M_PI;
    double omg = 304.3380307222211 / 180.0 * M_PI;
    double f = 0;
    double t = 0;

    double a1[3][3] = {
        {cos(w * t), sin(w * t), 0},
        {-sin(w * t), cos(w * t), 0},
        {0, 0, 1}
    };

    double a2[3][3] = {
        {cos(M_PI / 2 - be), 0, -sin(M_PI / 2 - be)},
        {0, 1, 0},
        {sin(M_PI / 2 - be), 0, cos(M_PI / 2 - be)}
    };

    double a3[3][3] = {
        {cos(dt), sin(dt), 0},
        {-sin(dt), cos(dt), 0},
        {0, 0, 1}
    };

    double A[3][3] = {0};
    double temp[3][3] = {0};

    // Multiply a1 * a2
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            for (int k = 0; k < 3; k++) {
                temp[r][c] += a1[r][k] * a2[k][c];
            }
        }
    }

    // Multiply result by a3, store in A
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            for (int k = 0; k < 3; k++) {
                A[r][c] += temp[r][k] * a3[k][c];
            }
        }
    }

    double B[3] = {
        cos(omg) * cos(w + f) - sin(omg) * sin(w + f) * cos(i),
        sin(omg) * cos(w + f) - cos(omg) * sin(w + f) * cos(i),
        sin(omg) * sin(w + f)
    };

    double factor = -a * (1 - e * e) / (1 + e * cos(f));

    for (int r = 0; r < 3; r++) {
        RD[r] = 0;
        for (int c = 0; c < 3; c++) {
            RD[r] += factor * A[r][c] * B[c];
        }
    }
}




struct ORB1 ASCMorbequ(double y[], double g[]){
    struct ORB1 result;
    double w[3] = {0, 0, 0.0003314};
    double poss[3];
    double cro1[3];
    double cro2[3];
    double cro3[3];
    double x,k,z;
    double a,b,c,d,e,f;
    double pos[3] = {y[0], y[1], y[2]};
    double vel[3] = {y[3], y[4], y[5]};
   

    //cross(w,vel,x,k,z);
    
    a=w[0];b=w[1];c=w[2];
    d=vel[0];e=vel[1];f=vel[2];
    x=b*f-c*e;
    k=-a*f+c*d;
    z=-a*e+d*b;
    cro1[0]=x;
    cro1[1]=k;
    cro1[2]=z;
   

    //cross(w, pos,x,k,z);

    a=w[0];b=w[1];c=w[2];
    d=pos[0];e=pos[1];f=pos[2];
    x=b*f-c*e;
    k=-a*f+c*d;
    z=-a*e+d*b;
    cro2[0]=x;
    cro2[1]=k;
    cro2[2]=z;
    poss[0]=cro2[0];
    poss[1]=cro2[1];
    poss[2]=cro2[2];
 //   printf("%f %f %f",poss[0],poss[1],poss[2]);
   // printf("\n");
   // cross(w, poss,x,k,z);
    a=w[0];b=w[1];c=w[2];
    d=poss[0];e=poss[1];f=poss[2];
    x=b*f-c*e;
    k=-a*f+c*d;
    z=-a*e+d*b;
 //  printf("%lf %lf %lf",x,k,z);
 //   printf("\n");
    cro3[0]=x;
    cro3[1]=k;
    cro3[2]=z;

 

    result.yp[0] = vel[0];
    result.yp[1] = vel[1];
    result.yp[2] = vel[2];
    result.yp[3] = g[0] -2*cro1[0]-cro3[0];
    result.yp[4] = g[1]-2*cro1[1]-cro3[1];
    result.yp[5] = g[2]-2*cro1[2]-cro3[2];
    return result;
}

