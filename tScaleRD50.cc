#include <iostream>
#include <cstdlib>
#include <math.h>

void usage( int, char** );

int main ( int argc, char** argv ) {
  
  double I=1; 
  double tref=20;

  if ( argc < 2 || argc > 4 ) {
    usage(argc,argv);
    exit( 2 );
  }
  

  double t = atof(argv[1]); 
  if ( argc > 2  ) I = atof(argv[2]); 

  if ( argc == 4  ) tref = atof(argv[3]);

  const double offset = 273.15; // K
  double T = t + offset;
  double Tref = tref + offset;

  const double kboltz = 8.617343e-5; // eV K−1
  const double egap = 1.21; //eV

  double scale = pow((Tref/T),2) * exp( (-egap/(2.*kboltz)) * (1./Tref -1./T));

  std::cout << "Scaling " << I << " A leakage current from " 
            << t << " ºC to " << tref  << " ºC\n";

  std::cout << "Scale factor = " << scale << "\n";

  double scaledCurrent = scale*I;
  std::cout << "Scaled current = " << scaledCurrent << " A\n";

  return I*scale;
}

void usage( int argc, char** argv ) {
  std::cout << "Wrong number of arguments: " << argc << "\n";
  std::cout << "Usage: " << argv[0] << " <t (ºC)> [<current (A)>] [<reference temperature (ºC)>]\n";
}
