#include <iostream>
#include <string>
using namespace std;

void lastOccurrence(string s, char c, int size, int index, int &ans) {
    if(index >= size)
        return;
    if(s[index]==c)
        ans=index;
    lastOccurrence(s,c,size,index+1,ans);
}

void lastOccurrence2(string s, char c, int size, int index, int &ans){
    if(index >= size)
        return;
    if(s[index]==c){
        ans=index; //When we traverse from last to first then we stop once we get the char
        return;
    }
    lastOccurrence2(s,c,size,index-1,ans);      
}

int main() {
    string s = "dcaaaaabd";
    char c = 'c';
    int size = s.size();
    int index = size-1;
    int ans=-1;
    lastOccurrence2(s, c, size, index,ans);
    cout<<ans;
}
