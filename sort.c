//
//  sort.c
//  转c
//
//  Created by 刘子晗 on 2023/11/9.
//

#include "sort.h"

struct SORT sort(float arr[], int size)
{
    
    struct SORT result;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    result.arr[0]=arr[0];
    result.arr[1]=arr[1];
    result.arr[2]=arr[2];
    return result;
}
