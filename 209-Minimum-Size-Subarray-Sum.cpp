class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum =0;
        int minL = INT_MAX;

        for(int right=0; right < n; ++right){
            sum += nums[right];
            while(sum >= target){
                minL = min(minL, right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return minL == INT_MAX ? 0 : minL ;
    }
};