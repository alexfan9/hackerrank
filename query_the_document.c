/*
Hanckerrank
https://www.hackerrank.com/challenges/querying-the-document/problem?isFullScreen=true&h_r=next-challenge&h_v=zen 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    printf("k=%d, m=%d, n=%d\n", k, m, n);
    return document[k-1][m-1][n-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    printf("k=%d, m=%d\n", k, m); 
    return document[k-1][m-1];
}

char*** kth_paragraph(char**** document, int k) {
    printf("k=%d\n", k);
    return document[k-1];
}
char**** get_document(char* text) {
    char *p = text;
    int word_start = 0, word_end = 0;
    
    
    char **sentence = NULL;
    char ***para = NULL;
    char ****doc = NULL;
    int word_count = 0;
    int sentence_count = 0;
    int para_count = 0;
    
    while (*p != '\0'){
        if(*p == ' ' || *p == '.'){
            word_end = p - text;
            char *word = calloc(100, sizeof(char));
            strncpy(word, text+word_start, word_end-word_start);
            word_count ++;
            
            sentence = (char**)realloc(sentence, word_count * sizeof(char*));
            sentence[word_count-1] = word; 
            word_start = word_end + 1;
        }
        if(*p == '.') {
            word_count = 0;
            sentence_count++;
            
            para = (char***)realloc(para, sentence_count * sizeof(char**));
            para[sentence_count-1] = sentence;
            sentence = NULL;
        }
        if(*p == '\n') {
            sentence_count = 0;
            para_count++;
            doc = (char****)realloc(doc, para_count * sizeof(char***));
            doc[para_count-1] = para;
            para = NULL;
        }
        p++;
    }
    /*The last paragraph which is not end of '\n'*/
    para_count++;
    doc = (char****)realloc(doc, para_count * sizeof(char***));
    doc[para_count-1] = para;
    printf("para_count=%d\n", para_count);
    return doc;
}



char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
