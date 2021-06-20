#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <time.h>
#include "stringsort.h"

void quickSortIntegerFromFile(bool);
void bubbleSortIntegerFromFile(bool);
void printArray(int[], int);
void swap(int*, int*);
int partition (int[],int,int,bool);
void quickSort(int[], int, int,bool);
void bubbleSort(int[], int,bool);
void display();
void redisplay();


using  namespace std;
using namespace std::chrono;
int main(){
	 cout<<"My Sorting Machine"<<endl;
	cout<<"Please select your sorting choice"<< endl;
	cout<<"Pres '1' for ascending order quicksort integers"<<endl;
	cout<<"Pres '2' for descending order quicksort integers"<<endl;
	cout<<"Pres '3' for ascending order bubblesort integers"<<endl;
	cout<<"Pres '4' for descending order bubblesort integers"<<endl;
	cout<<"Pres '5' for ascending order quicksort string"<<endl;
	cout<<"Pres '6' for descending order quicksort string"<<endl;
	cout<<"Pres '7' for ascending order bubblesort string"<<endl;
	cout<<"Pres '8' for descending order bubblesort string"<<endl;
	char choice;
	cout<<"Enter choice ";
	cin>>choice;
	switch(choice){
	 	    case '1':
			quickSortIntegerFromFile(true);
			break;
			case '2':
				quickSortIntegerFromFile(false);
				break;
				case '3':
			bubbleSortIntegerFromFile(true);
			break;
			case '4':
			bubbleSortIntegerFromFile(false);
			break;
			 case '5':
			quickSortStringFromFile(true);
			break;
			case '6':
				quickSortStringFromFile(false);redisplay();
				break;
				case '7':
			bubbleSortStringFromFile(true);redisplay();
			break;
			case '8':
			bubbleSortStringFromFile(false);redisplay();
			break;
				default:cout<<"Wrong choice!!!"<<endl; redisplay();
			
	}
	
	return 0;
}


 void redisplay(){
 	cout<<endl;
 	main();
 	cout<<endl;
 }

// Quick Sort integers ascending descending
void quickSortIntegerFromFile(bool ascending){
	vector<int> vect;
	fstream myfile("myfile1.txt",ios_base::in);
	int a;
	while (myfile >> a)
	{
		vect.push_back(a);
	}
	int n = vect.size();
	int arr [n];
	for(int i=0;i<n;i++){
		arr[i] = vect[i];
	}
	time_t begin, end;
    time(&begin);
	auto start = high_resolution_clock::now();
	quickSort(arr, 0, n-1,ascending);
	auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
	 cout << "Time taken by quick sort: "
         << duration.count() << " milliseconds" << endl;
         cout<<endl;
	if(ascending == true){
	cout<<"Output from quick sort ascending"<<endl;
}
else{
	cout<<"Output from quick sort descending"<<endl;
}
printArray(arr, n);
	redisplay();
	getchar();	
}

// Bubble Sort integers ascending descending
void bubbleSortIntegerFromFile(bool ascending){
	vector<int> vect;
	fstream myfile("myfile1.txt",ios_base::in);
	int a;
	while (myfile >> a)
	{
		vect.push_back(a);
	}
	int n = vect.size();
	int arr [n];
	for(int i=0;i<n;i++){
		arr[i] = vect[i];
}
    auto start = high_resolution_clock::now();
	bubbleSort(arr,n,ascending);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by bubble sort: "
         << duration.count() << " milliseconds" << endl;
         cout<<endl;
	if(ascending == true){
	cout<<"Output from bubble sort ascending"<<endl;
}
else{
	cout<<"Output from bubble sort descending"<<endl;
}
cout<<endl;
printArray(arr, n);
	redisplay();
	getchar();	
}



// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high,bool ascending)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        //change to > for descending order
        if(ascending == true){
		
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
        }else if(ascending == false){
        	if (arr[j] > pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
		}
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}



void quickSort(int arr[], int low, int high,bool ascending)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high,ascending);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,ascending);
        quickSort(arr, pi + 1, high,ascending);
    }
}


// perform bubble sort
void bubbleSort  (int array[], int size,bool ascending) {
    
  // loop to access each array element
  for (int step = 0; step < (size-1); ++step) {
      
    // check if swapping occurs
    int swapped = 0;
    
    // loop to compare two elements
    for (int i = 0; i < (size-step-1); ++i) {
        
      // compare two array elements
      // change > to < to sort in descending order
      
      if(ascending ==  true){
	  
      if (array[i] > array[i + 1]) {

        // swapping occurs if elements
        // are not in intended order 
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        
        swapped = 1;
      }
  }else if(ascending == false){
  	if (array[i] < array[i + 1]) {

        // swapping occurs if elements
        // are not in intended order 
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        
        swapped = 1;
      }
  }
    }

    // no swapping means the array is already sorted
    // so no need of further comparison
    if (swapped == 0)
      break;
  }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 



