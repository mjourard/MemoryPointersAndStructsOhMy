This repository is to show an example of compiling with the c99 standard while
using a function that is not included in c99 by default. 

In this case, we will be using strdup from the string.h library.

If you inspect the two files goodStrdup.c and badStrdup.c, you will notice that 
the only differences between the two is that goodStrdup has two PREPROCESSOR 
variables defined before any other libraries are included. 

These preprocessor variables tell the compiler at compile time to include strdup
in the string.h header file, as outlined in the man page for strdup.

If you look at the man page for strdup, you will see a section called 
"Feature Test Macro Requirements for glibc". This section defines the variables required to be defined for each function of the strdup family. The '||' depict
the 'OR' operation, meaning you can define any of the individual clauses to have
that function included.

For strdup, you'll notice the fourth clause is '_XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED'.
This means to include strdup, we had to define those two variables, such as has been done in goodStrdup.c

While both the compiled executables from goodStrdup.c and badStrdup.c will run with the same output and success rates,
it is still good practice to get rid of any compiler warnings, as well as good
to know why warnings such as these happen.

A programmer can never make the transition from good to great if they do not understand 
the tools they use, much like a jedi can not become a master without a great knowledge of the force
and adept skills with a light saber.

There are many other functions that have definition requirements in order to be included when being compiled with
a c standard. Now you know what to do and how to acquire the information you need 
in order to include them.

Good luck and may your code flow bug free.