#include <stdio.h>

int LgChaine(char ch1[]){
    int i = 0 ;
    while (ch1[i]){
        i ++ ;
    }
    return i ;
}

int main(){
    char t[8] = {'h','e','l','l','o','t'};

    printf("%d",LgChaine(t));

    return 0 ;
}