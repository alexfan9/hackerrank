/*
https://www.hackerrank.com/challenges/permutations-of-strings/problem?isFullScreen=true
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void* e1, const void* e2)
{
    int ret = strcmp((char *)e1,(char *)e2); 
    if(ret > 0) {
        return 1;
    } else {
        return 0;
    }
}

void sort_test(){
    int i = 0;
    int n = 3;
    char **s = calloc(n, sizeof(char*));
    s[0] = calloc(11, sizeof(char));
    strcpy(s[0], "bc");
    s[1] = calloc(11, sizeof(char));
    strcpy(s[1], "bc");
    s[2] = calloc(11, sizeof(char));
    strcpy(s[2], "a");
    
    printf("sort_test start\n");
    for (int i = 0; i < n; i++)
        printf("{%s}%c", s[i], i == n - 1 ? '\n' : ' ');
        
    qsort(s, 2, sizeof(char*), cmp_str);
    printf("after  sort\n");
    for (int i = 0; i < n; i++)
        printf("{%s}%c", s[i], i == n - 1 ? '\n' : ' ');
    printf("sort_test end\n");
    for (i = 0; i < n; i++)
        free(s[i]);
    free(s);
}

int next_permutation(int n, char **a)
{

    int i = 0;
    int j = 0;
    if (n <= 1) return 0;
    int found = 0;

    // sort_test();
    
    for(i = n-1; i >= 0; i--){
        for(j = i-1; j >=0; j--){
            if(strcmp(a[i], a[j]) > 0){
                char *tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                found = 1;
                break;
            }
        }
        if(found){
            break;
        }
    }
    if(found == 0) {
        return 0;
    }
    

    int count = n - j - 1;
    int start = j+1;
    qsort(&a[start], count, sizeof(a[0]), cmp_str);
    return 1;
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
