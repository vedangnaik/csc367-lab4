// ------------
// This code is provided solely for the personal and private use of
// students taking the CSC367 course at the University of Toronto.
// Copying for purposes other than this use is expressly prohibited.
// All forms of distribution of this code, whether as given or with
// any changes, are expressly prohibited.
//
// Authors: Bogdan Simion, Maryam Dehnavi, Alexey Khrabrov
//
// All of the files in this directory and all subdirectories are:
// Copyright (c) 2020 Bogdan Simion and Maryam Dehnavi
// -------------

#include <assert.h>
#include <omp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


static bool is_prime(int n)
{
	assert(n > 0);
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

static int primes_count(int n, int chunk)
{
	int p = 0;
	//TODO: parallelize using OpenMP, with dynamic scheduling
	for (int i = 2; i < n; i++) {
		if (is_prime(i)) p++;
	}
	return p;
}


int main(int argc, char *argv[])
{
	if ((argc < 3) || (atoi(argv[1]) <= 0) || (atoi(argv[2]) <= 0)) {
		fprintf(stderr, "Invalid arguments\n");
		return 1;
	}
	int N = atoi(argv[1]);
	int chunk = atoi(argv[2]);

	//TODO: measure time (in milliseconds) taken to execute primes_count()
	double time_msec = 0.0;
	int p = primes_count(N, chunk);

	printf("%d\n", p);
	printf("%f\n", time_msec);
	return 0;
}
