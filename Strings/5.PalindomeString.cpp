#include<iostream>
#include<string.h>
using namespace std;

bool palindromeString(char ch[], int size){
    int i=0, j=size-1;
    while(i<=j){
        if(ch[i]!=ch[j]) return false;
        if(ch[i]==ch[j]){
            i++;
            j--;
        }
    }
   return true;
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int size = strlen(ch);
    if(palindromeString(ch,size))
        cout<<"true";
    else
        cout<<"false";
}