class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;

        int left = 1, right = x;
        int result = 0;
        while(left <= right){
            long long mid = left + (right - right)/2;
            long long square = mid * mid;

            if(square == x){
                return mid;
            }
            else if(square < x){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        }
        return result;
    }
};