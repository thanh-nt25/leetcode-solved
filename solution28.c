int strStr(char * haystack, char * needle){
    if (strcmp(haystack, needle) == 0) return 0;
    if (strlen(needle) > strlen(haystack)) return -1;
    if (haystack == NULL || needle == NULL) return -1;
    
    for (int i=0; i < (strlen(haystack) - strlen(needle) +1); ++i){
            char *cmp = (char *)malloc(sizeof(needle));
            for (int j = i, k = 0; j < (i + strlen(needle)); ++j, ++k){
                cmp[k] = haystack[j];
            }
            if (strcmp(cmp, needle) == 0) return i;
    }   
    return -1;
}