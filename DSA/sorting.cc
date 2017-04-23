#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <ctime>

void mergeSort(std::vector<int> &ivec, int l, int h);
void merge(std::vector<int> &ivec, int l, int m, int h);
void insertionSort(std::vector<int> &ivec);
void selectionSort(std::vector<int> &ivec);
void bubbleSort(std::vector<int> &ivec);

int main()
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    int n;
    std::cout << "Size: ";
    std::cin >> n;
    std::vector<int> mergeVec;

    for(int i = 0; i < n; ++i)
    {
        int num = dist(engine);
        mergeVec.push_back(num);
    }
    
    std::vector<int> bubbleVec(mergeVec.begin(), mergeVec.end());
    std::vector<int> selectionVec(mergeVec.begin(), mergeVec.end());
    std::vector<int> insertionVec(mergeVec.begin(), mergeVec.end());

    clock_t start, end;

    // // merge sort
    start = clock();
    mergeSort(mergeVec, 0, n - 1);
    end = clock();

    std::cout << "Merge Sort\nTime Taken: " << std::fixed
              << static_cast<double> (end - start) / CLOCKS_PER_SEC << "\n\n";
    
    // insertion sort
    start = clock();
    insertionSort(insertionVec);
    end = clock();

    std::cout << "Insertion Sort\nTime Taken: " << std::fixed
              << static_cast<double> (end - start) / CLOCKS_PER_SEC << "\n\n";

    // selection sort
    start = clock();
    selectionSort(selectionVec);
    end = clock();

    std::cout << "Selection Sort\nTime Taken: " << std::fixed
              << static_cast<double> (end - start) / CLOCKS_PER_SEC << "\n\n";

    // bubble sort
    start = clock();
    bubbleSort(bubbleVec);
    end = clock();

    std::cout << "Bubble Sort\nTime Taken: " << std::fixed
              << static_cast<double> (end - start) / CLOCKS_PER_SEC << '\n';
}

void mergeSort(std::vector<int> &ivec, int l, int h)
{
    if(l >= h)
        return ;
    
    int m = (l + h) / 2;
    mergeSort(ivec, l, m);
    mergeSort(ivec, m + 1, h);
    merge(ivec, l, m, h);
}

void merge(std::vector<int> &ivec, int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    std::vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; ++i)
        left[i] = ivec[i + l];
    
    for(int i = 0; i < n2; ++i)
        right[i] = ivec[i + m + 1];
    
    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
        ivec[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    
    while(i < n1)
        ivec[k++] = left[i++];
    
    while(j < n2)
        ivec[k++] = right[j++];
}

void insertionSort(std::vector<int> &ivec)
{
    size_t n = ivec.size();

    for(size_t i = 1; i < n; ++i)
    {
        int key = ivec[i];
        int j = i - 1;

        while(j >= 0 && ivec[j] > key)
        {
            ivec[j + 1] = ivec[j];
            --j;
        }

        ivec[j + 1] = key;
    }
}

void bubbleSort(std::vector<int> &ivec)
{
    size_t n = ivec.size();
    for(size_t i = 0; i < n - 1; ++i)
        for(size_t j = 0; j < n - 1 - i; ++j)
            if(ivec[j] > ivec[j + 1])
            {
                int temp = ivec[j + 1];
                ivec[j + 1] = ivec[j];
                ivec[j] = temp;
            }
}

void selectionSort(std::vector<int> &ivec)
{
    size_t n = ivec.size();

    for(size_t i = 0; i < n; ++i)
    {
        size_t imin = i;
        for(size_t j = i + 1; j < n; ++j)
            if(ivec[j] < ivec[imin])
                imin = j;
        
        int temp = ivec[imin];
        ivec[imin] = ivec[i];
        ivec[i] = temp;
    }
}