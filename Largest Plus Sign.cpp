class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines)
    {
        
        
        vector<vector<int> > grid (N+1,vector<int>(N+1,1));
        
        
        for(int i=0;i<mines.size();i++) {
            grid [mines[i][0]][mines[i][1]]=0;
        }
        
        
        vector<vector<int> > left(N+1,vector<int>(N+1)),right(N+1,vector<int>(N+1)),
        up(N+1,vector<int>(N+1)),down(N+1,vector<int>(N+1));
        
         
        /// up ward from bottom to top 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==0)
                {
                    up[i][j]=grid [i][j];
                }
                else
                {
                    if(grid[i][j]==0)
                    {
                        up[i][j]=0;
                    }
                    else
                    {
                        up[i][j]=1+up[i-1][j];
                    }
                }
            }
        }
        
        
        // from up to down 
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                if(i==N-1)
                {
                    down[i][j]= grid [i][j];
                }
                else{
                    if( grid[i][j]==0)
                    {
                        down[i][j]=0;
                    }
                    else
                    {
                        down[i][j]=1+down[i+1][j];
                    }
                }
            }
        }
        
        
        
        
         // left to right 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==0)
                {
                    left[j][i]= grid[j][i];
                }
                else
                {
                    if(grid[j][i]==0)
                    {
                        left[j][i]=0;
                    }
                    else
                    {
                        left[j][i]=1+left[j][i-1];
                    }
                }
            }
        }
        
        
        
       //// right to left
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                if(i==N-1)
                {
                    right[j][i]= grid[j][i];
                }
                else{
                    if( grid [j][i]==0)
                    {
                        right[j][i]=0;
                    }
                    else
                    {
                        right[j][i]=1+right[j][i+1];
                    }
                }
            }
        }
        
        
        
        
        //  minimum of 4 and then taking max with ans  
        
        
        int mn =INT_MIN;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                mn  =max(mn ,min(min(right[i][j],left[i][j]),min(up[i][j],down[i][j])));
            }
        }
        return mn ;
    }
} ;
