//
// compile with
//  c++-52 -std=c++14 -O2 -Wall -fopt-info-vec -march=native matmul.cpp
//  change -O2 in -Ofast
//  add -funroll-loops
//
//  change order of loops using -DMMULT_ALGO=mmult2
//  change N (x2)
//

#ifndef MMULT_ALGO
#define MMULT_ALGO mmult
#warning "using default matmul algorithm"
#endif



void mmult(float const * a, float const * b, float * c, int N) {

  for ( int i = 0; i < N; ++i ) { 
    for ( int j = 0; j < N; ++j ) { 
      for ( int k = 0; k < N; ++k ) { 
	c[ i * N + j ]  +=   a[ i * N + k ]  *  b[ k * N + j ]; 
      } 
    } 
  }
  
}



void mmult1(float const * a, float const * b, float * c, int N) {

  for ( int j = 0; j < N; ++j ) {
    for ( int k = 0; k < N; ++k ) {
      for ( int i = 0; i < N; ++i ) {
	c[ i * N + j ]  +=   a[ i * N + k ]  *  b[ k * N + j ];
      }
    }
  }
  
}


void mmult2(float const * a, float const * b, float * c, int N) {

  for ( int i = 0; i < N; ++i ) {
    for ( int k = 0; k < N; ++k ) {
      for ( int j = 0; j < N; ++j ) {
	c[ i * N + j ]  +=   a[ i * N + k ]  *  b[ k * N + j ];
      }
    }
  }
  
}

void mdiv2(float const * a, float const * b, float * c, int N) {

  for ( int i = 0; i < N; ++i ) {
    for ( int k = 0; k < N; ++k ) {
      for ( int j = 0; j < N; ++j ) {
	c[ i * N + j ]  +=   a[ i * N + k ]  /  b[ k * N + j ];
      }
    }
  }
  
}



void init(float * x, int N, float y) {
  for ( int i = 0; i < N; ++i ) x[i]=y;
}


float * alloc(int N) {
  return new float[N];
  
}


int main() {
  
  int N = 1000;
  
  int size = N*N;
  float * a = alloc(size);
  float * b = alloc(size);
  float * c = alloc(size);
  
  init(c,size,0.f);
  init(a,size,1.3458f);
  init(b,size,2.467f);
  
  MMULT_ALGO(a,b,c,N);
  
  // mdiv2(a,b,c,N);

  return c[N];
  
}

