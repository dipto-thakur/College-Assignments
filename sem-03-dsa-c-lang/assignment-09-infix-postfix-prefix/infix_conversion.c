#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peekStack() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// Higher number means higher precedence. ^ (power) is right-associative,
// everything else here is left-associative, that distinction matters
// when two operators of equal precedence are compared.
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Standard infix-to-postfix conversion, single-character operands only,
// using a stack to hold operators until it's the right moment to
// output them.
void infixToPostfix(char infix[], char postfix[]) {
    top = -1;
    int k = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char c = infix[i];

        if (isspace(c)) continue;

        if (isalnum(c)) {
            // operands go straight to the output
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            // pop everything back to the matching '('
            while (!isEmpty() && peekStack() != '(') {
                postfix[k++] = pop();
            }
            pop();   // discard the '(' itself
        } else if (isOperator(c)) {
            // pop operators of equal or higher precedence first, so
            // they end up in the output before this one, which is how
            // postfix preserves the original evaluation order
            while (!isEmpty() && peekStack() != '(' &&
                   (precedence(peekStack()) > precedence(c) ||
                    (precedence(peekStack()) == precedence(c) && c != '^'))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// Prefix conversion reuses the postfix logic with a well-known trick:
// reverse the infix expression, swap '(' with ')' and vice versa,
// run it through infix-to-postfix, then reverse that result.
void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void swapParentheses(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    char temp[MAX];
    strcpy(temp, infix);

    reverseString(temp);
    swapParentheses(temp);

    infixToPostfix(temp, prefix);   // reuse postfix logic on the transformed string
    reverseString(prefix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter an infix expression (single-character operands, e.g. a+b*(c-d)): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("\nInfix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Prefix:  %s\n", prefix);

    return 0;
}
