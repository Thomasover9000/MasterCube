#include "cube.h"

int main (int argc, char* argv[]) {
	Cube solved;
	Cube scrambled;
	
	scrambled.scramble();
	solved.printCube();
	cout << "------------------" << endl<<endl;
	scrambled.printCube();
	
    return 0;
}
