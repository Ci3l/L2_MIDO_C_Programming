#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

typedef struct Maillon {
    int value;
    struct Maillon* next;
} Maillon;

typedef struct Liste {
    Maillon* first_maillon;
    int size;
} Liste;

Liste* init_list();
void add_element(Liste* liste, int value);
void add_element_at_the_end(Liste* liste, int value);
void show_list_it(Liste* liste);
void delete_liste_chainee(Liste* liste);
int is_in(Liste* liste, int value);
Maillon * pop(Liste* liste);

#endif