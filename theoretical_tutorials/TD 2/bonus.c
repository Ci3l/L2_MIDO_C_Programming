#include <stdio.h>

int findMax(int tab[],int n, int k) {
    int Nmax = -1 ;
    for (int i = 0; i < n; i++) {
        if (tab[i] > Nmax) {
            Nmax = tab[i]; 
        }
    }
    int tab2[Nmax  + 1];
    for (int i = 0 ; i<Nmax ; i++){
        tab2[i]=-1 ;
    }
    for (int i = 0 ; i<n ; i++){
        tab2[tab[i]]=i ;
    }
    for (int i = 0 ; i<n ; i++){
        if (k-tab[i]>=0 && k-tab[i]<=Nmax && tab2[k-tab[i]]>i){//we don t you this test :  tab2[k-tab[i]]!=-1 ; because count the pairs twice
            printf("%d+%d=%d\n",tab[tab2[k-tab[i]]],tab[i],k);//above we use the test >i because it checks if it's a number we ve already considered in a pair
            printf("found one pair");
        }
    }
}

int main(){
    int t[6] = {1,2,4,3,7,8} ;
    f(t,6,5);

    return 0 ;
}