class Solution {
public:
    
    static bool is_pair(char op, char cl)
    {
        if(op == '(' && cl == ')')
            return true;
        if(op == '{' && cl == '}')
            return true;
        if(op == '[' && cl == ']')
            return true;
        return false;
    }
   
    static bool is_opening(char c)
    {
        if(c == '(')
            return true;
        if(c == '[')
            return true;
        return c == '{';
    }
    
    bool isValid(string s) {
        //stack for keeping open parentheses
        stack<char> op_pars;
        
        for(int i=0; i < s.length(); ++i)
        {
            //push open parntheses to stack
            if(is_opening(s[i]))
            {
                op_pars.push(s[i]);
            }
            //it's a closing bracket, so check top of stack and see if it matches 
            else if(!op_pars.empty())
            {
                char op = op_pars.top();
                if(is_pair(op, s[i]))
                {
                    op_pars.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return op_pars.empty();
    }
};