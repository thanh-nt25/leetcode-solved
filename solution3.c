int compare(char *s, int i , int j){
    for (int p = i; p < j; ++p){
        // return -1;
        for (int q = p + 1; q <= j; ++q){
            if (s[p] == s[q]){
                return -1;}
        }
    }
    return 0;
}

int lengthOfLongestSubstring(char * s){
    if (*s == '\0') return 0;
    if (strlen(s) == 1) return 1;
    int length = 0;
    for (int i=0; i < (strlen(s)-1); ++i){
        for (int j=i; j < strlen(s); ++j){
            if((compare(s, i, j) == 0) && (length < (j-i+1)) ) length = j-i+1;
        }
    }
    return length;
}