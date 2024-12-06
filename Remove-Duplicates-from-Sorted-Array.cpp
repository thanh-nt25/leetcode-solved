#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> orderDup(nums.begin(), nums.end());
        int k = orderDup.size();

        auto it = orderDup.begin();
        for (int i=0; i < k; ++it, ++i){
            nums[i] = *it;
        }
        
        return k;
    }
};

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int j=1;
//         for(int i=1; i < nums.size(); ++i){
//             if(nums[i] != nums[i-1]){
//                 nums[j] = nums[i];
//                 j++;
//             }
//         }
//         return j;
//     }
// };

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = solution.removeDuplicates(nums);
    
    cout << solution.removeDuplicates(nums) << endl;
    for (int i=0; i < k; ++i){
        cout << nums[i] << endl;
    }


}