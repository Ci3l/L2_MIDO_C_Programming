#include <stdio.h>

void input_tab(int T[], int n){
    int j ;
    for(int i = 0 ; i < n ; i++){
        printf("Entrez la valeur numéro %d : ",i);
        scanf("%d",&j);
        T[i]=j;
    }
}

int f(int tab[],int n){
    if (n<2){
        printf("empty tab");
        return -1;
    }
    int max,max_prim; //faire attention de bien initier max_prim
    if (tab[0]<tab[1]){
        max = tab[1] ;
        max_prim = tab[0] ;
    } else {
        max = tab[0] ;
        max_prim = tab[1] ;
    }
    for(int i = 2 ; i<n ; i++){
        if (tab[i]>max_prim && tab[i]<max){
            max_prim = tab[i] ;
        } else if (tab[i]>max) {
            max_prim = max;
            max = tab[i];

        }
    }
    return max_prim ;
}

int main(){
    int n ;
    printf("Entrez la taille du tableau : ");
    scanf("%d",&n);
    int T[n];
    input_tab(T,n);

    return 0 ;
}