# 2Pass-Assembler-and-Emulator
**A 2 pass Assembler & Emulator for a custom assembly language called SIMPLE.**
(SIMPLE has 2 registers, program counter, stack counter and selected mnemonics which perform various operations)

The Assembler converts the given assembly code to machine code for emulator to run, also checking for various syntax errors in pass1 and obtaining the machine code (*the object file*) in pass2. It also generates a *listing file* (a human readable file showing what value is  stored at each address)

The Emulator emulates the machine code (if produced without errors) on Terminal / Command Prompt. User has been provided with various options to view the instructions getting executed.

Also a *log file* is generated giving the warnings and errors(if any).

#### The List of Instructions provided

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/instructions%20%26%20mnemonics%20used%20in%20SIMPLE/1.jpg" alt="1" style="zoom:10%;" />
<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/instructions%20%26%20mnemonics%20used%20in%20SIMPLE/2.jpg" alt="2" style="zoom:15%;" />



NOTE1: The design requirements are given in pdf file

NOTE2: The run instructions and project design are mentioned in claims.txt files.



##### Sample Assembler Run

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/test_run_pics/testing_pic1.jpg" alt="3"/>

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/test_run_pics/testing_pic2.jpg" alt="4" />

**Sample Emulator Run**

<img src="https://github.com/SunnyChaturvedi/2Pass-Assembler-and-Emulator/blob/main/test_run_pics/testing_pic3.jpg" alt="5" />
