// - we will have to add the size of every string and # symbol before
//   every string 
// - for decoding it we will use pointers i and j
// - we will start from index i=0 and j=0 and we will move until we find #
// - then we will take substring and covert it to integer
// - i will come at place of j+1 and j will go j + size of str
// - we will take the sub string and push in the vector of string i.e. res
// - again we will bring i to j and continue to do this until j equals n
// - we will start with i=0; and j will be equal to i intially
// - we have to move j until we reach # and then we will take substr of length j-i and stoi it
// - after we will set i to j+1 and then substr it with len and then increment our i to i+len
// - if it goes out of bound stop the loop
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto str:strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            i = j+1;
            string temp = s.substr(i,len);
            res.push_back(temp);
            i += len;
        }
        return res;
    }
};
