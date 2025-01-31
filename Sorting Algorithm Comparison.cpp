#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

// Function to generate random dataset
vector<int> generateRandomDataset(int size) {
    vector<int> dataset(size);
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 1000);
    for (int i = 0; i < size; ++i) {
        dataset[i] = dist(mt);
    }
    return dataset;
}

// Function to generate sorted dataset
vector<int> generateSortedDataset(int size) {
    vector<int> dataset(size);
    for (int i = 0; i < size; ++i) {
        dataset[i] = i + 1;
    }
    return dataset;
}

// Function to generate reverse sorted dataset
vector<int> generateReverseSortedDataset(int size) {
    vector<int> dataset(size);
    for (int i = 0; i < size; ++i) {
        dataset[i] = size - i;
    }
    return dataset;
}

// Bubble Sort implementation
void bubbleSort(vector<int>& dataset) {
    int n = dataset.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (dataset[j] > dataset[j + 1]) {
                swap(dataset[j], dataset[j + 1]);
            }
        }
    }
}

// Merge Sort implementation
void merge(vector<int>& dataset, int left, int mid, int right) {
    vector<int> leftArr(mid - left + 1);
    vector<int> rightArr(right - mid);
    for (int i = 0; i < leftArr.size(); ++i) {
        leftArr[i] = dataset[left + i];
    }
    for (int i = 0; i < rightArr.size(); ++i) {
        rightArr[i] = dataset[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            dataset[k] = leftArr[i];
            ++i;
        } else {
            dataset[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    while (i < leftArr.size()) {
        dataset[k] = leftArr[i];
        ++i;
        ++k;
    }
    while (j < rightArr.size()) {
        dataset[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSortHelper(vector<int>& dataset, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(dataset, left, mid);
        mergeSortHelper(dataset, mid + 1, right);
        merge(dataset, left, mid, right);
    }
}

void mergeSort(vector<int>& dataset) {
    mergeSortHelper(dataset, 0, dataset.size() - 1);
}

// Quick Sort implementation
int partition(vector<int>& dataset, int low, int high) {
    int pivot = dataset[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (dataset[j] <= pivot) {
            ++i;
            swap(dataset[i], dataset[j]);
        }
    }
    swap(dataset[i + 1], dataset[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& dataset, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(dataset, low, high);
        quickSortHelper(dataset, low, pivotIndex - 1);
        quickSortHelper(dataset, pivotIndex + 1, high);
    }
}

void quickSort(vector<int>& dataset) {
    quickSortHelper(dataset, 0, dataset.size() - 1);
}

// Function to measure execution time
double measureExecutionTime(void (*func)(vector<int>&), const vector<int>& dataset) {
    auto start = chrono::high_resolution_clock::now();
    vector<int> datasetCopy = dataset;
    func(datasetCopy);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
}

int main() {
    int sizes[] = {100, 500, 1000, 2000, 5000};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    const int numAlgorithms = 3;
    string algorithmNames[] = {"Bubble Sort", "Merge Sort", "Quick Sort"};
    void (*algorithms[])(vector<int>&) = {bubbleSort, mergeSort, quickSort};

    cout << "Sorting Algorithm Comparison" << endl;
    cout << "----------------------------" << endl;

    for (int sizeIndex = 0; sizeIndex < numSizes; ++sizeIndex) {
        int size = sizes[sizeIndex];
        cout << "Dataset Size: " << size << endl;
        vector<int> randomDataset = generateRandomDataset(size);
        vector<int> sortedDataset = generateSortedDataset(size);
        vector<int> reverseSortedDataset = generateReverseSortedDataset(size);

        // Measure execution time for each algorithm
        for (int algorithmIndex = 0; algorithmIndex < numAlgorithms; ++algorithmIndex) {
            double randomTime = measureExecutionTime(algorithms[algorithmIndex], randomDataset);
            double sortedTime = measureExecutionTime(algorithms[algorithmIndex], sortedDataset);
            double reverseSortedTime = measureExecutionTime(algorithms[algorithmIndex], reverseSortedDataset);

            cout << algorithmNames[algorithmIndex] << ":" << endl;
            cout << "  Random Dataset: " << randomTime << " ms" << endl;
            cout << "  Sorted Dataset: " << sortedTime << " ms" << endl;
            cout << "  Reverse Sorted Dataset: " << reverseSortedTime << " ms" << endl;
        }

        cout << endl;
    }

    return 0;
}
