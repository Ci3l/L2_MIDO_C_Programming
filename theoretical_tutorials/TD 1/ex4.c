#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Entrez une série d'entier : ");
    int nbr = 1, sum = 0, min, max,x ;
    float avg ;

    scanf("%d",&x);
    min = x ;
    max = x ;
    for (int i = 1 ; i>0 ; i++){
        scanf("%d",&x);
        if (x==0){
            avg = sum/nbr;
            printf("length of the serie : %d\naverage : %f\nmin : %d\nmax : %d",nbr,avg,min,max);
            return 0 ;
        }
        if (x<min){
            min = x ;
        }else if (x>max){
            max = x ;
        }
        sum += x ;
        nbr += 1 ;

    } 

    return 0 ;
}