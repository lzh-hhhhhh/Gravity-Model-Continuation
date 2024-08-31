//
//  inv.h
//  转c
//
//  Created by 刘子晗 on 2023/11/8.
//

#ifndef inv_h
#define inv_h

#include <stdio.h>
#include "gass.h"

struct INV
    {
        double invf[3][3];
      
    };
struct INV inv(double matrix11,double matrix12,double matrix13,double matrix21,double matrix22,double matrix23,double matrix31,double matrix32,double matrix33);
#endif /* inv_h */
