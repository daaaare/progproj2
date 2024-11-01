# Bitwise Operations
The code reads bitwise and arithmetic instructions from Programming-Project-2.txt, and does the operations and outputs in 32-bit hex. It does ADD, AND, ASR, LSR, NOTm ORRm SUB, and XOR

# Compilation
In vscode pull up a terminal and type in the following:
g++ -o main main.cpp
afterwards type the following into console: 
./main

# Working Process and Results 
The program processess each line of the input file in the following order
1. It reads the command and operands from each line
2.  If the command ends with an S for example ADDS the S is removed to just get the base command ADD
3.  Operands are parsed from hex strings to 32-bit ints (signed numbers like ASR are parsed as int32_t and unsigened as uint32_t
4.  The corresponding operation is performing using parsed operands
5.  The result is formatted as an 8-digit hex string with 0x at the front

# Description of Results
Addition (ADD)
ADDS 0x00AAA5555 0x00555AAAA results in 0x0FFFFFFF
Adds 0x00AAA5555 and 0x00555AAAA.
ADD 0xFFFFFFFF 0x1 results in 0x00000000 (overflow occurs in 32-bit arithmetic).

Bitwise AND (AND)
ANDS 0x00AAA5555 0x00555AAAA results in 0x00000000
Performs bitwise AND on the two operands.
AND 0xFFFFFFFF 0x1 results in 0x00000001

Arithmetic Shift Right (ASR)
ASRS 0x00AAA5555 1 results in 0x05552AAA
Shifts 0x00AAA5555 right by 1 bit, preserving the sign bit.
ASR 0xFFFFFFFF 2 results in 0xFFFFFFFF
Shifting a negative number (in two's complement) retains 0xFFFFFFFF.

Logical Shift Right (LSR)
LSRS 0x00AAA5555 1 results in 0x05552AAA
Shifts 0x00AAA5555 right by 1 bit, filling with zeros.
LSR 0xFFFFFFFF 2 results in 0x3FFFFFFF
Logical Shift Left (LSL)

LSL 0x00AAA5555 1 results in 0x1554AAAA
Shifts 0x00AAA5555 left by 1 bit.
LSLS 0xFFFFFFFF 2 results in 0xFFFFFFFC

Bitwise NOT (NOT)
NOT 0x00AAA5555 results in 0xF555AAAA
Inverts all bits of the operand.
NOTS 0xFFFFFFFF results in 0x00000000

Bitwise OR (ORR)
ORR 0x00AAA5555 0x00555AAAA results in 0x0FFFFFFF
Performs bitwise OR on the two operands.
Subtraction (SUB)

SUB 0x00AAA5555 0x00555AAAA results in 0x0554AAAB
Subtracts the second operand from the first.

Bitwise XOR (XOR)
XOR 0x00AAA5555 0x00555AAAA results in 0x0FFFFFFF
Performs bitwise XOR on the two operands.

# Overflow
In unsigened arithmetic, overflow wraps around

# Bitwise Operations
Operations like AND, OR, XOR, and NOT manipulate the bits directly, resulting in patterns that can be predicted by understanding binary representations.

# Shift Operations
ASR: Preserves the sign bit (most significant bit) when shifting right.
LSR: Shifts bits to the right, filling with zeros from the left.
LSL: Shifts bits to the left, filling with zeros on the right.

    
  
