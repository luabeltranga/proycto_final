#include <iostream>
#include <random>
#include <vector>
#include <cmath>

void initialize_lattice (std::vector<int> &latt);
void interaction(std::vector<int> &latt);
void clean_lattice(std::vector<int> &latt);
bool stop(std::vector<int> &latt);

int main (void){
  //tamaño de la malla
  const int N = 3;

  //numero de pasos maximos para alcanzar el consenso
  const int max = 100000; 

  //numero de repeticiones
  const int rep = 1;
  //creacion de la malla como vector unidimensional
  std::vector<int> latt (N*N*N);
  //start_gnuplot();

  for(int jj = 0; jj < rep; jj++){
    
    initialize_lattice(latt);
    for (int ii = 0 ; ii < max ; ii++){
      interaction(latt);
      if(stop(latt) == true){
	std::cout << ii << std::endl;
      break;
      }
    }
    clean_lattice(latt);
  }
  
  return 0;
}

//llena de forma aleatoria la malla de 0 y 1
void initialize_lattice (std::vector<int> &latt){
  //generador de semilla aleatoria
  std::random_device rd;

  //generador de numeros aleatorios para el llenado de la malla
  std::mt19937 gen(10);

  //funcion que toma el generador de numeros aleatorios para la
  //generacion de numeros entre 0 y 1 usando una distribucion uniforme
  //los cuales se asignan a la malla
  std::uniform_int_distribution<int> dis(0,1);
  int ii = 0;
  int jj = 0;
  int N = std::cbrt(latt.size());
  for(int ii = 0 ; ii < N ; ii++){
    for(int jj = 0 ; jj < N ; jj++){
      for(int kk = 0 ; kk < N ; kk++){     
	latt[ii*N*N+jj*N+kk] = dis(gen);
      }
    }  
  }
}
  //limpia la malla para correr de nuevo 
void clean_lattice(std::vector<int> &latt){
  int N = std::cbrt(latt.size());
  for(int ii = 0 ; ii < N ; ii++){
    for(int jj = 0 ; jj < N ; jj++){
      for(int kk = 0 ; kk < N ; kk++){
	latt[ii*N*N + jj*N + kk] = 0;
      }
    }  
  }
}



//inicia el intercambio
void interaction(std::vector<int> &latt){
  
  int N = std::cbrt(latt.size());
  //generador de la semilla para el generador de numeros aleatorios
  std::random_device rd;

  //generador con semilla activa
  std::mt19937_64 gen(rd());
  
  //se utiliza una distribucion uniforme para elegir un elemento de la malla
  std::uniform_int_distribution<int> dis1(0,N-1);
  
  //para la eleccion de los vecinos de elementos dentro del cubo
  std::uniform_int_distribution<int> dis2(1,26);
  
  //para la eleccion de los vecinos sobre las caras
  std::uniform_int_distribution<int> dis3(1,17);
  
  //para la eleccion de los vecinos en las esquinas
  std::uniform_int_distribution<int> dis4(1,3);

  //para la eleccion de los vecinos en las esquinas
  std::uniform_int_distribution<int> dis5(1,3);

  //genera coordenadas en la malla
  int ii = dis1(gen);
  int jj = dis1(gen);
  int kk = dis1(gen);

  //pruebas para eleccion de vecinos
  int test1 = dis2(gen);
  int test2 = dis3(gen);
  int test3 = dis4(gen);
   //implementacion de interaccion en caras 
  if(kk == 0 && (jj>0 && jj < N-1) && (ii > 0 && ii < N-1)){

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
  //implementacion de interaccion en borde inferior
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
  //implementacion de interaccion en borde izquierdo
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
  //implementacion de interaccion en borde derecho
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

  //implementacion de interaccion en las esquinas de la malla
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

  
  //implementacion de interaccion en el interior de la malla
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




//criterio de parada cuando se alcanza el consenso 
bool stop(std::vector<int> &latt){
  int N = std::cbrt(latt.size());
  unsigned long sum = 0;
  for(int ii = 0 ; ii < N ; ii++){
    for(int jj = 0 ; jj < N ; jj++){
      sum += latt[ii*N+jj];
    }
  }
  if(sum == N*N*N){
    std::cout << "win 1" << std::endl;
    return true;
  }
  if(sum == 0){
    std::cout << "win -1" << std::endl;
    return true;
  }
  return false;
}
