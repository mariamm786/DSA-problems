class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        long long sum = 0;
        //we are taking these operations to into the stack so what we can do the operation optimizely.
        for(string s: operations)
        {
            if(s == "+")
            {
                int prev1 = st.top();
                st.pop(); // removing the top element to get the 2nd top of the stack
                int prev2 = st.top();
                st.push(prev1);
                st.push(prev1 + prev2);
            }
            else if(s == "D")
            {
                st.push(st.top() * 2);
            }
            else if ( s == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(s));
            }
        }
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};