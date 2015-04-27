#include <iostream>

void usage( int , char** );

int main( int argc, char* argv[] ) {

  if ( argc != 2 ) {
    usage( argc, argv );
    exit( 1 );
  }

  float Neff = atof( argv[1] ); // cm^-3
  float q0 = 1.6e-19; // C
  float mue = 1350; // electron mobility in cm^2/V/s

  float rho = 1/(q0*Neff*mue); // resistivity

  std::cout << "Neff = " << Neff << "cm^-3\n"
            << " ==>\trho = " << rho << " Ohm/cm\n";

  return 0;

}

void usage( int argc, char** argv ) {
  std::cout << "You supplied " << argc-1 << " parameters\n";
  std::cout <<"Usage: " << argv[0] << " <Neff (cm^-3)>\n";
}
