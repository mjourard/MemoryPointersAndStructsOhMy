# Matthew Jourard github.com/mjourard

CCOMPILER          =	gcc
# Flags that are sent to the compiler
COMPILERFLAGS      =	-Wall -std=c99 -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -I/usr/local/include
LIBDIRS     = -L/usr/local/lib
LIBRARIES   = 

#C source code 
COMMANDLINE = UsingCommandLineArguments.c

#the object files to be created
COMMANDLINEOBJS  = UsingCommandLineArguments.c

EXECUTABLE = CLA

default : CLAlink

CLAcompile:
	$(CC) $(CFLAGS) -c  $(COMMANDLINE)

CLAlink: CLAcompile
	$(CC) $(LDFLAGS) -o $(EXECUTABLE) $(COMMANDLINEOBJS) 

clean:
	@ rm -f *.o
	@ rm -f $(EXECUTABLE)



