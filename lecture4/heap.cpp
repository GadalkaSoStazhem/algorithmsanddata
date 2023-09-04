//
// Created by Boss on 04.09.2023.
//

#include <cmath>
#include <iostream>
#include <array>
using namespace std;

//функции для нахождения родителя и детей элемента
int parent(int i){
    return floor((i - 1) / 2);
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

//операция подъема
void siftup(int* a, int i){
    while(a[i] > a[parent(i)] && i > 0){
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}
//добавление нового элемента
void insert(int* a, int x, int &n){
    a[n++] = x;
    siftup(a, n - 1);
}

//операция спуска с рекурсией
void siftdown(int* a, int i, int n){
    int j = i;
    if (left(i) < n && a[j] < a[left(i)]){
        j = left(i);
    }
    if (right(i) < n && a[j] < a[right(i)]){
        j = right(i);
    }
    if (i != j){
        swap(a[i], a[j]);
        siftdown(a, j, n);
    }
}
//спуск без рекурсии (быстрее рекурсии)
void siftdown_no_rec(int* a, int i, int n){
    int j = i;
    while(true) {
        if (left(i) < n && a[j] < a[left(i)]) {
            j = left(i);
        }
        if (right(i) < n && a[j] < a[right(i)]) {
            j = right(i);
        }
        if (i == j)
            break;
        swap(a[i], a[j]);
        i = j;
    }
}

int extract_max(int* a, int& n){
    swap(a[0], a[--n]);
    siftdown(a, 0, n);
    return a[n];
}

void print_arr(int* arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

//увеличение ключа приоритета (не нужна для сортировки кучей) - кода в лекции не было, это мой
int ind_and_change(int* arr, int old_val, int new_val, int n){
    int ind = -1;
    for (int i = 0; i < n; i++){
        if (arr[i] == old_val){
            arr[i] = new_val;
            ind = i;
        }
    }
    return ind;
}

void increase_key(int* arr, int ind, int n){
    if(arr[ind] > arr[parent(ind)]){
        siftup(arr, ind);
    }
    else{
        if (arr[ind] < arr[left(ind)] || arr[right(ind)]){
            siftdown(arr, ind, n);
        }
        else{
            abort();
        }
    }
}

void heap_actions(){
    int a[] = {56, 45, 34, 16, 27, 10, 21,13, 7, 15, 19, 8};
    int n = end(a) - begin(a);
    cout << "Исходный массив" << endl;
    print_arr(a, n);
    cout << endl;

    int a_ins[n];
    copy(begin(a), end(a), a_ins);
    int n_ins = n;
    cout << "Массив после добавления значения 50" << endl;
    insert(a_ins, 50, n_ins);
    print_arr(a_ins, n_ins);
    cout << endl;

    int a_extr[n];
    copy(begin(a), end(a), a_extr);
    int n_extr = n;
    cout << "Максимальный элемент: " << extract_max(a_extr, n_extr) << endl;
    cout << "Массив после перестановки " << endl;
    print_arr(a_extr, n_extr);
    cout << endl;

    int a_inc[n];
    copy(begin(a), end(a), a_inc);
    int n_inc = n;
    int ind = ind_and_change(a_inc, 16, 77, n_inc);
    cout << "Массив после изменения згачения 16 на 77" << endl;
    print_arr(a_inc, n_inc);
    cout << endl;
    increase_key(a_inc, ind, n);
    cout << "Сбалансированный массив" << endl;
    print_arr(a_inc, n_inc);
    cout << endl;
}

//ПОСТРОЕНИЕ КУЧИ ИЗ НЕСОРТИРОВАННОГО МАССИВА
//Метод Вильямса
void build_heap_insert(int* a, int n){
    int sz = 0;
    while(sz < n){
        insert(a, a[sz], sz);
    }
}

//метод Флойда (более оптимизированный, чем метод Вильямса)
void build_heap(int* a, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        siftdown(a, i, n);
    }
}

//Построение кучи из массива
void heap_builder(){
    int arr[] = {8, 13, 21, 27, 34, 19, 15, 10, 7, 16, 56, 45};
    int n = end(arr) - begin(arr);
    int arr_williams[n];
    int n_williams = n;
    copy(begin(arr), end(arr), arr_williams);
    build_heap_insert(arr_williams, n_williams);
    cout << "Метод Вильямса (хз почему нормально не работает, я вс списала с лекции)" << endl;
    print_arr(arr_williams, n_williams);
    cout << endl;

    int arr_floyd[n];
    int n_floyd = n;
    copy(begin(arr), end(arr), arr_floyd);
    build_heap(arr_floyd, n_floyd);
    cout << "Метод Флойда (результат как в лекции)" << endl;
    print_arr(arr_floyd, n_floyd);
    cout << endl;
}

//HEAPSORT - сортировка кучей
//надо использовать max-heap, чтобы не выделять дополнительную память
void heap_sort(int* heap, int n){
    while(n > 0){
        extract_max(heap, n);
    }
}

void sorting_staff(){
    int arr[] = {8, 13, 21, 27, 34, 19, 15, 10, 7, 16, 56, 45};
    int n = end(arr) - begin(arr);
    int heap[n];
    copy(begin(arr), end(arr), heap);
    build_heap(heap, n);
    cout << "Куча до сортировки" << endl;
    print_arr(heap, n);
    cout << "\nКуча после сортировки \n";
    heap_sort(heap, n);
    print_arr(heap, n);
    cout << endl;
}

int main(){
    cout << "ПРОСТО ПРИКОЛЫ С КУЧЕЙ" << endl;
    heap_actions();
    cout << "\nСОЗДАНИЕ КУЧИ ИЗ МАССИВА" << endl;
    heap_builder();
    cout << "\nСОРТИРОВКА КУЧЕЙ" << endl;
    sorting_staff();
    return 0;
}
