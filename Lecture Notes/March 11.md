### **Key Notes & Important Process Steps for Parallel Sorting with Bubble Sort**
---

### **Key Notes**
1. **Parallel Processing Concept**  
   - The dataset (array of 1 million elements) is split into **16 segments** of equal size (62,500 elements each).  
   - Each segment is sorted **independently** using **bubble sort**.  
   - Sorting within each segment does not interfere with others.  
<br>

2. **Why Parallel Sorting Helps**  
   - Bubble sort has **O(n²) complexity**, making it inefficient for large datasets.  
   - **Dividing the problem** into smaller segments allows multiple CPUs to work simultaneously.  
   - More CPUs mean faster processing and reduced total swaps.  
<br>

3. **Threading & Multi-Core Processing**  
   - Each segment is processed by a separate **CPU thread**.  
   - The program creates **multiple threads**, each handling one segment.  
   - Uses **join operations** to ensure threads complete before merging.  
<br>

4. **Swap Counts & Performance**  
   - The number of swaps **decreases** as the number of segments increases.  
   - Doubling the number of segments **reduces swap count significantly** due to reduced sorting complexity.  
   - There is an **optimal segment size** where performance is maximized.  
<br>

5. **Merging the Segments**  
   - After sorting, the 16 sorted segments must be **merged into a final sorted array**.  
   - This step **does not use merge sort**; it just **combines pre-sorted segments sequentially**.  
<br>

6. **Memory Management**  
   - Uses **dynamic memory allocation** (`new` keyword in C++).  
   - Properly **deallocates memory** after sorting and merging (`delete[]`).  
   - No **vectors** are used—only dynamically allocated arrays.  
<br>

7. **Mutex (Mutual Exclusion) for Global Variables**  
   - A **global swap counter** is updated by multiple threads.  
   - Mutex ensures **only one thread** modifies the global counter at a time.  
   - Prevents **race conditions** and data corruption.  

---

### **Important Process Steps**
#### **Step 1: Data Preparation**
- Allocate memory dynamically for **1 million integers**.  
- Read data from an input file (`numbers.dat`).  
- Split the array into **16 equal parts**.  

#### **Step 2: Multi-Threading Setup**
- Create **16 separate threads**.  
- Assign **each thread** to sort one segment using **bubble sort**.  
- Start **all threads simultaneously**.  

#### **Step 3: Sorting Each Segment (Parallel Execution)**
- Each thread runs **bubble sort** on its assigned segment.  
- The global swap counter is updated with **mutex locking** to prevent conflicts.  

#### **Step 4: Thread Synchronization**
- Use `.join()` to **wait for all threads to complete** before moving forward.  

#### **Step 5: Merging the Sorted Segments**
- Merge **all 16 sorted arrays** into one final sorted array.  
- This is done **sequentially** rather than using merge sort.  

#### **Step 6: Memory Cleanup**
- **Deallocate dynamically allocated memory** to prevent memory leaks.  

#### **Step 7: Performance Analysis**
- Record **swap counts and execution times** for different segment sizes.  
- Observe **trade-offs between parallelism and processing overhead**.  