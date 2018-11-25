# binary-game
a binary game demonstration.
game rule: Players pickup a element from a binary sequence array at his/her turn.
           the element must be surrounded by zero and not the first and last number.
           
input fortmat:
```
<number of game>
<number of element in sequence>
<sequence, each element seperated by a space>
...
```

# Compile
1. Make a build folder
   ```
   $ mkdir build
   ```
2. Move to build folder
   ```
   $ cd build
   ```
3. Generate project file
   ```
   $ cmake ../src
   ```
4. Compile
   ```
   cmake --build . --config Release
   ```
   
# Run
* Run with input file
   BinaryGame < input.txt
* Run with without inout file
   ```
   BinaryGame
   ```
   then input the sequences in terminal
