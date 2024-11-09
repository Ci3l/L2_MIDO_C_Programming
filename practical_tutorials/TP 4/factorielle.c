#include <stdio.h>

int fact_it(int a){
    int r = 1 ;
    for (int i = a ; i>0 ; i--){
        r = r*i ;
    }
    return r ;
}

int fact_rec(int a){
    if (a==1){
        return 1 ;
    } else {
        return a*fact_rec(a-1) ;
    }
}