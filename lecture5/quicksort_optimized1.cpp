//
// Created by Boss on 05.09.2023.
//
#include <iostream>

using namespace std;

//функция деления на подмассивы

int partition(int* a, int left, int right){ //массив, левый индекс, правый индекс
    int pivot_index = left; //индекс опорного элемента
    if (pivot_index != left)
        swap(a[left], a[pivot_index]);
    int p = a[left]; //сам опорный элемент
    int i = left + 1;
    for (int j = left + 1; j <= right; j++){
        if (a[j] <= p){
            swap(a[j], a[i]);
            ++i;
        }
    }
    swap(a[left], a[i - 1]);
    return i - 1; //индекс расположения опорного элемента
}


//оптимизация - выбор медианы в качестве опорного элемента
inline void comp_swap(int &a, int &b){
    if (a > b)
        swap(a, b);
}

void quicksort(int* a, int left, int right){
    if (right <= left)
        return;
    swap(a[(left + right) / 2], a[left + 1]);
    comp_swap(a[left], a[left + 1]);
    comp_swap(a[left], a[right]);
    comp_swap(a[left + 1], a[right]);
    if (right - left <= 2)
        return;
    int p = partition(a, left + 1, right - 1);
    quicksort(a, left, p - 1);
    quicksort(a, p + 1, right);
}


int main(){
    int arr[] = {2, 8, 9, 4, 1, 10, 7, 7};
    quicksort(arr, 0, 7);
    for (auto el : arr){
        cout << el << " ";
    }
    return 0;
}
