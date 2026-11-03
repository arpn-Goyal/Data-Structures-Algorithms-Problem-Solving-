class Solution {
public:
    bool checkPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }

            left++, right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right){
            // we check when left and right pointer character is not equal to each other for palindrome
            // In this we simply check condition for both pointers
            //  while not-include once left pointer, with rest of string(if palindromes just return true)
            // While not-include once right pointer, with rest of string(if palindrome just return true)
            if(s[left] != s[right]){
                return ((checkPalindrome(s, left, right - 1))|| (checkPalindrome(s, left + 1, right)));
            }
            // else
            left++, right--;
        }
        return true;
    }
};