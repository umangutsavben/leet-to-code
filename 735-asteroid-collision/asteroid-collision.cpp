class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int>st;
        int flag = 0;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(a[i]);
            else{
                while(1){
                    if(st.empty()){
                        st.push(a[i]);
                        break;
                    }
                    if(st.top()>0 && a[i]<0){
                        if(st.top() == abs(a[i])) {
                            st.pop();
                            break;
                        }
                        else if(st.top() > abs(a[i])) {
                            break;
                        }
                        else {
                            st.pop();
                        }
                    }
                    else if(st.top()*a[i]>0) {
                        st.push(a[i]);
                        break;
                    }
                    else if(st.top()<0 && a[i]>0){
                        st.push(a[i]);
                        break;
                    }
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};