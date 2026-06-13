class Solution {
    unordered_map<char,unordered_set<char>> adj;
    unordered_map<char,bool> vis;
    string result="";
public:
    bool dfs(char ch){
        if(vis.find(ch)!=vis.end())return vis[ch];
        vis[ch]=true;
        for(auto w:adj[ch]){
            if(dfs(w))return true;
        }
        vis[ch]=false;
        result.push_back(ch);
        return false;

    }
    string foreignDictionary(vector<string>& words) {
        for(auto &word: words){
            for(auto &ch:word){
                adj[ch];
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string &w1=words[i],&w2=words[i+1];
            int minLength=min(w1.length(),w2.length());
            if(w1.length()>w2.length() && w1.substr(0,minLength)==w2.substr(0,minLength)){
                return "";
            }
            for(int j=0;j<minLength;j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        
        for(auto &pair:adj){
            if(dfs(pair.first))return "";
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
