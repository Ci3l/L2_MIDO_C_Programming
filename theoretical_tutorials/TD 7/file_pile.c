#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"

struct File
{
    Liste * list ;
    Maillon * head ;
    Maillon * tail ;
};

struct Pile
{
    Liste * list ;
    Maillon * top ;
};

typedef struct File File ;
typedef struct Pile Pile ;

Pile * PileInitialiser(){
    Liste * liste = init_list() ;
    Pile * pile = malloc(sizeof(Pile)) ;
    if (!pile) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    pile->list = liste ;
    pile->top = NULL ;
    return pile ;
}

File * FileInitialiser(){
    Liste * liste = init_list() ;
    File * file = malloc(sizeof(File)) ;
    if (!file) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    file->head = liste->first_maillon ;
    file->tail = liste->first_maillon ;
    file->list = liste ;
    return file ;
}

int PileVide(Pile * pile){
    if (pile->top == pile->list->first_maillon){
        return 1 ;
    } else {
        return 0 ;
    }
}

int FileVide(File * file){
    if (file->head == file->tail){
        return 1 ;
    } else {
        return 0 ;
    }
}

int PileHauteur(Pile * pile){
    return pile->list->size ;
}

int FileHauteur(Pile * pile){
    return pile->list->size ;
}

void Enfiler(File *file, int n) {
    Maillon *new_maillon = malloc(sizeof(Maillon));
    if (!new_maillon) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_maillon->value = n;
    new_maillon->next = NULL;

    if (file->head == NULL) {
        file->head = new_maillon;
        file->tail = new_maillon;
    } else {
        file->tail->next = new_maillon;
        file->tail = new_maillon;
    }

    if (file->list) {
        file->list->size++; 
        file->list->first_maillon = file->head;
    }
}


void Empiler(Pile * pile, int n){
    if (pile->top == NULL){
        add_element(pile->list,n) ;
        pile->top = pile->list->first_maillon ;
    }
    add_element(pile->list,n) ;
    pile->top = pile->top->next ;
}

void Defiler(File * file){
    if (file->head == NULL) {
        printf("The queue is empty. Nothing to dequeue.\n");
        return;
    }

    Maillon *to_free = file->head;

    file->head = file->head->next;

    if (file->head == NULL) {
        file->tail = NULL;
    }

    free(to_free);

    if (file->list) {
        file->list->first_maillon = file->head;
        file->list->size--;
    }
}

void Depiler(Pile * pile){
    if (pile->top == NULL) {
        printf("The stack is empty. Nothing to pop.\n");
        return;
    }

    Maillon *to_free = pile->top;
    pile->top = pile->top->next;

    free(to_free);

    if (pile->list) {
        pile->list->size--;
        pile->list->first_maillon = pile->top;
    }
}

void PileDetruire(Pile * pile){
    delete_liste_chainee(pile->list) ;
    free(pile) ;
}

void FileDetruire(File * file){
    delete_liste_chainee(file->list) ;
    free(file) ;
}

int main() {
    // Step 1: Initialize a file and a pile
    File *file = FileInitialiser();
    Pile *pile = PileInitialiser();
    printf("File and Pile initialized.\n");

    // Step 2: Check if the file and pile are empty
    printf("Is the file empty? %s\n", FileVide(file) ? "Yes" : "No");
    printf("Is the pile empty? %s\n", PileVide(pile) ? "Yes" : "No");

    // Step 3: Add elements to the file
    printf("Adding elements to the file...\n");
    Enfiler(file, 10);
    Enfiler(file, 20);
    Enfiler(file, 30);
    printf("File length: %d\n", FileHauteur(pile)); // File length should be updated correctly

    // Step 4: Add elements to the pile
    printf("Adding elements to the pile...\n");
    Empiler(pile, 5);
    Empiler(pile, 15);
    Empiler(pile, 25);
    pile->top = pile->list->first_maillon; // Ensure top is updated
    printf("Pile height: %d\n", PileHauteur(pile));

    // Step 5: Remove elements from the file
    printf("Removing elements from the file...\n");
    Defiler(file);
    printf("File length after removal: %d\n", PileHauteur(pile));

    // Step 6: Remove elements from the pile
    printf("Removing elements from the pile...\n");
    Depiler(pile);
    printf("Pile height after removal: %d\n", PileHauteur(pile));

    // Step 7: Destroy file and pile
    printf("Destroying the file and pile...\n");
    FileDetruire(file);
    PileDetruire(pile);
    printf("File and Pile destroyed.\n");

    return 0;
}
