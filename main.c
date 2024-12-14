#include "stdio.h"
#include "stdlib.h"

#define N 100
//#define s rand() % (N + 1)

int binarySearch(int arr[], int low, int high, int s) {
  int mid = (low + high)/2;

  if (low <= high) {

    if (arr[mid] == s) {
      return mid;
    }

    if (arr[mid] > s) {
      return binarySearch(arr, low, mid-1, s);
    }

    else {
      return binarySearch(arr, mid+1, high, s);
    }
  }

  return -1;
}

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i; j++) {
      if (arr[j] > arr[j+1]) 
        swap(arr, j, j + 1);
    }
  }
}

int main() {
  //type in a number lol
  int s;
  printf("Pick a number! Any Number!\n");
  scanf("%d", &s);

  int arr[N];
  int len = sizeof(arr)/sizeof(arr[0]);
  printf("unsorted Array: \n");
  //populate array arr
  for (int i = 0; i<len; i++) {
    arr[i] = rand() % (N + 1);
    printf("%d, ", arr[i]);
  }

  bubbleSort(arr, len);

  printf("sorted Array: \n");

  for (int i = 0; i<len; i++) {
    printf("%d, ", arr[i]);
  }

  printf("\n");

  int res = binarySearch(arr, 0, len-1, s);
  
  if (res != -1) {
    printf("element %d last appears at index %d\n YOU WIN!!!1", s, res);
  } else {
    printf("element %d not found in array \n u lose :(", s);
  }
  
  return 0;
}
