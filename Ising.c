#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define L 10 // Lattice size
#define N (L*L*L) // Number of spins
#define J 1.0 // Interaction energy
#define KB 1.0 // Boltzmann constant

int lattice[L][L][L];

void initialize_lattice() {
    for (int x = 0; x < L; x++) {
        for (int y = 0; y < L; y++) {
            for (int z = 0; z < L; z++) {
                lattice[x][y][z] = 1; // Randomly assign spin up (+1) or down (-1)
            }
        }
    }
}

double calculate_energy() {
    double energy = 0.0;
    for (int x = 0; x < L; x++) {
        for (int y = 0; y < L; y++) {
            for (int z = 0; z < L; z++) {
                int spin = lattice[x][y][z];
                int neighbor_sum = lattice[(x+1)%L][y][z] + lattice[(x-1+L)%L][y][z] +
                                   lattice[x][(y+1)%L][z] + lattice[x][(y-1+L)%L][z] +
                                   lattice[x][y][(z+1)%L] + lattice[x][y][(z-1+L)%L];
                energy -= J * spin * neighbor_sum;
            }
        }
    }
    return energy / 2.0; // Each pair counted twice
}

void metropolis_step(double T) {
    for (int i = 0; i < N; i++) {
        int x = rand() % L;
        int y = rand() % L;
        int z = rand() % L;
        int spin = lattice[x][y][z];
        int neighbor_sum = lattice[(x+1)%L][y][z] + lattice[(x-1+L)%L][y][z] +
                           lattice[x][(y+1)%L][z] + lattice[x][(y-1+L)%L][z] +
                           lattice[x][y][(z+1)%L] + lattice[x][y][(z-1+L)%L];
        double dE = 2.0 * J * spin * neighbor_sum;
        if (dE < 0 || (rand() / (double)RAND_MAX) < exp(-dE / (KB * T))) {
            lattice[x][y][z] = -spin;
        }
    }
}

double calculate_magnetization() {
    double magnetization = 0.0;
    for (int x = 0; x < L; x++) {
        for (int y = 0; y < L; y++) {
            for (int z = 0; z < L; z++) {
                magnetization += lattice[x][y][z];
            }
        }
    }
    return magnetization / N;
}

int main() {
    srand(time(NULL));
    initialize_lattice();

    double T_start = 4.0;
    double T_end = 5.0;
    double T_step = 0.01;

    for (double T = T_start; T <= T_end; T += T_step) {
        for (int i = 0; i < 10000; i++) {
            metropolis_step(T);
        }

        double magnetization = abs(calculate_magnetization());
        printf("Temperature: %f, Magnetization: %f\n", T, magnetization);
    }

    return 0;
}