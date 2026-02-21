#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <random>

/// @author usersolvesgits
/// @date 2026/2/21 (yyyy/MM/dd)
/// @version 1.0.1

/// @brief
/// <SUMMARY>
/// This header file provides a collection of helpful utility functions and constants
/// for common tasks in C++ programs.
/// It includes:
///
/// - Printing utilities
/// - Input utilities
/// - Common mathematical constants
/// - Basic math operations
/// - Strings utilities
/// - Random utilities
/// <END SUMMARY>

namespace util {
    /// @category PRINTING

    /// @brief Prints a value to standard output without creating a newline
    inline void print() { std::cout << ""; }
    /// @brief Prints a value to standard output without creating a newline
    template<typename ...Args>
    void print(const Args&... args) { (std::cout << ... << args); std::cout << " "; }

    /// @brief Prints a value to standard output creating a newline
    inline void println() { std::cout << '\n'; }
    /// @brief Prints a value to standard output creating a newline
    template<typename ...Args>
    void println(const Args&... args) { (std::cout << ... << args); std::cout << '\n'; }

    /// @brief Prints two or more values consecutively followed by a space.
    template<typename ...Args>
    void fprint(const Args&... args) {
        (std::cout << ... << args);
        std::cout << " ";
    }

    /// @brief Prints two or morevalues consecutively followed by a newline.
    template<typename ...Args>
    void fprintln(const Args&... args) {
        (std::cout << ... << args);
        std::cout << '\n';
    }

    /// @brief Prints all elements of a container, each on a new line.
    /// @tparam T Iterable container type.
    template<typename T>
    void printContainer(const T& container) {
        for (const auto& element : container) {
            std::cout << element << '\n';
        }
    }
    /// @brief Prints all elements of a container either inline or multiline.
    /// @tparam T Iterable container type.
    /// @param If inLine is set to true, prints elements in one line separated by spaces.
    template<typename T>
    void printContainer(const T& container, bool inLine) {
        if (inLine) {
            for (const auto& element : container) {
                std::cout << element << " ";
            }
            std::cout << '\n';
        } else {
            for (const auto& element : container) {
                std::cout << element << '\n';
            }
        }
    }

    /// @category INPUT

    /// @brief Reads formatted input into a variable.
    /// @param val Variable to store input.
    template<typename T>
    void Scan(T& val) {
        std::cin >> std::ws >> val;
    }
    /// @brief Prints a message then reads formatted input.
    /// @param message Prompt message.
    /// @param val Variable to store input.
    /// @param newLine If true, prints the message on a new line.
    template<typename X, typename Y>
    void Scan(const X& message, Y& val, bool newLine = false) {
        if (newLine) {
       	println(message);
       	Scan(val);
        } else {
       	print(message);
       	Scan(val);
        }
    }
    /// @brief Reads an entire line of input.
    /// @param val Variable to store the full line.
    inline void Scanln(std::string& val) {
        std::getline(std::cin >> std::ws, val);
    }
    /// @brief Prints a message then reads a full line.
    /// @param message Prompt message.
    /// @param val Variable to store the full line.
    /// @param newLine If true, prints the message on a new line.
    template<typename X, typename Y>
    void Scanln(const X& message, Y& val, bool newLine = false) {
        if (newLine) {
            println(message);
            Scanln(val);
        } else {
            print(message);
            Scanln(val);
        }
    }

    /// @category MATH

    // Constants
    constexpr double PI    =   3.141592654;
    constexpr double TAU   =   6.283185307;
    constexpr double E     =   2.718281828;
    constexpr double PHI   =   1.618033989;
    constexpr double SQRT2 =   1.414213562;
    constexpr double LN2   =   0.6931471806;
    constexpr double LN10  =   2.302585093;

    // Operations

    inline double sum(const double a, const double b) { return a + b; }
    inline double subtract(const double a, const double b) { return a - b; }
    inline double multiply(const double a, const double b) { return a * b; }
    inline double divide(const double numerator, const double denominator) {
        return numerator / denominator;
    }
    inline double power(const double base, const double exponent) { return pow(base, exponent); }
    inline double squareRoot(const double value) { return std::sqrt(value); }
    /// @brief Computes the n-th root of a number.
    /// @param root The degree of the root (ex., 2 for square root).
    /// @param num The number to extract the root from.
    /// @return Approximate n-th root of the number.
    inline double n_Root(const double root, const double num) {
        double x = num / 2.0;
        double eps = 1e-6;

        while (true) {
            double fx = power(x, root) - num;
            double fpx = root * power(x, root - 1);
            double dx = fx / fpx; x -= dx;
            if (fabs(dx) < eps) {
                break;
            }
        }
        return x;
    }

    /// @brief Converts degrees to radians.
    inline double FromDegreesToRadians(const double degrees) { return degrees * (PI / 180); }
    /// @brief Converts radians to degrees.
    inline double FromRadiansToDegrees(const double radians) { return radians * (180 / PI); }
    inline double sine(const double value) { return sin(value); }
    inline double cosine(const double value) { return cos(value); }
    inline double tangent(const double value) { return tan(value); }

    inline double absoluteValue(const double value) { return fabs(value); }
    /// @brief Checks if a number is even (rounded the the first interger).
    inline bool IsEven(const double value) {
        return (int)round(value) % 2 == 0;
    }
    /// @brief Checks if an integer is a palindrome.
    inline bool IsPalindrome(const int num) {
        std::string num_s = std::to_string(num);
        size_t L = 0,
               R = num_s.size() - 1;
        while (R > L) {
            if (num_s[R] != num_s[L])
                return false;
            R--;
            L++;
        }
        return true;
    }

    /// @brief Computes logarithm with custom base.
    /// @param base Logarithmic base.
    /// @param val Value to compute.
    inline double Logarithm(const double base, const double val) {
        return std::log(val) / std::log(base);
    }
    /// @brief Converts feet to meters.
    /// @param Fval Value in feet.
    /// @return Value converted to meters.
    inline double FromFeetToMeters(const double Fval) {
        return Fval * 0.3048;
    }
    /// @brief Converts meters to feet.
    /// @param Mval Value in meters.
    /// @return Value converted to feet.
    inline double FromMetersToFeet(const double Mval) {
        return Mval * 3.280839895;
    }
    /// @brief Converts Celsius to Fahrenheit.
    /// @param Cval Temperature in Celsius.
    /// @return Temperature converted to Fahrenheit.
    inline double FromCelsiusToF(const double Cval) {
        return (double)9 / 5 * Cval + 32;
    }
    /// @brief Converts Fahrenheit to Celsius.
    /// @param Fval Temperature in Fahrenheit.
    /// @return Temperature converted to Celsius.
    inline double FromFahrenheitToC(const double Fval) {
        return (double)5 / 9 * (Fval - 32);
    }
    /// @brief Converts Celsius to Kelvin.
    /// @param Cval Temperature in Celsius.
    /// @return Temperature converted to Kelvin.
    inline double FromCelsiusToK(const double Cval) {
        return Cval + 273.15;
    }
    /// @brief Converts Kelvin to Celsius.
    /// @param Kval Temperature in Kelvin.
    /// @return Temperature converted to Celsius.
    inline double FromKelvinToC(const double Kval) {
        return Kval - 273.15;
    }
    /// @brief Converts Fahrenheit to Kelvin.
    /// @param Fval Temperature in Fahrenheit.
    /// @return Temperature converted to Kelvin.
    inline double FromFahrenheitToK(const double Fval) {
        return (double)5 / 9 * (Fval + 459.67);
    }
    /// @brief Converts Kelvin to Fahrenheit.
    /// @param Kval Temperature in Kelvin.
    /// @return Temperature converted to Fahrenheit.
    inline double FromKelvinToF(const double Kval) {
        return (double)9 / 5 * Kval - 459.67;
    }

    /// @category Strings

    /// @class String
    /// @brief Provides utility functions for string manipulation.
    class String {
        public:
        inline static const std::string Empty = "";
        inline static const std::string Lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer non metus purus. Etiam lacus diam, feugiat sed neque sit amet, faucibus egestas enim. Nulla vestibulum pellentesque ipsum, sit amet facilisis diam volutpat at. Nulla et molestie eros. Nullam a aliquet sapien.";
        template<typename T>
        /// @brief Converts a value to string.
        static std::string ToString(const T& val) { return std::to_string(val); }
        /// @brief Converts a value to string.
        static std::string ToString(const std::string& val) { return val; }
        /// @brief Converts string to uppercase.
        /// @param str Input string.
        /// @return Uppercase string.
        inline static std::string ToUpper(const std::string& str) {
            std::string result = str;
            std::transform(str.begin(), str.end(), result.begin(), ::toupper);
            return result;
        }
        /// @brief Converts string to lowercase.
        /// @param str Input string.
        /// @return Lowercase string.
        inline static std::string ToLower(const std::string& str) {
            std::string result = str;
            std::transform(str.begin(), str.end(), result.begin(), ::tolower);
            return result;
        }
        /// @brief concatenates 2 or more strings
        inline static std::string Join(const std::string& str1, const std::string& str2) {
            return str1 + str2;
        }
        /// @brief concatenates 2 or more strings
        inline static std::string Join(const std::string& str1, const std::string& str2, const std::string& str3) {
            return str1 + str2 + str3;
        }
        /// @brief concatenates 2 or more strings
        inline static std::string Join(const std::string& str1, const std::string& str2,
                                    const std::string& str3, const std::string& str4) {
            return str1 + str2 + str3 + str4;
        }
        /// @brief clears the string
        inline static void Clear(std::string& str) {
            str = String::Empty;
        }
        /// @brief clears the strings
        inline static void Clear(std::string& str, std::string& str2) {
            str = String::Empty;
            str2 = String::Empty;
        }
        /// @brief clears the strings
        inline static void Clear(std::string& str, std::string& str2, std::string& str3) {
            str = String::Empty;
            str2 = String::Empty;
            str3 = String::Empty;
        }
        /// @brief Searches for first occurrence of a substring.
        /// @param str Main string.
        /// @param subString Substring to find.
        /// @return Starting index or -1 if not found.
        inline static int SearchFirstSubString(const std::string& str, const std::string& subString) {
            const size_t n = str.size();
            const size_t m = subString.size();
            if (m == 0 || m > n) {
                return -1;
            }
            for (int i = 0; i <= n - m; i++) {
                int j = 0;
                while (j < m && str[i + j] == subString[j]) {
                    j++;
                }
                if (j == m) {
                    return i;
                }
            }
            return -1;
        }
        /// @brief Searches for first occurrence of a substring.
        /// @param str Main string.
        /// @param subString Substring to find.
        /// @param caseSensitive Executes a case-sensitive search.
        /// @return Starting index or -1 if not found.
        inline static int SearchFirstSubString(const std::string& str, const std::string& subString, bool caseSensitive) {
            const size_t n = str.size();
            const size_t m = subString.size();
            if (!caseSensitive) {
                std::string newStr = String::ToLower(str);
                std::string newSubStr = String::ToLower(subString);
                if (m == 0 || m > n) {
                    return -1;
                }
                for (int i = 0; i <= n - m; i++) {
                    int j = 0;
                    while (j < m && newStr[i + j] == newSubStr[j]) {
                        j++;
                    }
                    if (j == m) {
                        return i;
                    }
                }
                return -1;
            } else {
           	if (m == 0 || m > n) {
                return -1;
            }
            for (int i = 0; i <= n - m; i++) {
                int j = 0;
                while (j < m && str[i + j] == subString[j]) {
                    j++;
                }
                if (j == m) {
                    return i;
                }
            }
            return -1;
            }
        }
        /// @brief Finds substring and returns start & end indices.
        /// @param str Main string.
        /// @param subString Substring to search.
        /// @param arraySize Will always be set to 2.
        /// @return Pointer to array {startIndex, endIndex}. Returns {-1,-1} if not found.
        inline static int* SearchSubString(const std::string& str, const std::string& subString, int& arraySize) {
           	static int indexes[2] = { -1, -1 };
            arraySize = 2;
           	const size_t n = str.size();
    	    const size_t m = subString.size();
    		if (m == 0 || m > n) {
                return indexes;
            }
            for (int i = 0; i <= n - m; i++) {
                int j = 0;
                while (j < m && str[i + j] == subString[j]) {
                    j++;
                }
                if (j == m) {
              		indexes[0] = i;
              		indexes[1] = i + m - 1;
              		return indexes;
                }
            }
            return indexes;
        }
        /// @brief Finds substring and returns start & end indices.
        /// @param str Main string.
        /// @param subString Substring to search.
        /// @param arraySize Will always be set to 2.
        /// @param caseSensitive Executes a case-sensitive search.
        /// @return Pointer to array {startIndex, endIndex}. Returns {-1,-1} if not found.
        inline static int* SearchSubString(const std::string& str, const std::string& subString, int& arraySize, bool caseSensitive) {
    	    static int indexes[2] = { -1, -1 };
    		arraySize = 2;
    	   	const size_t n = str.size();
    	    const size_t m = subString.size();
    	    if (!caseSensitive) {
    			std::string newStr = String::ToLower(str);
    			std::string newSubStr = String::ToLower(subString);
    			if (m == 0 || m > n) {
                    return indexes;
                }
                for (int i = 0; i <= n - m; i++) {
                    int j = 0;
                    while (j < m && newStr[i + j] == newSubStr[j]) {
                        j++;
                    }
                    if (j == m) {
                  		indexes[0] = i;
                  		indexes[1] = i + m - 1;
                  		return indexes;
                    }
                }
                return indexes;
    		} else {
                if (m == 0 || m > n) {
                    return indexes;
                }
                for (int i = 0; i <= n - m; i++) {
                    int j = 0;
                    while (j < m && str[i + j] == subString[j]) {
                        j++;
                    }
                    if (j == m) {
                  		indexes[0] = i;
                  		indexes[1] = i + m - 1;
                  		return indexes;
                    }
                }
                return indexes;
    		}
        }
        inline static bool IsPalindrome(const std::string& str) {
            size_t L = 0,
                   R = str.size() - 1;
            while (R > L) {
                if (str[R] != str[L])
                    return false;
                R--;
                L++;
            }
            return true;
        }
        /// @brief Checks if two strings are anagrams.
        inline static bool IsAnagram(const std::string& str1, const std::string& str2) {
            std::string s1 = str1;
            std::string s2 = str2;
            std::sort(s1.begin(), s1.end());
            std::sort(s2.begin(), s2.end());
            if (s1 == s2) {
                return true;
            }
            return false;
        }
        /// @brief Checks if two strings are anagrams.
        /// @param caseSensitive Executes a case-sensitive search.
        inline static bool IsAnagram(const std::string& str1, const std::string& str2, bool caseSensitive) {
            std::string s1 = str1;
            std::string s2 = str2;
            std::sort(s1.begin(), s1.end());
            std::sort(s2.begin(), s2.end());
            if (caseSensitive) {
                if (s1 == s2) {
                    return true;
                }
                return false;
            } else {
                s1 = String::ToUpper(s1);
                s2 = String::ToUpper(s2);
                if (s1 == s2) {
                    return true;
                }
                return false;
            }
        }
    };

    /// @category RANDOM

    inline std::mt19937& rng() {
        static std::mt19937 engine(std::random_device{}());
        return engine;
    }

    /// @brief Generates a random floating-point number.
    /// @param minLimit Minimum value (default 0).
    /// @param maxLimit Maximum value (default 1).
    /// @return Random double in range [minLimit, maxLimit].
    inline double RandFloat(const double minLimit = 0.0, const double maxLimit = 1.0) {
        std::uniform_real_distribution<double> dist(minLimit, maxLimit);
        return dist(rng());
    }
    /// @brief Generates a random integer.
    /// @param minLimit Minimum value.
    /// @param maxLimit Maximum value.
    /// @return Random integer in range [minLimit, maxLimit].
    inline int RandInt(const int minLimit = 0, const int maxLimit = 100) {
        std::uniform_int_distribution<int> dist(minLimit, maxLimit);
        return dist(rng());
    }
    /// @brief Generates a random boolean value.
    inline bool RandomBool() {
        return RandInt(0, 1);
    }

    /// @brief Generates a random floating-point number.
    /// @return Random double in range [0.0, 1.0].
    inline double Random_Num() { return RandFloat(); }
    /// @brief Generates a random interger.
    /// @return Random int in range [1, 6].
    inline int Throw_Dice() { return RandInt(1, 6); }
}

#endif