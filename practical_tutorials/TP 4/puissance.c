#include <stdio.h>

int power_rec(int a, int n, int *count){
    (*count) ++ ;
    if (n==0){
        return 1 ;
    } else {
        return a*power_rec(a,n-1,count) ;
    }
}

int power_it(int a, int n, int *count){
    for (int i = 1 ; i<n ; i++){
        (*count) ++ ;
        a = a*a ;
    }
    return a ;
}

int smart_power(int a, int n, int *count){
    (*count)++;
    if (n==0){
        return 1 ;
    } else {
        if (n%2){
            return a*smart_power(a,(int)(n/2),count)*smart_power(a,(int)(n/2),count) ;
        } else {
            return smart_power(a,(int)(n/2),count)*smart_power(a,(int)(n/2),count) ;
        }
    }
}

int main(){
    int count= 0 ;
    printf("%d %d\n",power_rec(4,2,&count),count);
    count = 0 ;
    printf("%d %d\n",power_it(4,2,&count),count);
    count = 0 ;
    printf("%d %d\n",smart_power(4,2,&count),count);

    return 0 ;
}