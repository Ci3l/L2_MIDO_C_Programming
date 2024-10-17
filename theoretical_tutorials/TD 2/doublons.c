
int NbOccurenceTab(int tab[], int n, int a ){
    int r = 0 ;
    for (int i = 0 ; i<n;i++){
        if (tab[i]==a){
            r ++ ;
        }
    }
    return r ;
}

int ContientDoublons(int tab[],int n){
    for (int i = 0 ; i < n ; i++){
        if (NbOccurenceTab(tab,n,tab[i]!=1)){
            printf("%d est en doublon");
            return 1 ;
        }
    }
    return 0 ;
}

