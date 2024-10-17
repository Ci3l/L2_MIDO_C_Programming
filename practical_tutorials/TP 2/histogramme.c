#include <stdio.h>

void histogramme(int notes[], int histo[], int l_notes){
    for (int i = 0 ; i<21 ; i++){
        histo[i]=0;
    }

    for (int i = 0 ; i<l_notes ; i++){
        histo[notes[i]] ++ ;
    }
}

int main() {
    int notes[] = {15, 18, 15, 19, 10, 18, 15, 20, 0, 7, 10, 19, 5, 18, 3};
    int taille = sizeof(notes) / sizeof(notes[0]);

    int histo[21];

    histogramme(notes, histo, taille);

    printf("Histogramme des notes :\n");
    for (int i = 0; i < 21; i++) {
        if (histo[i] > 0) { 
            printf("Note %d : %d fois\n", i, histo[i]);
        }
    }

    return 0;
}
