/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-pangrams/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
*/

char* pangrams(char* s) {
    char arr[26] = {0};
    char *p = s;
    while(*p != '\0'){
        char c = *p;
        if(*p >= 'A' && *p <= 'Z' ){
            c += 32;
        }
        int index = c - 'a';
        arr[index] = 1;
        p++;
    }
    char * result = calloc(12, sizeof(char));
    for(int i = 0; i < 26; i++) {
        if(arr[i] == 0) {
            strcpy(result, "not pangram");
            return result;
        }
    }
    strcpy(result, "pangram");
    return result;
}
