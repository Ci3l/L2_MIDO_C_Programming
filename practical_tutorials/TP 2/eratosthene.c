#include <stdio.h>

void eratosthene(int tab[],int N){
    tab[0]=0, tab[1]=0 ;
    for(int i = 2 ; i<N ; i++){
        tab[i]=1 ;
    }
    int i = 0 ;
    int div = 2 ;
    while ((div*div)<N){
        for (int j = 2 ; j < N ; j++){
            if ((j%div)==0 && j!= div){
                tab[j]=0;
            }
        }
        div++;
    }
}

int main(){
    int tab[100];

    eratosthene(tab,100);

    for (int i = 0 ; i<100 ; i++){
        if (tab[i]==1){
            printf("%d\n",i);
        }
    }
    

    return 0 ;
}