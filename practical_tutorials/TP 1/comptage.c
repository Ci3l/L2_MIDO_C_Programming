#include <stdlib.h>
#include <stdio.h>

int main(){
    int n ;
    printf("combien d'entiers souhaitez vous entrer ? ");
    if (scanf("%d",&n) != 1){
        printf("Erreur : entrée invalide. Veuillez entrer un nombre entier.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Clear invalid input
        return 1;
    }

    int t, neg = 0, pos = 0 ;
    for (int i = 0; i<n ; i++){
        scanf("%d",&t);
        if (t<=0){
            neg++ ;
        } else {
            pos++ ;
        }
    }

    printf("vous avez entré %d nombres négatifs et %d nombre positifs",neg,pos);

    return 0 ;
}