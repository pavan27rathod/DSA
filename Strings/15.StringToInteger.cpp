   int myAtoi(string s) {
        int i = 0;
        int num = 0;
        int sign = 1;

        // Ignore leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        // Convert digits to integer
        while (i < s.size() && isdigit(s[i])) {
            // Handle overflow and underflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (s[i] - '0');
            i++;
        }

    return num * sign;
}