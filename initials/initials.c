// Created by hespinoza on 02-11-19.
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string name();
void upper(string value, int index);
void initials(string value, int index);

int main(void){
    initials(name(), 0);
    return 0;
}

string name(){ // get the name value
    string _name = get_string("");
    return (strlen(_name) > 0) ? _name : name();
}

void upper(string value, int index){ // convert char to upper value
    printf("%c",toupper(value[ (index==1) ? index-1 : index ]));
}

void initials(string value, int index){ // travel the name
    if(value[index] == ' ' || index == 0)  upper(value, index + 1);
    (index < strlen(value)) ? initials(value, index + 1) : printf("\n");
}