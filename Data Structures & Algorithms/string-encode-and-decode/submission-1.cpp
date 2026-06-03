class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        int n = strs.size();
        for(int i=0;i<n;i++){
            string curr = strs[i];
            res+= to_string(curr.size())+'#'+curr;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        int n = s.length();
        while(i<n){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            string str = s.substr(i,len);
            res.push_back(str);
            j=i+len;
            i=j;
        }
        return res;
    }
};
