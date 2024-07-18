//Q. https://leetcode.com/problems/palindromic-substrings/
    
    //Expands around the center indices i and j, counting palindromic substrings.
    int expand(string s, int i, int j){
        int count=0;
        //increments count for each palindrome found, then moves outward.
        while(i>=0 && j<s.length() && s[i]==s[j]){
                count++;
                i--;
                j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount=0;
        //Calls expand for odd-length palindromes (center at i).
        //Calls expand for even-length palindromes (center between i and i+1).
        //Adds the counts from both calls to totalCount.
        //Returns totalCount.
        for(int i=0;i<s.length();i++){
            int oddAns=expand(s,i,i);
            int evenAns=expand(s,i,i+1);
            totalCount=oddAns+evenAns+totalCount;
        }
        return totalCount;
    }