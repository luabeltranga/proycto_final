#include <iostream>
#include <random>
#include <vector>

void initialize (std::vector<int> &latt);
void print_gnuplot()


int main (void){
  const int N = 10;
  std::vector<int> latt (N*N);
  initialize(latt);
  
  
  return 0;
}

void initialize (std::vector<int> &latt){
  int N = latt.size();
  for(int ii = 0 ; ii < N ; ii++){
    for(int jj = 0 ; jj < N ; jj++){
      latt[ii*N+jj]=1.0;
    }
  }  
}
