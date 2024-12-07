import numpy as np
import random

# Parameters
L = 10  # Lattice size
J = 1.0  # Interaction strength
k_B = 1.0  # Boltzmann constant
n_steps = 1000  # Number of Monte Carlo steps
T_min, T_max, T_step = 4.0, 5.0, 0.1  # Temperature range

# Initialize the lattice with random spins
def initialize_lattice(L):
    return np.random.choice([-1, 1], size=(L, L, L))

# Calculate the energy of a given spin configuration
def calculate_energy(lattice, L, J):
    energy = 0
    for x in range(L):
        for y in range(L):
            for z in range(L):
                S = lattice[x, y, z]
                neighbors = lattice[(x+1)%L, y, z] + lattice[x, (y+1)%L, z] + lattice[x, y, (z+1)%L] + \
                            lattice[(x-1)%L, y, z] + lattice[x, (y-1)%L, z] + lattice[x, y, (z-1)%L]
                energy += -J * S * neighbors
    return energy / 2  # Each pair counted twice

# Perform a single Monte Carlo step
def monte_carlo_step(lattice, L, J, T):
    for _ in range(L**3):
        x, y, z = random.randint(0, L-1), random.randint(0, L-1), random.randint(0, L-1)
        S = lattice[x, y, z]
        neighbors = lattice[(x+1)%L, y, z] + lattice[x, (y+1)%L, z] + lattice[x, y, (z+1)%L] + \
                    lattice[(x-1)%L, y, z] + lattice[x, (y-1)%L, z] + lattice[x, y, (z-1)%L]
        dE = 2 * J * S * neighbors
        if dE < 0 or random.random() < np.exp(-dE / (k_B * T)):
            lattice[x, y, z] *= -1

# Main simulation loop
def simulate(L, J, T_min, T_max, T_step, n_steps):
    temperatures = np.arange(T_min, T_max, T_step)
    magnetizations = []

    for T in temperatures:
        lattice = initialize_lattice(L)
        for step in range(n_steps):
            monte_carlo_step(lattice, L, J, T)
        magnetization = np.abs(np.sum(lattice)) / (L**3)
        magnetizations.append(magnetization)
        print(f"T = {T:.2f}, Magnetization = {magnetization:.4f}")

    return temperatures, magnetizations

# Run the simulation
temperatures, magnetizations = simulate(L, J, T_min, T_max, T_step, n_steps)

# Plot the results
import matplotlib.pyplot as plt

plt.plot(temperatures, magnetizations, 'o-')
plt.xlabel('Temperature')
plt.ylabel('Magnetization')
plt.title('3D Ising Model')
plt.show()