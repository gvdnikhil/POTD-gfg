
// Fibonaacci

vector<int> Series(int n) {
        // Code here
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        for ( int i =2;i<=n;i++)
        {
            
            res.push_back((res[i-1]+res[i-2])%1000000007);
        }
        return res;
    }
