#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

bool isNumericDigit(char);
bool isOperator(char);
int performOperation(char ,int ,int);
int evaluatePrefix(string);
int rev(int);

int main()
{   string expression;
    cout<<"Enter prefix expression\n";
    getline(cin,expression);
    cout<<"Result: "<<evaluatePrefix(expression);
    return 0;
}

int evaluatePrefix(string expression){
    stack<int> S;

    for(int i=expression.length()-1; i>-1; i--){

        if(expression[i]==' ' || expression[i]==',') continue;

        else if(isOperator(expression[i])){
            int op1 = S.top();  S.pop();
            int op2 = S.top();  S.pop();
            int res = performOperation(expression[i], op1, op2);
            S.push(res);
        }

        else if(isNumericDigit(expression[i])){
            int operand=0,count=0,flag=0;;
            while(i>-1 && isNumericDigit(expression[i])){
                if(expression[i]>= '1' && expression[i]<='9')
                    flag=1;
                if(flag==0)
                    count++;
                operand = operand*10 + (expression[i] - '0');
                i--;
            }
            i++;
            int powOfTen=pow(10,count);
            cout<<count<<" "<<powOfTen<<endl;
            if(operand>9){
                operand=rev(operand);
            }
            operand*=powOfTen;
            S.push(operand);
        }
    }

    return S.top();
}

int rev(int n){
    int rev=0,d;
    while(n>0){
        d=n%10;
        rev= rev*10 + d;
        n=n/10;
    }
    return rev;
}

bool isOperator(char c){
    if(c== '+' || c== '-' || c== '*' || c== '/')
        return true;
    return false;
}

bool isNumericDigit(char c){
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

int performOperation(char o, int op1, int op2){
    if(o=='+')  return op1+op2;
    else if(o=='-')  return op1-op2;
    else if(o=='*')  return op1*op2;
    else if(o=='/')  return op1/op2;
}
