class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[0];
        int ct = 0;
        while(tmp){
            ct++;
            tmp = tmp/10;
        }
        vector<map<int,int>>v(ct);
        for(int i=0;i<n;i++){
            int tmp = nums[i];
            for(int j=0;j<ct;j++){
                v[j][tmp%10]++;
                tmp = tmp/10;
            }
        } // 3 3 2 1 1 4 
        long long int ans = 0;
        for(int i=0;i<ct;i++){
            long long int tmp = 0;
            long long int t = n;
            for(auto it: v[i]){
                tmp = tmp + (t-it.second)*it.second;
                t = t-it.second;
            }
            //if(v[i].size()==1) tmp = 0;
            ans = ans + tmp;           
        }
        return ans;
    }
};