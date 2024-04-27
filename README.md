# File Generator

## Description

This C program generates three binary files with different characteristics:

1. **random.bin**: Contains random unsigned 8-bit integers (0-255).
2. **restricted_random.bin**: Contains random unsigned 8-bit integers within a restricted range (0-25).
3. **non_random.bin**: Contains repeated sequences of unsigned 8-bit integers (0-255).

After generation, these files are suitable for compression analysis and entropy calculation.

## Usage

1. Ensure you have a C compiler installed (e.g., GCC).
2. Clone or download the repository.
3. Compile the program using `make`.
4. Run the compiled program with `./file_generator`.
5. Three binary files will be generated in the same directory.

## Cleaning Up

To remove the generated files and the compiled executable, run `make clean`.
