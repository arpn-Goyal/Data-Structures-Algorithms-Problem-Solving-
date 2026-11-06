class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int windowSize = p.size();

        unordered_map<char, int> freq;
        for(char ch : p){
            freq[ch]++;
        }

        unordered_map<char, int> mp;
        vector<int> result;
        for(int right = 0; right < s.size(); right++){
            mp[s[right]]++;

            if(right - left + 1 == windowSize){

                if(mp == freq)
                    result.push_back(left);
                
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return result;
    }
};