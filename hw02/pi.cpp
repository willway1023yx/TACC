#include <time.h>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <chrono>
using namespace std;


int main(int argc, char *argv[])
{
    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    if (argc <2) {
        printf ("Error! Please input at least one number!\n");
        exit(0);
     }

    /* code */
    int i, k;
    int N_o, N_i;
    double x, y, dist, pi_estimate, e_rel;
    double pi;
    int N_samples = stoi(argv[1]);

    srand(time(0));

    N_o = 0;
    N_i = 0;
    pi = 3.14159265358979323846;

    for (i = 1; i <= N_samples; i++){
        x = rand()/double(RAND_MAX);
        y = rand()/double(RAND_MAX);
        dist = x*x + y*y;

        if (dist > 1)
            N_o++;

    }

    N_i = N_samples - N_o;
    pi_estimate = double(4 * N_i) / N_samples;
    e_rel = pi_estimate/pi - 1;

    if (e_rel < 0)
        e_rel = - e_rel;

    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> dur = duration_cast<duration<double>>(end - start);
    printf ("%d %d %d %f %f %f\n", N_samples, N_i, N_o, pi_estimate, e_rel, dur);

    return 0;
}
