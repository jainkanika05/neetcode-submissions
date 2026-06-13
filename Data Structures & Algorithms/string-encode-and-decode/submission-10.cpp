class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size();i++){
            s+=strs[i]+".";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int j=0;
        while(i<s.size()){
            while(s[j]!='.')j++;
            string f=s.substr(i,j-i);
            cout<<f<<endl;
            res.push_back(f);
            i=j+1;
            j=i;
        }
        return res;
    }
};
