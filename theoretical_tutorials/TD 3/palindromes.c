#include <string.h>
#include <stdio.h>

void Copie(char ch1[], char ch2[]){
    int i = 0 ;
    for (i = 0 ; ch1[i]!='\0' ; i ++){
        ch2[i]=ch1[i] ;
    }
    ch2[i] = '\0';
}

void Miroir(char ch[]){
    int longueur = strlen(ch) ;
    char tmp ;
    int i = 0 ;
    int j = longueur-1 ;
    while (i<j){
        tmp = ch[i] ;
        ch[i] = ch[j] ;
        ch[j] = tmp ;
        i ++ ;
        j -- ;
    }   
}

void SupprOccur(char ch[], char c){
    int i,j = 0 ;
    while (ch[i]!='\0'){
        if (ch[i]!=c){
            ch[j++]=ch[i]; //l'incrémenetation de j a lieu après l'implémenttion
        }
        i ++ ;
    }
    ch[j]='\0';
}

int EstPalindrome(char ch[]){
    char ch_org[strlen(ch) + 1] ; 
    strcpy(ch, ch_org) ;
    Miroir(ch_org) ;
    for (int i = 0 ; ch[i] != '\0' ; i ++){
        if (ch[i] != ch_org[i]){
            return 0 ;
        }
    }  
    return 1 ;
}

int main(){
    char ch[5] = "kiwi" ;

    printf("%d", EstPalindrome(ch)) ;

    return 0 ;
}

