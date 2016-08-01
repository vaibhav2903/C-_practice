#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
double calcValue(char sym,double op1,double op2);
double pop(struct Stack* Stk);
double eval(char A[],int N);
struct Stack{
	unsigned int capacity;
	int top;
	double val[MAX];
};
int main(){
	char A[1000];
	int i=0;
	while((A[i]=getchar())!='\n')
		i++;
	A[i]='\0';
	cout<<eval(A,i)<<endl;
return 0;
}
bool isDigit(char c){
	return (c>='0' && c<='9');
}
void push(struct Stack* Stk,double key){
	
	Stk->top++;
	Stk->val[Stk->top] = key;
	return;
}
double pop(struct Stack* Stk){
	double key = Stk->val[Stk->top--];
	return key;
}
double eval(char A[],int N){
struct Stack* stk = (struct Stack*)malloc(sizeof(struct Stack));
stk->top = -1;
stk->capacity = MAX;
int i =0;double value;
double op1,op2;
while(i<N){
	if(isDigit(A[i]))
		push(stk,(double) (A[i]-'0'));
	else{
		op1 = pop(stk);
		op2 = pop(stk);
		value = calcValue(A[i],op1,op2);
		//cout<<value<<endl;
		push(stk,value);
	}
	i++;
}
return value;
}
double calcValue(char sym,double op1,double op2){
	switch(sym)
	{
		case '+': return op2 + op1 ;
		case '-':return op2-op1;
		case '*':return op2*op1;
		case '/':return op2/op1;
		case '$': return pow(op2,op1);
		default : cout<<"Illegal operation"<<endl;
					exit(1);
	}

}
