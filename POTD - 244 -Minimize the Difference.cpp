    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        // Brute Force Approach
        /*
        
        
        TC O(n^2)
        SC O(1)
        
        int s=0,e= s+k-1,curr_mini = INT_MAX,curr_maxi= INT_MIN, ans =INT_MAX;
        
        while (e<n)
        {
            curr_mini = INT_MAX;
            curr_maxi= INT_MIN;
            for ( int  i =0;i<n;i++)
            {
                if (i>= s&& i<=e) continue;
                else 
                {
                    curr_mini= min(arr[i],curr_mini);
                    curr_maxi = max(arr[i],curr_maxi);
                }
            }
            
            
            ans = min(ans, curr_maxi- curr_mini);
            s++;
            e++;
        }
        return ans;
    }
    
    
    */
   
   
   /* 
    // Optimised approach
    
        
        // TC O(n +n+n)
        // SC O(n+n+n+n)
  
  
        
    // using suffix_max , suffix_min, p_max,p_min
    int s_min[n],s_max[n],p_min[n],p_max[n];
    
    // prefix max and min
    p_min[0] = arr[0];
    p_max[0] = arr[0];
    s_min[n-1] = arr[n-1];
    s_max[n-1] = arr[n-1];
    for ( int i =1;i<n;i++)
    {
        p_max[i] = max(p_max[i-1],arr[i]);
        p_min[i] = min(p_min[i-1],arr[i]);
        
    }
    
    for ( int i= n-2;i>=0;i--)
    {
        s_max[i] = max(s_max[i+1],arr[i]);
        s_min[i] = min(s_min[i+1],arr[i]);
    }
    
    int ans =INT_MAX;
    int curr_min = INT_MAX;
    int curr_max = INT_MIN;
    
    for (int i=0;i<n;i++)
    {
        
        if ( i==0) 
        {
            curr_min = s_min[i+k];
            curr_max = s_max[i+k];
        }
        else if ( i==n-1)
        {
            curr_min = p_min[i-k];
            curr_max= p_max[i-k];
        }
        
        else 
        {
            curr_min = min(p_min[i-1],s_min[i+k]);
            curr_max = max(p_max[i-1],s_max[i+k]);
        }
        
        ans = min(ans,curr_max-curr_min);
    }
    
    return ans;
    
     public static int minimizeDifference(int n, int k, int[] arr) {
        // code here
        int[] suffMin = new int[n];
        int[] suffMax = new int[n];

        suffMin[n - 1] = arr[n - 1];
        suffMax[n - 1] = arr[n - 1];

        //Calculate suffix min Max array
        for (int i = arr.length - 2; i >= 0; i--) {
            suffMin[i] = Math.min(suffMin[i + 1], arr[i]);
            suffMax[i] = Math.max(suffMax[i + 1], arr[i]);
        }

        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        int minDiff = Integer.MAX_VALUE;

        //intution
        for (int i = 0, j = k - 1; i < n && j < n; i++, j++) {
            int diff = Integer.MAX_VALUE;
            if (j < n - 1) {
                diff = Math.abs((Math.max(suffMax[j + 1], max)) - (Math.min(suffMin[j + 1], min)));
            }
            else {
                diff = Math.abs(max - min);
            }

            minDiff = Math.min(diff, minDiff);

            min = Math.min(min, arr[i]);
            max = Math.max(max, arr[i]);
        }

        return minDiff;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
};
