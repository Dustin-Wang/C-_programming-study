class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len=digits.size();
        vector<string> res;
        if(len==0)
            return res;
        string s="";
        DFS(s,res,0,len,digits);
        return res;
    }
    void DFS(string& s, vector<string>& res, int i, int len,string& digits){
        if(i==len)
            res.push_back(s);
        else{
            i=i+1;
            if(digits[i-1]=='2'){
                s+='a';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='b';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='c';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else if(digits[i-1]=='3'){
                s+='d';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='e';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='f';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else if(digits[i-1]=='4'){
                s+='g';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='h';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='i';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else if(digits[i-1]=='5'){
                s+='j';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='k';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='l';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else if(digits[i-1]=='6'){
                s+='m';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='n';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='o';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else if(digits[i-1]=='7'){
                s+='p';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='q';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='r';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='s';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else if(digits[i-1]=='8'){
                s+='t';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='u';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='v';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
            else{
                s+='w';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='x';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='y';
                DFS(s,res,i,len,digits);
                s.pop_back();
                s+='z';
                DFS(s,res,i,len,digits);
                s.pop_back();
            }
        }
    }
};