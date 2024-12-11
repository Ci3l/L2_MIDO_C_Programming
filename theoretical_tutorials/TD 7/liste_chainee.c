#include <stdio.h>
#include <stdlib.h>

struct Maillon 
{
    int value ;
    struct Maillon * next ;
};

struct Liste
{
    int size ;
    struct Maillon * first_maillon ;
};

typedef struct Maillon Maillon ;
typedef struct Liste Liste ;

Liste * init_list(){
    Liste* list = malloc(sizeof(Liste)) ;
    if (list == NULL){
        fprintf(stderr, "Memory allocation failed for list\n") ;
        return NULL ;
    } 

    Maillon* maillon = malloc(sizeof(Maillon)) ;
    if (maillon == NULL){
        fprintf(stderr, "Memory allocation failed for maillon\n") ;
        return NULL ;
    }

    maillon->value = -1 ;
    maillon->next = NULL ;

    list->first_maillon = maillon ;
    list->size = 1 ;

    return list ;
}

void add_element(Liste * liste,int new_value){ //le temps d execution est constant au pire le nombre d'opération est de 4
    Maillon * new_maillon = malloc(sizeof(Maillon));
    new_maillon->value = new_value ;
    new_maillon->next = liste->first_maillon ;
    liste->first_maillon = new_maillon ;
    liste->size ++ ;
}

//void show_list_rec(Liste * liste){
//    if (liste->first_element == NULL){
//        return ;
//    }
//    printf("%d",liste->first_element) ;
//    Liste temp ;
//    temp.first_element = &(*(liste->first_element)->next) ;
//    show_list_rec(&temp) ;
//}

void show_list_it(Liste * liste){
    Maillon * current_maillon = liste->first_maillon;

    for (int i = 0 ; i < liste->size ; i++){
        printf("%d\n", current_maillon->value) ;
        current_maillon = current_maillon->next ;
    }
}

void add_element_at_the_end(Liste * liste, int new_value){// l exectution se fait en O(n) linéairement au nombre d element dans la liste chainee
    Maillon * new_maillon = malloc(sizeof(Maillon));
    new_maillon->next = NULL ;
    new_maillon->value = new_value ;

    Maillon * last_element = liste->first_maillon ;

    for (int i = 0 ; i < liste->size - 1 ; i ++){
        last_element = last_element->next ;
    }

    last_element->next = new_maillon ;
    liste->size ++ ;
}

int is_in(Liste* liste, int x){
    Maillon current_maillon ;
    current_maillon = *(liste->first_maillon) ;
    for (int i = 0 ; i < liste->size - 1 ; i++){
        if (current_maillon.value == x){
            return 1 ;
        }
        current_maillon = *(current_maillon.next) ;
    }
    return 0 ;
}

void show_list_rec_aux(Maillon * maillon){
    printf("%d\n",maillon->value) ;
    if (maillon->next == NULL){
        return ;
    } else {
    show_list_rec_aux(maillon->next) ;
    }
}

void show_list_rec(Liste * liste){
    show_list_rec_aux(liste->first_maillon) ;
}

Maillon * pop(Liste * liste){
    Maillon * temp = liste->first_maillon ;

    Maillon * new_first_element = liste->first_maillon->next ;

    liste->first_maillon = new_first_element ;
    liste->size -- ;

    return temp ;
}

void delete_liste_chainee(Liste * liste){
    Maillon * next_element = liste->first_maillon ;
    Maillon * temp ;
    while (next_element != NULL){
        temp = next_element->next;
        free(next_element) ;
        next_element = temp ;
    }
    free(liste) ;
}

void delete_occurences(Liste *liste, int value) {
    Maillon *current_maillon = liste->first_maillon;
    Maillon *prev_maillon = NULL;

    while (current_maillon != NULL) {
        if (current_maillon->value == value) {
            Maillon *to_delete = current_maillon;
            if (prev_maillon == NULL) {
                // We're deleting the first node
                liste->first_maillon = current_maillon->next;
            } else {
                // Skip the current node
                prev_maillon->next = current_maillon->next;
            }
            current_maillon = current_maillon->next; // Move to the next node
            free(to_delete); // Free the memory of the deleted node
            liste->size--;   // Update the size
        } else {
            // Move both pointers forward
            prev_maillon = current_maillon;
            current_maillon = current_maillon->next;
        }
    }
}


Liste* init_list();
void add_element(Liste* liste, int value);
void show_list_it(Liste* liste);
int is_in(Liste* liste, int value);
Maillon * pop(Liste* liste);


int main() {
    // Step 1: Initialize a new list
    Liste *list = init_list();
    printf("List initialized. Current size: %d\n", list->size);

    // Step 2: Add elements to the list
    printf("Adding elements to the beginning of the list...\n");
    add_element(list, 10);
    add_element(list, 20);
    add_element(list, 30);

    // Step 3: Display the list
    printf("Current list (iterative display):\n");
    show_list_it(list);

    // Step 4: Add elements at the end
    printf("Adding elements to the end of the list...\n");
    add_element_at_the_end(list, 40);
    add_element_at_the_end(list, 50);

    // Step 5: Display the list again
    printf("Updated list after adding elements to the end:\n");
    show_list_it(list);

    // Step 6: Check if elements exist in the list
    int element_to_check = 20;
    printf("Checking if %d is in the list: %s\n", element_to_check,
           is_in(list, element_to_check) ? "Yes" : "No");

    element_to_check = 60;
    printf("Checking if %d is in the list: %s\n", element_to_check,
           is_in(list, element_to_check) ? "Yes" : "No");

    // Step 7: Remove the first element
    printf("Removing the first element from the list...\n");
    pop(list);

    // Display the list after removal
    printf("List after removing the first element:\n");
    show_list_it(list);

    // Step 8: Remove all occurrences of an element
    printf("Removing all occurrences of 20 from the list...\n");
    delete_occurences(list, 20);

    // Display the list after removing occurrences
    printf("List after removing occurrences of 20:\n");
    show_list_it(list);

    // Step 9: Free the list
    printf("Deleting the entire list...\n");
    delete_liste_chainee(list);

    printf("List deleted successfully.\n");

    return 0;
}