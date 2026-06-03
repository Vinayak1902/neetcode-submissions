class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        int n = strs.size();
        for(int i=0;i<n;i++){
            res+= to_string(strs[i].size()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int n = s.size();
        while(i<n){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            i=j+1;j=i+len;
            string str = s.substr(i,len);
            res.push_back(str);
            i=j;
        }
        return res;
    }
};
