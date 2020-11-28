#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isOperator(char x)
{
    switch (x)
    {
    	case '+':

        case '-':

        case '/':

        case '*':

        return true;
    }
    return false;
}

string preToPost(string pre_exp)
{
    stack<string> s;

    int length = pre_exp.size();

    for (int i = length - 1; i >= 0; i--)

    {
        if (isOperator(pre_exp[i]))

        {
            string op1 = s.top();

            s.pop();

            string op2 = s.top();

            s.pop();

            string temp = op1 + op2 + pre_exp[i];

            s.push(temp);
        }

        else {

            s.push(string(1, pre_exp[i]));
        }

    }
    return s.top();
}

class Stack
{

    public:

    int top;

    unsigned capacity;

    int* array;
};

Stack* createStack( unsigned capacity )
{

    Stack* stack = new Stack();



    if (!stack) return NULL;



    stack->top = -1;

    stack->capacity = capacity;

    stack->array = new int[(stack->capacity * sizeof(int))];



    if (!stack->array) return NULL;



    return stack;
}



int isEmpty(Stack* stack)
{

    return stack->top == -1 ;
}



int peek(Stack* stack)
{

    return stack->array[stack->top];
}



int pop(Stack* stack)
{

    if (!isEmpty(stack))

        return stack->array[stack->top--] ;

    return '$';
}



void push(Stack* stack,int op)
{

    stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp)
{

  struct Stack* stack = createStack(strlen(exp));
 int i;

 // See if stack was created successfully
 if (!stack) return -1;

 // Scan all characters one by one
 for (i = 0; exp[i]; ++i)
 {
     // If the scanned character is an operand (number here),
     // push it to the stack.
     if (isdigit(exp[i]))
         push(stack, exp[i] - '0');

     // If the scanned character is an operator, pop two
     // elements from stack apply the operator
     else
     {
         int val1 = pop(stack);
         int val2 = pop(stack);
         switch (exp[i])
         {
         case '+': push(stack, val2 + val1); break;
         case '-': push(stack, val2 - val1); break;
         case '*': push(stack, val2 * val1); break;
         case '/': push(stack, val2/val1); break;
         }
     }
 }
 return pop(stack);  
}

int main()
{

    string pre_exp = "";
    cin >> pre_exp;

    cout << "Postfix : " << preToPost(pre_exp) << "\n";

    const string res = preToPost(pre_exp);
    char exp[res.length()];

    for(int i = 0; i < res.length(); i++)
    {
    	exp[i] = res[i];
    }

    cout << evaluatePostfix(exp) << "\n";

    return 0;
}
