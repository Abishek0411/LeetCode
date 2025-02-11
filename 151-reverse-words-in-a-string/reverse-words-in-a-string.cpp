class Solution {
public:
    string reverseWords(string s) {
        s=" "+s;//so that my loop below work efficiently in else case for first word
        string ans="";
        int n=s.size(),k=n-1,c=0,a=n-1,cs=0;//k = to iterate loop from reverse,c=count words
        //cs=count spaces

        while(k>=0){//iterate loop from last and extract words one by one and add in new string ans
            if(s[a]==' '){a--,k--;continue;}//to remove right leading spaces
            if(s[k] != ' ') c++,k--,cs=0;//to count the non-space values(count characters in word)
                                        //to make value 0 for previous spaces count
            else{
                cs++;//to increase count to 1 if we get space
                if(cs>1){k--;continue;}//skip further spaces in between words(when space is more than 1)
                string ss=s.substr(k+1,c);//to get words from last
                ans+=ss+' ';//to add word in ans string 
                c=0;//so that we can count new word length from 0
            }
        }
        ans.pop_back();//remove extra space from last that was added above in ans(during last iteration)
        return ans; 
    }
};
     