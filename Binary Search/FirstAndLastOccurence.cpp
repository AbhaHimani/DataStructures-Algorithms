class Solution {
public:
    void start(vector<int>&nums, int target,vector<int>&res){
        int n=nums.size();
        int start=0;
        int end=n-1;
        
       
        int re=-1;
        while(start<=end){
             int mid= start+ (end-start)/2;
        if(target==nums[mid]){
            
            re=mid;
            end=mid-1;
        }
        else if(target>nums[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
            
        }
        res.push_back(re);
    }
    void end(vector<int>&nums,int target, vector<int>&res){
        int n=nums.size();
        int start=0;
        int end=n-1;
        
        int re=-1;
        while(start<=end){
            int mid=start+ (end-start)/2;
            if(target==nums[mid]){
                re=mid;
                start=mid+1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        res.push_back(re);
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        start(nums,target,res);
        end(nums, target,res);
        return res;
    }
};