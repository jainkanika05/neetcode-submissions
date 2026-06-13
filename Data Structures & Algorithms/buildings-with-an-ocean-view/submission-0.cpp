class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> s;
        vector<int> ans;
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            if(s.empty() or heights[i]>heights[s.top()]){
                s.push(i);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};