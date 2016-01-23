# MemoryPointersAndStructsOhMy
A repository of samples of C that show how to use basic functions and how to do simple tasks for when you're learning C.

This repository is to be used as a supplement to my tutoring services. Feel free to use the code as you wish, but please reference this repository in the files.

As needed, I'll add styling rules that, if followed, should net you close to 100% on style.

1. All variables and functions should have meaningful names. If you can't think of a name based on the variable's purpose, you probably don't need the variable.

2. All functions should have a singular purpose. If you're finding you're making a function with the word 'And' or 'Or' in the name, the function likely needs to be refactored into smaller functions.

3. Follow the Don't Repeat Yourself rule. If you find yourself copying and pasting code, you likely can put it into a function.

4. All significant, hardcoded numbers should be replaced with Enums. Enum stand for Enumeration and is a fancy way for saying giving a name to a number. Example: http://www.cs.utah.edu/~germain/PPS/Topics/C_Language/enumerated_types.html

5. If your file has a 'main' method definition, it should be the very first function definition to come before any other function definitions. This is done through function prototypes. All following function definitions should be ordered alphabetically. Find/write a script you can run on your code to automatically order them for you.

6. All variables should be defined at the top of functions before any logic takes place, in alphabetical order. This is to make it easy to find variable definitions/types, as well as declutter your function logic. Again, a script can do the ordering for you.

7. All variables should have an inline comment on the line above it explaining its purpose. This makes maintaining your code much easier and is a good habit to get into.

8. All function prototypes should have a block comment above it describing the purpose of the function, the purpose of each passed in argument and the return value(s) expected. An example:
/**
 * Calculates the body mass index based on the passed in height and weight.
 * 
 * @height The height of the person.
 * @weight The weight of the person.
 * @returns The BMI of the person.
 */
 int calculateBMI(int height, int weight);

 9. Don't reinvent the wheel. So much of programming is putting pieces of a puzzle together, because the pieces have already been made. If it's a simple task, there is probably a standard function to do it, even in C. If you're trying to do anything with strings, always check the string.h library first. Some useful standard libraries and their purposes:
 string manipulation: string.h
 math equations: math.h
 A boolean type: bool.h
 
