class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";
        for(string &str:strs) encodedStr+= to_string(str.size())+"#"+str;
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrs;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            decodedStrs.push_back(s.substr(i,len));
            i+=len;
        }
        return decodedStrs;
    }
};
