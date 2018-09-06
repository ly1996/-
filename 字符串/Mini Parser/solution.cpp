/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int parseToInt(string string_temp)
    {
        int int_temp;
        stringstream stream(string_temp);  
        stream>>int_temp;  
        return int_temp;
    }
    
    NestedInteger deserialize(string s) {
        int len = s.length();
        
        stack<NestedInteger> st;
        int index = 0;
        while(index < len)
        {
            char ch = s[index];
            if(ch == '[')
            {
                NestedInteger tmp_integer(INT_MIN);
                st.push(tmp_integer);
                index ++;
            }
            else if (ch == ']')
            {
                NestedInteger tmp_integer;
                vector<NestedInteger> tmpVec;
                while(true)
                {
                    NestedInteger numInStack = st.top();
                    st.pop();
                    if(numInStack.isInteger() == true && numInStack.getInteger() == INT_MIN)
                    {
                        break;
                    }
                    else
                    {
                        // tmp_integer.add(numInStack);
                        tmpVec.push_back(numInStack);
                    }
                }
                
                for(int i = tmpVec.size() - 1; i >= 0 ; i --)
                {
                    tmp_integer.add(tmpVec[i]);
                }
                st.push(tmp_integer);
                index ++;
            }
            else if(ch == ',')
            {
                index ++;
                continue;
            }
            else
            {
                string num_str = "";
                int index_2 = index;
                while(s[index_2] != '[' && s[index_2] != ']' && s[index_2] != ',')
                {
                    num_str += s[index_2];
                    index_2 ++;
                }
                int num = parseToInt(num_str);
                NestedInteger tmp_integer(num);
                st.push(tmp_integer);
                index = index_2;
            }
        }
        
        return st.top();
    }
};