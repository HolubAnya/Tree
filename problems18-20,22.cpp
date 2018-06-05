#include <iostream>
using namespace std;
#include "climits"
#include <string.h>

void printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << ", ";
        cout << endl;
}

void printArray(string arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << ", ";
        cout << endl;
}

void pushElement(int *array, int &n, const int value){
    int *newArray = new int[n];
    n++;
    int j = 0;
    
     while (array[j] < value){
         newArray[j] = array[j];
         j++; 
     }
    
     newArray[j] = value;
    
     for (int i = j+1; i < n; i++){
         newArray[i] = array[i-1];
    }
     
}

string* alphabeticOrder(string *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            string temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return arr;
}

pair<int, string>* telephoneExchange(pair<int, string> arr[], int n)
{
    for (int gap = n/ 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            pair<int, string> temp = make_pair(arr[i].first, arr[i].second);
            int j;
            for (j = i; j >= gap && arr[j - gap].first > temp.first; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

string* LengthSort(int n, string *arr)
{
    for (int gap = n/ 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            string temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].length() > temp.length(); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return arr;
}

int* insertAverage(int *arr, int n)
{
    int* result = new int[n * 2 - 1];
    for (int i = 0; i < n - 1; i++)
    {
        int av = (arr[i] + arr[i + 1]) / 2;
        pushElement(arr, n, av);
    }
    return arr;
}