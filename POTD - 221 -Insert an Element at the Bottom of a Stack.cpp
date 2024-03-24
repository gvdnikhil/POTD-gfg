//Insert an Element at the Bottom of a Stack

   stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> dup;
        
        while(!st.empty())
        {
            int temp = st.top();
            st.pop();
            dup.push(temp);
            
        }
        st.push(x);
         while(!dup.empty())
        {
            int temp = dup.top();
            dup.pop();
            st.push(temp);
            
        }
        return st;
    }

// This is an easy code  so I've used 2 loops  and created separate duplicate stack to store the elements of the 1st stack and then made the st stack empty and pushed the x into the st and copied all the elements from duplicate to the st stack
