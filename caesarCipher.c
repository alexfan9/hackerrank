/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-caesar-cipher-1/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-two
*/


char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    char *res = calloc((len+1), sizeof(char));
    if(k >= 26) {
        k = k % 26;
    }
    for(int i = 0; i < len; i++) {
        int c = s[i] + k;
        res[i] = c;
        if(s[i] >='a' && s[i] <= 'z') {
            if(c > 'z') {
                res[i] =  c - 'z' + 'a' -1 ;
            }
        }else if(s[i] >='A' && s[i] <= 'Z') {
            if(c > 'Z') {
                res[i] = 'A' + c - 'Z' - 1;
            }
        } else {
            res[i] = s[i];
        }
    }
    return res;
}
