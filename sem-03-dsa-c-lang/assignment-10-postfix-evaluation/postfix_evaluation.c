#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

// Scans left to right: operands get pushed as-is, and whenever an
// operator is seen, the two most recently pushed operands are popped,
// combined with that operator, and the result is pushed back. Postfix
// notation is designed so this single left-to-right pass, with no need
// to worry about precedence or parentheses, always works.
int evaluatePostfix(char expr[]) {
    top = -1;
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            push(c - '0');   // convert the character digit to its numeric value
        } else {
            int b = pop();   // second operand (popped first)
            int a = pop();   // first operand

            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < b; j++) result *= a;
                    push(result);
                    break;
                }
                default:
                    printf("Unknown operator: %c\n", c);
            }
        }
    }

    return pop();   // whatever's left is the final result
}

int main() {
    char expr[MAX];

    printf("Enter a postfix expression (single-digit operands, e.g. 62/3-42*+): ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Result = %d\n", result);

    return 0;
}
