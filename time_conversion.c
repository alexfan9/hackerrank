/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-time-conversion/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
*/
char* timeConversion(char* s) {
    char arr[4][5] = {0};
    char *p = s;
    int start = 0;
    int end = 0;
    int index = 0;
    int first_letter = 0;
    
    while(*p != '\0'){
        if(*p == ':'){
            strncpy(arr[index], s + start, end - start);
            index++;
            start = end + 1;
        } else if(*p > '9' && first_letter == 0) {
            strncpy(arr[index], s + start, end - start);
            index++;
            start = end;
            first_letter = 1;
        }
        end++;
        p++;
    }
    
    strncpy(arr[index], s + start, end - start);
    int hour = atoi(arr[0]);
    if(strncmp(arr[3], "PM", 2) == 0){
        if(hour + 12 < 24){
            hour += 12;
            hour %= 24;
        }
    }
    
    if(strncmp(arr[3], "AM", 2) == 0){
        if((hour +12) >= 24){
            hour += 12;
            hour %= 24;
        }
    }
    char buf[10] = {0};
    
    sprintf(buf,"%02d:%s:%s\n", hour, arr[1], arr[2]);
    char *res = malloc((strlen(buf) +1 ) * sizeof(char));
    strcpy(res, buf);
    return res;
}
