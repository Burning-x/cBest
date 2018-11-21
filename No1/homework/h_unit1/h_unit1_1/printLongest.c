//
//  printLongest.c
//  h_unit1_1
//
//  Created by 熊蕲涛 on 2018/11/21.
//  Copyright © 2018 熊蕲涛. All rights reserved.
//

#include "printLongest.h"
int tempreture(){
    int fahr,celsius;
    int lower,upper,step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while(fahr <= upper){
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;
    }
    return 0;
}
