/*
question-link:https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Input: strs = ["flower","flow","flight"]
Output: "fl"

Solution:Least time complexity
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string s="";
        string a=strs[0];
        string b=strs[n-1];
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i]) s+=a[i];
            else break;
        }
        return s;
    }
};