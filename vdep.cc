#include <iostream>

void usage( int , char** );

int main( int argc, char* argv[] ) {

  if ( argc < 2 || argc > 3 ) {
    usage( argc, argv );
    exit( 1 );
  }

  float Neff = atof( argv[1] ); // cm^-3
  float d = 3e-2; // 300 um = 3e-2 cm // standard wafer thickness in cm
  if ( argc == 3 ) d = 1e-4* atof( argv[2] ) ; // thickness in cm
  float e0 = 8.85e-14; // F/cm
  float er = 11.8; // silicon dieletric constant
  float q0 = 1.6e-19; // C

  float Vdep = q0*Neff*d*d/2/e0/er; // depletion voltage

  std::cout << "Neff = " << Neff << "cm^-3\n"
            << "d    = " << d*1e4<< "um\n"
            << " ==>\tVdep = " << Vdep << " V\n";

  return 0;

}

void usage( int argc, char** argv ) {
  std::cout << "You supplied " << argc-1 << " parameters\n";
  std::cout <<"Usage: " << argv[0] << " <Neff (cm-3)> [<d (um)>]\n";
}
