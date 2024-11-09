#include <stdio.h>

int pgcd_rec(int a, int b){
    if (a*b==0){
        return a+b ;
    } else {
        if (a>b){
            return pgcd_rec(b,a%b) ;
        } else {
            return pgcd_rec(a,b%a) ;
        }

    }
}

int main(){
    printf("%d",pgcd_rec(142,12)) ;

    return 0 ;
}