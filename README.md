# GTNH Thaumcraft Research Solver

A  C program that helps you find which aspects to use to complete a path in **GTNH Thaumcraft**.  
Still in early development, feel free to modify and improve it.

## Requirements

- A basic C compiler (e.g. `gcc`, `clang`)
  to remove aspects and compile the .c file

---

## How to Use

1. Download the .exe file
2. Run it
3. Type the aspect you're starting from and hit `enter` eg: Aer, Vacuos, Nebrisum, Perditio
   You can find all aspects and how to create each one inside the file `Aspects.txt`
5. Same as 3. for the aspect you want to reach
6. Type the number of aspects between the starting and ending aspect
   If there is nothing wrong it should show the list of aspects to form a path between the two


How to remove aspects so the solver doesnt use them
by default all aspects can be used

1. Open `ThaumSolver.c`
2. In the function `populate()` add a `//` before the function `add_aspect` that has the aspects you wish not to use as the first parameter
   eg:
   If i wish not to use Fabrico than i change the line:
   ```
   add_aspect(Fabrico, Humanus, Instrumentum);
   ```
   into:
   ```
   //add_aspect(Fabrico, Humanus, Instrumentum);
   ```
4. Save
5. Compile
6. Run

   when i make the CLI removing an aspect should be done inside the executable

   

If a valid path isn't found at that distance, the program will increment the distance and retry until a path is found.

---

### Example

```
Aspect1: Cognitio
Aspect2: Victus
Distance: 4

Found path of length 4: Cognitio Ignis Potentia Ordo Sano Victus

To exit press q, else press any other button
q

```
---

## License

This project is licensed under the [Creative Commons Attribution-NonCommercial 4.0 International License](https://creativecommons.org/licenses/by-nc/4.0/).  
You are free to use, modify, and redistribute the code, but **commercial use is strictly prohibited**.
