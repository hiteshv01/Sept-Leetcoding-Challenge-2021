class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int suffix =0 ;
      for(int i = shifts.size()-1 ; i>=0 ; i--)
      {
        suffix  = (suffix + shifts[i]) % 26 ;
        s[i]  = ('a' + (s[i] - 'a' + suffix) %26) ;
        
      }
      return s ;
    }
};
