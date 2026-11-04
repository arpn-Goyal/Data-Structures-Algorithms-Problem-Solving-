class Solution {
public:
    int checkPalindrome(string s, int left, int right){
        while(left <= right){
            if(s[left] != s[right]) return 0;

            else{
                left++, right--;
            }
        }
        return 1;
    }
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                result += checkPalindrome(s, i, j);
            }
        }
        return result;
    }
};