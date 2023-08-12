/* Online C Compiler and Editor */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    printf("get_document enter\n");
    char *p = text;
    int word_start = 0, word_end = 0;
    
    struct document doc;
    int word_count = 0;
    int sentence_count = 0;
    int paragraph_count = 0;
    
    struct paragraph *p_paragraph = NULL;
    struct sentence *p_sentence = NULL;
    struct word *p_word = NULL;
  
    while (*p != '\0'){
        if(*p == ' ' || *p == '.'){
            word_end = p - text;
            p_word = (struct word*)realloc(p_word, (word_count +1 )* sizeof(struct word*));
            char *p_data = calloc(word_end-word_start +1, sizeof(char));
            strncpy(p_data, text+word_start, word_end-word_start);
            p_word[word_count].data = p_data;
            
            if(p_sentence == NULL){
                p_sentence = calloc(1, sizeof(struct sentence*));
            }
            printf("word_count=%d,p_word->data=%s\n", word_count, p_word[word_count].data);
            word_count ++;
            printf("size=%ld\n", word_count * sizeof(struct word *));
            p_sentence->data = (struct word *)realloc(p_sentence->data, word_count * sizeof(struct word *));
            printf("\np_word=%p\n", p_word+word_count);
            printf("p_sentence=%p\n", p_sentence);
            printf("p_sentence->data=%p\n\n\n", p_sentence->data+word_count);
            p_sentence->data[word_count] = *p_word;
            p_sentence->word_count = word_count; 
            word_start = word_end + 1;
        }
        if(*p == '.') {
            word_count = 0;
            sentence_count++;
            
            if(p_paragraph == NULL){
                p_paragraph = calloc(1, sizeof(struct paragraph*));
            }
            printf("get_document enter 999999\n");
            printf("sentence_count=%d\n", sentence_count);
            p_paragraph->data = (struct sentence *)realloc(p_paragraph->data, sentence_count * sizeof(struct sentence *));
            printf("p_paragraph=%p\n", p_paragraph);
            p_paragraph->data[sentence_count] = *p_sentence;
            p_paragraph->sentence_count = sentence_count;

            p_word = NULL;
            p_sentence = NULL;
        }
        if(*p == '\n') {
            sentence_count = 0;
            paragraph_count++;
            word_start ++; /* skip '\n' for new word*/
            printf("222");
            doc.data = (struct paragraph *)realloc(doc.data, paragraph_count * sizeof(struct paragraph *));
            
            doc.data[paragraph_count] = *p_paragraph;
            doc.paragraph_count = paragraph_count;
            p_paragraph = NULL;
        }
        p++;
    }
    /*The last paragraph which is not end of '\n'*/
    printf("111");
    paragraph_count ++;
    doc.data = (struct paragraph *)realloc(doc.data, paragraph_count * sizeof(struct paragraph *));
    doc.data[paragraph_count] = *p_paragraph;
    doc.paragraph_count = paragraph_count;

    return doc;
}

int main()
{
    char *s = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";
    
    printf("hello\n");
    struct document doc = get_document(s);
    // printf("doc.paragraph_count=%d\n", doc.paragraph_count);
    // for(int i = 0; i < doc.paragraph_count; i++){
    //     printf("sentence_count of paragraph%d is %d\n", i, doc.data[i].sentence_count);
    // }

    return 0;
}
