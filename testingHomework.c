#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 50

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high, int index, char* string);

int main()
{
   
    int merge[MAX],i,n;

    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements which to be sort: ");
    char* string = "numbers.txt";
    FILE* writeFile = fopen(string, "w");
    
    for(i=0;i<n;i++)
    {
         scanf("%d",&merge[i]);
         
    }
    fwrite("hello", 5, 1, writeFile);
    
    partition(merge,0,n-1,0, string);

    printf("After merge sorting elements are: ");
    for(i=0;i<n;i++)
    {
         printf("%d ",merge[i]);
    }

   return 0;
}

void partition(int arr[],int low,int high, int index, char* string)
{

    int mid;
    
    FILE* readFile = fopen(string, "r");

    if(low<high)
    {
         mid=(low+high)/2;
         printf("Forking...");
         pid_t pid = fork();
         if(pid == 0)
         {
             partition(arr,low,mid, low, string);
         }
         else
         {
             partition(arr,mid+1,high, mid, string);
         }
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high)
{

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high))
    {

         if(arr[l]<=arr[m])
         {
             temp[i]=arr[l];
             l++;
         }
         else
         {
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid)
    {
         for(k=m;k<=high;k++)
         {
             temp[i]=arr[k];
             i++;
         }
    }
    else
    {
         for(k=l;k<=mid;k++)
         {
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++)
    {
         arr[k]=temp[k];
    }
}