/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-diagonal-difference/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-one
*/

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int left = 0;
    int right = 0;
    for(int i = 0 ; i < arr_columns;i++){
        left += arr[i][i];
        right += arr[i][arr_columns-i -1];
        // printf("left=%d, right=%d\n", left, right);
    }
    return abs(left - right);
}
