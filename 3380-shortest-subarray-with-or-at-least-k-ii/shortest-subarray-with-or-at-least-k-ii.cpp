class Solution {
public:
    void update(vector<int>&nums,int i,map<int,int>&mp){
        int tmp = nums[i];
        for(int i=0;i<32;i++){
            mp[i] = mp[i] + (tmp&1);
            tmp = tmp>>1;
        }
    }
    int build(map<int,int>&mp){
        int n = 0;
        for(int i=0;i<32;i++){
            if(mp[i] > 0){
                n |= (1 << i);
            }
        }
        return n;
    }
    void reduce(int tmp,map<int,int>&mp){
        for(int i=0;i<32;i++){
            if(tmp&1){
                mp[i]--;
            }
            tmp = tmp>>1;
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<32;i++){
            mp[i] = 0;
        }
        int ret = INT_MAX;
        int curr=0;
        int j = 0;
        for(int i=0;i<n;i++){
            update(nums,i,mp);
            curr = build(mp);
            while(j <= i && curr>=k){
                if(ret>i-j+1){
                    ret = i-j+1;
                }
                reduce(nums[j],mp);
                curr = build(mp);
                j++;
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};