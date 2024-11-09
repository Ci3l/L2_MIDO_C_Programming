#include <stdio.h>

void RemplirTableauMult(int tab[][11]) {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            tab[i][j] = i * j;
        }
    }
}

void showTab(int tab[][11]) {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            printf("%3d ", tab[i][j]); 
        }
        printf("\n");
    }
}

int main(){
    int tab[11][11] ;

    RemplirTableauMult(tab) ;

    showTab(tab) ;

    return 0 ;
}