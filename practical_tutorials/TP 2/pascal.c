#include <stdlib.h>
#include <stdio.h>

void pascal(int r[],int n){
    if (n==1){
        r[0]=1;
        return ;
    }
    r[0]=1 ;
    for (int j = 1 ; j<n ; j ++){
        for(int i = n-1 ; i>0 ; i--){
            r[i]=r[i]+r[i-1] ;
        }
    }
}

int main(){
    int n ;
    printf("Entrez le numéro de la ligne que vous souhaitez connaitre : ");
    scanf("%d",&n);

    int r[n];
    for (int i = 0 ; i<n ; i++){
        r[i]=0 ;
    }
    pascal(r,n);

    for(int i = 0 ; i<n ; i ++){
        printf("%d ",r[i]);
    }

    return 0 ;
}