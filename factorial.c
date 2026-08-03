#include <stdio.h>

int main (){
	int num;
   	printf("enter number:");
   	scanf("%d",&num);
	
	if(num<0){
	printf("factorial of negative number does not exist");
	return 0;
	}


	long long fact = 1;
 	
	for(int i=1;i<=num;i++){
	 fact = fact * i;
   	}
	printf("Factorial of %d = %lld",num,fact);
	return 0;
}