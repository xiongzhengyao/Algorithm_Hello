# 排序算法总览

## 1. 比较类排序

### 1.1 交换排序
- 冒泡排序 (Bubble Sort)
  - 时间复杂度: O(n²)
  - 空间复杂度: O(1)
  - 稳定性: 稳定
  - 举例: 
    - 原始数组: [64, 34, 25, 12, 22, 11, 90]
    - 第1轮: [34, 25, 12, 22, 11, 64, 90] (64与34交换)
    - 第2轮: [25, 12, 22, 11, 34, 64, 90] (34与25交换)
    - 第3轮: [12, 22, 11, 25, 34, 64, 90] (25与12交换)
    - 第4轮: [12, 11, 22, 25, 34, 64, 90] (22与11交换)
    - 第5轮: [11, 12, 22, 25, 34, 64, 90] (12与11交换)
    - 最终结果: [11, 12, 22, 25, 34, 64, 90]
  - C++实现:
    ```cpp
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    ```
  - 效率优化: 
    - 设置标志位，如果某一轮没有发生交换，则说明已经排序完成，可以提前退出。
    ```cpp
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            bool swapped = false;
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;  // 如果没有发生交换，说明已经排序完成
            }
        }
    }
    ```
    - 记录最后一次交换的位置，下一轮只需要比较到该位置即可。
    - 使用双向冒泡排序，可以减少比较次数。
    - 使用鸡尾酒排序，可以减少比较次数。
    - 使用奇偶排序，可以减少比较次数。
  效率优化举例：


- 快速排序 (Quick Sort)
  - 时间复杂度: O(nlogn)
  - 空间复杂度: O(logn)
  - 稳定性: 不稳定
  - 举例: 
    - 原始数组: [64, 34, 25, 12, 22, 11, 90]
    - 选择基准元素: 64
    - 分区: [34, 25, 12, 22, 11, 64, 90]
    - 递归排序: [11, 12, 22, 25, 34, 64, 90]
    - 最终结果: [11, 12, 22, 25, 34, 64, 90]
  - C++实现:
    ```cpp
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot+1, high);
        }
    }
    ```

### 1.2 插入排序
- 简单插入排序 (Insertion Sort)
  - 时间复杂度: O(n²)
  - 空间复杂度: O(1)
  - 稳定性: 稳定
  - 举例: 
    - 原始数组: [64, 34, 25, 12, 22, 11, 90]
    - 第1轮: [34, 64, 25, 12, 22, 11, 90] (34插入到64前面)
    - 第2轮: [25, 34, 64, 12, 22, 11, 90] (25插入到34前面)
    - 第3轮: [12, 25, 34, 64, 22, 11, 90] (12插入到25前面)
    - 第4轮: [12, 22, 25, 34, 64, 11, 90] (22插入到25前面)
    - 第5轮: [11, 12, 22, 25, 34, 64, 90] (11插入到12前面)
    - 最终结果: [11, 12, 22, 25, 34, 64, 90]
  - C++实现:
    ```cpp
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    ```

- 希尔排序 (Shell Sort)
  - 时间复杂度: O(n^1.3)
  - 空间复杂度: O(1)
  - 稳定性: 不稳定

### 1.3 选择排序
- 简单选择排序 (Selection Sort)
  - 时间复杂度: O(n²)
  - 空间复杂度: O(1)
  - 稳定性: 不稳定
  - 举例: 
    - 原始数组: [64, 25, 12, 22, 11]
    - 第1轮: [11, 25, 12, 22, 64] (11最小，与64交换)
    - 第2轮: [11, 12, 25, 22, 64] (12最小，与25交换) 
    - 第3轮: [11, 12, 22, 25, 64] (22最小，与25交换)
    - 第4轮: [11, 12, 22, 25, 64] (25最小，位置不变)
    - 最终结果: [11, 12, 22, 25, 64]
  - C++实现:
    ```cpp
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }
    ```
    
    选择排序动画演示:
    ```
    Step 1: 初始数组
    [64│25 12 22 11]  ← 未排序区域
     ↑
    当前位置
    
    Step 2: 找到最小值11
    [64│25 12 22 11]
     ↑           ↑
    当前位置    最小值
    
    Step 3: 交换
    [11│25 12 22 64]  第一轮完成
    ----
    
    Step 4: 移动到下一位
    [11│25│12 22 64]
         ↑
        当前位置
    
    Step 5: 找到最小值12
    [11│25│12 22 64]
         ↑  ↑
        当前位置 最小值
    
    Step 6: 交换
    [11│12│25 22 64]  第二轮完成
    ----
    
    Step 7: 继续
    [11 12│25│22 64]
            ↑
           当前位置
    
    Step 8: 找到最小值22
    [11 12│25│22 64]
            ↑  ↑
           当前位置 最小值
    
    Step 9: 交换
    [11 12│22│25 64]  第三轮完成
    ----
    
    Step 10: 最后一轮
    [11 12 22│25│64]
               ↑
              当前位置
    
    最终结果:
    [11 12 22 25 64]  排序完成
    ```

- 堆排序 (Heap Sort)
  - 时间复杂度: O(nlogn)
  - 空间复杂度: O(1)
  - 稳定性: 不稳定

### 1.4 归并排序 (Merge Sort)
- 时间复杂度: O(nlogn)
- 空间复杂度: O(n)
- 稳定性: 稳定

## 2. 非比较类排序

### 2.1 计数排序 (Counting Sort)
- 时间复杂度: O(n+k)
- 空间复杂度: O(k)
- 稳定性: 稳定

### 2.2 桶排序 (Bucket Sort)
- 时间复杂度: O(n+k)
- 空间复杂度: O(n+k)
- 稳定性: 稳定

### 2.3 基数排序 (Radix Sort)
- 时间复杂度: O(n×k)
- 空间复杂度: O(n+k)
- 稳定性: 稳定

## 3. 各算法特点比较

### 3.1 时间复杂度比较
- O(n²): 冒泡排序、选择排序、插入排序
- O(nlogn): 快速排序、归并排序、堆排序
- O(n+k): 计数排序、桶排序
- O(n×k): 基数排序

### 3.2 稳定性比较
- 稳定: 冒泡排序、插入排序、归并排序、计数排序、桶排序、基数排序
- 不稳定: 快速排序、希尔排序、选择排序、堆排序

### 3.3 适用场景
- 数据量小: 插入排序、选择排序
- 数据量大: 快速排序、归并排序、堆排序
- 数据范围集中: 计数排序、桶排序、基数排序