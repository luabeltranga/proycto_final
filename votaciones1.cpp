#include <iostream>
#include <random>
#include <vector>
#include <cmath>

void initialize_voters (std::vector<int> &latt,int voters);
void print_gnuplot(std::vector<int> &latt);
void start_gnuplot(void);
void clean_lattice(std::vector<int> &latt);

int main (void){
  const int N = 50;
  const int repetitions = 4 ;
  const int voters = 5;
  std::vector<int> latt (N*N);
  start_gnuplot();
  //random values 0 and 1 on the lattice 
  for (int ii = 0 ; ii < repetitions ; ii++){
    initialize_voters(latt, 10);
    print_gnuplot(latt);
    clean_lattice(latt);
  }
  return 0;
}
//
void initialize_voters (std::vector<int> &latt,int voters){
  int N = std::sqrt(latt.size());
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0,N-1);
  int ii = 0;
  int jj = 0;
  for(int kk = 0 ; kk < voters ; kk++){
    ii = dis(gen);
    jj = dis(gen);
    latt[ii*N+jj] =1;
  }  
}

void clean_lattice(std::vector<int> &latt){
  int N = std::sqrt(latt.size());
    for(int ii = 0 ; ii < N ; ii++){
      for(int jj = 0 ; jj < N ; jj++){
	latt[ii*N+jj] = 0;;
      }
    }  
}

void print_gnuplot(std::vector<int> &latt){
  const int N = std::sqrt(latt.size());
  std::cout<<"plot [0:"<< N <<"] [0:"<<N<<"] '-'  matrix with image "<< std::endl;
  for(int ii = 0 ; ii < N ; ii++){
    for(int jj = 0 ; jj < N ; jj++){
      std::cout << latt[ii*N+jj] << " ";
    }
    std::cout << std::endl;    
  }
  std::cout << "e " << std::endl;
  std::cout << "e " << std::endl;
}

void start_gnuplot(void){
  std::cout << "unset key" << std::endl;
  std::cout << "set palette model RGB" << std::endl;
  std::cout << "unset colorbox" << std::endl;
  std::cout << "set terminal gif animate delay 100" << std::endl;
  std::cout << "set out 'vot.gif'" << std::endl;
  std::cout << std::endl;
}
