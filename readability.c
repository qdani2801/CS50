// Including all necessary libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Declaring function Prototypes
int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void){
    string text = get_string("Text: ");

    // Counting total number of Letters, Words and Sentences in the given text by user
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);

    // Calculating the Value of L and S for the Index Formula
    float L = ((float) num_letters / num_words) * 100;
    float S = ((float) num_sentences / num_words) * 100;

    // Calculating the Index Formula to find out the Grade level
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1){
        printf("Before Grade 1\n");
    }
    else if (index > 16){
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %i\n", index);
    }

}

// Defining Function for counting total letters in User Provided Text, only looks for characters that fall into Uppercase or Lowercase Alphabets
int count_letters(string s){
    int n = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if ((s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= 'a' && s[i] <= 'z')){
            n += 1;
        }
    }
    return n;
}

// Defining Function for counting total words in User Provided Text, only looks for spaces that seperate Words
int count_words(string s){
    int n = 1;
    // int j = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i ++){
        if(isspace(s[i])){
            n += 1;
        }
    }
    return n;
}

// Defining Function for counting total sentences in User Provided Text, only looks for '!', '?' and '.'.
int count_sentences(string s){
    int n = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (s[i] == '.' || s[i] == '!' || s[i] == '?'){
            n += 1;
        }
    }
    return n;
}

// check50 cs50/problems/2022/x/readability
