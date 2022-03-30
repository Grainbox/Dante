# Dante

OS:
  Linux

Project:
  The dante is a maze generator and solver.
  The Generator must create a perfect or imperfect maze depends on the option given.
  The Solver must solve any given maze even if there is no result.
 
 Build:
  "make" in the root directory will build the two binaries : solver and generator.
  "make" in the generator directory will build the generator and "make" in the solver directory do the same for the solver.
 
 Using:
  Generator (at root)
    ./generator/generator cols row [perfect / imperfect]
    Exemple : ./generator 20 20 perfect
  Solver (at root)
    ./solver/solver path_to_map
    Exemple : ./solver/solver map.txt
