//
// Created by raghu on 9/3/2020.
//

# include<stdio.h>
# include<stdlib.h>
# include"helper.h"

void print_exit(char *s) {
    printf("%s", s);
    exit(1);
}

float max(float a, float b) {
    if (a>=b) {
        return a;
    }
    else {
        return b;
    }
}