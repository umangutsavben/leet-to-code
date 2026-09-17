class Solution {
public:
    int f(int idx,vector<int>&nums,int k,int n,vector<int>&tmp){
        if(idx == n) return 0;
        // at each node i have to check so ...
        int dif;
        int flag = 0;
        for(int i=0;i<tmp.size();i++){
            dif = abs(tmp[i] - nums[idx]);
            if(dif == k) flag=1;
        }
        tmp.push_back(nums[idx]);
        //take
        int take = 0;
        if(flag == 0) take = 1+f(idx+1,nums,k,n,tmp);
        tmp.pop_back();
        int not_take = f(idx+1,nums,k,n,tmp);
        return take + not_take;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>tmp;
        return f(0,nums,k,n,tmp);
    }
};