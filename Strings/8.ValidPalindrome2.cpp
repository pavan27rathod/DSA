//Q. https://leetcode.com/problems/valid-palindrome-ii/description/
bool checkPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            if(s[i]==s[j]){
                i++;
                j--;
            }
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                bool ans1=checkPalindrome(i+1,j,s);
                bool ans2=checkPalindrome(i,j-1,s);
                return ans1||ans2;
            }
        }
        return true;
    }
