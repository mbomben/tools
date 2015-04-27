#include <iostream>

void usage( int , char** );

int main( int argc, char* argv[] ) {

  if ( argc < 2 || argc > 3 ) {
    usage( argc, argv );
    exit( 1 );
  }

  float Vdep = atof( argv[1] ); // V
  float d = 3e-2; // 300 um = 3e-2 cm // standard wafer thickness in cm
  if ( argc == 3 ) d = 1e-4* atof( argv[2] ) ; // thickness in cm
  float e0 = 8.85e-14; // F/cm
  float er = 11.8; // silicon dieletric constant
  float q0 = 1.6e-19; // C

  float Neff = 2*e0*er*Vdep/d/d/q0; // depletion voltage

  std::cout << "Vdep = " << Vdep << "V\n"
            << "d    = " << d*1e4<< "um\n"
            << " ==>\tNeff = " << Neff << " cm^-3\n";

  return 0;

}

void usage( int argc, char** argv ) {
  std::cout << "You supplied " << argc-1 << " parameters\n";
  std::cout <<"Usage: " << argv[0] << " <Vdep (V)> [<d (um)>]\n";
}
