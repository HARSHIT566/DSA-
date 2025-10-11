class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";  
        // Initialize nesting level counter
        int level = 0;       

        // Traverse the string
        for (char ch : s) {
             if (ch == '(') {
                if (level > 0) result += ch;
                level++;  
            } 
            else if (ch == ')'){
                level--;  
                if (level > 0) result += ch;
            }
        }
        return result;
        
    }
};
