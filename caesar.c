// Including all the necessary libraries
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Declaring function prototypes
bool only_digits(string s);
char rotate(char c, int k);

// Giving command line arguments to main()
int main(int argc, string argv[]){

    // If user enters none or more than just 1 word for key, we will return 1 error with error msg
    if (argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // If the user enters only 1 argument for key, we check whether its a digit by using only_digit()
    else if (argc == 2){
        bool check = only_digits(argv[1]);

        // If its a digit then we proceed further to our main work
        if (check ==true){
            // Converting the string argv[1] into a integer and assigning that to key
            int key = atoi(argv[1]);
            printf("plaintext:  ");
            string p = get_string("");
            string c = p;
            printf("ciphertext: ");
            int n = strlen(p);
            for (int i = 0; i < n; i++){
                // Using rotate() to convert plaintext character into ciphered character using given key by user
                c[i] = rotate(p[i], key);
                // Printing the value assigned to c[i] on the loop without any line break
                printf("%c", c[i]);
            }
            // Using line break to move the $ sign on the new line
            printf("\n");
        }
        // If the string in place of key is not a digit then we return error code 1 with error message
        else {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
}

// Using this function for checking whether the characters in argv[1] are digit or not
bool only_digits(string s){
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        // If even a single character is not a digit, we return false
        if (!isdigit(s[i])){
            return false;
        }
    }
    // If loop runs successfully then we return true
    return true;
}

// Using rotate() by passing it single character from loop along with key
char rotate(char c, int k){
    char t;
    // If the character falls between ASCII value of A and Z, meaning uppercase, then we compute as follows
    if (c >= 'A' && c <= 'Z'){
        t = 'A' + (c + k - 'A') % 26;
    }
    // If the character falls between ASCII value of a and z, meaning lowercase, then we compute as follows
    else if (c >= 'a' && c <= 'z'){
        t = 'a' + (c + k - 'a') % 26;
    }
    // If it doesnt fall in upper or lower case then it must be a non decimal value and we assign it as it is
    else {
        t = c;
    }
    // Finally returning t to be assigned for c[i]
    return t;
}

// check50 cs50/problems/2022/x/caesar
