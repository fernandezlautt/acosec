#include "graph.h"
#include "aco.h"
#include "system.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Parameters
#define N_CITIES 10
#define N_ANTS 1
#define ALPHA 0.5
#define BETA 0.5
#define N_ITERATIONS 1
#define EVAPORATION_RATE 0.5
#define REINFORCEMENT_RATE 1.0

int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;

    // Initialize the system
    SYSTEM *system = initialize_system(N_CITIES, N_ANTS, ALPHA, BETA, EVAPORATION_RATE, REINFORCEMENT_RATE);

    // Start the clock
    start = clock();
    // Run the algorithm
    int *path = aco(system, N_ITERATIONS);
    // Stop the clock
    end = clock();

    // Calculate the time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time: %f\n", cpu_time_used);
    // Print the results
    print_vector(path, N_CITIES);
    printf("Cost: %f\n", system->best_cost);

    // Free memory
    free_system(system);

    return 0;
}