/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-drawing-book/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-two
*/

/*
*/
int pageCount(int n, int p) {
    int mid = n / 2;
    if(mid >= p) {
        return p/2;
    } else {
        return abs(p /2 - mid);
    }
}
