class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) return "";

        unordered_map<char, int> freq;
        for (char ch : t) {
            freq[ch]++;
        }

        unordered_map<char, int> window;

        int required = freq.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int startIndex = 0;

        for (int right = 0; right < n; right++) {

            // 1. Expand the window
            char ch = s[right];
            window[ch]++;

            // 2. Check whether this character's requirement is satisfied
            if (freq.count(ch) && window[ch] == freq[ch]) {
                formed++;
            }

            // 3. Shrink while the window is valid
            while (formed == required) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Remove the leftmost character
                char leftChar = s[left];
                window[leftChar]--;

                // Check whether removing it breaks validity
                if (freq.count(leftChar) &&
                    window[leftChar] < freq[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(startIndex, minLen);
    }
};