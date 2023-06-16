/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -
struct Stack
{
    char arr[MAX];
    int n;
};

void Init(Stack& S)
{
    S.n = 0;
}

bool isFull(Stack S)
{
    return (S.n == MAX);
}
void Push(Stack& S, char x)
{
    if (isFull(S))
        return;
    S.arr[S.n++] = x;
}

bool isEmpty(Stack S)
{
    return (S.n == 0);
}

void Pop(Stack& S)
{
    if (isEmpty(S))
        return;
    --S.n;
}

char Top(Stack& S)
{
    if (isEmpty(S))
        return NULL;
    return S.arr[S.n - 1];
}

bool isValid(string s) 
{
    Stack S;
    Init(S);
    for (char c : s) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            Push(S, c);
        }
        else 
        {
            if (isEmpty(S)) 
            {
                return false;
            }

            char tmp = Top(S);
            Pop(S);

            if ((c == ')' && tmp != '(') || (c == ']' && tmp != '[') || (c == '}' && tmp != '{')) {
                return false;
            }
        }
    }

    return isEmpty(S);
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



