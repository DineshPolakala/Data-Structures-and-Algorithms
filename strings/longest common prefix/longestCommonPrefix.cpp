class Solution {
    string getPrefix(string str1, string str2){
        int n1 = str1.length(), n2= str2.length();
        string res ="";
        for(int i =0, j = 0; i<n1 and j < n2; i++, j++){
            if(str1[i]!= str2[j])
                break;
            res += str1[i];
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0)return "";
        string prefix = strs[0];
        for(int i=1; i< strs.size(); i++){
            prefix = getPrefix(prefix, strs[i]);
        }
        return prefix;
        
    }
};