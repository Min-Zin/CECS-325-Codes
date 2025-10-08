Here are **detailed notes** based on your lecture transcript from April 8:

---

## 📆 Course & Schedule Updates
- **Final Program (Program 5)**: Will be assigned in two weeks, focused on **operator overloading**.
- **Last Class (April 29)**:
  - **Quiz Review**
  - **Final Test Preparation**
  - **Potential guest presentation (Ivy)**
- **Final Test**: Scheduled for the **week of May 6**

---

## 🧵 Topic: C-Strings vs. std::string
- **Why Learn C-Strings?**
  - C was a foundational language; many legacy systems still use it.
  - C-strings are essentially character arrays ending in a null terminator (`'\0'`).
  - Knowledge is important for maintaining old codebases.

- **Example**:
  ```cpp
  char a[10] = "bingo";
  ```
  - `"bingo"` has 5 letters + `'\0'` → total size used: 6
  - `strlen(a)` (from `<cstring>`) returns `5`
  - `sizeof(a)` would return `10` (array size)

- **Writing a custom `strlen()` function**:
  - Use `while` loop to count until `'\0'` is reached.
  - Arrays and pointers can be used interchangeably in C/C++.

  ```cpp
  int strlen(const char* a) {
      int i = 0;
      while (*(a + i) != '\0') {
          i++;
      }
      return i;
  }
  ```

---

## 🚀 Integer Overflow: Ariane 5 Failure Case Study
- **Story Summary**:
  - Ariane 5 rocket exploded in 1996 due to integer overflow.
  - Guidance system tried converting a large 64-bit float to a 16-bit int.
  - Resulted in **integer overflow**, leading to a **shutdown** and misinterpreted navigational data.
  - Lesson: **Overflow handling is critical**, especially in high-stakes systems.

- **In C++**:
  - `int` max value ≈ 2.1 billion
  - Adding two large `int`s can result in **wrap-around (negative value)**

---

## 🐇 Gold Rabbits Assignment (Program 5)
### Concept:
- Mimics the **Fibonacci sequence**: each month, rabbits reproduce as follows:
  - Baby rabbits mature in 1 month.
  - Each **mature pair** produces 1 new **baby pair** every month.
  - **Rabbits never die.**

- Recursive function `goldRabbits(n)`:
  ```cpp
  int goldRabbits(int n) {
      if (n == 0 || n == 1) return 1;
      return goldRabbits(n - 1) + goldRabbits(n - 2);
  }
  ```

---

## 🛠️ Task Requirements
1. **Detect and Handle Integer Overflow**:
   - If overflow is detected, **throw an exception** with the value of `n` where it occurs.
   - Example: if overflow happens at `n = 46`, throw an error dynamically (don’t hardcode).

2. **Optimize with Memoization (using `map`)**:
   - Use `static std::map<int, int>` inside the recursive function.
   - Store and retrieve previously calculated values to avoid redundant calls.

3. **Print Map Contents**:
   - If function is called with `-1`, **print all key-value pairs** from the map.
   - Helps verify internal state of memoization.

4. **Error Handling**:
   - Handle invalid inputs:
     - Strings: print error "You can’t Fibonacci a string"
     - Integers < -1 (other than -1): optional to reject

5. **Logging Output**:
   - Submit a `.sh` log file showing outputs for:
     - Several inputs (e.g., `4`, `6`, `1000`)
     - `-1` for printing the map
     - A large value causing overflow
     - An invalid input like `"monkey"`

---

## 🕐 Performance Discussion
- **Unoptimized recursion** for large `n` (e.g., `45+`) takes excessive time due to repeated calls.
- **Memoization** turns a deep recursive structure into a **linear-time** process.

---

## 🔁 Alternatives to Recursion
- **Iterative approach** is also valid and more efficient.
- Optionally explore **tail recursion** in Program 6.

---

## 📝 Summary Checklist
- [ ] Implement `goldRabbits(n)` with recursion.
- [ ] Use `std::map` with `static` keyword for memoization.
- [ ] Detect overflow by checking for a negative result when adding positive integers.
- [ ] Throw and catch exceptions properly.
- [ ] Handle special inputs (`-1`, invalid strings).
- [ ] Print map contents when input is `-1`.
- [ ] Create a shell script (`.sh`) log file capturing output for required test cases.

---

Let me know if you want help drafting the code or the shell script!