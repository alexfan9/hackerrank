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
            if(p_word == NULL) {
                printf("realloc p_word fails\n");
                return doc;
            }
            char *p_data = calloc(word_end-word_start +1, sizeof(char));
            if(p_data == NULL) {
                printf("realloc p_data fails\n");
                return doc;
            }
            strncpy(p_data, text+word_start, word_end-word_start);
            p_word[word_count].data = p_data;
            word_count ++;
            word_start = word_end + 1;
        }
        if(*p == '.') {
            p_sentence = realloc(p_sentence, (sentence_count+1) * sizeof(struct sentence*));
            if(p_sentence == NULL) {
                printf("realloc p_sentence fails\n");
                return doc;
            }
            p_sentence[sentence_count].data = p_word;
            p_sentence[sentence_count].word_count = word_count;
            
            word_count = 0;
            sentence_count++;
            

            p_word = NULL;
            
        }
        if(*p == '\n') {
            p_paragraph = realloc(p_paragraph, (paragraph_count+1) * sizeof(struct paragraph*));
            if(p_paragraph == NULL) {
                printf("realloc p_sentence fails\n");
                return doc;
            }
            p_paragraph[paragraph_count].data = p_sentence;
            p_paragraph[paragraph_count].sentence_count = sentence_count;
            sentence_count = 0;
            paragraph_count++;
            p_sentence = NULL;
            word_start+= 1;
        }
        p++;
    }
    /*The last paragraph which is not end of '\n'*/
    p_paragraph = realloc(p_paragraph, (paragraph_count+1) * sizeof(struct paragraph*));
    if(p_paragraph == NULL) {
        printf("realloc p_sentence fails\n");
        return doc;
    }
    p_paragraph[paragraph_count].data = p_sentence;
    p_paragraph[paragraph_count].sentence_count = sentence_count;
    
    paragraph_count ++;
    
    doc.data= p_paragraph;
    doc.paragraph_count = paragraph_count;

    return doc;
}

void print_doc(struct document doc){
    for(int i = 0; i < doc.paragraph_count; i++){
        struct paragraph* p_paragraph = &doc.data[i];
        
        for(int j = 0; j < p_paragraph->sentence_count; j++){
            struct sentence* p_sentence = &p_paragraph->data[j];
            for(int k = 0; k < p_sentence->word_count; k++){
                struct word* p_word = &p_sentence->data[k];
                printf("%s ", p_word->data);
            }
            printf(".");
        }
        printf("\n");
    }
}

void free_doc(struct document doc){
    for(int i = 0; i < doc.paragraph_count; i++){
        struct paragraph* p_paragraph = &doc.data[i];
        
        for(int j = 0; j < p_paragraph->sentence_count; j++){
            struct sentence* p_sentence = &p_paragraph->data[j];
            for(int k = 0; k < p_sentence->word_count; k++){
                struct word* p_word = &p_sentence->data[k];
                printf("k=%d, p_word->data=%p\n", k, p_word->data);
                free(p_word->data);
            }
            //free(p_sentence->data);
        }
        //free(p_paragraph->data);
    }
}

int main()
{
    char *s = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";
    struct document doc = get_document(s);
    print_doc(doc);
    // free_doc(doc);
    return 0;
}
