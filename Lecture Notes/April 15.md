Here are **detailed notes** from the lecture transcript, organized by topic:

---

### 🔧 **Log File Redirection (Program Output Management)**
- Use `&` and redirection (`>`) to direct all terminal output to a log file (cross-platform for macOS & Windows).
- Example: `./gold_rabbits > goldrabbits.log`
- This is how graders validate your program’s output—**you should not open `goldrabbits.log` in your code**.
- Log file redirection simplifies grading by avoiding manual file searching.

---

### 📆 **Schedule & Assignment Overview**
- There are about **3 weeks and 1 day left** in the semester.
- **Program 6** is assigned next Tuesday (April 22).
- **Program 5 is due and quizzed** that same day.
- **Quiz for Program 6** is scheduled for the **last class session**.
- **May 8:** Ivy will give a **final exam review**.
- **Final exam is May 15, 5:00–7:00 PM** in the usual classroom.
- Instructor prefers a **cumulative final** (50% past content, 50% recent).

---

### 📚 **Topics for Today:**
- Namespaces
- Custom Vectors
- Templates (you've been using them unknowingly)
- Extra credit opportunity: a more complex program using these concepts

---

### 📦 **C++ Vectors (Standard Template Library - STL)**
#### 📌 General Overview
- Vectors are **dynamic arrays**: unlike static arrays, they grow/shrink during runtime.
- Defined in the **`<vector>` header**.
- Part of STL, which includes `vector`, `map`, `set`, `list`, etc.
- All vector elements must be the **same data type** (for speed and memory layout).

#### 🆚 Vector vs Array
| Feature            | Vector                           | Array                          |
|--------------------|-----------------------------------|--------------------------------|
| Size               | Dynamic                          | Fixed                          |
| Bounds checking    | Optional (with `.at()`)          | No built-in protection         |
| Insertion          | Easy with `.insert()`            | Must shift elements manually   |
| Memory layout      | Contiguous                       | Contiguous                     |
| Speed              | Slightly slower (more overhead)  | Faster but rigid               |

---

### 🧪 **Vector Declaration Examples**
```cpp
vector<int> example;                   // empty
vector<int> example1 = {1, 2, 3, 4};   // 4 elements
vector<int> example2{5, 6, 7, 8};      // 4 elements
vector<int> example3(5, 10);           // 5 elements, all 10
vector<int> example4(5);              // 5 elements, all 0
```

---

### 📤 **Passing Vectors to Functions**
- Without `&` = **pass by value** → function gets a **copy**.
- With `&` = **pass by reference** → function can **modify original** vector.

---

### 🔧 **Useful Vector Functions**
| Function         | Description |
|------------------|-------------|
| `.size()`        | Number of elements |
| `.clear()`       | Removes all elements |
| `.front()`       | Returns first element |
| `.back()`        | Returns last element |
| `.push_back(x)`  | Appends `x` to end |
| `.pop_back()`    | Removes last element |
| `.at(i)`         | Safe access (bounds-checked) |
| `[i]`            | Regular access (not safe) |
| `.empty()`       | Returns true if size = 0 |
| `.capacity()`    | Total reserved storage |
| `.max_size()`    | Max theoretical size (often ~2 billion+) |
| `.resize(n)`     | Resizes vector to size `n` |
| `.assign(n, x)`  | Fill vector with `n` elements of value `x` |
| `.swap(v2)`      | Swaps contents with `v2` |
| `.data()`        | Returns pointer to internal array (contiguous memory) |

---

### 🧠 **Vector Memory & Performance**
- **Capacity doubles** when exceeded (e.g., 4 → 8 → 16...).
- **Memory reallocation** is costly (copying old → new space).
- Vectors change **address** when resized.

---

### 🧵 **Templates & Type Safety**
- Vectors are **templated containers**.
- Can be used for any consistent type (e.g., `int`, `string`, custom class).
- Benefit: type safety + reuse across types without duplication.

---

### 🌐 **Namespaces**
- Prevent naming collisions (e.g., `draw()` in card game vs. graphics library).
- Common to use `using namespace std;` to avoid `std::` everywhere.
- Safer to specify namespace if function names conflict.

---

### 🔁 **Iterators in Vectors**
| Iterator       | Purpose |
|----------------|---------|
| `begin()`      | Points to first element |
| `end()`        | Points one past the last element |
| `rbegin()`     | Reverse begin (last element) |
| `rend()`       | One before first (in reverse) |
| `cbegin()`, `cend()` | Constant iterators |
| `crbegin()`, `crend()` | Constant reverse iterators |

- Normal iterators can use `++`, but not `--`.
- Reverse iterators traverse backward with `++`.

---

Let me know if you want these in a printable format or want a cheat sheet from them!