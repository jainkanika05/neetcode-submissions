class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool> arr;
        for(auto n:nums){
            if(arr[n])return true;
            arr[n]=true;
        }
        return false;
    }
};