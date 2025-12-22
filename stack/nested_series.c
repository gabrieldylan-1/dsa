#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

static char contents[MAX_SIZE];
static int top = 0;

static void push(char item);
static char pop(void);
static char peek(void);
static bool is_empty(void);
static bool is_full(void);

int main(void)
{
    char c;
    bool flag = 0;
    printf("Enter parentheses and/or braces: ");

    while ((c = getchar()) != '\n') 
    {
        if (c == '(' || c == '{') push(c);
        else if (!is_empty() && ((peek() == '(' && c == ')') || (peek() == '{' && c == '}'))) pop();
        else { flag = 1; break; }
    }

    if(!flag && is_empty()) printf("Parentheses/braces are properly nested\n");
    else printf("Parentheses/braces are NOT properly nested\n");

    return 0;
}

static void push(char item)
{
    if (is_full()) 
    {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    contents[top++] = item;
}

static char pop(void)
{
    if (is_empty())
    {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    } 
        
    return contents[--top];
}

static bool is_empty(void)
{
    return top == 0;
}

static bool is_full(void)
{
    return top == MAX_SIZE;
}

static char peek(void)
{
    if(is_empty())
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    
    return contents[top - 1];
}
