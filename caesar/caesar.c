// Created by hespinoza on 02-11-19.
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getKey(string value);
string plaintext();
void cipher(string value, int key);
char change(char value, int key);

int main(int argc, char* argv[]){
    if(argc != 2 && atoi(argv[1]) < 1) return 1;

    int key = getKey(argv[1]);
    string _plaintext = plaintext();

    cipher(_plaintext, key);

    return 0;
}

int getKey(string value){
    return (atoi(value) > 26) ? atoi(value)%26 : atoi(value);
}

string plaintext(){
    string value = get_string("plaintext: ");
    return (strlen(value) > 0) ? value : plaintext();
}

void cipher(string value, int key){
    printf("ciphertext: ");
    for(int i=0; i<strlen(value); i++){
        char letter = (isalpha(value[i])) ? change(value[i], key) : value[i];
        printf("%c", letter);
    }
    printf("\n");
}

char change(char value, int key){
    int l = value + key;
    return islower(value) ? (((l - 97) % 26) + 97) : (((l - 65) % 26) + 65);
}