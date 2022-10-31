#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
//
// Created by treelanguage on 10/29/2022.
//

char compareStringLen(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        printf("1");
    } else if (len1 < len2) {
        printf("2");
    } else {
        printf("3");
    }
    return 0;
}

int main(){

    compareStringLen("zhitingxuan","tingxuan");
    return 0;
}