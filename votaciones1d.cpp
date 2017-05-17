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
  //tamaño de la malla
  const int N = 4;

  //numero de pasos maximos para alcanzar el consenso
  const int max = 100000; 

  //numero de repeticiones
  const int rep = 1;
  //creacion de la malla como vector unidimensional
  std::vector<int> latt (N);
  
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
  std::mt19937_64 gen(10);
  
  //funcion que toma el generador de numeros aleatorios para la
  //generacion de numeros entre 0 y 1 usando una distribucion uniforme
  //los cuales se asignan a la malla
  std::uniform_int_distribution<int> dis(0,1);
  int ii = 0;
  int N = latt.size();
  for(int ii = 0 ; ii < N ; ii++){
    latt[ii] = dis(gen);
  }  
}

//limpia la malla para correr de nuevo 
void clean_lattice(std::vector<int> &latt){
  int N = latt.size();
  for(int ii = 0 ; ii < N ; ii++){
    latt[ii] = 0;
  }  
}

//inicia el intercambio
void interaction(std::vector<int> &latt){
  
  int N = latt.size();
  //generador de la semilla para el generador de numeros aleatorios
  std::random_device rd;

  //generador con semilla activa
  std::mt19937_64 gen(rd());
  
  //se utiliza una distribucion uniforme para elegir un elemento de la malla
  std::uniform_int_distribution<int> dis1(0,N-1);
  
  //para la eleccion de los vecinos de elementos fuera de la frontera
  std::uniform_int_distribution<int> dis2(1,2);
 
  //genera coordenadas en la malla
  int ii = dis1(gen);


  //pruebas para eleccion de vecinos
  int test1 = dis2(gen);
  
  //implementacion de interaccion en borde superior 
  if(ii == 0){
    latt[ii] = latt[(ii+1)];
  }
  //implementacion de interaccion en borde inferior
  else if(ii == N-1){
    latt[ii] = latt[(ii-1)];    
  }
  
  //implementacion de interaccion en el interior de la malla
  else{
    if(test1 == 1){
      latt[ii] = latt[(ii+1)];    
    }
    if(test1 == 2){
      latt[ii] = latt[(ii-1)];    
    }
    
  }
}


//criterio de parada cuando se alcanza el consenso 
bool stop(std::vector<int> &latt){
  int N = latt.size();
  unsigned long sum = 0;
  for(int ii = 0 ; ii < N ; ii++){
      sum += latt[ii];
  }
  if(sum == N){
    std::cout << "win 1" << std::endl;
    return true;
  }
  if(sum == 0){
    std::cout << "win -1" << std::endl;
    return true;
  }
  return false;
}
