#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Problem 1
// avg. arrival rate: 2 processes per second, Poisson distrinution
// avg. service time: 1 second, Exonential distrinution
// Output: Print list of tuples in the format <process ID, arrival time, requested service time>
// Process ID assigned incrementally when process arrives, starting at 1
// Based on actual experiment outcome, also answer the following question:
// What are the actual average arrival rate and actual average service time that were generate?

float random_float() {
  return ((float)rand()/(float)(RAND_MAX/0.25) + 0.25);
}
int main(void) {
  
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    printf("%f\n", random_float());
  }
  return 0;
}