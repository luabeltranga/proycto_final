#include <iostream>
#include <random>
#include <vector>
#include <cmath>

void initialize_lattice (std::vector<int> &latt);
void interaction(std::vector<int> &latt);
void print_gnuplot(std::vector<int> &latt);
void start_gnuplot(void);
void clean_lattice(std::vector<int> &latt);
bool stop(std::vector<int> &latt);

int main (void){
  const int N = 6;
  const int repetitions = 5000 ;
  const int voters = 1;
  std::vector<int> latt (N*N);
  //start_gnuplot();
  //random values 0 and 1 on the lattice 
  initialize_lattice(latt);
  for (int ii = 0 ; ii < repetitions ; ii++){
    //print_gnuplot(latt);
    interaction(latt);
    if(stop(latt) == true){
      std::cout << ii << std::endl;
      break;
    }
  }
  clean_lattice(latt);
  return 0;
}

void initialize_lattice (std::vector<int> &latt){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0,1);
  int ii = 0;
  int jj = 0;
  int N = std::sqrt(latt.size());
    for(int ii = 0 ; ii < N ; ii++){
      for(int jj = 0 ; jj < N ; jj++){
	latt[ii*N+jj] = dis(gen);
      }
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
  std::cout<<"plot [-0.5:"<< N-0.5 <<"] [-0.5:"<< N-0.5 <<"] '-'  matrix with image "<< std::endl;
  //std::cout << "plot '-' matrix with image " << std::endl;
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
  std::cout << "unset tics" << std::endl;
  std::cout << "set terminal gif animate " << std::endl;
  std::cout << "set out 'vot.gif'" << std::endl;
  std::cout << std::endl;
}

void interaction(std::vector<int> &latt){
  int N = std::sqrt(latt.size());
  std::random_device rd;
  std::mt19937_64 gen(rd());
  //for the election of the voter
  std::uniform_int_distribution<int> dis1(0,N-1);
  
  //for the interaction between elements without the border
  std::uniform_int_distribution<int> dis2(1,8);
  
  //for the interaction on the border
  std::uniform_int_distribution<int> dis3(1,5);
  
  //for the intetaction on the tips of the lattice
  std::uniform_int_distribution<int> dis4(1,3);
  
  int ii = dis1(gen);
  int jj = dis1(gen);
  int test1 = dis2(gen);
  int test2 = dis3(gen);
  int test3 = dis4(gen);
  
  //borde superior
  if(ii == 0 && (jj>0 && jj < N-1)){

    if(test2 == 1){
      latt[ii*N+jj] = latt[ii*N+(jj-1)];    
    }
    if(test2 == 2){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj-1)];    
    }
    if(test2 == 3){
      latt[ii*N+jj] = latt[(ii+1)*N+jj];    
    }
    if(test2 == 4){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj+1)];    
    }
    if(test2 == 5){
      latt[ii*N+jj] = latt[ii*N+(jj+1)];    
    }
  }
  //borde inferior
  else if(ii == N-1 && (jj>0 && jj < N-1)){
    if(test2 == 1){
      latt[ii*N+jj] = latt[ii*N+(jj-1)];    
    }
    if(test2 == 2){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj-1)];    
    }
    if(test2 == 3){
      latt[ii*N+jj] = latt[(ii-1)*N+jj];    
    }
    if(test2 == 4){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj+1)];    
    }
    if(test2 == 5){
      latt[ii*N+jj] = latt[ii*N+(jj+1)];    
    }
  }
  //borde izquierdo
  else if(jj == 0 && (ii>0 && ii < N-1)){
    if(test2 == 1){
      latt[ii*N+jj] = latt[(ii-1)*N+jj];    
    }
    if(test2 == 2){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj+1)];    
    }
    if(test2 == 3){
      latt[ii*N+jj] = latt[ii*N+(jj+1)];    
    }
    if(test2 == 4){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj+1)];    
    }
    if(test2 == 5){
      latt[ii*N+jj] = latt[(ii+1)*N+jj];    
    }
  }
  //borde derecho
  else if(jj == N-1 && (ii>0 && ii < N-1)){
    if(test2 == 1){
      latt[ii*N+jj] = latt[(ii-1)*N+jj];    
    }
    if(test2 == 2){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj-1)];    
    }
    if(test2 == 3){
      latt[ii*N+jj] = latt[ii*N+(jj-1)];    
    }
    if(test2 == 4){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj-1)];    
    }
    if(test2 == 5){
      latt[ii*N+jj] = latt[(ii+1)*N+jj];    
    }
  }

  //the tips of the lattice
  else if(ii == 0 && jj == 0){
    if(test3 == 1){
      latt[ii*N+jj] = latt[ii*N+(jj+1)];    
    }
    if(test3 == 2){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj+1)];    
    }
    if(test3 == 3){
      latt[ii*N+jj] = latt[(ii+1)*N+jj];    
    }
  }
  else if(ii == 0 && jj == N-1){
    if(test3 == 1){
      latt[ii*N+jj] = latt[ii*N+(jj-1)];    
    }
    if(test3 == 2){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj-1)];    
    }
    if(test3 == 3){
      latt[ii*N+jj] = latt[(ii+1)*N+jj];    
    }
  }

  else if(ii == N-1 && jj == 0){
    if(test3 == 1){
      latt[ii*N+jj] = latt[(ii-1)*N+jj];    
    }
    if(test3 == 2){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj+1)];    
    }
    if(test3 == 3){
      latt[ii*N+jj] = latt[ii*N+(jj+1)];    
    }
  }
  else if(ii == N-1 && jj == N-1){
    if(test3 == 1){
      latt[ii*N+jj] = latt[ii*N+(jj-1)];    
    }
    if(test3 == 2){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj-1)];    
    }
    if(test3 == 3){
      latt[ii*N+jj] = latt[(ii-1)*N+jj];    
    }
  }
  //the rest of the lattice
  else{
    if(test1 == 1){
      latt[ii*N+jj] = latt[ii*N+(jj+1)];    
    }
    if(test1 == 2){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj+1)];    
    }
    if(test1 == 3){
      latt[ii*N+jj] = latt[(ii+1)*N+jj];    
    }
    if(test1 == 4){
      latt[ii*N+jj] = latt[(ii+1)*N+(jj-1)];    
    }
    if(test1 == 5){
      latt[ii*N+jj] = latt[ii*N+(jj-1)];    
    }
    if(test1 == 6){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj-1)];    
    }
    if(test1 == 7){
      latt[ii*N+jj] = latt[(ii-1)*N+jj];    
    }
    if(test1 == 8){
      latt[ii*N+jj] = latt[(ii-1)*N+(jj+1)];    
    }
  }
}

bool stop(std::vector<int> &latt){
  int N = std::sqrt(latt.size());
  int sum = 0;
  for(int ii = 0 ; ii < N ; ii++){
    for(int jj = 0 ; jj < N ; jj++){
      sum += latt[ii*N+jj];
    }
  }
  if(sum == N*N || sum == 0){
    return true;
  }
  return false;
}
