#include <bits/stdc++.h>
using namespace std;
void toUpperCase(char ch[], int size){
    int i=0;
    while(ch[i]!='\0'){
        if(ch[i]>='a' && ch[i]<='z'){
            ch[i]=ch[i]-'a'+'A';
        }
        i++;
    }
}

void toLowerCase(char ch[], int size){
    int i=0;
    while(ch[i]!='\0'){
        if(ch[i]>='A' and ch[i]<='Z')
            ch[i]=ch[i]-'A'+'a';
        i++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    // toUpperCase(ch,100);
    toLowerCase(ch,100);
    cout<<ch<<endl;
}