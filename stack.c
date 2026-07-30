#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
 void push(int value){
    if(top==SIZE-1)
      printf("stack overflow \n");
    else
      stack[++top]=value;
 }

  void pop(){
    if(top == -1)
     printf("stack underflow \n");
     else
     printf("deleted element = %d \n",stack[top--]);
  }
  
   void peek(){
     if(top == -1)
     printf("stack is empty \n");
     else
     printf("top element = %d \n",stack[top]);
  }
  

int main(){
    push(10);
    push(20);
    push(30);
    push(40);

    peek();
    pop();
    peek();
    
    return 0;
}