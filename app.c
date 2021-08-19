#include<stdio.h>
#include"lib.h"


sint8 binarySearch(uint8* arr, uint8 arrSize, uint8 value);
uint8 Is_sorted (uint8* arr, uint8 arrSize);
uint8 bubbleSort(uint8* arr, uint8 arrSize);
void printArray(uint8* arr, uint8 size);

int main() {
    int number ;
    scanf("%d",&number);

    // array to search inside
    uint8 data[20] = {10,21,30,55,201,0,46,87,52,123,3,21,2,25,44,1,54,67,7,8};

    // print the array before sorting
    printArray(data, 20);
    // is array sorted?
    if (Is_sorted(data, 20) == 0)
    {
        // SORT
        bubbleSort(data, 20);
    }
    
    printArray(data, 20);
    // Is_sorted(data, 20);

    sint8 index = binarySearch(data, 20, (uint8)number);
    
    if (index == -1) // not found?
    {
        printf("The value %d isn't found \n", number);
    }
    // print the index
    else { printf("The value %d at the index %i \n", number, index+1); }
    
    return 0;
}

sint8 binarySearch(uint8* arr, uint8 arrSize, uint8 value) 
{
    uint8 start = 0;                // start position
    uint8 end = arrSize-1;          // end position
    uint8 mid = (start + end) / 2;  // middle position
    uint8 previousMid = 0;      // the previous value of mid to avoid infinite loop
    uint8 state = 1;
    while (1)
    {
        // infinite loop?
        if (previousMid == mid)
        {
            // value is not found
            return -1;
        }
        
        // value is found?
        if (arr[mid] == value)
        {
            return mid; // reurn index
        }

        // stuck and didn't find the value?
        if (start == end)
        {
            return -1;  // not found
        }
        
        // the value is at the right side?
        if (arr[mid] < value)
        {
            // update positions
            start = mid+1;
            previousMid = mid;
            mid = (start + end) / 2;
            continue;
        }

        // the value is at the left side?
        if (arr[mid] > value)
        {
            // update positions
            end = mid-1;
            previousMid = mid;
            mid = (start + end) / 2;
            continue;
        } 
    }
   
    return 0;
}


uint8 Is_sorted (uint8* arr, uint8 arrSize)
{
    // iterate over the whole array
    for (int j = 0; j < arrSize-1; j++)
    {
        // left element  >  right element (not sorted)
        if(arr[j] > arr[j+1]) {
            printf("Not sorted\n");
            return 0;
        }
    }
    printf("sorted\n");
    return 1;    // sorted
}

uint8 bubbleSort(uint8* arr, uint8 arrSize) 
{
    uint8 dynamicSize = arrSize; // decremented after each iteration on the array
    /* Bubble sort */
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < dynamicSize-1; j++)
        {
            
            if(arr[j] > arr[j+1]) {
                // SWAP
                uint8 temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        dynamicSize--;
    }
}

void printArray(uint8* arr, uint8 size)
{
    printf("Array Elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}