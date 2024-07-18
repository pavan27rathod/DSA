#include<bits/stdc++.h>
#include<string>
using namespace std;

string removeOccurances(string s, string part){
    while(s.find(part)!=string::npos){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    string s;
    string part;
    cin>>s>>part;
    cout<<removeOccurances(s,part);
}