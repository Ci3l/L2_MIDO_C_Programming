#include <stdio.h>
#include <string.h>

int is_palindrome(char word[]){
    int n = strlen(word) ;
    if ((n == 1) || (n == 0)){
        return 1 ;
    }
    else if (word[0] == word[n-1]){
        char subword[n-1];
        strncpy(subword, word + 1, n - 2);
        subword[n-2] = '\0';
        return is_palindrome(subword);
    } 
    else {
        return 0 ;
    }
}

int main(){

    printf("%d", is_palindrome("kiwi"));

    return 0 ;
}