#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;
bool ValidAnagram(string str, string str2){
    string tempStr=str;
    string tempStr2=str2;
    sort(tempStr.begin(),tempStr.end());
    sort(tempStr2.begin(),tempStr2.end());
    if(tempStr==tempStr2)
        return true;
    else 
        return false;
}

int main(){
    string str="anagram";
    string str2="nagaram";
    cout<<ValidAnagram(str,str2);

}