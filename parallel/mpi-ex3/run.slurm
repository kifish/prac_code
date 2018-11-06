#!/bin/bash

#SBATCH -o job_%j_%N.out
#SBATCH --partition=cpu
#SBATCH -J mm 
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=8
#SBATCH --cpus-per-task=1
#SBATCH -t 10:00

# you'll need mpich/3.2.1 to run this job
mpiexec -n 4 ./hello2
mpiexec -n 1 ./cpi
mpiexec -n 2 ./cpi
mpiexec -n 4 ./cpi
mpiexec -n 8 ./cpi
mpiexec -n 16 ./split
mpiexec -n 8 ./group
