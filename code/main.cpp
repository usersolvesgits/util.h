#include <vector>
#include "util/util.h"

using namespace util;

int main() {

    /// =========================
    /// PRINTING UTILITIES
    /// =========================

    print("Hello ");
    println("World!");

    fprint("My cat is ", 1, " year old!");
    fprintln("I'm ", 17, " years old!");

    int arr[] = {1,2,3,4,5};
    std::vector<double> vect = {1.5, 2.3, 3.6};

    printContainer(arr);
    printContainer(vect, true);

    /// =========================
    /// INPUT UTILITIES
    /// =========================

    int age;
    Scan("Enter your age: ", age);
    fprintln("You entered: ", age);

    double height;
    Scan("Enter your height (meters): ", height, true);
    fprintln("Height: ", height);

    std::string fullName;
    Scanln("Enter your full name: ", fullName, true);
    fprintln("Hello ", fullName);

    /// =========================
    /// MATH UTILITIES
    /// =========================

    // Constants
    println(PI);
    println(TAU);
    println(E);
    println(PHI);
    println(SQRT2);
    println(LN2);
    println(LN10);

    double x = 10.0;
    int y = 5;
    int z = -2;

    // Functions
    println(sum(x,y));
    println(subtract(x,y));
    println(multiply(x,y));
    println(divide(x,y));
    println(power(x,y));
    println(squareRoot(x));
    println(n_Root(3, 27));
    println(Logarithm(3, 244));

    // Trigonometry
    x = FromDegreesToRadians(x);
    println(sine(x));
    println(cosine(x));
    println(tangent(x));
    x = FromRadiansToDegrees(x);

    println(absoluteValue(z));

    if (IsEven(x)) {
        fprintln(x, " is even!");
    } else {
        fprintln(x, " is odd!");
    }

    if (IsPalindrome(y)) {
        fprintln(y, " is a palindrome!");
    } else {
        fprintln(y, " is NOT a palindrome!");
    }

    // Unit Conversions
    double feet = 10;
    double meters = FromFeetToMeters(feet);
    fprintln(feet, " feet in meters: ", meters);

    fprintln(meters, " meters in feet: ", FromMetersToFeet(meters));

    double celsius = 25;
    fprintln(celsius, " C in F: ", FromCelsiusToF(celsius));
    fprintln(celsius, " C in K: ", FromCelsiusToK(celsius));

    double fahrenheit = 77;
    fprintln(fahrenheit, " F in C: ", FromFahrenheitToC(fahrenheit));
    fprintln(fahrenheit, " F in K: ", FromFahrenheitToK(fahrenheit));

    double kelvin = 300;
    fprintln(kelvin, " K in C: ", FromKelvinToC(kelvin));
    fprintln(kelvin, " K in F: ", FromKelvinToF(kelvin));

    /// =========================
    /// STRING UTILITIES
    /// =========================

    std::string s1 = "hello world!";
    std::string s2 = "HELLO WORLD!";
    std::string emptyStr = String::Empty;
    std::string dummyText = String::Lorem;

    println(String::ToUpper(s1));
    println(String::ToLower(s2));

    // Join
    std::string joined = String::Join("Hello ", "C++ ", "World!");
    println(joined);

    // Clear
    String::Clear(joined);
    fprintln("After clear: '", joined, "'");

    // Search substring
    std::string text = "I love programming in C++";
    std::string sub = "programming";

    int index = String::SearchFirstSubString(text, sub);
    fprintln("First occurrence at index: ", index);

    int arraySize;
    int* indexes = String::SearchSubString(text, sub, arraySize);

    fprintln("Substring start: ", indexes[0], " end: ", indexes[1]);

    // Palindrome (string)
    std::string palindromeStr = "hellolleh";
    if (String::IsPalindrome(palindromeStr)) {
        fprintln(palindromeStr, " is a palindrome");
    }

    // Anagram
    std::string a1 = "anagram";
    std::string a2 = "nagaram";

    if (String::IsAnagram(a1, a2)) {
        println("They are anagrams!");
    }

    if (String::IsAnagram(a1, a2, false)) {
        println("They are case-insensitive anagrams!");
    }

    /// =========================
    /// RANDOM UTILITIES
    /// =========================

    println(Random_Num());
    println(Throw_Dice());

    int randomInt = RandInt(0,100);
    double randomFloat = RandFloat(0,100);

    println(randomInt);
    println(randomFloat);

    if (RandomBool()) {
        println("I got lucky!");
    } else {
        println("I didn't get lucky!");
    }

    return 0;
}