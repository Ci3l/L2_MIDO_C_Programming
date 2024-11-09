#include <stdio.h>

int fibo_rec(int n, int* count){
    (*count)++ ;
    if (n == 0){ return 0 ; }
    if (n == 1){ return 1 ; }
    else { return fibo_rec(n-1, count) + fibo_rec(n-2, count) ; }
}

int fibo_it(int n, int* count){
    if (n == 0){ return 0 ; }
    if (n == 1){ return 1 ; }
    else {
        int a, b, tmp ;
        a = 0 ;
        b = 1 ;
        for (int i = 1 ; i < n ; i ++){
            (*count)++ ;
            tmp = a ;
            a = b ;
            b = tmp + a ;
        }
        return b ;
    }
}

int main(){
    int count = 0 ;
    int n ;
    n = 12 ;
    printf("Computed the %d-th Fibonacci number = %d with %d=2*%d-1 recursive calls.\n",n,fibo_rec(n, &count),count,fibo_rec(n+1, &count)) ;

    count = 0 ;
    printf("Computed the %d-th Fibonacci number = %d with %d iterations.",n,fibo_it(n, &count),count) ;

    return 0 ;
}