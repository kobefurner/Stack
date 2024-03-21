#include "ParenthesesMatch.h"

bool parenthesesMatch(const char* str){
   Stack<char> stack;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            stack.push(str[i]);
        } 
        else if (str[i] == ')') {
            if (stack.empty()) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}
