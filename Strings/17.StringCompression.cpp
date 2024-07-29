int compress(vector<char>& s) {
        if (s.empty()) return 0; // handle empty input
        
        int index = 0;
        char prev = s[0];
        int count = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i < s.size() && s[i] == prev) {
                count++;
            } 
            else {
                s[index] = prev;
                index++;
                if (count > 1) {
                    int start = index;
                    while (count) {
                        s[index] = (count % 10) + '0';
                        index++;
                        count = count / 10;
                    }
                    reverse(s.begin() + start, s.begin() + index);
                }
                if (i < s.size()) {
                    prev = s[i];
                    count = 1;
                }
            }
        }

        return index;
    }