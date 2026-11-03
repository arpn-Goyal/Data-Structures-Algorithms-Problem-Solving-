class Solution {
public:
    bool isAlp(char ch){
        return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right){
            while(left < right && !isAlp(s[left])) left++;
            while(left < right && !isAlp(s[right])) right--;

            if(tolower(s[left]) != tolower(s[right])) return false;

            left++, right--;
        }
        return true;
    }
};