# 0x19. C - Stacks, Queues - LIFO, FIFO

## Resources:books:
Read or watch:
* [Google](https://intranet.hbtn.io/rltoken/56-bDz7IrFgcH02EkGkB3w)
* [How do I use extern to share variables between source files in C?](https://intranet.hbtn.io/rltoken/9neX6gaN6DoA-ow1INgZqw)

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

## The monty program

### Usage: monty file
* where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
* If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE where <file> is the name of the file
* If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE where is the line number where the instruction appears.
* Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
    * it executed properly every line of the file
    * it finds an error in the file
    * an error occured
* If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
* You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

---
## Learning Objectives:bulb:
What you should learn from this project:

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

---

### [0. push, pall]
* Implement the push and pall opcodes.
* The opcode push pushes an element to the stack.
* The opcode pall prints all the values on the stack, starting from the top of the stack.


### [1. pint]
* Implement the pint opcode.
* The opcode pint prints the value at the top of the stack, followed by a new line.

### [2. pop]
* Implement the pop opcode.
* The opcode pop removes the top element of the stack.


### [3. swap]
* Implement the swap opcode.
* The opcode swap swaps the top two elements of the stack.


### [4. add]
* Implement the add opcode.
*The opcode add adds the top two elements of the stack.


### [5. nop]
* Implement the nop opcode.
* The opcode nop doesn’t do anything.


### [6. sub]
* Implement the sub opcode.
* The opcode sub subtracts the top element of the stack from the second top element of the stack.


### [7. div]
* Implement the div opcode.
* The opcode div divides the second top element of the stack by the top element of the stack.


### [8. mul]
* Implement the mul opcode.
* The opcode mul multiplies the second top element of the stack with the top element of the stack.


### [9. mod]
* Implement the mod opcode.
* The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.


### [10. comments]
* Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).


### [16. Holberton](./bf/1000-holberton.bf)
* Write a Brainf*ck script that prints Holberton, followed by a new line.


### [17. Add two digits](./bf/1001-holberton.bf)
* Add two digits given by the user.
* Read the two digits from stdin, add them, and print the result
* The total of the two digits with be one digit-long (<10)


---

## Author
* **Tim McMacken** - [TMcMac](https://github.com/TMcMac)