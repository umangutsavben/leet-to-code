class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<32;i++){
            int one = 0;
            int zero = 0;
            for(int j=0;j<n;j++){
                if((nums[j]&1)==1) one++;
                else zero++;
                nums[j] = nums[j]>>1;
            }
            //int tmp
            if(one%3){
                res = (res|(1<<i));
            }
            else{
                res = (res|(0<<i));
            }
        }
        return res;
    }
};