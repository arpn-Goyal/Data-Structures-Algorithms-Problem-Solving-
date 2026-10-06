class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxFruits = 0;
        vector<int> freq(100001, 0);
        int distinct = 0;

        for(int right = 0; right < fruits.size(); right++){
            // Add right fruit
            if (freq[fruits[right]] == 0)
                distinct++;

            freq[fruits[right]]++;

            // Shrink until only 2 types remain
            while(distinct > 2){
                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0)
                    distinct--;

                left++;
            }
            // Valid window
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};