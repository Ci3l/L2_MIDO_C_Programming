#include <stdio.h>
#include <stdlib.h>

int main(){
    int age ;
    printf("Entrer votre âge : ");
    scanf("%d",&age);

    if (age<18){
        printf("MINEUR\n");
    } else {
        printf("MAJEUR\n");
    }

    return 0 ;
}