# GTNH Thaumcraft Research Solver

A  C program that helps you find which aspects to use to complete a path in **GTNH Thaumcraft**.  
Still in early development, feel free to modify and improve it.

## Requirements

- A basic C compiler (e.g. `gcc`, `clang`)

## How to Use

To change the starting point of the research:

1. Open `Solver.c`
2. In `main()` modify the first two parameters of the function `find_path()` to be the **starting** and **ending** aspects.
3. Set the third parameter to the **distance** (number of aspects in the path).

If a valid path isn't found at that distance, the program will increment the distance and retry until a path is found.

If you wish not to use a certain aspect just comment it out 
eg:
inside the function `populate()`
```
//add_aspect(Iter, Motus, Terra);
```
---

### Example

```c
path(Lucrum, Ordo, 3);
path(Electrum, Superbia, 3);
```
---

## License

This project is licensed under the [Creative Commons Attribution-NonCommercial 4.0 International License](https://creativecommons.org/licenses/by-nc/4.0/).  
You are free to use, modify, and redistribute the code, but **commercial use is strictly prohibited**.
