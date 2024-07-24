//Q. https://leetcode.com/problems/isomorphic-strings/description/
 bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        char mapS[256] = {0};
        char mapT[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapS[c1] == 0 && mapT[c2] == 0) {
                // Map c1 to c2 and c2 to c1
                mapS[c1] = c2;
                mapT[c2] = c1;
            } else if (mapS[c1] != c2 || mapT[c2] != c1) {
                // If there's a mismatch in the expected mapping, return false
                return false;
            }
        }

    return true;