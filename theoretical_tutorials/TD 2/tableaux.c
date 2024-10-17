#include <stdio.h>

void show_tab(int T[],int n){
    for(int i = 0 ; i<n ; i++){
        printf("%d\n",T[i]);
    }
}

void input_tab(int T[], int n){
    int j ;
    for(int i = 0 ; i < n ; i++){
        printf("Entrez la valeur numéro %d : ",i);
        scanf("%d",&j);
        T[i]=j;
    }
}

int sum_tab(int T[], int n){
    int sum = 0 ;
    for (int i = 0 ; i < n ; i++){
        sum += T[i] ;
    }
    return sum ;
}


int main(){
    int n ;
    printf("Entrez la taille du tableau : ");
    scanf("%d",&n);
    int T[n];
    input_tab(T,n);
    show_tab(T,n);
    printf("la somme des termes du tableaux vaut %d",sum_tab(T,n));
}
