#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void F1(int arr[], int n); // The recursion sort
void F2(int arr[], int n); // The bubble sort
void PrintArray(int arr[], int n); // Print 1,000 integer numbers
void GenerateArray(int arr[], int n); // Generate 1,000 integer numbers randomly 

int main(int argc, char *argv[])
{
    int arr[N];    
    GenerateArray(arr, N); 
    printf("Before the recursion sort ----------\n");
    PrintArray(arr, N);
    printf("Start the recursion sort ----------\n");
    clock_t start_time1 = clock();
    F1(arr, N);
    clock_t end_time1 = clock(); 
    printf("Running time is: %lf ms\n", (double)(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000);
    printf("After the recursion sort ----------\n");
    PrintArray(arr, N);

    printf("**********\n");

    GenerateArray(arr, N); 
    printf("Before the bubble sort ----------\n");
    PrintArray(arr, N);
    printf("Start Bubble sort ----------\n");
    clock_t start_time2 = clock();
    F2(arr, N);
    clock_t end_time2 = clock();
    printf("Running time is: %lf ms\n", (double)(end_time2 - start_time2) / CLOCKS_PER_SEC * 1000);
    printf("After the bubble sort ----------\n");
    PrintArray(arr, N);

    return 0;
}

// Generate 1,000 integer numbers randomly 
void GenerateArray(int arr[], int n)
{
     int i;
     srand((unsigned)time(0));
     
     for(i = 0; i <N; i++) 
     {
          arr[i] = rand(); 
     }
}

// Print 1,000 integer numbers
void PrintArray(int arr[], int n)
{
     int i = 0;
     for(i = 0; i < n; i++)
           printf("%6d\t", arr[i]);
     printf("\n");
}

// recursion sort
void F1(int arr[], int n)
{
     if(n <= 1)
     return;
     
     int i =0 , j = n - 1;
     int key = arr[0];
     int index = 0;
     
     while(i < j)
     {
             while(j > i && arr[j] >= key)
             j--;
             if(j == i)
             break;
             else
             {
                 arr[j] = arr[j] ^arr[i];
                 arr[i] = arr[j] ^arr[i];
                 arr[j] = arr[j] ^arr[i];
                 index = j;
             }
             
             while(i < j && arr[i] <= key)
             i++;
             if(i == j)
             break;
             else
             {
                 arr[j] = arr[j] ^arr[i];
                 arr[i] = arr[j] ^arr[i];
                 arr[j] = arr[j] ^arr[i];
                 index = i;
             }             
     }     
     F1(arr, index);
     F1(arr + index + 1, n - 1 - index);
}

// bubble sort
void F2(int arr[], int n)
{
     int i = 0, j =0;     
     for(i = 0; i < n; i++)
       for(j = 0; j < n - 1 - i; j++)
       {
             if(arr[j] > arr[j + 1])
             {
                       arr[j] = arr[j] ^ arr[j+1];
                       arr[j+1] = arr[j] ^ arr[j+1];
                       arr[j] = arr[j] ^ arr[j+1];
             }             
       }     
}
