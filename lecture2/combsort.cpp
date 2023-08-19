//
// Created by Boss on 19.08.2023.
//


//Сортировка расческой, в лекции нет

// вообще gap - зазор по-английски (как между зубцами гребня)
// но я буду называть это "промежуток", потому что "зазор" как-то по-дибильному
#include <iostream>
#include <array>
using namespace std;

// нахождение промежутка между элементами
int getNextGap(int gap)
{
    // по вот этой формуле находим промежуток (хз откуда, везде эта цифра)
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

void combsort(int a[], int n)
{
    // объявление промежутка
    int gap = n;

    // флаг перестановки
    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        // нахождение следующего промежутка
        gap = getNextGap(gap);

        swapped = false;

        // сравнение элементов с текущим промежутком
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}

int main(){
    int arr[] = {3, 9, 4, 1, 15, 6};
    combsort(arr, 6);

    for (auto el : arr){
        cout<<el<<' ';
    }
    return 0;
}


