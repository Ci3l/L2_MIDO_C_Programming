int CompareChaine(char ch1[], char ch2[]){ //equivalent to strcmp
    int i = 0 ;
    while (ch1[i] && ch1[i]==ch2[i]){
        i ++ ;
    }
    return ch1[i]-ch2[i] ; //the result is asked to be either positive or negative so no need for further tests
}

//ATTENTION strcmp works the same and returns 0 if both chain are equals so 
//you can t use directly if(strcmp(ch1,ch2)) for example 