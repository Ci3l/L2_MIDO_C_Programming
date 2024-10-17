#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Remplissage(int T[], int n){
    srand(time(NULL));
    for (int i = 0 ; i<n ; i++){
        T[i]=rand()%10 ;
    }
}

void Affichage(int T[], int n){
    for (int i = 0 ; i<n ; i++){
        printf("%d ; ",T[i]);
    }
}

int Position(int T[],int n, int e){
    for (int i = 0 ; i<n ; i++){
        if (T[i]==e){
            return i ;
        }
    }
    return -1 ;
}

void Somme(int tabA[], int tabB[], int resultat[], int n){
    for (int i = 0 ; i<n; i++){
        resultat[i] = tabA[i]+tabB[i] ;
    }
}

int main(void) { int nb;
    srandom(time(NULL));
    
    do {
        printf("Entrez le nombre de valeurs que vous désirez\n"); scanf("%d", &nb);
    } while (nb < 1);
    int tab1[nb], tab2[nb], tab3[nb];

    Remplissage(tab1, nb);
    Affichage(tab1, nb);
    printf("%d %d\n", Position(tab1, nb, 2), Position(tab1, nb, 4));
        
    Remplissage(tab2, nb);
    Affichage(tab2, nb);
    Somme(tab1, tab2, tab3, nb);
    Affichage(tab3, nb);
    return 0; }