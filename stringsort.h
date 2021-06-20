#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <chrono>

using  namespace std;
using namespace std::chrono;
void quickSortString(string[], int, int,bool);
void quickSortStringFromFile(bool);
void swap(string[], int, int);
void printArray(string[], int size);
void bubbleSortString(string[], int,bool);
void bubbleSortStringFromFile(bool);

 
 void quickSortString(string a[], int start, int end,bool ascending)
 
{
        // index for the "left-to-right scan"
        int i = start;
        // index for the "right-to-left scan"
        int j = end;

        // only examine arrays of 2 or more elements.
        if (j - i >= 1)
        {
            // The pivot point of the sort method is arbitrarily set to the first element int the array.
            string pivot = a[i];
            // only scan between the two indexes, until they meet.
            while (j > i)
            {
                if(ascending == true){
				
                while (a[i].compare(pivot) <= 0 && i < end && j > i){
                    i++;
                }
            
                while (a[j].compare(pivot) >= 0 && j > start && j >= i){
                    j--;
                }
            }else if(ascending == false){
            	 while (a[i].compare(pivot) >= 0 && i < end && j > i){
                    i++;
                }
               
                while (a[j].compare(pivot) <= 0 && j > start && j >= i){
                    j--;
                }
			}
                // check the two elements in the center, the last comparison before the scans cross.
                if (j > i)
                    swap(a, i, j);
            }

            // Swap the pivot point with the last element of the left partition.
            swap(a, start, j);
            // sort left partition
            quickSortString(a, start, j - 1,ascending);
            // sort right partition
            quickSortString(a, j + 1, end,ascending);
        }
    }
    /**
     * This method facilitates the quickSort method's need to swap two elements, Towers of Hanoi style.
     */
 void swap(string a[], int i, int j)
    {
    string temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    }
    
    
void quickSortStringFromFile(bool ascending){
vector<string> vect;
string line;
  ifstream myfile;
  string i;
  myfile.open("myfile2.txt");
    stringstream ss(line);
    while ( getline (myfile,line) )
    {
    stringstream ss(line);
        getline(ss,i,' ');
        vect.push_back(i);  
	}
	int n = vect.size();
	string arr[n];
	for(int i=0;i<n;i++){
		arr[i] = vect[i];
	}
	auto start = high_resolution_clock::now();
	quickSortString(arr, 0, n-1,ascending);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Time taken by bubble sort: "
         << duration.count() << " milliseconds" << endl;
         cout<<endl;
	if(ascending == true){
	cout<<"Output from quick sort ascending"<<endl;
}
else{
	cout<<"Output from quick sort descending"<<endl;
}
printArray(arr, n);
	getchar();	
}


void bubbleSortStringFromFile(bool ascending){
vector<string> vect;
string line;
  ifstream myfile;
  string i;
  myfile.open("myfile2.txt");
    stringstream ss(line);
    while ( getline (myfile,line) )
    {
    stringstream ss(line);
        getline(ss,i,' ');
        vect.push_back(i);  
	}
	int n = vect.size();
	string arr[n];
	for(int i=0;i<n;i++){
		arr[i] = vect[i];
	}
	auto start = high_resolution_clock::now();
	bubbleSortString(arr,n,ascending);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "Time taken by bubble sort: "
         << duration.count() << " milliseconds" << endl;
         cout<<endl;
	if(ascending == true){
	cout<<"Output from string bubble sort ascending"<<endl;
}
else{
	cout<<"Output from string bubble sort descending"<<endl;
}
printArray(arr, n);
	getchar();	
}

// perform bubble sort
void bubbleSortString(string arr[], int n,bool ascending) {
	string temp;
  // Sorting strings using bubble sort
    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
        	int bLength = arr[i].length();
			int cLength = arr[j].length();
			char b[bLength + 1];
			char c[cLength + 1];
		     strcpy(b,arr[i].c_str());
		     strcpy(c,arr[j].c_str());
        	if(ascending == true){
            if (strcmp(c, b) > 0)
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            	}else if(ascending == false){
            	if (strcmp(c, b) < 0)
            {
                 temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }	
				}
        }
    }
}

void printArray(string arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<< arr[i]<<" ";
    printf("\n");
}
