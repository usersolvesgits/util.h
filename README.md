# util.h - C++ Utility Header
A lightweight, header‑only collection of helpful utilities for C++ projects.

## 📚 Table of Contents
- [Features](#-features)
- [Printing Utilities](#️-printing-utilities)
- [Input Utilities](#-input-utilities)
- [Math Utilities](#-math-utilities)
- [String Utilities](#-string-utilities)
- [Random Utilities](#-random-utilities)
- [How to Download](#-how-to-download)
- [Usage Example](#-usage-example)


## 📌 Features
## 🖨️ Printing Utilities

- `print()` – prints without newline  
- `println()` – prints with newline  
- `fprint()` – formatted multi-argument print  
- `fprintln()` – formatted multi-argument print with newline  
- `printContainer(container)` – prints container elements line-by-line  
- `printContainer(container, true)` – prints container inline  

---

## ⌨️ Input Utilities

- `Scan(variable)` – reads formatted input  
- `Scan(message, variable)` – prints message then reads input  
- `Scanln(string)` – reads full line  
- `Scanln(message, string)` – prints message then reads full line  

---

## 🧮 Math Utilities

### 🔢 Constants
- `PI`
- `TAU`
- `E`
- `PHI`
- `SQRT2`
- `LN2`
- `LN10`

### ➕ Basic Operations
- `sum(a, b)` - returns the sum of two numbers
- `subtract(a, b)` - returns the difference between two numbers
- `multiply(a, b)` - returns the product of two numbers
- `divide(a, b)` - returns the result of dividing one number by another
- `power(base, exponent)` - raises a base number to a given exponent
- `squareRoot(value)` - returns the square root of a number
- `n_Root(root, number)` - computes the n-th root of a number using iterative approximation
- `absoluteValue(value)` - returns the absolute (non-negative) value of a number

### 📐 Trigonometry
- `sine(value)` - returns the sine of a value (in radians)
- `cosine(value)` - returns the cosine of a value (in radians)
- `tangent(value)` - returns the tangent of a value (in radians)
- `FromDegreesToRadians(deg)` - converts degrees to radians
- `FromRadiansToDegrees(rad)` - converts radians to degrees

### 📊 Logarithms
- `Logarithm(base, value)` - computes the logarithm of a value with a custom base

### ✅ Number Checks
- `IsEven(number)` - checks if a number is even (rounded to the nearest integer)
- `IsPalindrome(int)` - checks if an integer reads the same forward and backward

### 📏🌡️ Unit Conversions

**Length**
- `FromFeetToMeters()` - converts feet to meters
- `FromMetersToFeet()` - converts meters to feet

**Temperature**
- `FromCelsiusToF()` - converts Celsius to Fahrenheit
- `FromFahrenheitToC()` - converts Fahrenheit to Celsius
- `FromCelsiusToK()` - converts Celsius to Kelvin
- `FromKelvinToC()` - converts Kelvin to Celsius
- `FromFahrenheitToK()` - converts Fahrenheit to Kelvin
- `FromKelvinToF()` - converts Kelvin to Fahrenheit

---

## 🔤 String Utilities

Encapsulated inside the `String` class.

### 🔄 Conversion
- `ToString(value)` - converts a value to string
- `ToUpper(str)` - returns a converted string to uppercase
- `ToLower(str)` - returns a converted string to lowercase

### 🧵 Manipulation
- `Join(str1, str2, ...)` - concatenates two or more strings together
- `Clear(str)` - clears a string (makes it an empty string)
- `SearchFirstSubString(str, subStr)` - returns the starting index of the substring or -1 if not found.
- `SearchSubString(str, subStr)` - returns a pointer to an array containing the first and last index of a substring (both endpoints included)

### ✅ Checks
- `IsPalindrome(str)` - checks if a string is a palindrome
- `IsAnagram(str1, str2)` - checks if two strings could be considered anagrams of eachothers

### 📚 Static Members
- `String::Empty` - returns an empy string
- `String::Lorem` - prints out dummy text

---

## 🎲 Random Utilities

- `RandFloat(min, max)` - generates a random floating-point number within the specified range [min, max] (both endpoints included)
- `RandInt(min, max)` - generates a random integer within the specified range [min, max] (both endpoints included)
- `RandomBool()` - generates a random boolean value (true or false)
- `Random_Num()` - generates a random floating-point number in the range [0,1] (both endpoints included)
- `Throw_Dice()` - simulates a dice roll and returns a random integer in the range [1,6] (both endpoints included)

---

## 📥 How to Download
You can add utils.h to your project in any of these ways:

### 1. Download directly
- [Click Here](https://github.com/usersolvesgits/util.h/blob/main/code/util/util.h) to go to the page of the header file
- Click Download Raw File
- Save it as utils.h inside your project’s include/ or source folder

### 2. Clone the repository
```bash
git clone https://github.com/usersolvesgits/util.h.git
```

### 3. Copy & paste
Simply copy the contents of utils.h into your own header file.

## 🚀 Usage Example
To see how everything works in practice, check the main.cpp file included in the 'code' folder, or by [clicking here](https://github.com/usersolvesgits/util.h/blob/main/code/main.cpp).  
It contains simple, clear examples demonstrating each category of utilities.
### Preview
<details>
<summary>Click to expand</summary>

```cpp
// Printing utilities
println("Hello, world!");
fprintln("Sum of 3 + 7 = ", sum(3, 7));

// Container printing
std::vector<int> nums = {1, 2, 3, 4, 5};
printContainer(nums, true);

// Math utilities
println("PI = ", PI);
println("Square root of 49 = ", squareRoot(49));
println("Is 42 even? ", IsEven(42));
println("Log base 2 of 32 = ", Logarithm(2, 32));

// String utilities
println(String::ToUpper("hello"));
println("Is 'racecar' a palindrome? ", String::IsPalindrome("racecar"));
println("Are 'listen' and 'silent' anagrams? ", String::IsAnagram("listen", "silent"));

// Random utilities
println("Random float [0,1]: ", RandFloat());
println("Random int [1,10]: ", RandInt(1, 10));
println("Random bool: ", RandomBool());
```
Sample Output
```txt
Hello, world!
Sum of 3 + 7 = 10
1 2 3 4 5 
PI = 3.14159
Square root of 49 = 7
Is 42 even? 1
Log base 2 of 32 = 5
HELLO
Is 'racecar' a palindrome? 1
Are 'listen' and 'silent' anagrams? 1
Random float [0,1]: 0.48291
Random int [1,10]: 7
Random bool: 0
```
</details>
