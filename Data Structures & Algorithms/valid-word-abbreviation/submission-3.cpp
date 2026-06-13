class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n=word.size();
        int m=abbr.size();
        int i=0;
        int j=0;
        while(j<m){
            int num=0;
            if(abbr[j]=='0')return false;
            while(abbr[j] and abbr[j]<='9'){
                num= num*10 + (abbr[j]-'0');
                j++;
            }
            cout<<num<<endl;
            for(int h=0;h<num;h++){
                i++;
            }
            if(word[i]!=abbr[j])return false;
            i++;
            j++;
        }
        return true;
    }
};