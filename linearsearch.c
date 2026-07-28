#include<stdio.h>
int linear_search(int arr[],int n,int key)
{
 int i;
  for(i=0;i<n;i++){
    if(key==arr[i])
    {
      return i;
    }
  }
  return -1;
}
int main()
{
 int arr[5]={10,20,30,40,50};
 int key;
 int ret;
  printf("enter key element to search:");
  scanf("%d",&key);
     ret=linear_search(arr,5,key);
  if(ret==-1){
     printf("element not found");
     }
  else{
     printf("key found at index %d",ret);
      }
 return 0;
}