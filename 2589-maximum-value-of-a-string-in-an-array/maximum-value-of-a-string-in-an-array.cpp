class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;

        for (string s : strs) {
            bool isNumber = true;

            for (char c : s) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            int value;

            if (isNumber)
                value = stoi(s);
            else
                value = s.length();

            ans = max(ans, value);
        }

        return ans;
    }
};