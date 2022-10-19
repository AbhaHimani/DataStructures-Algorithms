class Solution {
    public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue <pair<int,char>, vector<pair<int,char>>,greater<pair<int,char>>> minH;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto i=mp.begin();i!=mp.end();i++){

            minH.push({i->second,i->first}); // not i.second, it is i->second
        }
        string ans;

        while(!minH.empty()){
            for(int i=0;i<minH.top().first;i++)
                ans+= minH.top().second;
            minH.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};