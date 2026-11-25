class Solution {
public:
    bool possible(vector<int>& position, int m, int distance){
        int cntBalls = 1, lastPosition = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i] - lastPosition >= distance){
                cntBalls++;
                lastPosition = position[i];
            }
            if(cntBalls >= m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(), position.end());

        int low = 1, high = position[position.size() - 1] - position[0];

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(position, m, mid)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low - 1;
    }
};