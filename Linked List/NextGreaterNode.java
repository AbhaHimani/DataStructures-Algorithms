/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        vector<int> ans;
        // 2 7 4 3 5
        vector<int> a;
        if(head==NULL ) return ans;
        ListNode *curr=head;
        while(curr!=NULL){
            a.push_back(curr->val);
            curr=curr->next;
        }
        for(int i=a.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=a[i]){
                s.pop();
            }
            if(s.empty()) ans.push_back(0);
            else if (!s.empty()){
                ans.push_back(s.top());
            }

            s.push(a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};