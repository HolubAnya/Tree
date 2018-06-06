#include <iostream>
using namespace std;
#include "climits"
#include <string.h>

void printArray(int arr[], int size){  //функція, яка виводить масив на екран
    for (int i=0; i < size; i++)
        cout << arr[i] << ", ";
        cout << endl;
}

void printArray(string arr[], int size){ //перегрузка попередньої функції
    for (int i=0; i < size; i++)
        cout << arr[i] << ", ";
        cout << endl;
}

void pushElement(int *array, int &n, const int value){ //функція для вставки елемента в потрібне місце відсортованого масиву
    int *newArray = new int[n]; //динамічно створюємо масив
    n++;//більшуємо розмір
    int j = 0;
    
     while (array[j] < value){ //шукаємо потрібне місце
         newArray[j] = array[j];
         j++; 
     }
    
     newArray[j] = value; //встановлюємо потрібне значення
    
     for (int i = j+1; i < n; i++){
         newArray[i] = array[i-1]; //зміщуємо наступні елементи
    }
     
}

string* alphabeticOrder(string *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2) { //циклічно
        for (int i = gap; i < n; i += 1) {
            string temp = arr[i]; //обираємо елементи в інтервалі
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap]; //змінюємо
            arr[j] = temp; //присвоюємо потрібне значення
        }
    }
    return arr; //повертаємо вісортований масив
}

pair<int, string>* telephoneExchange(pair<int, string> arr[], int n)
{
    for (int gap = n/ 2; gap > 0; gap /= 2) {//циклічно
        for (int i = gap; i < n; i += 1) {
            pair<int, string> temp = make_pair(arr[i].first, arr[i].second);//створюємо пари з елементів
            int j;
            for (j = i; j >= gap && arr[j - gap].first > temp.first; j -= gap) {//поки значення елемента відповідає умові
                arr[j] = arr[j - gap];//присвоюємо потрібне значення
            }
            arr[j] = temp;
        }
    }
    return arr;//повертаємо масив
}

string* LengthSort(int n, string *arr)
{
    for (int gap = n/ 2; gap > 0; gap /= 2) {//циклічно
        for (int i = gap; i < n; i += 1) {
            string temp = arr[i]; //обираємо елементи в інтервалі
            int j;
            for (j = i; j >= gap && arr[j - gap].length() > temp.length(); j -= gap) {//поки значення елемента відповідає умові
                arr[j] = arr[j - gap]; //присвоюємо потрібне значення
            }
            arr[j] = temp;
        }
    }
    return arr;//повертаємо масив
}

int* insertAverage(int *arr, int n)
{
    int* result = new int[n * 2 - 1]; //динамічно ствоюємо масив збільшеного розміру
    for (int i = 0; i < n - 1; i++) //циклічно
    {
        int av = (arr[i] + arr[i + 1]) / 2; //знаходимо середнє значення
        pushElement(arr, n, av); //вставляємо його у потрібне місце за допомогю функції вище
    }
    return arr;//повертаємо масив
}
