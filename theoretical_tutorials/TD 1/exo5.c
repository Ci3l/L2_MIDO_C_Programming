#include <stdio.h>

int main(){
    char ch_lowercase  = 'a';
    char ch_uppercase = 'A';

    for (int i = 0 ; i<25 ; i++){
        while (ch_lowercase<='z'){
            printf("%c : %d\n",ch_lowercase,(int)ch_lowercase);
            ch_lowercase ++ ;
        }
        while (ch_uppercase<='Z'){
            printf("%c : %d\n",ch_uppercase,(int)ch_uppercase);
            ch_uppercase ++ ;
        }
    }

    return 0 ;
}