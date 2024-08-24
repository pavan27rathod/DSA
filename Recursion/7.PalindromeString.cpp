#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s, int start, int end){
    if(start>end)
        return true;
    bool ans=false;
    if(s[start]==s[end])
        return true;
    isPalindrome(s,start+1,end-1);
    return ans;
}

int main(){
    string s="radara";
    cout<<isPalindrome(s,0,s.length()-1)<<endl;
}