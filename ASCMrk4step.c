//
//  ASCMrk4step.c
//  转c
//
//  Created by 刘子晗 on 2023/11/5.
//

#include "ASCMrk4step.h"
struct RKST1 ASCMrk4step(double R0[], double V0[],double dt, double U, double g[]) {
    struct RKST1 result;
   // printf("rks能进");
   double y[6];
    // printf("rks能进");
     for (int i = 0; i < 3; i++)
            {
                y[i]=R0[i] ;
        
            }
            for (int i = 0; i < 3; i++)
            {
              y[i+3]=  V0[i] ;
                
            }
 //for (int i = 0; i < 6; i++) {
  //      printf("%f ", y[i]);
  //  }

 //   printf("\n");
 //    for (int i = 0; i < 3; i++) {
 //       printf("%f ", g[i]);
 //   }
 //   printf("%f, \n", U);
 //   printf("\n");
    double f0[6] = {0};
    double f1[6] = {0};
    double f2[6] = {0};
    double f3[6] = {0};
    
    double u1[6] = {0};
    double u2[6] = {0};
    double u3[6] = {0};

    // Get four sample values of the derivative.
    struct ORB1 orb=ASCMorbequ(y, g);
    for (int i = 0; i < 6; i++) {
        f0[i] = orb.yp[i];
       // printf("%f ", f0[i]);
    }
 //   printf("\n");

    double dth = dt * 0.5;
   
    for (int i = 0; i < 6; i++) {
        u1[i] = y[i] + dth * f0[i];
      //  printf("%f ", u1[i]);
    }
     // printf("\n");

    struct ORB1 orb1=ASCMorbequ(u1, g);
    for (int i = 0; i < 6; i++) {
        f1[i] = orb1.yp[i];
    }
    for (int i = 0; i < 6; i++) {
        u2[i] = y[i] + dth * f1[i];
    }

    struct ORB1 orb2=ASCMorbequ(u2, g);
    for (int i = 0; i < 6; i++) {
        f2[i] = orb2.yp[i];
    }
    for (int i = 0; i < 6; i++) {
        u3[i] = y[i] + dt * f2[i];
    }


    struct ORB1 orb3=ASCMorbequ(u3, g);
    for (int i = 0; i < 6; i++) {
        f3[i] = orb3.yp[i];
    }
    for (int i = 0; i < 6; i++) {
        result.y[i] = y[i] + dt * (f0[i] + 2.0 * f1[i] + 2.0 * f2[i] + f3[i]) / 6.0;
        //  printf("%f ", result.y[i]);
    }//printf("\n");
    
    return result;
}
