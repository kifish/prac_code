#!/bin/bash

#SBATCH -o job_%j_%N.out
#SBATCH --partition=cpu
#SBATCH -J mm 
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=8
#SBATCH --cpus-per-task=1
#SBATCH -t 10:00

# you'll need mpich/3.2.1 to run this job
mpiexec -n 8 ./ring

