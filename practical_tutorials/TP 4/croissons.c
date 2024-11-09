#include <stdio.h>
void croissRec(int a) { 
    if (a == 0) {
        return; 
    } else {
        croissRec(a-1);
        printf("%d\n", a); 
    }
}

void decroissRec(int a) {
    if (a==0) {
        return;
    } else {
        printf("%d\n",a); 
        decroissRec(a-1);   
    }
}

int main(){
    croissRec(10);
    decroissRec(10);

    return 0 ;
}