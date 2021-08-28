# 2Pass-Assembler-and-Emulator
**A 2 pass Assembler & Emulator for a custom assembly language called SIMPLE.**<br/>
(SIMPLE has 2 registers, program counter, stack counter and selected mnemonics which perform various operations)
&nbsp;

### The Assembler
Converts the given assembly code to machine code for emulator to run. In<br/>
Pass1 : It checks for various syntax errors.<br/>
Pass2 : It obtains the machine code (*the object file*) <br/>

It also generates <br/>
*Listing file* : A human readable file showing what value is  stored at each address.
_Log file_ : Contains the warnings and errors(if any).


### The Emulator
Emulates the machine code (if produced without errors) on Terminal / Command Prompt. <br/>
User has been provided with various options to view the instructions getting executed.

&nbsp;

#### The List of Instructions provided

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/instructions%20%26%20mnemonics%20used%20in%20SIMPLE/Instruction_set.png" alt="1"/>


NOTE1: The design requirements are given in pdf file.<br/>
NOTE2: The run instructions and project design are mentioned in claims.txt files.<br/>




### Sample Assembler Run

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/test_run_pics/testing_pic1.jpg" alt="3"/>

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/test_run_pics/testing_pic2.jpg" alt="4" />

### Sample Emulator Run

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/test_run_pics/testing_pic3.jpg" alt="5" />
