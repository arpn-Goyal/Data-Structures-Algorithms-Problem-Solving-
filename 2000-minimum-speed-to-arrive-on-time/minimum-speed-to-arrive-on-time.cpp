class Solution {
public:
    bool possible(vector<int>& dist, double hour, int speed){
        double time = 0;
        for(int i = 0; i < dist.size(); i++){
            double travelTime = (double)dist[i] / speed;
            if(i == dist.size() - 1){
                time += travelTime;
            }
            else{
                time = ceil(time + travelTime);
            }
        }
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(dist, hour, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};