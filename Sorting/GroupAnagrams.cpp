class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;

        for(auto str : strs){
            string s=str;
            sort(str.begin(),str.end());
            mp[str].push_back(s);


        }
        vector<vector<string>> ans;
        for(auto i = mp.begin(); i != mp.end(); i++){
            ans.push_back(i->second);
        }

        return ans;


    }
};