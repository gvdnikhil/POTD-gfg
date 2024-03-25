   void solve(vector<string> &result, string &temp, int n, int ones, int zeros)
    {
        if(n == 0)
        {
            result.push_back(temp);
            return ;
        }
        temp += '1';
        solve(result, temp, n - 1, ones + 1, zeros);
        temp.pop_back();
        if(ones > zeros)
        {    
            temp += '0';
            solve(result, temp, n - 1, ones, zeros + 1);
            temp.pop_back();
            // back track to check other possibilites
        }
    }
    vector<string> NBitBinary(int n)
    {
        vector<string> result;
        string temp = "";
        solve(result, temp, n, 0, 0);
        return result;
    }
