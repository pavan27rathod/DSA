#include<iostream>
#include<vector>
#include<string>
using namespace std;

// void findSubSequences(string str, string output, int index, vector<string> &ans){
//     if(index>=str.length()){
//         //required answer is achieved in output string
//         ans.push_back(output);
//         return;
//     }

//     //Get single character to include or exclude
//     char ch=str[index];

//     //Include this current character in output string
//     output.push_back(ch);
//     //Do same steps again for further character
//     findSubSequences(str, output, index+1, ans);

//     //Exclude the current character in output string
//     output.pop_back(); // we first include an element in the subset, then explore further, and finally, we remove it (using pop_back()) to explore the possibility of excluding it
//     //Do same steps again for further character
//     findSubSequences(str, output, index+1, ans);
// }

void findSubSequences(string str, string output, int index, vector <string> &ans){
    if(index>=str.length()){
        //required answer is achieved in output string
        ans.push_back(output);
        return;
    }
    char ch=str[index];
    
    //Exclude first
    findSubSequences(str, output, index+1, ans);

    //Include later
    output.push_back(ch);
    findSubSequences(str,output,index+1,ans);
}

int main(){
    string str="abc";
    string output="";
    vector<string> ans;
    findSubSequences(str, output, 0, ans);
    cout<<"Printing subsequences, subsequencr will contain empty string too : "<<endl;
    for(string s : ans){
        cout<<"-> "<<s<<endl;
    }
}