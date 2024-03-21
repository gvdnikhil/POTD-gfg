   int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    int s = 1;
    int e = stalls[n - 1] - stalls[0];
    int ans = 0;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        int count = 1;
        int pos = stalls[0];

      // This is Application of lower bound 
/*    
upper bound = iterator/index of (arr.start,arr.end, val)   i.e 1st elements whose value > val
lower bound = iterator/index of (arr.start,arr.end, val)   i.e 1st element whose value >= val


This is o(logn)

*/

      
        // int i = 0;
        // while (i < n) {
        //     auto ind = lower_bound(stalls.begin() , stalls.end(), stalls[i] + mid);
        //     i = ind - stalls.begin();
        //     if (i < n) count++;
        // }
        
        
        // and also this is o(n) code
        for ( int i=0;i<n;i++)
        {
            if (pos+mid <= stalls[i])
            {
                count++;
                pos = stalls[i];
            }
        }
        
        
        if (count < k) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}



Total tc of code is 

TC: o(n*logn)
  and usign lower bound 
TC = O(logn*logn);
