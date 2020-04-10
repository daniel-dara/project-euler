
# What is Project Euler?
> [Project Euler](https://projecteuler.net/) is a series of challenging mathematical/computer programming problems that will require more than just mathematical insights to solve. Although mathematics will help you arrive at elegant and efficient methods, the use of a computer and programming skills will be required to solve most problems.

# My Progress
I discovered Project Euler as a junior in high school when I still mostly programmed in TI-BASIC. I solved the first 25 problems in Visual Basic before learning that there were more than just BASIC languages. Once I learned C and C++ in college, I recoded my earlier solutions and made some progress into the 40s. After college my interest waned until one day I learned Python. Enthralled by the simple yet robust language, I picked up where I left off.

<img src="http://projecteuler.net/profile/ddara.png" alt="Project Euler Stats">

# My Solutions
* Problems 1 - 44 are written in C or C++.
* Problems 46 - 50 are written in Python using my old, personal style.
* Problems 51 - 55 are written in Python following PEP8 standards and have basic test cases. 

The `problems` directory structure is not very Python-friendly since leading numbers are not allowed in keywords. I chose readable folder names over valid package names since the goal is to make it easier to read and navigate the code.

The test for a given problem can be run by calling:
```
python -m unittest problems.50-59.51.TestSolution -v
```

It is possible to import a problem directly but it requires using `importlib.import_module()` due to the invalid package names.
```
python -c "import importlib; problem_51 = importlib.import_module('problems.50-59.51.prime_digit_replacements'); print(problem_51.solve(6));"
```


