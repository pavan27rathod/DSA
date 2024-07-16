#include <bits/stdc++.h>
using namespace std;

void replaceChars(char ch[], int size){
    int i=0;
    while(ch[i]!='\0'){
        if(ch[i]=='@')
            ch[i]=' ';
        i++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    replaceChars(ch,100);
    cout<<ch<<endl;
}