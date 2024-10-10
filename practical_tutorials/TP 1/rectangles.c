#include <stdio.h>
#include <stdlib.h>

int main(){
    int hauteur, largeur ;
    printf("Etnrer la hauteur du triangle que vous souhaitez voir dessiné : ");
    scanf("%d",&hauteur);
    printf("Puis la largeur : ");
    scanf("%d",&largeur);

    //Rectangle plein
    for (int i = 0 ; i<hauteur ; i ++){
        for (int j = 0 ; j<largeur ; j++){
            printf("*");
        }
        printf("\n");
    }

    //Rectangle vide
    for (int i = 0 ; i < hauteur ; i ++){
        printf("*");
        if ( i == 0 || i == hauteur - 1){
            for (int j = 0 ; j < largeur ; j ++){
                printf("*");
            }
        } else {
            for (int j = 0 ; j < largeur ; j ++){
                printf(" ");
            }
        }
        printf("*");
        printf("\n");
    }


    return 0 ;
}