#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
char a[30], b[30];
int len1, len2;
//
// Created by treelanguage on 10/29/2022.
//

void calculateAllPlus(int num) {
    int sum = 0;
    for (int i; i <= num; i++) {
        sum += i;
    }
    printf("The result is %d", sum);
}

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
}

void transformAa() {
    int input = 0;
    while ((scanf("%c", &input)) != EOF) {
        if (input >= 'A' && input <= 'Z') {
            //input = input + 32;
            printf("%c", input);
        } else if (input >= 'a' && input <= 'z') {
            input = input - 32;
            printf("%c", input);
        }
    }
}

int LCS(int i, int j)
{
    if (i >= len1 || j >= len2) {
        return 0;
    }
    if (a[i] == b[j]) {
        return 1 + LCS(i + 1, j + 1);
    }else{
        return LCS(i + 1, j)>LCS(i, j + 1) ? LCS(i + 1, j) : LCS(i, j + 1);
    }
}

void manStringMatch(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int maxL = 0, c = 0;
    int t = 0;
    for (int i = 0; i<str1.size()&&t<str1.size(); i++) {
        auto re = str2.find(str1[i]);
        while (re != string::npos) {
            t = i;
            int b = re;
            while (t<str1.size() && re<str2.size() && str1[t] == str2[re]) {
                ++t;
                ++re;
            }
            if (maxL<t - i) {
                c = i;
                maxL = t - i;
            }
            if (b<str2.size() - 1) {
                re = str2.find(str1[i],b+1);
            }
            else {
                break;
            }
            if (t == str1.size()) {
                break;
            }
        }
    }
    cout << maxL << endl;
    cout << str1.substr(c, maxL) << endl;
}


int main_null() {
    int n;
    manStringMatch();
    printf("Please tell what do you want to do\n"
           "1. calculateAllPlus\n"
           "2. compareStringLen\n"
           "3. transformAa\n"
           "4. manStringMatch\n"
           "Enter below number\n");
    scanf("%d",&n);
    switch(n){
        case 1:
            int m;
            printf("Please tell 1+2+...+*\nEnter the * to calculate\n");
            scanf("%d",&m);
            calculateAllPlus(m);
            break;
        case 2:
            char *c1,*c2;
            printf("Error\nPlease tell me two letter then to compare\n");
            scanf("%d",&c1);
            scanf("%d",&c2);

            compareStringLen(c1, c2);
            break;
        case 3:
            int b;
            printf("Error\nPlease tell me letter to transform\n");
            transformAa();
            break;
        case 4:
            printf("Error\nPlease tell me two letter then to match\n");
            manStringMatch();
            break;
        default:
            break;
    }
    return 0;
}
