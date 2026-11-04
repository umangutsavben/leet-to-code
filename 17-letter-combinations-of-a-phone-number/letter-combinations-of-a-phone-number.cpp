class Solution {
public:
    void f(int k,string &s,vector<string>&ans,map<int,vector<char>>&mp,string &tmp){
        if(k==s.size()){
            ans.push_back(tmp);
            return ;
        }
        vector<char> v = mp[s[k] - '0'];
        for(int i=0;i<v.size();i++){
            tmp = tmp + v[i];
            f(k+1,s,ans,mp,tmp);
            tmp.pop_back();
            //f(k+1,s,ans,mp,tmp);
        }
    }
    vector<string> letterCombinations(string s) {
        map<int,vector<char>>mp;
        if(s.empty()) return {};
        char curr = 'a';
        for(int i=2;i<10;i++){
            if(i == 7 || i == 9){
                for(int k=0;k<4;k++){
                    mp[i].push_back(curr);
                    curr = curr + 1;
                }
            }
            else{
                for(int k = 0;k<3;k++){
                    mp[i].push_back(curr);
                    curr = curr +1;
                }
            }
        }
        vector<string>ans;
        string tmp;
        f(0,s,ans,mp,tmp);

        return ans;
    }
};