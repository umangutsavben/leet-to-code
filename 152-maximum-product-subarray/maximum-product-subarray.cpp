class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int preffix = 1;
        int suffix = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                preffix = 1;
                ans = max(0,ans);
            }
            else{
                preffix = preffix * nums[i];
                ans = max(preffix,ans);
            }
            if(nums[n-i-1]==0){
                suffix = 1;
                ans = max(0,ans);
            }
            else{
                suffix = suffix * nums[n-i-1];
                ans = max(suffix,ans);
            }
        }
        return ans;
    }
};