class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        int windowSize = s1.size();
        int left = 0;
        unordered_map<char,int> freq;
        for(char ch : s1){
            freq[ch]++;
        }
        unordered_map<char, int> window;
        for(int right = 0; right < s2.size(); right++){
            window[s2[right]]++;

            if(right - left + 1 == windowSize){

                if(window == freq) return true;
                
                window[s2[left]]--;
                if(window[s2[left]] == 0){
                    window.erase(s2[left]);
                }

                left++;
            }
        }
        return false;
    }
};