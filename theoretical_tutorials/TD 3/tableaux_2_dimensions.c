#include <stdio.h>
#include <stdlib.h>


void CreerDamier(int n, char tab[n][n]){
    for (int i = 0 ; i<n ; i ++){
        for (int j = 0 ; j<n ; j++){
            if ((i + j) % 2 == 0) {
                tab[i][j] = '-';  
            } else {
                tab[i][j] = '*'; 
            }
        }
    }
}

void showTab(int n, char tab[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", tab[i][j]); 
        }
        printf("\n");
    }
}

void CreerCroix(int n, char tab[n][n], int i, int j){
    for (int x = 0 ; x < n ; x ++ ){
        for (int y = 0 ; y < n ; y ++){
            if (x==i && y == j){
                tab[x][y] = '*' ;
            }
            else if (abs(j - y) == abs(i - x)){
                tab[x][y] = '+' ;
            }
            else {
                tab[x][y] = '.' ;
            }
        }
    }
}

int main(){
    int n ;
    n = 7 ;
    char tab[n][n] ;
    CreerCroix(n, tab,1,2) ;
    showTab(n, tab);

    return 0 ;
}