struct Compare {
        bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
        return a.second < b.second;
        else
        return a.first > b.first;
        }
        };


class Solution {
    public:


    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue <pair<int,string>, vector<pair<int,string>>,Compare> minH;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        for(auto i=mp.begin();i!=mp.end();i++){

            minH.push({i->second,i->first}); // not i.second, it is i->second
            if(minH.size()>k){
                minH.pop();
            }
        }
        // sort(pq.begin(),pq.end(),comp);
        vector<string> ans;
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};