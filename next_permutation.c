#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_int(const void* e1, const void* e2){
    return *(int*)e1 - *(int*)e2;
}

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int n, int *a)
{
    int has_next = 0;
    int i, j;
    if (n <= 1) return has_next;

    for(i = n-1; i >= 0; i--){
        for(j = i-1; j >=0; j--){
            if(a[i] > a[j]){
                swap(&a[i], &a[j]);
                has_next = 1;
                break;
            }
        }
        if(has_next){
            break;
        }
    }
    if(has_next == 0) return has_next;

    j += 1;
    qsort(a+j, n - j, sizeof(int), cmp_int);

    return has_next;
}

int main()
{
    int arr[3] = {1,2,3};
    int n = 3;
    int i= 0;
    do
    {
        for (i = 0; i < n; i++)
            printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, arr));

    return 0;
}
