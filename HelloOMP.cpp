// Reference Link:
// https://computing.llnl.gov/tutorials/openMP/samples/C/omp_hello.c
//
// Compile: g++ -fopenmp HelloOMP.cpp -o omphello
// .\omphello.exe

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// main loop
int main (int argc, char *argv[]) 
{
    int nthreads, tid;

    // nthreads: number of threads
    // tid: process number (rank)
  #pragma omp parallel private(nthreads, tid)
  {

    // thread number
    tid = omp_get_thread_num();
    // std::cout << "Hello World from thread = " << tid << std::endl;
    printf("Hello world from thread: %i\n", tid);
    

    // At the master thread
    if (tid == 0) 
    {
      // get total number of threads
      nthreads = omp_get_num_threads();
      std::cout << "Number of threads  " << nthreads << "(Master id:" << tid << ")" << std::endl;
    }

  }  // All threads join master thread and disband

}