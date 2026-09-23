# 67Lang
67lang is an interpreted esoteric language, with its interpreter written in pure C.

# Why?
bro is a 67 aura language

# Compiling
simple
```
make
```
on the project folder

# Usage
```
./67lang <target .67 file here>
```
# Examples
## the addition (5 + 3)
```
./67lang examples/addition.67
```
## the subtraction (5 - 2)
```
./67lang examples/subtraction.67
```
## the multiplication (3 * 3)
```
./67lang examples/multiplication.67
```
## the division (10 / 2)
```
./67lang examples/division.67
```
## Hello World
```
./67lang examples/helloworld.67
```
This should print "Hello World".

## Debug Mode
By default, debug mode is enabled to observe the language's behavior. It can be disabled to see the pure output by changing the "debug_mode" variable to 0 and compiling again.

# How the language works?
## It's inspired by Brainfuck, but with several design differences. The language is based on 10 registers; registers 6 and 7 navigate between them, and a space toggles between incrementing and decrementing the value from the current register, Two spaces is the loop syntax; if the current register has a value greater than one, it enters the loop and will remain there until the value of that register is less than one. And the last thing to say These are the standard functions, which are activated by manipulating register nine; for now, there is only the print function. Each register before nine represents a character from the ASCII table according to its The respective value, and by changing the value of register nine to one, the program will print the character sequence and then return the value to zero.
