#include <iostream>

void usage( int , char** );

int main( int argc, char* argv[] ) {

  if ( argc != 2 ) {
    usage( argc, argv );
    exit( 1 );
  }

  float rho = atof( argv[1] ); // ohm/cm
  float q0 = 1.6e-19; // C
  float mue = 1350; // electron mobility in cm^2/V/s

  float Neff = 1/(q0*rho*mue); // effective dopant concentration

  std::cout << "rho = " << rho << " Ohm/cm\n"
            << " ==>\tNeff = " << Neff << "cm^-3\n";

  return 0;

}

void usage( int argc, char** argv ) {
  std::cout << "You supplied " << argc-1 << " parameters\n";
  std::cout <<"Usage: " << argv[0] << " <rho (Ohm/cm)>\n";
}
