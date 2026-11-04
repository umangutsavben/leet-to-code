class Solution {
public:
    int f(vector<int>& nums, int k){
        int n = nums.size();
        map<int,int>mp;
        int j = 0;
        int ct = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(j<=i && mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            if(mp.size()<=k){
                ct += (i - j + 1);
            }
        }
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return f(nums,k)-f(nums,k-1);
    }
};