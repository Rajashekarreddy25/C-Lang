# Introduction to C
1.charcter set:names that are used to write c program .

2.identifer :Names given to to memory locations .

3.keywords : pre-defined words are keywords.

4.datatypes : 

5.constants :

6.variables :

### character set:

We have 4 Categories in character set 

1. Alphabets:
### Arrays in C

### An array is a data structure that is used to store elements of the same data type, and memory allocated is contiguous


✅ Field Width, Precision, and Suppression in C (printf() and scanf())
📌 printf() – Field Width and Precision
🔹 Field Width (Minimum Display Width)
It defines the minimum number of characters to be printed.

If the actual output is shorter, it is right-aligned and padded with spaces by default.

```
printf("%5d", 42);     // Output: "   42"
printf("%-5d", 42);    // Output: "42   " (left-aligned)

```
🔹 Precision
Precision means different things depending on data type:

Type	Meaning of Precision	Example
float	Digits after decimal point	printf("%.2f", 3.14159); // 3.14
int	Minimum number of digits	printf("%.5d", 42); // 00042
string	Maximum characters to print	printf("%.3s", "Hello"); // Hel

🔹 Field Width + Precision Together
```
printf("%8.2f", 3.14); // Output: "    3.14"

```
Total width: 8

Decimal digits: 2

Spaces are added in the front to match width

📌 scanf() – Field Width, Precision, and Suppression
🔹 Field Width in scanf()
It limits the number of characters read from input.

```
char name[10];
scanf("%5s", name);  // Even if user types "ShankarReddy", only "Shank" is read
🔹 Suppression in scanf()
Use * to skip (suppress) reading a value from input.
```
📍 Examples:

```
int a;
scanf("%*d %d", &a);  // Skips the first number and stores the second

// Input: 10 20
// Output stored: a = 20
```
```
char ch;
scanf("%*c %c", &ch); // Skips one character and reads the next

// Input: AB
// Output stored: ch = 'B'

```
🧠 Summary Table
Format	        Used In	Meaning
%5d	printf	    Print int in width of 5 (right-aligned)
%8.2f	        printf	Float with width 8 and 2 decimal places
%.3s	        printf	Print first 3 characters of string
%5s	scanf	    Read max 5 characters from input
%*d	scanf	    Suppress first int input (skip storing)
```
🧪 Test Programs
###  test programs
// printf field width & precision
#include <stdio.h>
int main() {
    printf("Number with width 5: [%5d]\n", 42);
    printf("Float with 2 decimals: [%.2f]\n", 3.14159);
    printf("Float with width and precision: [%8.2f]\n", 3.14);
    printf("String precision: [%.3s]\n", "HelloWorld");
    return 0;
}
c
Copy
Edit
// scanf suppression
#include <stdio.h>
int main() {
    int a;
    printf("Enter two numbers: ");
    scanf("%*d %d", &a);
    printf("Second number is: %d\n", a);
    return 0;
}

```

###🔧 C Compilation Process — Step by Step
```
Source Code (file.c)
       ↓
🔹 Pre-processing Stage
       ↓
Preprocessed Code (file.i)
       ↓
🔹 Compilation Stage
       ↓
Assembly Code (file.s)
       ↓
🔹 Assembly Stage
       ↓
Object Code (file.o)
       ↓
🔹 Linking Stage
       ↓
Executable File (a.out or custom name)
```
📘 Explanation of Each Stage:
🔹 1. Source Code (file.c)
The raw C program written by the user.

Example:

```
#include <stdio.h>
#define PI 3.14

int main() {
    float area;
    area = PI * 2 * 2;
    printf("Area = %f\n", area);
    return 0;
}
```
🔹 2. Pre-processing Stage
Removes comments.

Expands macros (#define, #include).

Conditional compilation with #ifdef, #ifndef.

Tool: C Preprocessor (cpp)
Output: file.i
```
gcc -E file.c -o file.i
```
🔹 3. Compilation Stage
Converts preprocessed code into Assembly Code.

Syntax and semantic checking.

Basic optimizations.

Tool: Compiler (gcc)
Output: file.s
```
gcc -S file.i -o file.s
```
🔹 4. Assembly Stage
Translates .s (assembly) to .o (object code).

Machine-level instructions generated.

Tool: Assembler (as)
Output: file.o
```
gcc -c file.s -o file.o
```
🔹 5. Linking Stage
Combines one or more .o files and libraries.

Resolves function calls (printf, etc.).

Produces final executable.

Tool: Linker (ld via gcc)
Output: a.out (default) or ./your_program
```
gcc file.o -o output
```
✅ Final Output: Executable File
This is the final runnable program:
```
./output
```
# ✅  Static Variable in C
A static variable retains its value between function calls.

Scope is local to the function, but it is not destroyed when the function exits.

Example:


```
#include <stdio.h>

void demo() {
    static int x = 0;
    x++;
    printf("%d\n", x);
}

int main() {
    demo(); // 1
    demo(); // 2
    demo(); // 3
    return 0;
}
```
->>Without static, x would always be 1 in each call.


# ✅ 2. Break and Continue
🔹 break:
Exits the loop or switch immediately.

🔹 continue:
Skips the current iteration and jumps to the next.

Example:
```
#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue;  // skip when i == 3
        if (i == 5) break;     // stop loop when i == 5
        printf("%d\n", i);
    }
    return 0;
}
```

# ✅ 3. Enum (Enumeration) in C
Used to assign names to integer constants for better readability.

Example:

```
#include <stdio.h>

enum week { MON=1, TUE, WED, THU, FRI, SAT, SUN };

int main() {
    enum week today = WED;
    printf("Day number: %d", today); // Output: 3
    return 0;
}

```

If you don't assign numbers, it starts from 0 by default.


# ✅ 4. Call by Value vs Call by Reference
🔹 Call by Value:
A copy of the variable is passed.

Changes inside the function don’t affect the original variable.

```
void modify(int x) {
    x = x + 10;
}
```
🔹 Call by Reference:
Address of the variable is passed (using pointers).

Changes inside the function affect the original variable.
```
void modify(int *x) {
    *x = *x + 10;
}

```


```
#include <stdio.h>

void byValue(int x) {
    x = 10;
}

void byReference(int *x) {
    *x = 10;
}

int main() {
    int a = 5, b = 5;

    byValue(a);        // a is still 5
    byReference(&b);   // b becomes 10

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}

```
# 📘 Dynamic Memory Allocation (DMA) in C

In C, Dynamic Memory Allocation (DMA) allows you to allocate memory at runtime, instead of fixing the size at compile time.
The standard library <stdlib.h> provides four main functions:

malloc()

calloc()

realloc()

free()

🔹 1. malloc()
```
Syntax:
ptr = (type *)malloc(size_in_bytes);
```
Allocates a block of memory of given size (in bytes).

The content is uninitialized (contains garbage values).

Returns a pointer to the first byte of allocated memory.

Returns NULL if allocation fails.
```
int *arr;
arr = (int *)malloc(3 * sizeof(int));

arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
```

🔹 2. calloc()
```
Syntax:

ptr = (type *)calloc(num_elements, size_of_each);
```

Allocates memory for an array of elements.

Initializes all elements to zero.

Returns NULL if allocation fails.

Example:
```
int *arr;
arr = (int *)calloc(3, sizeof(int));

// All values are automatically 0
```
🔹 3. realloc()
```
Syntax:

ptr = (type *)realloc(ptr, new_size_in_bytes);
```

Resizes previously allocated memory.

Keeps old data intact and adds extra space if needed.

Returns NULL if reallocation fails (old memory remains valid).

Example:
```
arr = (int *)realloc(arr, 5 * sizeof(int));
arr[3] = 40;
arr[4] = 50;
```
🔹 4. free()

Syntax:
```
free(ptr);

```
Releases allocated memory back to the system.

Must be called when memory is no longer needed.

After free(), the pointer becomes invalid (dangling).

Example:
```
free(arr);
```
## Storage Classes in C


Storage classes in C define the scope (visibility), lifetime, and storage location of variables and functions.
They tell the compiler:

Where the variable is stored (memory/RAM or CPU register)

How long the variable exists (lifetime)

Where it can be accessed (scope)

Default initial value

### 1. auto

Default storage class for local variables inside functions.

Scope: Local to the block/function.

Lifetime: Created when function is called, destroyed when function ends.

Default value: Garbage (undefined).

Example:
```
void func() {
    auto int x = 5; // same as just 'int x = 5;
}
```
### 2. register

Requests the compiler to store the variable in a CPU register (for faster access).

Scope: Local to the block/function.

Lifetime: Function call duration.

Default value: Garbage.

Cannot use & (address-of) operator with it (since it may not be in RAM).

Example:
```
void func() {
    register int i;
    for (i = 0; i < 10; i++) {
        // fast access counter
    }
}
```
### 3. static

Preserves the value of a variable between multiple function calls.

Scope: Local to the block/function (if declared inside function), OR global (if outside).

Lifetime: Entire program execution.

Default value: Zero.

Example:
```
void func() {
    static int count = 0; 
    count++;
    printf("%d\n", count);
}
// Each call remembers the old value
```
### 4. extern

Used to declare a global variable or function that is defined in another file.

Scope: Global (visible to all files).

Lifetime: Entire program execution.

Default value: Zero.

Example:
```
// file1.c
int num = 10;

// file2.c
extern int num;
printf("%d", num); // uses variable from file1
```



### 🔹 What is a Function Pointer?

A function pointer is a pointer that stores the address of a function.
Just like you can have a pointer to an int or char, you can also have a pointer to a function.

--->A function pointer is a variable that stores the memory address of a function, allowing it to be called indirectly or passed as an argument to another function.

🔹 Syntax:
```
return_type (*pointer_name)(parameter_types);


Example:

int (*func_ptr)(int, int);

```
👉 This means func_ptr is a pointer to a function that takes two int arguments and returns an int.

🔹 Example 1: Simple function pointer
```
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare function pointer
    int (*func_ptr)(int, int);

    // Assign address of function
    func_ptr = add;

    // Call function using pointer
    int result = func_ptr(10, 20);

    printf("Result = %d\n", result);
    return 0;
}
```

✅ Output:
```
Result = 30
```
### 2. Static Function

- A function declared with static keyword.

- Its scope is limited to the file where it is defined.

- It cannot be called from other .c files (used in modular programming).

Example:
```
#include <stdio.h>

static void showMessage() {  // static function
    printf("Hello from static function!\n");
}

int main() {
    showMessage();  // Works here
    return 0;
}
```

👉 But if another .c file tries to call showMessage(), it will give an error because it is private to its file.

✅ Summary:

- static variable → keeps its value even after function exits.

- static function → accessible only within the same file (file scope).

## 🔹 What is a Function in C?

A function is a block of code that performs a specific task.
Functions make programs modular, readable, and reusable.

There are two main types of functions in C:

Library Functions

User-defined Functions

### 🧩 1. Library Functions

These are predefined functions provided by C libraries (like <stdio.h>, <math.h>, etc.).

#### ✳️ Examples:

| Function   | Header File  | Purpose            |
| ---------- | ------------ | ------------------ |
| `printf()` | `<stdio.h>`  | Print output       |
| `scanf()`  | `<stdio.h>`  | Take input         |
| `sqrt()`   | `<math.h>`   | Find square root   |
| `strlen()` | `<string.h>` | Find string length |
| `pow()`    | `<math.h>`   | Power calculation  |

### 🧠 2. User-defined Functions

These are functions that you write yourself to perform specific tasks.

A function has four parts:

return_type function_name(parameter list) {
    // function body
}

🔹 Based on Arguments and Return Type:

There are 4 types of user-defined functions:

Type	Arguments	Return Value	Example

1️⃣ Function with no arguments & no return value	❌	❌	void greet();

2️⃣ Function with arguments but no return value	✅	❌	void sum(int a, int b);

3️⃣ Function with no arguments but returns value	❌	✅	int getNumber();

4️⃣ Function with arguments and returns value	✅	✅	int add(int a, int b);

🧾 Example of Each:

1️⃣ No Arguments, No Return
```
#include <stdio.h>
void greet() {
    printf("Hello, Welcome!\n");
}

int main() {
    greet();
    return 0;
}
```
2️⃣ Arguments, No Return
```
void sum(int a, int b) {
    printf("Sum = %d\n", a + b);
}
``
3️⃣ No Arguments, With Return
```
int getNumber() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    return x;
}
```

4️⃣ Arguments, With Return
```
int add(int a, int b) {
    return a + b;
}
```
```

### 🎲 rand() Function in C
#### 📌 What is rand()?

- rand() is a standard C library function used to generate pseudo-random numbers.

📂 Header file:
```
#include <stdlib.h>
```
🔹 Syntax
```
int rand(void);
```
🔹 Return Value

- Returns a pseudo-random integer

Range:
```
0  to  RAND_MAX
```

- (RAND_MAX is usually 32767)

#### 🔹 Why is it called pseudo-random?

Numbers are not truly random

Generated using a mathematical algorithm

Same sequence repeats unless we change the seed

#### 🔑 srand() – Seed Function

To get different random values every time, use:
```
srand(seed);

```
Common seed:
```
srand(time(NULL));
```

📂 Required header:
```
#include <time.h>
```
✅ Basic Example
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", rand());
    return 0;
}

```
🔹 Output (same every run):
```
1804289383
```
#### ✅ Example with srand()
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));   // seed
    printf("%d\n", rand());
    return 0;
}
```

**🔹 Output (different every run):**
```
24567
```
🔢 Generate Random Numbers in a Range
🎯 0 to 9
```
rand() % 10;
```
🎯 1 to 10
```
(rand() % 10) + 1;
```
🎯 10 to 50
```
(rand() % 41) + 10;
```
🧵 rand() in Threads (Important!)

rand() is NOT thread-safe

Use mutex or rand_r() in multithreading

Example with Mutex
```
pthread_mutex_lock(&lock);
int r = rand();
pthread_mutex_unlock(&lock);
```
### 🧠 Important Points (Exam Focus)

- rand() → generates pseudo-random numbers

- srand() → sets seed

- Call srand() once per program

- % operator limits range

- Not suitable for cryptography
