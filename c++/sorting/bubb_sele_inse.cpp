#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

clock_t start_bubble, end_bubble;
clock_t start_selection, end_selection;
clock_t start_insertion, end_insertion;

// Bubble Sort
void bubble(int arr[], int ele) {
    for (int i = 0; i < ele - 1; i++) {
        for (int j = 0; j < ele - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selection(int arr[], int ele) {
    for (int i = 0; i < ele - 1; i++) {
        int minind = i;
        for (int j = i + 1; j < ele; j++) {
            if (arr[j] < arr[minind]) {
                minind = j;
            }
        }
        if (minind != i) {
            swap(arr[i], arr[minind]);
        }
    }
}

// Insertion Sort
void insertion(int arr[], int ele) {
    for (int i = 1; i < ele; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int ele;
    cout << "Enter the number of elements in the array: ";
    cin >> ele;
    int arr[ele];

    // Random Seed Initialization
    srand(time(NULL));
    
    for (int i = 0; i < ele; i++) {
        arr[i] = rand() % 1000;
    }
    
    cout << "Original array: ";
    for (int i = 0; i < ele; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int bubble_arr[ele], selection_arr[ele], insertion_arr[ele];
    for (int i = 0; i < ele; i++) {
        bubble_arr[i] = arr[i];
        selection_arr[i] = arr[i];
        insertion_arr[i] = arr[i];
    }

    cout << "\nBubble Sort\n";
    start_bubble = clock();
    bubble(bubble_arr, ele);
    end_bubble = clock();
    double elapsed_time_bubble = ((double)(end_bubble - start_bubble) / CLOCKS_PER_SEC);
    cout << "Time taken by Bubble Sort: " << elapsed_time_bubble * 1000 << " milliseconds" << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < ele; i++) {
        cout << bubble_arr[i] << " ";
    }
    cout << endl;

    cout << "\nSelection Sort\n";
    start_selection = clock();
    selection(selection_arr, ele);
    end_selection = clock();
    double elapsed_time_selection = ((double)(end_selection - start_selection) / CLOCKS_PER_SEC);
    cout << "Time taken by Selection Sort: " << elapsed_time_selection * 1000 << " milliseconds" << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < ele; i++) {
        cout << selection_arr[i] << " ";
    }
    cout << endl;

    cout << "\nInsertion Sort\n";
    start_insertion = clock();
    insertion(insertion_arr, ele);
    end_insertion = clock();
    double elapsed_time_insertion = ((double)(end_insertion - start_insertion) / CLOCKS_PER_SEC);
    cout << "Time taken by Insertion Sort: " << elapsed_time_insertion * 1000 << " milliseconds" << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < ele; i++) {
        cout << insertion_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
