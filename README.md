# Gravity-Model-Continuation

The detailed code of the paper "Design of Two-Impulse Soft-Landing Trajectories from Periodic Orbits around an Irregular Asteroid by Gravity Model Continuation" is available in this repository.  Below is the C language code primarily for implementing step 3 in Section III.B.


## Installation

1. Clone the repository.
2. Navigate to the project directory.
3. Ensure GCC compiler is installed.

## Usage

1. Compile the code in Visual Studio Code's terminal:

   ```bash
   gcc -g.\main.c  .\ASCM.c .\deltax.c .\ASCMcontinuation.c .\ASCMgravity.c .\ASCMhuaraodong.c .\ASCMorbequ.c .\ASCMriteOrbLevel.c .\ASCMrk4.c .\ASCMrk4step.c .\ASCMzhouqiguidaoqiujie.c  .\astgravity_preload.c .\sort.c .\Gass.c .\tuoqiugravity.c .\inv.c  -o out
   ```

2. Run the executable to perform calculations:

   ```bash
   ./out.exe
   ```


Feedback and suggestions are welcome!
