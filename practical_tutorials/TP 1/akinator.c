#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srandom(time(NULL));
    int guess = random()%100;

    int user_guess;
    for (int i = 0 ; i < 10 ; i++){
        printf("Entrer votre guess numéro %2d: ",i+1);
        if (scanf("%d",&user_guess) != 1){
            printf("Erreur : entrée invalide. Veuillez entrer un nombre entier.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Clear invalid input
            return 1;
        }
        if (user_guess == guess){
            printf("La solution était bien %d !!!\nVous avez trouvé la solution en %d essais !",user_guess,i+1);
            return 0;
        }
        else if (guess<user_guess){
            printf("Plus petit !\n");
        } else {
            printf("Plus grand !\n");
        }
    }
    printf("Vous avez excédé le nombre d'essais maximal, la solution était %d\n",guess);
    return 0;
}