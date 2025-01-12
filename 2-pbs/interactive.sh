#!/usr/bin/bash

qsub -I -N interactive_demo -l select=2:ncpus=64:mpiprocs=64 -l walltime=00:5:00 -P personal -q normal
