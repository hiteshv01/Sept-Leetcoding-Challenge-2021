class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size() ;
        int i ,j ;
        int ans  =0 ;
        
        
        
        vector<unordered_map<int,int>>dp (n);
         // {index , [common diff  , count]}
        
        
        for(int i=0 ; i< n ; i++)
        {
            for(int j=0 ; j< i ; j++)
            {   
                long  cd = (long) a[i] - (long)a[j] ;
                
                if(cd <= INT_MIN || cd >= INT_MAX) {  // trivial case 
                      continue ;
                }    
                
           
                dp[i][cd] ++ ;   /// ending  at  ind i 
                
                if(dp[j].find(cd)  != dp[j].end())
                {
                    dp[i][cd] += dp[j][cd] ;       /// ending at ind j 
                    
                    ans += dp[j][cd] ;        // ans me j wla hi add krenge 
                    
                }
                
            }
        }
        
        
        return ans  ;
        
    }
};
