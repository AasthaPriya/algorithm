/*
question link :https://leetcode.com/problems/zigzag-conversion/
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Solution: Store in a zigzag order 
*/


string convert(string s, int numRows) {
    int n=s.length();
    if(n==1 || n==0 || numRows==1|| n<=numRows)
        return s;
    
    string row[numRows];
    for(int i=0;i<numRows;i++)
        row[i]="";
    
    int j=0;
    bool flag;
    for(int i=0;i<s.length();i++){
        row[j]=row[j]+s[i];
         if(j==0)
             flag=true;
         if(j==numRows-1)
             flag=false;
        
        if(flag==true)
            j++;
        else
            j--;
    }
    string ans="";
    for(int i=0;i<numRows;i++)
        ans=ans+row[i];
    
    return ans;
}