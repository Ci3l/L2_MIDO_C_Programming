#include <stdio.h>
#include <stdlib.h>

int main(){
    int n ;
    printf("Entrez votre entier : ");
    scanf("%d",&n);

    int r = 0;
    for (int i = n-1 ; i>0 ; i --){
        if (n%i == 0){
            r += i ;
        }
    }

    if (r==n){
        printf("%d est bien un nombre parfait !",n);
    } else {
        printf("%d n'est pas un nombre parfait.\n", n);
    }


    return 0 ;
}