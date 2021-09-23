class Solution {
public:
    int maxLength(vector<string>& arr , string s = "" , int ind  =0 ) {
      
       unordered_set<char> S(s.begin() , s.end()) ;
      // use set to check the unique charcters in the string 
      if(S.size() != (int) s.size())
        return 0 ;
      int ans  = s.size() ;
      for(int i=ind ; i< arr.size() ; i++)
      {
        ans = max(ans , maxLength(arr,s+arr[i], i+1)) ;
      }
        return ans ;
    }
};
