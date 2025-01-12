#!/usr/bin/bash

###### Basic Usage #####

# Show available modules
module avail

# Show currently loaded modules
module list

# Unload all modules
moudle purge

# Show currently loaded modules
module list

# Load a specific compiler version
module load gcc/12.3.0-nscc

# Show the change in environment
which gcc
gcc --version

# Demonstrate conflicts
module load gcc/9.5.0-nscc # Should show conflict with gcc-12

# Swap versions
module switch gcc/12.3.0-nscc gcc/9.5.0-nscc 

# Show the change in environment
which gcc
gcc --version


##### Module dependencies #####
moudle purge

# Try to load openmpi 4.1.7 compiled by gcc11 (error)
module load openmpi/4.1.7-gcc11

# Load depended gcc-11
module load gcc/11.2.0

# Now can load openmpi 4.1.7 successfully
module load openmpi/4.1.7-gcc11

moudle list


##### Prgramming Env #####
module purge

# Show avaiable programming environment
module show PrgEnv

# Load GNU PrgEnv
module load PrgEnv-gnu/8.3.3

# Show loaded modules
module list

# Show modified compiler
cc --version
CC --version
ftn --version

# Swap to Intel PrgEnv
module purge
module load PrgEnv-intel/8.3.3

# Show loaded modules
module list

# Show modified compiler
cc --version
CC --version
ftn --version

##### Get module info #####
# Show module help
module help valgrind4hpc

# Show env var module modified
module show valgrind4hpc

