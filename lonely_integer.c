/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-lonely-integer/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one

*/

int lonelyinteger(int a_count, int* a) {
    int value = 0;
    for(int i = 0; i < a_count; i++){
        if(a[i] < 0) {
            continue;
        }
        for(int j = i+1; j< a_count; j++){
            if(a[j] < 0) {
                continue;
            }
            if(a[i]==a[j]){
                a[i] = -1;
                a[j] = -1;
            } 
        }
    }
    for(int i = 0; i < a_count; i++){
        if(a[i] > 0) {
            value = a[i];
            break;
        }
    }
    return value;
}
