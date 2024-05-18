Corewar Virtual Machine Project

Introduction

The Corewar tournament is a competitive game where several programs, known as Champions, battle to be the last one standing. This is simulated on a virtual machine where these programs share memory and execute instructions. The last Champion to execute the live instruction is declared the winner.

Objectives

The goal of this project is to develop the Virtual Machine component of the Corewar game. This involves simulating the execution of multiple Champions, managing their memory, and determining the winner based on specific game rules.

Project Components

The project consists of three main components, though you are only required to develop the Virtual Machine:

1. Champions: Provided. These are programs written in a specific assembly language.
1. Assembler: Converts Champion files from assembly language to machine code. Developed in a previous project.
1. Virtual Machine: Executes the Champions' machine code, simulating their battle.

Instructions

Files Provided

* op.c and op.h: Contain definitions and functions necessary for the Corewar game. These must be integrated into your project directory.

Core Instructions

* 0x01 (live): Announces that the player is alive.
* 0x02 (ld): Loads a value into a register.
* 0x03 (st): Stores a value from a register into memory.
* 0x04 (add): Adds values from two registers and stores the result in a third register.
* 0x05 (sub): Subtracts values from two registers and stores the result in a third register.
* 0x06 (and), 0x07 (or), 0x08 (xor): Perform bitwise operations.
* 0x09 (zjmp): Jumps to a specified address if a condition is met.
* 0x0a (ldi), 0x0b (sti): Load and store indexed values.
* 0x0c (fork), 0x0f (lfork): Create new processes.
* 0x0d (lld), 0x0e (lldi): Load long distance.
* 0x10 (aff): Outputs a character.

Virtual Machine

* Registers: Each Champion has a set number of registers.
* Program Counter (PC): Points to the next instruction to execute.
* Carry Flag: Indicates the result of the last operation.
* Cycle Management: Champions must execute the live instruction every CYCLE\_TO\_DIE cycles to stay in the game.

Usage


./corewar [-dump nbr\_cycle] [[-n prog\_number] [-a load\_address] prog\_name] ...


* -dump nbr\_cycle: Dumps memory after the specified number of cycles.
* -n prog\_number: Sets the program number.
* -a load\_address: Sets the program's loading address.

Output

* Announce when a player is alive: "The player NB\_OF\_PLAYER(NAME\_OF\_PLAYER) is alive."
* Announce the winner: "The player NB\_OF\_PLAYER(NAME\_OF\_PLAYER) has won."

Implementation Details

1. Memory Management: Allocate a memory zone for the Champions to share.
1. Instruction Execution: Decode and execute instructions based on the provided opcodes.
1. Cycle Handling: Manage execution cycles and ensure Champions call the live instruction appropriately.
1. Output Handling: Display messages according to the specified format for player announcements and the winner declaration.

Scheduling

* Simulate a parallel machine, executing instructions in cycle-based order.
* Execute instructions in ascending order based on the program number.

Conclusion

Carefully follow the provided instructions and ensure your implementation adheres to the coding style guidelines. Utilize op.c and op.h for reference and necessary constants.