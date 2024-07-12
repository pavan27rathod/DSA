//Q. Reverse the given String
#include<bits/stdc++.h>
using namespace std;
void reverse(char ch[], int size){
    int i=0;
    int j=size-1;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int size=strlen(ch);
    reverse(ch,size);
    cout<<ch;
}