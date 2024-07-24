bool isVowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'|| 
        s=='A' || s=='E' ||s=='I' ||s=='O' || s=='U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(isVowel(s[i]) and isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isVowel(s[i]))
                i++;
            else
                j--;
        }
        return s;
    }