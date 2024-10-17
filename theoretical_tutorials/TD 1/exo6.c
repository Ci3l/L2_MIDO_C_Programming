#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,tmp ;
    scanf("%d",&n);

    while (n>0){
        tmp=n%10 ;
        printf("%d\n",tmp);
        n /= 10 ;
    }

    return 0 ;
}