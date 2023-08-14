/*
* https://www.hackerrank.com/challenges/one-month-preparation-kit-sparse-arrays/problem?h_l=interview&isFullScreen=false&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
*/
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int *result = calloc(queries_count, sizeof(int));
    for(int i = 0; i < queries_count; i++){
        for(int j = 0; j < strings_count; j++){
            if(strcmp(queries[i], strings[j]) == 0){
                result[i] ++;
            }
        }
    }
    *result_count = queries_count;
    return result;
}
