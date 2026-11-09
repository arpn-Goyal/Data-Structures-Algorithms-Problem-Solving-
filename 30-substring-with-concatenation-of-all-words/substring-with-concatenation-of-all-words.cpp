class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (words.empty() || s.empty()) {
            return result;
        }

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        // this length will be our valid substring window

        if (s.size() < totalLen)
            return result;

        // Frequency of required words
        unordered_map<string, int> required;
        for (string word : words) {
            required[word]++;
        }

        // Try every possible word alignment
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset; right + wordLen <= s.size();
                 right += wordLen) {

                // Extract current word
                string word = s.substr(right, wordLen);

                // Case 1: Word is not required
                if (required.find(word) == required.end()) {

                    window.clear();
                    count = 0;
                    left = right + wordLen;

                    continue;
                }

                // Add current word
                window[word]++;
                count++;

                // Case 2: Current word occurs more than required
                while (window[word] > required[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    count--;

                    if (window[leftWord] == 0) {
                        window.erase(leftWord);
                    }

                    left += wordLen;
                }

                // Case 3: Found all required words
                if (count == wordCount) {

                    result.push_back(left);

                    // Remove leftmost word to continue searching
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    count--;

                    if (window[leftWord] == 0) {
                        window.erase(leftWord);
                    }

                    left += wordLen;
                }
            }
        }
        return result;
    }
};