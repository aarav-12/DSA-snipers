class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        // Har token ko process karenge
        for (auto &token : tokens) {

            /*
              Agar token number hai:
              1) Single digit positive number → "5"
              2) Ya negative number → "-11"
            */
            if (
                isdigit(token[0]) || 
                (token[0] == '-' && token.length() > 1)
            ) {
                // String ko integer mein convert karke stack mein push
                //stoi = stringt to integer
                st.push(stoi(token));
            }
            else {
                // Operator mila toh stack se last 2 operands nikalo
                int b = st.top(); st.pop(); // second operand
                int a = st.top(); st.pop(); // first operand

                // Operator ke hisaab se operation
                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else if (token == "/")
                    st.push(a / b); // integer division
            }
        }

        // Final result stack ke top par hoga
        return st.top();
    }
};
