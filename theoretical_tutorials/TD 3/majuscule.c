void Majuscules(char ch[]){
    int i ;
    for (int i = 0 ; ch[i]!='\0' ; i++){
        if (ch[i]>='a' && ch[i]<='z'){
            ch[i] = 'A' + ch[i]-'a';
        }
    }
}