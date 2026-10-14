class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        /*
        4  8  12 16 20
        10 14 18
        */
        int n = nums1.size();
        int dif = 1e9;
        int ans;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int k=0;
                int delta = 1e9;
                bool flag = 0;
                for(int r=0;r<n;r++){
                    if(r==i || r==j){
                        continue;
                    }
                    int tmp = nums2[k]-nums1[r];
                    if(delta != 1e9 ){
                        if(delta != tmp){
                            flag = 1;
                            break;
                        }
                    }
                    else{
                        delta = tmp;
                    }
                    k++;
                }
                if(flag==false){
                    if(dif>(delta)){
                        dif = (delta);
                        ans = delta;
                    }
                }
            }
        }
        return ans;
    }
};