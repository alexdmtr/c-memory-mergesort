#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int *, int, int);

// Array sort method.
void sort(int * array, int left, int right) 
{
  int * sortingBuffer = (int *) malloc((right+1) * sizeof(int));

  mergeSort(array, sortingBuffer, left, right);

  free(sortingBuffer);
}

// Simple merge sort.
void mergeSort(int * array, int * buffer, int left, int right)
{
  if (left == right)
    return;
  int middle = (left+right)/2;

  mergeSort(array, buffer, left, middle);
  mergeSort(array, buffer, middle+1, right);

  // Merge the two halves.
  int leftIndex = left, rightIndex = middle+1;
  int bufferIndex = 0;

  while (leftIndex <= middle && rightIndex <= right)
  {
    if (array[leftIndex] < array[rightIndex])
      buffer[bufferIndex++] = array[leftIndex++];
    else
      buffer[bufferIndex++] = array[rightIndex++];
  }

  while (leftIndex <= middle)
    buffer[bufferIndex++] = array[leftIndex++];
  while (rightIndex <= right)
    buffer[bufferIndex++] = array[rightIndex++];

  // Put buffer back in array.
  for (int index = 0; index < bufferIndex; index++)
    array[index+left] = buffer[index];
}

int main()
{
  int * array, * buffer = NULL;
  int arrayCapacity = 2;
  int arraySize = 0;

  array = (int *) malloc(arrayCapacity * sizeof(int));

  int element;
  // Read the array, element by element, from stdin.
  while (scanf("%d", &element) == 1) // While we still have elements to read.
  {
   // printf("%d ", element);
    if (arraySize+1 > arrayCapacity) 
    {
      arrayCapacity = arrayCapacity * 2;
      
      buffer = (int *) malloc(arrayCapacity * sizeof(int));

      // Copy the array into our new buffer.
      for (int index = 0; index < arraySize; index++)
        buffer[index] = array[index];

      // We can free our array now.
      free(array);

      array = buffer;
    }
    array[arraySize++] = element;
  }

  // Sort the array. 
  sort(array, 0, arraySize-1);

  // Print out the array.
  for (int index = 0; index < arraySize; index++)
    printf("%d ", array[index]);
  printf("\n");

  // Finally, we can free the array.
  free(array);
  
  return 0;
}
