//
//  tuoqiugravity.c
//  转c
//
//

#include "tuoqiugravity.h"

struct GravityResult tuoqiugravity(double r[]) {
    struct GravityResult result;
    double R[3] = {r[0], r[1], r[2]};
    double a=16712;
    double b=6704;
    double c=5752;
    double m=7.2e+15;
    double G=6.67428e-11;
    double detla=1e-3;
 
    r[0] = R[0] + detla;
    double u1, u2;
    r[0] = R[0] + detla;
    u1 = calculateU(r, a, b, c, m, G);
    r[0] = R[0] - detla;
    u2 = calculateU(r, a, b, c, m, G);
    result.g[0] = (u1 - u2) / (2 * detla);

    r[0] = R[0];
    r[1] = R[1] + detla;
    u1 = calculateU(r, a, b, c, m, G);
    r[1] = R[1] - detla;
    u2 = calculateU(r, a, b, c, m, G);
    result.g[1] = (u1 - u2) / (2 * detla);

    r[0] = R[0];
    r[1] = R[1];
    r[2] = R[2] + detla;
    u1 = calculateU(r, a, b, c, m, G);
    r[2] = R[2] - detla;
    u2 = calculateU(r, a, b, c, m, G);
    result.g[2] = (u1 - u2) / (2 * detla);
    
    r[0] = R[0];
    r[1] = R[1];
    r[2] = R[2];
    result.u = calculateU(R, a, b, c, m, G);

    return result;
}

double calculateU(double* r, double a, double b, double c, double m, double G) 
{
    double u;
    double R[3];

   // R[0]=r[0] ;
   // R[1]=r[1];
   // R[2]=r[2];
   u=G*m/sqrt(pow(r[0], 2) + pow(r[1], 2) + pow(r[2], 2))+G*m*((a*a - 0.5*b*b - 0.5*c*c) * pow(r[0], 2) + (b*b - 0.5*a*a - 0.5*c*c) * pow(r[1], 2) +(c*c - 0.5*b*b - 0.5*a*a) * r[2]*r[2] )/ (5 * pow((r[0] * r[0] + r[1] * r[1] + r[2] * r[2]), 2.5))+3*G*m*((a*a*a*a)*(r[0]*r[0]*r[0]*r[0]-3*(r[1]*r[1]+r[2]*r[2])*r[0]*r[0]+0.375*(r[1]*r[1]+r[2]*r[2])*(r[1]*r[1]+r[2]*r[2]))+(b*b*b*b)*(r[1]*r[1]*r[1]*r[1]-3*(r[0]*r[0]+r[2]*r[2])*r[1]*r[1]+0.375*(r[0]*r[0]+r[2]*r[2])*(r[0]*r[0]+r[2]*r[2]) )+(c*c*c*c)*(r[2]*r[2]*r[2]*r[2]-3*(r[0]*r[0]+r[1]*r[1])*r[2]*r[2]+0.375*(r[0]*r[0]+r[1]*r[1])*(r[0]*r[0]+r[1]*r[1]) )+a*a*b*b*(0.25*pow(r[2], 4) -pow(r[0], 4) -pow(r[1], 4)-0.75*r[2]*r[2]*r[0]*r[0]-0.75*r[2]*r[2]*r[1]*r[1] +0.75*3*r[0]*r[0]*r[1]*r[1] ) +a*a*c*c*(0.25*pow(r[1], 4) -pow(r[0], 4)-pow(r[2], 4) -0.75*r[1]*r[1]*r[0]*r[0] -0.75*r[1]*r[1]*r[2]*r[2] +0.75*3*r[0]*r[0]*r[2]*r[2])+b*b*c*c*(0.25*pow(r[0], 4) -pow(r[1], 4)-pow(r[2],4)-0.75*r[0]*r[0]*r[1]*r[1]-0.75*r[0]*r[0]*r[2]*r[2] +0.75*3*r[1]*r[1]*r[2]*r[2]) )/( 35* pow((r[0]*r[0]+r[1]*r[1]+r[2]*r[2]), 4.5)) ;
return u;
}
