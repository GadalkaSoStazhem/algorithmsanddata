//
// Created by Boss on 05.09.2023.
//
#include <iostream>

using namespace std;


//оптимизация - рандомный выбор индекса
inline int choose_pivot(int* a, int left, int right){
    return left +(rand() % (right - left + 1));
}

//функция деления на подмассивы

int partition(int* a, int left, int right){ //массив, левый индекс, правый индекс
    int pivot_index = choose_pivot(a, left, right); //индекс опорного элемента
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



void quicksort(int* a, int left, int right){
    if (right <= left)
        return;
    int p = partition(a, left, right);
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
