#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "Stack/stack.h"

char *infix_to_postfix(char *infix);
bool isOpeneingBrace(char token);
bool isClosingBrace(char token);
bool isOperator(char token);
bool hasLowerPrecedence(char infix_token, char stack_token);
int precedence_val(char operator);
double evaluatePostfix(char *postfix);

int main(void) {
    size = 0;
    top = NULL;


    char infix[100];
    printf("Infix expression: ");
    fgets(infix, 100, stdin);

    char *postfix = infix_to_postfix(infix);
    printf("POSTFIX: %s\n", postfix);

    double result = evaluatePostfix(postfix);
    printf("RESULT: %.3lf\n", result);

    free(postfix);
    dealloc();
}

char *infix_to_postfix(char *infix) {
    int postfix_index = 0;
    char *postfix = malloc(100 * sizeof *postfix);

    for (int i = 0; infix[i] != '\0'; ++i) {
        char token = infix[i];
        if (isalpha(token)) {
            postfix[postfix_index++] = token;
        } else if (isOpeneingBrace(token)) {
            push(token);
        } else if (isClosingBrace(token)) {
            char stack_token = pop();
            while (stack_size() > 0 &&  !isOpeneingBrace(stack_token)) {
                postfix[postfix_index++] = stack_token;
                stack_token = pop();
            }
        } else if (isOperator(token)) {
            while (hasLowerPrecedence(token, stack_top())) {
                postfix[postfix_index++] = pop();
            }
            push(token);
        }
    }

    while (stack_size() > 0) {
        postfix[postfix_index++] = pop();
    }

    return postfix;
}

bool isOpeneingBrace(char token) {
    return token == '(' || token == '{' || token == '[';
}

bool isClosingBrace(char token) {
    return token == ')' || token == '}' || token == ']';
}

bool isOperator(char token) {
    return token == '+' || token == '-' || token == '*' ||
           token == '/' || token == '^';
}

bool hasLowerPrecedence(char infix_token, char stack_token) {
    int ICP = precedence_val(infix_token);
    int ISP = precedence_val(stack_token);

    return ICP < ISP;
}

int precedence_val(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;

        case '*':
            return 2;

        case '/':
            return 3;

        case '^':
            return 4;

        default:
            return 0;
    }
}

double evaluatePostfix(char *postfix) {
    dealloc();

    for (int i = 0; postfix[i] != '\0'; ++i) {
        char token = postfix[i];
        if (isalpha(token)) {
            int data;
            printf("%c: ", token);
            scanf("%d", &data);
            push(data);
        } else {
            double b = pop();
            double a = pop();

            switch (token) {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;

                case '^':
                    push(pow(a, b));
                    break;
            }
        }
    }

    return pop();
}
