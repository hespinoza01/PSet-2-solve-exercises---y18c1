// Created by hespinoza on 02-12-19.
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool verify(int argc, string argv[]);
string plaintext();
int change(char character, int index, string key);
void cipher(string value, string key);

int main(int argc, string argv[]){
    if(verify(argc, argv)) return 1;

    string _key = argv[1];
    string _plaintext = plaintext();

    cipher(_plaintext, _key);

    return 0;
}

bool verify(int argc, string argv[]){ // verify the arguments counter
    if(argc != 2){
        printf("Wrong number of arguments. Please try again.\n");
        return false;
    }

    bool isNotAlpha = false;
    string value = argv[1];

    for(int i=0; i<strlen(value); i++){  isNotAlpha = (isalpha(value[i])) ? false : true;  }
    if(isNotAlpha) printf("Key must be alphabetic chars only.\n");

    return isNotAlpha;
}

string plaintext(){ // get text to encode
    string value = get_string("plaintext: ");
    return (strlen(value) > 0) ? value : plaintext();
}

int change(char character, int index, string key){ // change the character value
    int keyLen = strlen(key);
    int keyInt = tolower(key[index % keyLen]) - 'a';
    int l = character + keyInt;

    return islower(character) ? (((l - 97) % 26) + 97) : (((l - 65) % 26) + 65);
}

void cipher(string value, string key){ // encode input text
    printf("ciphertext: ");
    for(int i=0, j=0; i<strlen(value); i++){
        char letter = (isalpha(value[i])) ? change(value[i], j, key) : value[i];
        if(isalpha(value[i])) j++;
        printf("%c", letter);
    }
    printf("\n");
}