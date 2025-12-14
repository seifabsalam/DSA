#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void selectionSort(int* arr, int size)
{
    int minIndex;
    for (int i = 0; i < size-1; i++)
    {
        minIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]>arr[j])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(int* arr, int start, int mid, int end)
{
    int n = mid - start + 1;
    int m = end - mid;
    int* arr_L = new int[n] ;
    int* arr_R = new int[m] ;

    for (int i = 0; i < n; i++)
        arr_L[i] = arr[start+i];
    for (int i = 0; i < m; i++)
        arr_R[i] = arr[mid+1+i];

    int i = 0 , j = 0, k = start;

    while (i<n && j<m)
    {
        if (arr_L[i] <= arr_R[j])
        {
            arr[k] = arr_L[i];
            i++;
        }
        else
        {
            arr[k] = arr_R[j];
            j++;
        }
        k++;
    }

    while(i < n)
    {
        arr[k] = arr_L[i];
        i++;
        k++;
    }

    while(j < m)
    {
        arr[k] = arr_R[j];
        j++;
        k++;
    }

    delete[] arr_L;
    delete[] arr_R;
}

void mergeSort(int* arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end-start)/2 ;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

bool iterativeBS(int* arr, int size, int target)
{
    int low = 0;
    int high = size-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

bool recursiveBS(int* arr, int target, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return recursiveBS(arr, low, mid - 1, target);
        return recursiveBS(arr, mid + 1, high, target);
    }
    return false;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



int main()
{
    int arr[] = {5,4,3,2,1};
    int arr2[] = {5,4,3,2,1};
    int arr3[] = {5,4,3,2,1};
    int arr4[] = {5,4,3,2,1};
    bubbleSort(arr, 5);
    selectionSort(arr2, 5);
    mergeSort(arr3, 0, 4);
    quickSort(arr4,0,4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << "\t";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr2[i] << "\t";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr3[i] << "\t";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr4[i] << "\t";
    cout << endl;

    /*
    if (iterativeBS(arr, 5, 5))
        cout << "Found!!" << endl;
    else
        cout << "Not There!!" << endl;
    if (iterativeBS(arr, 5, 6))
        cout << "Found!!" << endl;
    else
        cout << "Not There!!" << endl;
    if (recursiveBS(arr, 5, 0, 4))
        cout << "Found!!" << endl;
    else
        cout << "Not There!!" << endl;
    if (recursiveBS(arr, 6, 0, 4))
        cout << "Found!!" << endl;
    else
        cout << "Not There!!" << endl;
    cout << "=============Q1================" << endl;
    int r, c;
    cout << "PLZ enter r, c:" << endl;
    cin >> r ;
    cin >> c ;
    cout << "PLZ enter matrix values:" << endl;
    int* matrix = new int[r*c];
    for (int i = 0; i < r*c; i++)
        cin >> matrix[i];
    mergeSort(matrix, 0, r*c-1);
    for (int i = 0; i < r; i++)
    {
        for(int j = i*r; j < (i+1)*c; j++)
            cout << matrix[j] << "\t";
        cout << endl;
    }
    delete[] matrix ;
    /// { {5, 4, 7}, {1, 3, 8}, {2, 9, 6} }

    cout << "=============Q2================" << endl;
    int freq[100] = {};
    int n;
    int dump;
    cout << "PLZ Enter number elements:" << endl;
    cin >> n;
    cout << "PLZ Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> dump;
        freq[dump]++;
    }
    ///mergeSort(freq, 0, 99);
    for (int i = 99; i >= 0; i--)
    {
        while(freq[i])
        {
            cout << i << "\t" ;
            freq[i] --;
        }
    }
    cout << endl;
    /// 9 9 9 5 2
    */
    return 0;
}
