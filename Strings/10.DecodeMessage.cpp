//Q. https://leetcode.com/problems/decode-the-message/
string decodeMessage(string key, string message) {
        char start='a';
        char mapping[300]={0};
        for(auto ch: key){
            if(ch!=' ' && mapping[ch]==0){
                mapping[ch]=start;
                start++;
            }
        }
        string ans;
        for(auto ch: message){
            if(ch!=' '){
                char decodedChar=mapping[ch];
                ans.push_back(decodedChar);
            }
            else{
                ans.push_back(' ');
            }
            
        }
        return ans;
    }