#include <stdio.h>

int f(int tab[],int n, int k){
    int r = 0;
    for (int i = 0 ; i<n ; i ++){
        for (int j = i+1 ; j<n ; j ++){//attention à l'initialisation de j !!!
            if (tab[i]+tab[j]==k){
                printf("%d+%d=%d\n",tab[i],tab[j],k);
                r ++ ;
            }
        }
    }
    return r ;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5, 6};
    int taille = sizeof(tab) / sizeof(tab[0]);
    int k;

    printf("Entrez la valeur de k : ");
    scanf("%d", &k);

    int nombre_paires = f(tab, taille, k);

    printf("Nombre de paires trouvées dont la somme est %d : %d\n", k, nombre_paires);

    return 0;
}