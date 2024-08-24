// Q. https://leetcode.com/problems/add-strings/

void addRecursively(string &x, int p1, string &y, int p2, string &ans, int carry){
        if (p1 < 0 && p2 < 0) {
            if (carry != 0) {
                ans.push_back(carry + '0');
            }
            return;
        }

        // Extract digits from the strings, or use '0' if indices are out of bounds
        int n1 = (p1 >= 0 ? x[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? y[p2] : '0') - '0';
        int sum = n1 + n2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit + '0');  // Digits are added in reverse order

        addRecursively(x, p1 - 1, y, p2 - 1, ans, carry);
    }

    string addStrings(string x, string y) {
        string ans = "";
        addRecursively(x, x.size() - 1, y, y.size() - 1, ans, 0);
        reverse(ans.begin(), ans.end());  // The issue is here; the reversal should happen outside the recursion
        return ans;
    }