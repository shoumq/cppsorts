#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <utility>
#include "Node.h"

using namespace std;

// сортировка вставками
void insertionSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

// сортировка пузырьком
void bubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// сортировка выбором
void selectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void shellSort(vector<int>& a) {
    int n = a.size();
    int step, temp;
    for (step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n; i++)
        {
            temp = a[i];
            int j;
            for (j = i; j >= step && a[j - step] > temp; j -= step)
            {
                a[j] = a[j - step];
            }
            a[j] = temp;
        }
    }
}


int main() {
    // vector<int> arr = {5, 2, 6, 2, 4, 3, 9, 1, 0, 7, 8, 3};
    // shellSort(arr);
    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }

    Tree tree;
    Tree::Node* root = nullptr;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 70);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    vector<int> sortedKeys = tree.sort(root);

    cout << "Sorted keys: ";
    for (int key : sortedKeys) {
        std::cout << key << " ";
    }
    cout << std::endl;

    return 0;
}