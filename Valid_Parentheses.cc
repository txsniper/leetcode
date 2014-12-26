class Solution {
public:
    bool isValid(string s) {
               stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if ( c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if (st.size() == 0)
                    return false;
                char top_c = st.top();
                if (
                    (c == ')' && top_c == '(') ||
                    (c == ']' && top_c == '[') ||
                    (c == '}' && top_c == '{')
                    )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.size() > 0)
            return false;
        return true;
    }
};
