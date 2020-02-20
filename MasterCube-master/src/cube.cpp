#include "cube.h"


//-----------------------------------------------//
//---------------Allgemeine Funktionen---------------//
//-----------------------------------------------//

char numbers_to_color(int number)
{
	char color[] = "wgrboy"; //white green red blue orange yellow
	return color[number];
}

int color_to_number(char color)
{
	switch (color)
	{
	case 'w':
		return 0;

	case 'g':
		return 1;

	case 'r':
		return 2;

	case 'b':
		return 3;

	case 'o':
		return 4;

	case 'y':
		return 5;

	default:
		//cout << "you took a wrong turn" <<endl;
		return -1;
	}
}


//-----------------------------------------------//
//---------------Globale Drehungen---------------//
//-----------------------------------------------//
void Cube::globalRotationR(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=1; i<5; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==4){
					_cube[i-3][j][k]=_old[i][j][k];
				}
				else{
					_cube[i+1][j][k]=_old[i][j][k];
				}
			}
		}
	}

	// //corners der oberseite
	_cube[0][0][0] = _old[0][0][2];
	_cube[0][2][2] = _old[0][2][0];
	_cube[0][2][0] = _old[0][0][0];
	_cube[0][0][2] = _old[0][2][2];
	// //edges der oberseite
	_cube[0][1][2] = _old[0][2][1];
	_cube[0][1][0] = _old[0][0][1];
	_cube[0][0][1] = _old[0][1][2];
	_cube[0][2][1] = _old[0][1][0];
	//corners der unterseite
	_cube[5][0][0] = _old[5][2][0];
	_cube[5][2][0] = _old[5][2][2];
	_cube[5][2][2] = _old[5][0][2];
	_cube[5][0][2] = _old[5][0][0];
	//edges der unterseite
	_cube[5][0][1] = _old[5][1][0];
	_cube[5][1][0] = _old[5][2][1];
	_cube[5][2][1] = _old[5][1][2];
	_cube[5][1][2] = _old[5][0][1];


	moves += "gR_";
}

void Cube::globalRotationL(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=1; i<5; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==1){
					_cube[i+3][j][k]=_old[i][j][k];
				}
				else{
					_cube[i-1][j][k]=_old[i][j][k];
				}
			}
		}
	}
	//corners der oberseite
	_cube[0][2][2] = _old[0][0][2];
	_cube[0][2][0] = _old[0][2][2];
	_cube[0][0][0] = _old[0][2][0];
	_cube[0][0][2] = _old[0][0][0];
	//edges der oberseite
	_cube[0][2][1] = _old[0][1][2];
	_cube[0][1][2] = _old[0][0][1];
	_cube[0][0][1] = _old[0][1][0];
	_cube[0][1][0] = _old[0][2][1];
	//corners der unterseite
	_cube[5][0][0] = _old[5][0][2];
	_cube[5][2][0] = _old[5][0][0];
	_cube[5][2][2] = _old[5][2][0];
	_cube[5][0][2] = _old[5][2][2];
	//edges der unterseite
	_cube[5][0][1] = _old[5][1][2];
	_cube[5][1][2] = _old[5][2][1];
	_cube[5][2][1] = _old[5][1][0];
	_cube[5][1][0] = _old[5][0][1];

	moves += "gL_";
}

void Cube::globalRotationD(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==0) _cube[i+2][j][k] = _old[i][j][k];
				if(i==2) _cube[i+3][j][k] = _old[i][j][k];
				if(i==4) _cube[i-4][j][k] = _old[i][j][k];
				if(i==5) _cube[i-1][j][k] = _old[i][j][k];
			}
		}
	}
	//corners linken Seite -> drehung nach rechts
	_cube[1][0][0] = _old[1][2][0];
	_cube[1][2][0] = _old[1][2][2];
	_cube[1][2][2] = _old[1][0][2];
	_cube[1][0][2] = _old[1][0][0];
	//edges der linken Seite -> drehung nach rechts
	_cube[1][0][1] = _old[1][1][0];
	_cube[1][1][0] = _old[1][2][1];
	_cube[1][2][1] = _old[1][1][2];
	_cube[1][1][2] = _old[1][0][1];
	//corners der rechten Seite - > Dreheung nach links
	_cube[3][0][0] = _old[3][0][2];
	_cube[3][0][2] = _old[3][2][2];
	_cube[3][2][2] = _old[3][2][0];
	_cube[3][2][0] = _old[3][0][0];
	//edges der rechten Seite - > Dreheung nach links
	_cube[3][0][1] = _old[3][1][2];
	_cube[3][1][0] = _old[3][0][1];
	_cube[3][2][1] = _old[3][1][0];
	_cube[3][1][2] = _old[3][2][1];

	copyCube();
	//corners der Oberseite
	_cube[0][0][0] = _old[0][2][2];
	_cube[0][2][2] = _old[0][0][0];
	_cube[0][0][2] = _old[0][2][0];
	_cube[0][2][0] = _old[0][0][2];
	//edges der Oberseite
	_cube[0][0][1] = _old[0][2][1];
	_cube[0][2][1] = _old[0][0][1];
	_cube[0][1][0] = _old[0][1][2];
	_cube[0][1][2] = _old[0][1][0];
	//corners der Hinterseite
	_cube[4][0][0] = _old[4][2][2];
	_cube[4][2][2] = _old[4][0][0];
	_cube[4][0][2] = _old[4][2][0];
	_cube[4][2][0] = _old[4][0][2];
	//edges der Hinterseite
	_cube[4][0][1] = _old[4][2][1];
	_cube[4][2][1] = _old[4][0][1];
	_cube[4][1][0] = _old[4][1][2];
	_cube[4][1][2] = _old[4][1][0];

	moves += "gD_";
}

void Cube::globalRotationU(){
	copyCube(); //copiere den aktuellen Cube in den _old
	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				if(i==0) _cube[i+4][j][k] = _old[i][j][k];
				if(i==2) _cube[i-2][j][k] = _old[i][j][k];
				if(i==4) _cube[i+1][j][k] = _old[i][j][k];
				if(i==5) _cube[i-3][j][k] = _old[i][j][k];
			}
		}
	}
	//corners der linken Seite - > Dreheung nach links
	_cube[1][0][0] = _old[1][0][2];
	_cube[1][0][2] = _old[1][2][2];
	_cube[1][2][2] = _old[1][2][0];
	_cube[1][2][0] = _old[1][0][0];
	//edges der linken Seite - > Dreheung nach links
	_cube[1][0][1] = _old[1][1][2];
	_cube[1][1][0] = _old[1][0][1];
	_cube[1][2][1] = _old[1][1][0];
	_cube[1][1][2] = _old[1][2][1];
	//corners rechten Seite -> drehung nach rechts
	_cube[3][0][0] = _old[3][2][0];
	_cube[3][2][0] = _old[3][2][2];
	_cube[3][2][2] = _old[3][0][2];
	_cube[3][0][2] = _old[3][0][0];
	//edges der rechten Seite -> drehung nach rechts
	_cube[3][0][1] = _old[3][1][0];
	_cube[3][1][0] = _old[3][2][1];
	_cube[3][2][1] = _old[3][1][2];
	_cube[3][1][2] = _old[3][0][1];

	copyCube();
	//corners der Unterseite
	_cube[5][0][0] = _old[5][2][2];
	_cube[5][2][2] = _old[5][0][0];
	_cube[5][0][2] = _old[5][2][0];
	_cube[5][2][0] = _old[5][0][2];
	//edges der Unterseite
	_cube[5][0][1] = _old[5][2][1];
	_cube[5][2][1] = _old[5][0][1];
	_cube[5][1][0] = _old[5][1][2];
	_cube[5][1][2] = _old[5][1][0];
	//corners der neuen hinterseite
	_cube[4][0][2] = _old[4][2][0];
	_cube[4][2][0] = _old[4][0][2];
	_cube[4][0][0] = _old[4][2][2];
	_cube[4][2][2] = _old[4][0][0];
	//edges der neuen hinterseite
	_cube[4][0][1] = _old[4][2][1];
	_cube[4][2][1] = _old[4][0][1];
	_cube[4][1][0] = _old[4][1][2];
	_cube[4][1][2] = _old[4][1][0];

	moves += "gU_";
}


//-----------------------------------------------//
//---------------------Moves---------------------//
//-----------------------------------------------//

void Cube::r()
{
	if (last() == "r__")
	{
		removeLast();
		moves += "r2_";
	}
	else if (last() == "r2_")
	{
		removeLast();
		moves += "ri_";
	}
	else if (last() == "ri_")
	{
		removeLast();
	}
	else
	{
		moves += "r__";
	}

	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][i][2] = _old[5][i][2];
		_cube[0][i][2] = _old[2][i][2];
		_cube[4][i][0] = _old[0][2 - i][2];
		_cube[5][i][2] = _old[4][2 - i][0];
	}
	_cube[3][0][2] = _old[3][0][0];
	_cube[3][2][2] = _old[3][0][2];
	_cube[3][2][0] = _old[3][2][2];
	_cube[3][0][0] = _old[3][2][0];

	_cube[3][1][2] = _old[3][0][1];
	_cube[3][2][1] = _old[3][1][2];
	_cube[3][1][0] = _old[3][2][1];
	_cube[3][0][1] = _old[3][1][0];
}

void Cube::ri()
{
	if (last() == "ri_")
	{
		removeLast();
		moves += "r2_";
	}
	else if (last() == "r2_")
	{
		removeLast();
		moves += "r__";
	}
	else if (last() == "r__")
	{
		removeLast();
	}
	else
	{
		moves += "ri_";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[5][i][2] = _old[2][i][2];
		_cube[2][i][2] = _old[0][i][2];
		_cube[0][2 - i][2] = _old[4][i][0];
		_cube[4][2 - i][0] = _old[5][i][2];
	}
	_cube[3][0][0] = _old[3][0][2];
	_cube[3][0][2] = _old[3][2][2];
	_cube[3][2][2] = _old[3][2][0];
	_cube[3][2][0] = _old[3][0][0];

	_cube[3][0][1] = _old[3][1][2];
	_cube[3][1][2] = _old[3][2][1];
	_cube[3][2][1] = _old[3][1][0];
	_cube[3][1][0] = _old[3][0][1];
}

void Cube::l()
{
	if (last() == "l__")
	{
		removeLast();
		moves += "l2_";
	}
	else if (last() == "l2_")
	{
		removeLast();
		moves += "li_";
	}
	else if (last() == "li_")
	{
		removeLast();
	}
	else
	{
		moves += "l__";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[5][i][0] = _old[2][i][0];
		_cube[2][i][0] = _old[0][i][0];
		_cube[0][i][0] = _old[4][2 - i][2];
		_cube[4][2 - i][2] = _old[5][i][0];
	}
	_cube[1][0][2] = _old[1][0][0];
	_cube[1][2][2] = _old[1][0][2];
	_cube[1][2][0] = _old[1][2][2];
	_cube[1][0][0] = _old[1][2][0];

	_cube[1][1][2] = _old[1][0][1];
	_cube[1][2][1] = _old[1][1][2];
	_cube[1][1][0] = _old[1][2][1];
	_cube[1][0][1] = _old[1][1][0];
}

void Cube::li()
{
	if (last() == "li_")
	{
		removeLast();
		moves += "l2_";
	}
	else if (last() == "l2_")
	{
		removeLast();
		moves += "l__";
	}
	else if (last() == "l__")
	{
		removeLast();
	}
	else
	{
		moves += "li_";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][i][0] = _old[5][i][0];
		_cube[0][i][0] = _old[2][i][0];
		_cube[4][i][2] = _old[0][2 - i][0];
		_cube[5][i][0] = _old[4][2 - i][2];
	}
	_cube[1][0][0] = _old[1][0][2];
	_cube[1][0][2] = _old[1][2][2];
	_cube[1][2][2] = _old[1][2][0];
	_cube[1][2][0] = _old[1][0][0];

	_cube[1][0][1] = _old[1][1][2];
	_cube[1][1][2] = _old[1][2][1];
	_cube[1][2][1] = _old[1][1][0];
	_cube[1][1][0] = _old[1][0][1];
}

void Cube::u()
{
	if (last() == "u__")
	{
		removeLast();
		moves += "u2_";
	}
	else if (last() == "u2_")
	{
		removeLast();
		moves += "ui_";
	}
	else if (last() == "ui_")
	{
		removeLast();
	}
	else
	{
		moves += "u__";
	}

	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][0][i] = _old[2][0][i];
		_cube[4][0][i] = _old[1][0][i];
		_cube[3][0][i] = _old[4][0][i];
		_cube[2][0][i] = _old[3][0][i];
	}
	_cube[0][0][0] = _old[0][2][0];
	_cube[0][0][2] = _old[0][0][0];
	_cube[0][2][2] = _old[0][0][2];
	_cube[0][2][0] = _old[0][2][2];

	_cube[0][0][1] = _old[0][1][0];
	_cube[0][1][2] = _old[0][0][1];
	_cube[0][2][1] = _old[0][1][2];
	_cube[0][1][0] = _old[0][2][1];
}

void Cube::ui()
{
	if (last() == "ui_")
	{
		removeLast();
		moves += "u2_";
	}
	else if (last() == "u2_")
	{
		removeLast();
		moves += "u__";
	}
	else if (last() == "u__")
	{
		removeLast();
	}
	else
	{
		moves += "ui_";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][0][i] = _old[1][0][i];
		_cube[1][0][i] = _old[4][0][i];
		_cube[4][0][i] = _old[3][0][i];
		_cube[3][0][i] = _old[2][0][i];
	}
	_cube[0][2][0] = _old[0][0][0];
	_cube[0][0][0] = _old[0][0][2];
	_cube[0][0][2] = _old[0][2][2];
	_cube[0][2][2] = _old[0][2][0];

	_cube[0][1][0] = _old[0][0][1];
	_cube[0][0][1] = _old[0][1][2];
	_cube[0][1][2] = _old[0][2][1];
	_cube[0][2][1] = _old[0][1][0];
}

void Cube::d()
{
	if (last() == "d__")
	{
		removeLast();
		moves += "d2_";
	}
	else if (last() == "d2_")
	{
		removeLast();
		moves += "di_";
	}
	else if (last() == "di_")
	{
		removeLast();
	}
	else
	{
		moves += "d__";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[2][2][i] = _old[1][2][i];
		_cube[1][2][i] = _old[4][2][i];
		_cube[4][2][i] = _old[3][2][i];
		_cube[3][2][i] = _old[2][2][i];
	}
	_cube[5][0][0] = _old[5][2][0];
	_cube[5][0][2] = _old[5][0][0];
	_cube[5][2][2] = _old[5][0][2];
	_cube[5][2][0] = _old[5][2][2];

	_cube[5][0][1] = _old[5][1][0];
	_cube[5][1][2] = _old[5][0][1];
	_cube[5][2][1] = _old[5][1][2];
	_cube[5][1][0] = _old[5][2][1];
}

void Cube::di()
{
	if (last() == "di_")
	{
		removeLast();
		moves += "d2_";
	}
	else if (last() == "d2_")
	{
		removeLast();
		moves += "d__";
	}
	else if (last() == "d__")
	{
		removeLast();
	}
	else
	{
		moves += "di_";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][2][i] = _old[2][2][i];
		_cube[4][2][i] = _old[1][2][i];
		_cube[3][2][i] = _old[4][2][i];
		_cube[2][2][i] = _old[3][2][i];
	}
	_cube[5][2][0] = _old[5][0][0];
	_cube[5][0][0] = _old[5][0][2];
	_cube[5][0][2] = _old[5][2][2];
	_cube[5][2][2] = _old[5][2][0];

	_cube[5][1][0] = _old[5][0][1];
	_cube[5][0][1] = _old[5][1][2];
	_cube[5][1][2] = _old[5][2][1];
	_cube[5][2][1] = _old[5][1][0];
}

void Cube::f()
{
	if (last() == "f__")
	{
		removeLast();
		moves += "f2_";
	}
	else if (last() == "f2_")
	{
		removeLast();
		moves += "fi_";
	}
	else if (last() == "fi_")
	{
		removeLast();
	}
	else
	{
		moves += "f__";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[0][2][i] = _old[1][2 - i][2];
		_cube[3][i][0] = _old[0][2][i];
		_cube[5][0][2 - i] = _old[3][i][0];
		_cube[1][2 - i][2] = _old[5][0][2 - i];
	}
	_cube[2][0][2] = _old[2][0][0];
	_cube[2][2][2] = _old[2][0][2];
	_cube[2][2][0] = _old[2][2][2];
	_cube[2][0][0] = _old[2][2][0];

	_cube[2][1][2] = _old[2][0][1];
	_cube[2][2][1] = _old[2][1][2];
	_cube[2][1][0] = _old[2][2][1];
	_cube[2][0][1] = _old[2][1][0];
}

void Cube::fi()
{
	if (last() == "fi_")
	{
		removeLast();
		moves += "f2_";
	}
	else if (last() == "f2_")
	{
		removeLast();
		moves += "f__";
	}
	else if (last() == "f__")
	{
		removeLast();
	}
	else
	{
		moves += "fi_";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][i][2] = _old[0][2][2 - i];
		_cube[0][2][2 - i] = _old[3][2 - i][0];
		_cube[3][2 - i][0] = _old[5][0][i];
		_cube[5][0][i] = _old[1][i][2];
	}
	_cube[2][0][0] = _old[2][0][2];
	_cube[2][0][2] = _old[2][2][2];
	_cube[2][2][2] = _old[2][2][0];
	_cube[2][2][0] = _old[2][0][0];

	_cube[2][0][1] = _old[2][1][2];
	_cube[2][1][2] = _old[2][2][1];
	_cube[2][2][1] = _old[2][1][0];
	_cube[2][1][0] = _old[2][0][1];
}

void Cube::b()
{
	if (last() == "b__")
	{
		removeLast();
		moves += "b2_";
	}
	else if (last() == "b2_")
	{
		removeLast();
		moves += "bi_";
	}
	else if (last() == "bi_")
	{
		removeLast();
	}
	else
	{
		moves += "b__";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[1][2 - i][0] = _old[0][0][i];
		_cube[0][0][i] = _old[3][i][2];
		_cube[3][i][2] = _old[5][2][2 - i];
		_cube[5][2][2 - i] = _old[1][2 - i][0];
	}
	_cube[4][0][2] = _old[4][0][0];
	_cube[4][2][2] = _old[4][0][2];
	_cube[4][2][0] = _old[4][2][2];
	_cube[4][0][0] = _old[4][2][0];

	_cube[4][1][2] = _old[4][0][1];
	_cube[4][2][1] = _old[4][1][2];
	_cube[4][1][0] = _old[4][2][1];
	_cube[4][0][1] = _old[4][1][0];
}

void Cube::bi()
{
	if (last() == "bi_")
	{
		removeLast();
		moves += "b2_";
	}
	else if (last() == "b2_")
	{
		removeLast();
		moves += "b__";
	}
	else if (last() == "b__")
	{
		removeLast();
	}
	else
	{
		moves += "bi_";
	}
	copyCube();
	for (int i = 0; i < 3; i++)
	{
		_cube[0][0][i] = _old[1][2 - i][0];
		_cube[3][i][2] = _old[0][0][i];
		_cube[5][2][2 - i] = _old[3][i][2];
		_cube[1][2 - i][0] = _old[5][2][2 - i];
	}
	_cube[4][0][0] = _old[4][0][2];
	_cube[4][0][2] = _old[4][2][2];
	_cube[4][2][2] = _old[4][2][0];
	_cube[4][2][0] = _old[4][0][0];

	_cube[4][0][1] = _old[4][1][2];
	_cube[4][1][2] = _old[4][2][1];
	_cube[4][2][1] = _old[4][1][0];
	_cube[4][1][0] = _old[4][0][1];
}


void Cube::solveTopCross()
{
	moveTopEdges();
	//look for the 4 yellow edges
	for (int i = 1; i < 5; i++)
	{
		int side = 0; //side that the yellow sticker is on
		int pos = 0; //position (1-4) of the yellow sticker
		findNextTopEdge(side, pos);
		int numTurns = 0; //keeps track of how many times we turn the cube to put pieces on the bottom layer so we can undo the turns
		if (side == 1)
		{
			while (_cube[5][1][0] == 0)
			{
				d();
			}
			while (_cube[0][1][0] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				l();
				l();
			}
			else if (pos == 2)
			{
				l();
			}
			else if (pos == 4)
			{
				li();
			}
		}
		else if (side == 2)
		{
			while (_cube[5][0][1] == 0)
			{
				d();
			}
			while (_cube[0][2][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				f();
				f();
			}
			else if (pos == 2)
			{
				f();
			}
			else if (pos == 4)
			{
				fi();
			}
			di();
		}
		else if (side == 3)
		{
			while (_cube[5][1][2] == 0)
			{
				d();
			}
			while (_cube[0][1][2] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				r();
				r();
			}
			else if (pos == 2)
			{
				r();
			}
			else if (pos == 4)
			{
				ri();
			}
			d();
			d();
		}
		else if (side == 4)
		{
			while (_cube[5][2][1] == 0)
			{
				d();
			}
			while (_cube[0][0][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				b();
				b();
			}
			else if (pos == 2)
			{
				b();
			}
			else if (pos == 4)
			{
				bi();
			}
			d();
		}
		else if (side == 5)
		{
			for (int j = 0; j < 4 - pos; j++)
			{
				d();
			}
		}
		for (int j = 0; j < numTurns; j++)
		{
			ui();
		}
		if (side == 5) //algorithm for when the sticker is on the bottom
		{
			int color = _cube[1][2][1];
			for (int a = 1; a < color; a++) //set-up so that the edge goes into the right spot
			{
				u();
			}
			l();
			l();
			for (int a = 1; a < color; a++) //undo set-up
			{
				ui();
			}
		}
		else //algorithm for when th esticker is not on the bottom
		{
			int color = _cube[5][1][0];
			if (color < 4) //set-up so that the sticker goes into the right spot
			{
				for (int a = 1; a < color + 1; a++)
				{
					u();
				}
			}
			l();
			bi();
			li();
			if (color < 4) //undo set-up
			{
				for (int a = 1; a < color + 1; a++)
				{
					ui();
				}
			}
		}
	}
}

void Cube::moveTopEdges() //move all yellow edge stickers on top to the bottom
{
	for (int i = 0; i < 4; i++)
	{
		if (_cube[0][2][1] == 0)
		{
			while (_cube[5][0][1] == 0)
			{
				d();
			}
			f();
			f();
		}
		u();
	}
}

void Cube::findNextTopEdge(int & s, int & p)
{
	for (s = 1; s < 6; s++)
	{
		if (_cube[s][0][1] == 0)
		{
			p = 1;
			break;
		}
		else if (_cube[s][1][2] == 0)
		{
			p = 2;
			break;
		}
		else if (_cube[s][2][1] == 0)
		{
			p = 3;
			break;
		}
		else if (_cube[s][1][0] == 0)
		{
			p = 4;
			break;
		}
	}
}

void Cube::solveTopCorners()
{
	moveTopCorners();
	for (int i = 1; i < 5; i++)
	{
		bool bottom = false; //holds whether the yellow sticker is on the bottom face
		bool rig = false; //holds whether the yellow sticker is on the right face
		int side = 0; //what face the yellow sticker is on
		int pos = 0; //which corner the piece is in
		findNextTopCorner(side, pos);
		if (side < 5) //puts the corner in the back bottom right corner
		{
			if (pos == 2)
			{
				rig = true;
			}
			for (int t = 0; t < side + pos - 1; t++)
			{
				di();
			}
		}
		else //puts the corner in the back bottom right corner
		{
			bottom = true;
			for (int t = 0; t < pos; t++)
			{
				di();
			}
		}
		if (rig) //algorithm for when yellow is on the right
		{
			int color = _cube[4][2][0];
			if (color < 4) //move the top so that the corner goes into the correct position
			{
				for (int t = 0; t < color; t++)
				{
					u();
				}
			}
			r();
			d();
			ri();
			if (color < 4) //undo the setup moves to put the corner in the right position
			{
				for (int t = 0; t < color; t++)
				{
					ui();
				}
			}
		}
		else if (bottom) //algorithm for when yellow is on bottom
		{
			int color = _cube[3][2][2];
			if (color < 4) //move the top so that the corner goes into the correct position
			{
				for (int t = 0; t < color; t++)
				{
					u();
				}
			}
			r();
			d();
			d();
			ri();
			di();
			r();
			d();
			ri();
			if (color < 4) //undo the setup moves to put the corner in the right position
			{
				for (int t = 0; t < color; t++)
				{
					ui();
				}
			}
		}
		else //algorithm for when yellow is on back
		{
			int color = _cube[5][2][2];
			if (color < 4) //move the top so that the corner goes into the correct position
			{
				for (int t = 0; t < color; t++)
				{
					u();
				}
			}
			bi();
			di();
			b();
			if (color < 4) //undo the setup moves to put the corner in the right position
			{
				for (int t = 0; t < color; t++)
				{
					ui();
				}
			}
		}
	}
}

void Cube::moveTopCorners() //moves all yellow corners on the top to the bottom face
{
	for (int i = 0; i < 4; i++)
	{
		if (_cube[0][2][2] == 0 || _cube[2][0][2] == 0 || _cube[3][0][0] == 0)
		{
			while (_cube[1][2][2] == 0 || _cube[2][2][0] == 0 || _cube[5][0][0] == 0) //make sure not to push a different yellow corner back to the top
			{
				d();
			}
			ri();
			d();
			r();
		}
		u();
	}
}

void Cube::findNextTopCorner(int & s, int & p) //locates the next corner that is not in its correct spot (guaranteed to be one of the bottom four corners)
//updates pos and side in solveTopCorners() to hold the side and position of the yellow sticker
{
	for (s = 1; s < 5; s++)
	{
		if (_cube[s][2][0] == 0)
		{
			p = 1;
			return;
		}
		else if (_cube[s][2][2] == 0)
		{
			p = 2;
			return;
		}
	}
	if (_cube[5][0][0] == 0)
	{
		p = 2;
	}
	else if (_cube[5][0][2] == 0)
	{
		p = 3;
	}
	else if (_cube[5][2][2] == 0)
	{
		p = 0;
	}
	else
	{
		p = 1;
	}
}

void Cube::solveMiddleLayer()
{
	int side = -1;
	int color = -1;
	int count = 0;

beginning:
	if (side != -1)
	{
		placeMiddleEdge(color, side);
		//print();
		count++;
		side = -1;
		color = -1;
	}

	for (int i = 1; i <= 4; i++)
	{
		side = findBottomMatch(i);

		if (side != -1)
		{
			color = i;
			goto beginning;
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (_cube[i][1][0] != (i))
		{
			middleAlgorithm(i, 1);
			if(count >= 15)
			{
				solveTopCross();
				solveTopCorners();
			}

			goto beginning;
		}
		else if (_cube[i][1][2] != i)
		{
			middleAlgorithm(i, 2);

			if(count >= 10)
			{
				solveTopCross();
				solveTopCorners();
			}

			goto beginning;
		}
	}

	int done = 0;
}

int Cube::findBottomMatch(int color)
{
	for (int i = 1; i <= 4; i++)
	{
		if (_cube[i][2][1] == color)
		{
			if (i % 2 == 0)
			{
				if (_cube[5][abs(2 - i)][1] != 5)
				{
					return i;
				}
			}
			else
			{
				if (_cube[5][abs(2 - i)][i - 1] != 5)
				{
					return i;
				}
			}
		}
	}

	return -1;
}

void Cube::placeMiddleEdge(int color, int edgeSide)
{
	if (edgeSide - color == 0)
	{
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == 1)
	{
		di();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == 2)
	{
		di();
		di();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == 3)
	{
		d();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == -1)
	{
		d();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == -2)
	{
		d();
		d();
		middleAlgorithm(color, -1);
	}
	else if (edgeSide - color == -3)
	{
		di();
		//print();
		middleAlgorithm(color, -1);
	}
}

void Cube::middleAlgorithm(int color, int direction) //1 - L 2 - R -1 for nothing
{
	if (color == 1)
	{
		if (_cube[5][1][0] == 4 || direction == 1)
		{
			d();
			b();
			di();
			bi();
			di();
			li();
			d();
			l();
		}
		else if (_cube[5][1][0] == 2 || direction == 2)
		{
			di();
			fi();
			d();
			f();
			d();
			l();
			di();
			li();
		}
	}
	else if (color == 2)
	{
		if (_cube[5][0][1] == 1 || direction == 1)
		{
			d();
			l();
			di();
			li();
			di();
			fi();
			d();
			f();
		}
		else if (_cube[5][0][1] == 3 || direction == 2)
		{
			di();
			ri();
			d();
			r();
			d();
			f();
			di();
			fi();
		}
	}
	else if (color == 3)
	{
		if (_cube[5][1][2] == 2 || direction == 1)
		{
			d();
			f();
			di();
			fi();
			di();
			ri();
			d();
			r();
		}
		else if (_cube[5][1][2] == 4 || direction == 2)
		{
			di();
			bi();
			d();
			b();
			d();
			r();
			di();
			ri();
		}
	}
	else if (color == 4)
	{
		if (_cube[5][2][1] == 3 || direction == 1)
		{
			d();
			r();
			di();
			ri();
			di();
			bi();
			d();
			b();
		}
		else if (_cube[5][2][1] == 1 || direction == 2)
		{
			di();
			li();
			d();
			l();
			d();
			b();
			di();
			bi();
		}
	}
}

void Cube::solveBottomLayer()
{
	positionBottomCorners();
	//print();
	positionBottomEdges();
	//print();
	correctBottomCorners();
	//print();
	correctBottomEdges();
	//	print();
}

void Cube::positionBottomCorners()
{
	int dTurns[4];

	int bestNumDTurns = 0;
	int pos1 = -1;
	int pos2 = -1;

	for (int i = 0; i < 4; i++)
	{
		dTurns[i] = numCorrectCorners();

		if (dTurns[i] == 4)
		{
			pos1 = 4;
			bestNumDTurns = i;
			break;
		}
		else if (dTurns[i] < 4 && dTurns[i] > -1)
		{
			if (pos2 == -1)
			{
				pos1 = dTurns[i];
				bestNumDTurns = i;
			}
		}
		else if (dTurns[i] > 4)
		{
			int side1 = dTurns[i] % 10 + 1;
			int side2 = (int)(dTurns[i] / 10) + 1;

			//Corners are next to each other
			if (side2 == (side1 + 1) || side1 == (side2 + 1) || (side2 == 4 && side1 == 1) || (side2 == 1 && side1 == 4))
			{
				pos1 = side1;
				pos2 = side2;
				bestNumDTurns = i;
			}
			else if (pos2 == -1)
			{
				pos1 = side1;
				pos2 = side2;
				bestNumDTurns = i;
			}
		}

		d();
		//print();
	}

	for (int i = 0; i < bestNumDTurns && pos1 != 4; i++)
	{
		d();
	}


	//Finally Ready to start positioning corners with algorithm!!!!! OMG WHO KNEW A BRAIN COULD DO SO MUCH SO EASILY!!!!!

	if (pos1 == 4)
	{
		//One CRAZY lucky scenario, and is the only way to exit this nightmare :D
		return;
	}
	else if (pos2 != -1 && (pos2 == (pos1 + 1) || pos1 == (pos2 + 1) || (pos2 == 4 && pos1 == 1) || (pos2 == 1 && pos1 == 4)))
	{
		int oppFace = pos2 + 3;
		//int face = oppFace + 2;

		if (oppFace > 4)
		{
			oppFace = oppFace - 4;
		}

		swapCorners(oppFace);
		positionBottomCorners();
		return;
	}
	else if (pos2 != -1)
	{
		//Corners opp. corners correct
		int face = pos1 + 4;

		if (face > 4)
		{
			face = face - 4;
		}

		int face2 = face + 1;
		if (face2 > 4)
		{
			face2 = face2 - 4;
		}

		swapCorners(face);
		swapCorners(face2);
		swapCorners(face);
		positionBottomCorners();
		return;
	}
	else
	{
		//Only 1 correct, 3 corners wrong... If thats even posible (I'm 99% positive it isnt the way I set the cube up)?????
		//But just in case
		int face = pos1 + 2;

		if (face > 4)
		{
			face = face - 4;
		}

		swapCorners(face); //Eventually One of the previous situations above will occur :D
		positionBottomCorners();
		return;
	}

}

void Cube::swapCorners(int face)
{
	if (face == 1)
	{
		di();
		fi();
		d();
		b();
		di();
		f();
		d();
		bi();
		di();
	}
	else if (face == 2)
	{
		di();
		ri();
		d();
		l();
		di();
		r();
		d();
		li();
		di();
	}
	else if (face == 3)
	{
		di();
		bi();
		d();
		f();
		di();
		b();
		d();
		fi();
		di();
	}
	else if (face == 4)
	{
		di();
		li();
		d();
		r();
		di();
		l();
		d();
		ri();
		di();
	}
}

int Cube::numCorrectCorners()
{
	//If numCorrect == 4 it will return 4
	//If numCorrect == 2 it will return 2nd Corner * 10 + 1st corner (i.e. 20)
	//Else if numCorrect == 1 it will return pos of corner
	//Else if 0 are correct return -1
	int cornerColors[3];
	int side1 = 0;
	int side2 = 0;

	int count = 0;

	int colorsMatch = 0; //if this equals 2 then there is a match per corner
	int position[4] = { -1, -1, -1, -1 }; //-1 means there is no match, 1 means match

	for (int i = 0; i < 4; i++)
	{
		getCorner(i, cornerColors);

		side1 = i + 1;
		side2 = i + 2;

		if (side2 == 5)
		{
			side2 = 1;
		}

		for (int j = 0; j < 3; j++)
		{
			if (cornerColors[j] == side1 || cornerColors[j] == side2)
			{
				colorsMatch++;
			}
		}

		if (colorsMatch == 2)
		{
			position[i] = 1;
			count++;
		}

		colorsMatch = 0;
	}

	int pos = 0;
	int multiplier = 1;

	if (count == 4)
	{
		return 4;
	}
	else if (count == 2 || count == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (position[i] == 1)
			{
				pos += i * multiplier;
				multiplier *= 10;
			}
		}
	}
	else
	{
		pos = -1;
	}

	return pos;
}

void Cube::getCorner(int num, int corners[])
{
	if (num == 0)
	{
		corners[0] = _cube[1][2][2];
		corners[1] = _cube[2][2][0];
		corners[2] = _cube[5][0][0];
	}
	else if (num == 1)
	{
		corners[0] = _cube[2][2][2];
		corners[1] = _cube[3][2][0];
		corners[2] = _cube[5][0][2];
	}
	else if (num == 2)
	{
		corners[0] = _cube[3][2][2];
		corners[1] = _cube[4][2][0];
		corners[2] = _cube[5][2][2];
	}
	else if (num == 3)
	{
		corners[0] = _cube[4][2][2];
		corners[1] = _cube[1][2][0];
		corners[2] = _cube[5][2][0];
	}
}

void Cube::positionBottomEdges()
{
	int pos = numEdgesInCorrectPos();

	if (pos == 0)
	{
		rotateEdges(2, true);
		positionBottomEdges();
		return;
	}
	else if (pos == 5)
	{
		return;
	}
	else
	{
		bool clockwise = pos > 0;

		int face = abs(pos) + 1;

		if (face > 4)
		{
			face = face - 4;
		}

		rotateEdges(face, clockwise);
		return;
	}
}

int Cube::numEdgesInCorrectPos()
{
	//Note this will either be 1, 0 or 4...
	//It will return 0 if none are in correct position
	//If there is one in correct position it will return the corresponding position pos or neg determining rotation
	//Note positions are determined by what side they match with, 1 - 4
	//Return 5 if all are in position

	int edges[4][2] = { { _cube[5][1][0], _cube[1][2][1] }, { _cube[5][0][1], _cube[2][2][1] }, { _cube[5][1][2], _cube[3][2][1] }, { _cube[5][2][1], _cube[4][2][1] } };

	int correctPos = -1;
	int numCorrect = 0;
	bool isOneCorrect = false;
	int positions[4];

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (edges[i - 1][j] == i)
			{
				isOneCorrect = true;
				correctPos = i - 1;
				numCorrect++;
			}

			if (edges[i - 1][j] != 5)
			{
				positions[i - 1] = edges[i - 1][j];
			}
		}
	}

	if (numCorrect == 4)
	{
		return 5;
	}

	if (isOneCorrect == false)
	{
		return 0;
	}
	else
	{
		bool clockwise = false;
		bool firstTime = true;
		int numTimesThrough = 0;
		numCorrect = 0;
		int temp;
		int temp2;

		while (numCorrect != 4)
		{
			firstTime = true;
			numCorrect = 0;
			for (int i = 0; i < 4; i++)
			{
				if (i != correctPos)
				{
					if (firstTime)
					{
						firstTime = false;
						temp = positions[i];

						int j = i - 1;

						if (j < 0)
						{
							j = 4 + j;
						}

						if (j == correctPos)
						{
							j--;
							if (j < 0)
							{
								j = 4 + j;
							}
						}

						positions[i] = positions[j];
					}
					else
					{
						temp2 = positions[i];
						positions[i] = temp;
						temp = temp2;
					}
				}

				if (positions[i] == i + 1)
				{
					numCorrect++;
				}
			}

			numTimesThrough++;
		}

		clockwise = numTimesThrough == 1;
		correctPos++;

		if (clockwise == false)
		{
			correctPos = -1 * (correctPos);
		}
	}

	return correctPos;
}

void Cube::rotateEdges(int face, bool rotClockwise)
{
	if (face == 1)
	{
		if (rotClockwise == true)
		{
			f();
			f();
			d();
			li();
			r();
			f();
			f();
			l();
			ri();
			d();
			f();
			f();
		}
		else
		{
			f();
			f();
			di();
			li();
			r();
			f();
			f();
			l();
			ri();
			di();
			f();
			f();
		}
	}
	else if (face == 2)
	{
		if (rotClockwise == true)
		{
			r();
			r();
			d();
			fi();
			b();
			r();
			r();
			f();
			bi();
			d();
			r();
			r();
		}
		else
		{
			r();
			r();
			di();
			fi();
			b();
			r();
			r();
			f();
			bi();
			di();
			r();
			r();
		}
	}
	else if (face == 3)
	{
		if (rotClockwise == true)
		{
			b();
			b();
			d();
			ri();
			l();
			b();
			b();
			r();
			li();
			d();
			b();
			b();
		}
		else
		{
			b();
			b();
			di();
			ri();
			l();
			b();
			b();
			r();
			li();
			di();
			b();
			b();
		}
	}
	else if (face == 4)
	{
		if (rotClockwise == true)
		{
			l();
			l();
			d();
			bi();
			f();
			l();
			l();
			b();
			fi();
			d();
			l();
			l();
		}
		else
		{
			l();
			l();
			di();
			bi();
			f();
			l();
			l();
			b();
			fi();
			di();
			l();
			l();
		}
	}
}

void Cube::correctBottomCorners()
{
	int result = cornerOrientation();

	while (result != 5)
	{
		twoCornerRotate(abs(findBestFace(result)), findBestFace() > 0);

		result = cornerOrientation();
	}
}

int Cube::cornerOrientation()
{
	int numCorrect = 0;
	int wrongPosition = 0;

	int corners[4] = { _cube[5][0][0], _cube[5][0][2], _cube[5][2][2], _cube[5][2][0] };

	for (int i = 0; i < 4; i++)
	{
		if (corners[i] == 5)
		{
			numCorrect++;
		}
		else
		{
			wrongPosition = i;
		}
	}

	if (numCorrect == 4)
	{
		return 5;
	}

	return wrongPosition;
}

int Cube::findBestFace(int cornerNum)
{
	int corners[4] = { _cube[5][0][0], _cube[5][0][2], _cube[5][2][2], _cube[5][2][0] };

	int corner1 = cornerNum + 1;
	int corner2= cornerNum - 1;

	if (corner1 > 3)
	{
		corner1 = 4 - corner1;
	}

	if (corner2< 0)
	{
		corner2= 4 + corner2;
	}

	//First Determine which corner to go with
	int finalCorner = -1;
	int face = -1;

	if (corners[cornerNum] == corners[corner1])
	{
		finalCorner = corner1;

		face = corners[finalCorner] + 1;

		if (face > 4)
		{
			face = face - 4;
		}

		return face;
	}
	else if (corners[cornerNum] == corners[corner2])
	{
		finalCorner = corner2;

		face = corners[finalCorner] + 1;

		if (face > 4)
		{
			face = face - 4;
		}

		return face;
	}
	else if (abs(corners[cornerNum] - corners[corner1]) == 2 && corners[corner1] != 5)
	{
		finalCorner = corner1;
		face = corners[finalCorner];
		return -face;
	}
	else if (abs(corners[cornerNum] - corners[corner2]) == 2 && corners[corner2] != 5)
	{
		finalCorner = corner2;
		face = corners[cornerNum];
		return -face;
	}
	else
	{
		face = corners[cornerNum];
		return face;
	}
}

void Cube::twoCornerRotate(int face, bool goForward)
{
	if (face == 1)
	{
		if (goForward == true)
		{
			bi();
			u();
			b();
			l();
			u();
			li();
			d();
			l();
			ui();
			li();
			bi();
			ui();
			b();
			di();
		}
		else
		{
			d();
			bi();
			u();
			b();
			l();
			u();
			li();
			di();
			l();
			ui();
			li();
			bi();
			ui();
			b();
		}
	}
	else if (face == 2)
	{
		if (goForward == true)
		{
			li();
			u();
			l();
			f();
			u();
			fi();
			d();
			f();
			ui();
			fi();
			li();
			ui();
			l();
			di();
		}
		else
		{
			d();
			li();
			u();
			l();
			f();
			u();
			fi();
			di();
			f();
			ui();
			fi();
			li();
			ui();
			l();
		}
	}
	else if (face == 3)
	{
		if (goForward == true)
		{
			fi();
			u();
			f();
			r();
			u();
			ri();
			d();
			r();
			ui();
			ri();
			fi();
			ui();
			f();
			di();
		}
		else
		{
			d();
			fi();
			u();
			f();
			r();
			u();
			ri();
			di();
			r();
			ui();
			ri();
			fi();
			ui();
			f();
		}
	}
	else if (face == 4)
	{
		if (goForward == true)
		{
			ri();
			u();
			r();
			b();
			u();
			bi();
			d();
			b();
			ui();
			bi();
			ri();
			ui();
			r();
			di();
		}
		else
		{
			d();
			ri();
			u();
			r();
			b();
			u();
			bi();
			di();
			b();
			ui();
			bi();
			ri();
			ui();
			r();
		}
	}
}

void Cube::correctBottomEdges()
{
	int edges[4] = { _cube[5][1][0], _cube[5][0][1], _cube[5][1][2], _cube[5][2][1] };

	bool isTogether = false;
	bool isStart = false;
	int numWrong = 0;
	int pos1 = -1;
	int pos2 = -1;
	int j = 0;

	for (int i = 0; i < 5; i++)
	{
		j = i;

		if (i == 4)
		{
			j = 0;
		}

		if (edges[j] != 5)
		{
			numWrong++;
			if (isStart == false)
			{
				pos1 = j;
				isStart = true;
			}
			else
			{
				pos2 = j;
				isTogether = true;
			}
		}
		else
		{
			isStart = false;
		}
	}

	if (numWrong >= 4)
	{
		twoEdgeRotate(1, false);
		twoEdgeRotate(2, false);
		return;
	}
	else
	{
		if(pos2 != -1)
		{
			twoEdgeRotate(pos2 + 1, isTogether);
		}
		else
		{
			twoEdgeRotate(pos1 + 1, isTogether);
		}
		return;
	}
}

void Cube::twoEdgeRotate(int face, bool isNextTo)
{
	if (face == 1)
	{
		if (isNextTo == true)
		{
			l();
			ui();
			d();
			f();
			f();
			d();
			d();
			u();
			u();
			b();
			d();
			bi();
			u();
			u();
			d();
			d();
			f();
			f();
			di();
			u();
			li();
			di();
		}
		else
		{
			l();
			ui();
			d();
			f();
			f();
			d();
			d();
			u();
			u();
			b();
			d();
			d();
			bi();
			u();
			u();
			d();
			d();
			f();
			f();
			di();
			u();
			li();
			di();
			di();
		}
	}
	else if (face == 2)
	{
		if (isNextTo == true)
		{
			f();
			ui();
			d();
			r();
			r();
			d();
			d();
			u();
			u();
			l();
			d();
			li();
			u();
			u();
			d();
			d();
			r();
			r();
			di();
			u();
			fi();
			di();
		}
		else
		{
			f();
			ui();
			d();
			r();
			r();
			d();
			d();
			u();
			u();
			l();
			d();
			d();
			li();
			u();
			u();
			d();
			d();
			r();
			r();
			di();
			u();
			fi();
			di();
			di();
		}
	}
	else if (face == 3)
	{
		if (isNextTo == true)
		{
			r();
			ui();
			d();
			b();
			b();
			d();
			d();
			u();
			u();
			f();
			d();
			fi();
			u();
			u();
			d();
			d();
			b();
			b();
			di();
			u();
			ri();
			di();
		}
		else
		{
			r();
			ui();
			d();
			b();
			b();
			d();
			d();
			u();
			u();
			f();
			d();
			d();
			fi();
			u();
			u();
			d();
			d();
			b();
			b();
			di();
			u();
			ri();
			di();
			di();
		}
	}
	else if (face == 4)
	{
		if (isNextTo == true)
		{
			b();
			ui();
			d();
			l();
			l();
			d();
			d();
			u();
			u();
			r();
			d();
			ri();
			u();
			u();
			d();
			d();
			l();
			l();
			di();
			u();
			bi();
			di();
		}
		else
		{
			b();
			ui();
			d();
			l();
			l();
			d();
			d();
			u();
			u();
			r();
			d();
			d();
			ri();
			u();
			u();
			d();
			d();
			l();
			l();
			di();
			u();
			bi();
			di();
			di();
		}
	}
}

//-----------------------------------------------//
//----------------other Functions----------------//
//-----------------------------------------------//

void Cube::printCube()
{
	for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "    ";
				for (int k = 0; k < 3; k++)
				{
					cout << _cube[i][j][k];
				}
				cout << endl;
			}
		}cout << endl;

	for (int j = 0; j < 3; j++)
		{
			for (int i = 1; i < 5; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					cout << _cube[i][j][k];
				}
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;

	for (int i = 5; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "    ";
				for (int k = 0; k < 3; k++)
				{
					cout << _cube[i][j][k];
				}
				cout << endl;
			}
		}cout << endl;
}

// void TempCube::printCube()
// {
// 	for (int i = 0; i < 1; i++)
// 		{
// 			for (int j = 0; j < 3; j++)
// 			{
// 				cout << "    ";
// 				for (int k = 0; k < 3; k++)
// 				{
// 					cout << _tmp_cube[i][j][k];
// 				}
// 				cout << endl;
// 			}
// 		}cout << endl;

// 	for (int j = 0; j < 3; j++)
// 		{
// 			for (int i = 1; i < 5; i++)
// 			{
// 				for (int k = 0; k < 3; k++)
// 				{
// 					cout << _tmp_cube[i][j][k];
// 				}
// 				cout << " ";
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;

// 	for (int i = 5; i < 6; i++)
// 		{
// 			for (int j = 0; j < 3; j++)
// 			{
// 				cout << "    ";
// 				for (int k = 0; k < 3; k++)
// 				{
// 					cout << _tmp_cube[i][j][k];
// 				}
// 				cout << endl;
// 			}
// 		}cout << endl;
// }


void Cube::printMoves(){
	cout << moves << endl;
}

void Cube::copyCube()
{

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				_old[i][j][k] = _cube[i][j][k];

			}
		}
	}
}

string Cube::last()
{
	if (moves.size() < 3)
	{
		return "";
	}
	int s = moves.size();
	return moves.substr(s - 3, 3);
}

void Cube::removeLast()
{
	if (moves.size() < 3)
	{
		return;
	}
	int s = moves.size();

	
	moves = moves.substr(0, s - 3);
}

void Cube::clearMoves()
{
	moves.clear();
}

void Cube::scramble()
{
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		int num = rand() % 12 + 1;
		switch (num)
		{
			case 1: r(); break;
			case 2: ri(); break;
			case 3: u(); break;
			case 4: ui(); break;
			case 5: f(); break;
			case 6: fi(); break;
			case 7: l(); break;
			case 8: li(); break;
			case 9: b(); break;
			case 10: bi(); break;
			case 11: d(); break;
			case 12: di(); break;
		}
	}
}

void/* MY NAME IS */ Cube::solveCube(){
	//clearMoves();
	cout << "scrambled:" << endl;
	printCube();
	solveTopCross();
	cout << "Top Cross " << endl;
	printMoves();

	//clearMoves();
	printCube();
	solveTopCorners();
	cout << "Corners " << endl;
	printMoves();

	//clearMoves();
	printCube();
	solveMiddleLayer();
	cout << "Middle Layer " << endl;
	printMoves();

	//clearMoves();
	printCube();
	solveBottomLayer();
	cout << "Bottom Layer " << endl;
	printMoves();
	//clearMoves();
	printCube();

}

// cube questions //
	int Cube::array_to_int(int i_1, int j_1, int k_1 )
	{
		int counter = 0;
		for (int i = 0; i < 6 ;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				counter++;
			if( i == i_1 && j_1 == j && k_1 == k)
				{
					return counter;
				}
			}
		}

	}
		return 100000;
	}

	int Cube::int_to_array( int counter)
	{
		int question_array[55] = { 0,
1,
2,
10,
11,
12,
20,
21,
22,
100,
101,
102,
110,
111,
112,
120,
121,
122,
200,
201,
202,
210,
211,
212,
220,
221,
222,
300,
301,
302,
310,
311,
312,
320,
321,
322,
400,
401,
402,
410,
411,
412,
420,
421,
422,
500,
501,
502,
510,
511,
512,
520,
521,
522};
		return question_array[counter];
	}
// cube questions end //

//-----------------------------------------------//
//---------------Question/Answer-----------------//
//-----------------------------------------------//

/*void Cube::mapColor()
{

}
*/
vector< pair<int, pair<int, int> > > _ecken; //wird global als auflistung für alle zusammenhangenden Ecken benotigt

void init_Ecken(){ //einmalige initialisierung aller zusammenhangenden Felder zu Ecken
	_ecken.push_back(make_pair(0, make_pair(9, 38)));
	_ecken.push_back(make_pair(2, make_pair(29, 36)));
	_ecken.push_back(make_pair(6, make_pair(11, 18)));
	_ecken.push_back(make_pair(8, make_pair(20, 27)));
	_ecken.push_back(make_pair(45, make_pair(24, 17)));
	_ecken.push_back(make_pair(47, make_pair(33, 26)));
	_ecken.push_back(make_pair(51, make_pair(15, 44)));
	_ecken.push_back(make_pair(53, make_pair(35, 42)));
}

vector<pair<int, int>> getAdjecentEcken(int pos){ //returniert einen vector mit den angrenzenden 2 Ecken des abgefragten Felds
	vector<pair<int, int>> vec;

	for (int i=0; i<_ecken.size(); i++){
		//cout << _ecken[i].first << ", " << _ecken[i].second.first
    		// << ", " << _ecken[i].second.second << endl;//kontrollausgabe
		if(_ecken[i].first==pos) //Die anderen 2 Felder herrausfinden und zurückgeben
		{
			vec.push_back(make_pair(_ecken[i].second.first,_ecken[i].second.second));
			//cout<< "\n--" << _ecken[i].second.first << " "<<_ecken[i].second.second<< endl;
		}
		else if(_ecken[i].second.first==pos)
		{
			vec.push_back(make_pair(_ecken[i].first,_ecken[i].second.second));
			//cout<< "\n--" << _ecken[i].first << " "<<_ecken[i].second.second<< endl;
		}
		else if(_ecken[i].second.second==pos)
		{
			vec.push_back(make_pair(_ecken[i].first,_ecken[i].second.first));
			//cout<< "\n--" << _ecken[i].first << " "<<_ecken[i].second.first<< endl;
		}
	}
	return vec;
}

int Cube::getColor(int pos){//holt die eingetragene Farbe aus dem cube
	int it=0;
	for(int a=0; a<6; a++){
		for(int b=0; b<3; b++){
			for(int c=0; c<3; c++){
				if(it == pos){
						return this->_cube[a][b][c];
				}
				it++;
			}
		}
	}
}
bool isEcke(int z){
  int qPosE[]={0,2,6,8,9,11,15,17,18,20,24,26,27,29,33,35,36,38,42,44,45,47,51,53};
  int *i = find(std::begin(qPosE), std::end(qPosE), z);
  if (i != std::end(qPosE)) {
    return true;
  } else {
    return false;
  }
}

bool isKante(int z){
  int qPosK[]={1,3,5,7,10,12,14,16,19,21,23,25,28,30,32,34,37,39,41,43,46,48,50,52};
  int *i = find(std::begin(qPosK), std::end(qPosK), z);
  if (i != std::end(qPosK)) {
    return true;
  } else {
    return false;
  }
}

bool isMitte(int z){
  int qPosM[]={4,13,22,31,40,49};
  int *i = find(std::begin(qPosM), std::end(qPosM), z);
  if (i != std::end(qPosM)) {
    return true;
  } else {
    return false;
  }
}

int Cube::middleIndexOf(int pos){ //holt sich die nummer des mittelfelds der Seite auf der die gefragt Position ist

	if(pos>=0&&pos<=8)
		return 4;
	if(pos>8&&pos<=17)
		return 13;
	if(pos>18&&pos<=26)
		return 22;
	if(pos>27&&pos<=35)
		return 31;
	if(pos>=36&&pos<=44)
		return 40;
	if(pos>=45&&pos<=53)
		return 49;
}
multimap <int,int> _kanten; //globale kanten

void init_Kanten(){ //multimap aller Kanten und deren Felder anlegen
	_kanten.insert( pair <int,int> (1,37));
	_kanten.insert( pair <int,int> (3,10));
	_kanten.insert( pair <int,int> (5,28));
	_kanten.insert( pair <int,int> (7,19));
	_kanten.insert( pair <int,int> (10,3));
	_kanten.insert( pair <int,int> (12,41));
	_kanten.insert( pair <int,int> (14,21));
	_kanten.insert( pair <int,int> (16,48));
	_kanten.insert( pair <int,int> (19,7));
	_kanten.insert( pair <int,int> (21,14));
	_kanten.insert( pair <int,int> (23,30));
	_kanten.insert( pair <int,int> (25,46));
	_kanten.insert( pair <int,int> (28,5));
	_kanten.insert( pair <int,int> (30,23));
	_kanten.insert( pair <int,int> (32,39));
	_kanten.insert( pair <int,int> (34,50));
	_kanten.insert( pair <int,int> (37,1));
	_kanten.insert( pair <int,int> (39,32));
	_kanten.insert( pair <int,int> (41,12));
	_kanten.insert( pair <int,int> (43,52));
	_kanten.insert( pair <int,int> (46,25));
	_kanten.insert( pair <int,int> (48,16));
	_kanten.insert( pair <int,int> (50,34));
	_kanten.insert( pair <int,int> (52,43));
}

int getAdjecentKante(int pos){ //angrenzende Kante aus der Liste finden
  return _kanten.find(pos)->second;
}

string randomizeFeedback(string s){ //randomisiert den von der generateMastermindAnswer Methode erstellten Feedbackstring
	string randFeedback, feedback=s;
  int num =0;
  list<int> my_list;
  list<int>::iterator it;

  for(int i=0;i<feedback.length();i++){
    randFeedback.append("0");
  }

  for(int i=0;i<feedback.length();i++){

  while(find(my_list.begin(), my_list.end(), num)!=my_list.end()){
    num = rand() % feedback.length();
    //cout<<num;
  }
    my_list.push_back(num);
    randFeedback[i]=feedback[num];
  }
  //cout<< "\n fkt: "<<randFeedback;

  return randFeedback;
}


//bis hier Matthias 7.2.20

string Cube::splitQuestion(string s, int n) //by Isabella Reithner
{
	// cout<< "--Entering splitQ"<<endl;
	int pos = 0; //Position
	char color = ' '; //Farbe
	int question[n]; //Farbe aus der Frage
	int groundTruth[n]; //Farbe im verdrehten (übergebenen) Würfel
	string tmp; //temporärer Speichererort des gespaltenen Strings
	int cnt = 0; //counter
	int it = 0; //Zähler für Iterationen (ebenfalls ein Counter)
	//von Matthias Anfang
	int white=0; //Zähler für Richte Farbe am Falschen Platz
	int black=0; //Zähler Richtige Farbe richtiger Platz
	string feedback;
	int qPos[n], qCol[n], gtPos[n], gtCol[n];

	init_Kanten();//wir jedes mal beim Feedback request neu initialisiert->Performance?
	init_Ecken();
	int h=0;//ungut,, listen bzw vektoren wären besser

	for(int j=0; j<n*3; j+=3){ //Spalten der Frage in Position und Farbe
		it = 0;
		int pos1=((int)(s[j])-'0');
		int pos2=(int)(s[j+1])-'0';
		pos = pos1*10+pos2;

		color = s[j+2];
		int farbe = (int)(color)-48;//ASCII-Zahl um 48 verschieben
		qPos[h]=pos;
		qCol[h]=farbe;

//Durchgehen des übergebenen Würfels
		for(int a=0; a<6; a++){ //Seite
			for(int b=0; b<3; b++){ //Zeile
				for(int c=0; c<3; c++){ //Spalten
					if(it == pos){ //Wenn die Position befunden wurde, Farbe in reference schreiben
						gtPos[h]=pos;
						gtCol[h]=this->_cube[a][b][c];
						//cout<<"it: " << h << ". gt an Position: "<< gtPos[h]<<" hat Farbe "<< gtCol[h] << ". Zu Farbe in Question: "<<qCol[h] <<endl;
					}
					it++;
				}
			}
		}
		cnt++;
		h++;
	}

	return	this->generateMastermindAnswer(&qPos[0],&qCol[0],n);

}

//generateMastermindAnswer here
string Cube::generateMastermindAnswer(int* qPos, int *qCol, int n ){
	string randFeedback;
	int num =0;
	list<int> my_list;
	list<int>::iterator it;
	bool b;
	string feedback;

	for(int i=0;i<n;i++){
		//cout<<"\nqPos["<<i<<"] "<< qPos[i];

		if(isMitte(qPos[i]))
		{ //cout<<" m ";
			if(qCol[i]==getColor(middleIndexOf(qPos[i])))//Wenn die Farbe aus der Frage vom aktuellen Mittelfeld gleich der Farbe an der seleben Stelle im scrambeld Cube
			{
				//cout<<"b";
				feedback.append("1");
			}else{
				feedback.append("2");//x
			}
		}

		if(isKante(qPos[i]))
		{//cout<<"k";

			if(qCol[i]==getColor(qPos[i])){// weiß
				if(qCol[i]==getColor(middleIndexOf(qPos[i]))&&getColor(getAdjecentKante(qPos[i]))==getColor(middleIndexOf(getAdjecentKante(qPos[i])))){
					feedback.append("1");//schwarz
				}else{
					feedback.append("0");//weiß
				}
			}
			else
			{
					//cout<<"x";
					feedback.append("2");
			}
		}

		if(isEcke(qPos[i]))
		{
			// cout<<" e ";
			int a,b;
			vector<pair<int,int>> adjEcken;
			adjEcken=getAdjecentEcken(qPos[i]);
			a=adjEcken[0].first;
			b=adjEcken[0].second;
			//cout<< "--a: "<< a << " b: "<<b<<endl;
			bool s1,s2,s3;

			if(qCol[i]==getColor(qPos[i])) s1=true; else s1=false;
				//cout<<s1;
			if(getColor(a)==getColor(middleIndexOf(a))) s2=true; else s2=false;
				//cout<<s2;
			if(getColor(b)==getColor(middleIndexOf(b))) s3=true; else s3=false;
				//cout<<s3;


			if(qCol[i]==getColor(qPos[i]))
			{
				if(s1==true&&s2==true&&s3==true){
					feedback.append("1");//b
				}else{
					feedback.append("0");
				}
			}
			else
			{
				feedback.append("2");//x
			}
		}
	}
	//cout <<"\nFeedback: "<< feedback<<endl;
		//randomize feedbackstring
	string temp=randomizeFeedback(feedback);
	// cout<<"Randomisiertes Feedback: "<<feedback <<endl;
	return temp;

}

//-------------------------BayesGuesser----------------------//
//farben fix und positionen raten
//3 stelligen() mit 9 stelligen(t)(hat 3 mal die farbe 4) array vergleichen. suchen wo diese 3 4er sind
void showlist2(list <int> g)
{
    list <int> :: iterator it;
    
    for(it = g.begin(); it != g.end(); ++it){
        cout << *it;
    cout << " ";}
}

void showPositionList(list <vector<int>> g)
{int z=0;
list <vector<int>> :: iterator it;

  for(it = g.begin(); it != g.end(); ++it){
    if(z%2==0)cout<< "\n";

	  vector<int> actual_vector = *it;
	   for (int i = 0; i < actual_vector.size(); i++) {
			 if(actual_vector.at(i)<10)
			 		cout<< "0";
		   std::cout << actual_vector.at(i) << " ";
       z++;
	   }
	   cout << "  ";

  }

}


void Cube::alot_like_alotlot(int n)
{
	//fill color array
	//big_color_array
	//list<vector<int>> positionen; existiert in .h
	vector <int> farb;
	int randy;

	for(int big = 0; big < 5000; big++)
	{
		farb.clear();
		for(int i=0;i<n;i++)
	    {	//hier wird der index des arrays t erstellt, anden die abzufragende Farbe 4 ist
	      //pos[i] = rand() % t_size;
				randy = rand() % 6;
				farb.push_back(randy);

	      //cout<<" "<<farb[i];
				//7 0 13 24 10 mit Farbarray {00000}
				//7 0 11 20 50

	    }
	   positionen.push_back(farb);
	}

	//showPositionList(positionen);
}


void Cube::showPositionList(list <vector<int>> g)
{
	int z=0;
	list <vector<int>> :: iterator it;

  for(it = g.begin(); it != g.end(); ++it){
    if(z%2==0)cout<< "\n";

	  vector<int> actual_vector = *it;
	   for (int i = 0; i < actual_vector.size(); i++) {
			 if(actual_vector.at(i)<10)
			 		cout<< "0";
		   std::cout << actual_vector.at(i) << " ";
       z++;
	   }
	   cout << "  ";

  }

}


int Cube::amountWandBofPosAndCol(int *farb,int *PosArray,int n){
  int counter=0;
  string question, feedback;

  for(int k=0;k<n;k++){
		if(PosArray[k]<10)
			question.append(to_string(0));

		question.append(to_string(PosArray[k]));
		//cout<< " posk"<<pos[k];
    //question.append(to_string(getColor(pos[k]))); die zeile mit der darunter mach keinen sinn!?
    question.append(to_string(farb[k]));
		//cout<<"\ngenerate question in process: "<<question<<endl;
  }
	//cout<<"Question to check: "<<question<<endl;

//Frage an Server schicken und Feedback evaluieren?

  //feedback=splitQuestion(question,n);//getfeedback

	// Hier liste aufrufen und das jeweilige Feedback zu einer Frage haben


  int b=count(feedback.begin(), feedback.end(), '1');
  int w=count(feedback.begin(), feedback.end(), '0');
//	cout<<"b "<<b <<" w "<<w<<endl;
  //return (b*10)+w;
	return b+w;
}



string Cube::bayes_guesser(int n,int bayes_wurde_gefragt){
cout<<"+bayesguessser";
  list<int> wert; //positionen ist pos-array, wert ist der counter
  vector<int> w;
  int M = 1000;
  //int farb[n];
  int counter=0;//anzahl w und s

  //float cutoff= n*0.9;
	//int cutoff=static_cast<int>(n*0.9);
  int cutoff=bayes_wurde_gefragt;
	//cout<<"cutoff eingeben";
	//cin>>cutoff;
  //z=(int)cutoff;//funktioniert??
  int check = 0;



/* ich hab dich 1000 mal gefragt
  for(int z=0;z<M;z++){//++++++++++++++BEGIN OF FOR
    counter = 0;
    vector<int> p;

			cout << "farbi: ";
	    for(int i=0;i<n;i++)
	    {	//hier wird der index des arrays t erstellt, anden die abzufragende Farbe 4 ist
	      //pos[i] = rand() % t_size;
				farb[i] = rand() % 6;
	      //cout<<" "<<farb[i];
				//7 0 13 24 10 mit Farbarray {00000}
				//7 0 11 20 50

	    }
			cout<<"\n";

    //Guess = pos[] verschmelzt mit farb[]

    cout<<"\n";


    /*for(int i=0;i<n;i++){	//counter steht für Anzahl BLACK und WHITE vom Feedbackstring
      if(t[pos[i]]==4){
        counter++;
      } //wird ersetzt durch:

    }
		cout<<"++Entering-amountWandBofPosAndCol"<<endl;
    counter = amountWandBofPosAndCol(&farb[0],&posArray[0],n);
		if(counter>=cutoff)
			cout << "\033[1;31mCounter\033[0m";

		cout<<"Counter: "<<counter<<endl;
		cout<<"--Leaving-amountWandBofPosAndCol\n"<<endl;
    //for (int i = 0; i < p.size(); i++)
      //  cout << p[i] << " ";
		for(int i=0;i<n;i++)
			p.push_back(farb[i]);

		//cout<<"\nCutoff: "<<cutoff<<endl;
    if(counter>=cutoff){//gute guesses behalten
      positionen.push_back(p);
      wert.push_back(counter);
    }
  }//+++++++++++++++++++++END OF FOR. bis hier wird gefüllt

*/ // Tausendmal hast du zu recht nein gesagt







  // cout<<"B_Gpositionen.size():"<<positionen.size()<<" "<<endl;
  // cout << "B_Gpositionen: "<<endl;

  // showPositionList(positionen);


  //cout<< "counter: "<<endl;
  //showlist2(wert);
  vector<int> bestGuess;
  int max=0,haeufigste=0;

  for(int u=0;u<n;u++)
  {
  //++++++++++++++++++BEGIN OF FOR
  	max=0;
    // cout<<"\n--u = "<<u;
    list <vector<int>> :: iterator iterator;
    vector<int> spalte;
		int zahlVar=0;
		vector<int> viele_feedbacks;

		list <int> :: iterator vf_it;
    for(vf_it = Mehrere_feedbacks.begin(); vf_it != Mehrere_feedbacks.end(); ++vf_it)
        viele_feedbacks.push_back(*vf_it);

    for(iterator = positionen.begin(); iterator != positionen.end(); ++iterator)
    {
			if(viele_feedbacks[zahlVar]>=cutoff){//!!!!!!!//Mehrere_feedbacks soll vector werden!!!!
				vector<int> actual_vector = *iterator;
      	//cout<< "\nactual_vector " << actual_vector.at(l);
      	spalte.push_back(actual_vector.at(u));
			}
			zahlVar++;
    }

    int i,last,temp;
    sort(spalte.begin(),spalte.end());//vector sortieren, damit einfacher evaluiert werden kann
		/*for(int i=0;i<spalte.size();i++){
			cout<<spalte[i];
		}
		cout<<endl;*/

		 //cout<<"\n--spalte.size(): "<<spalte.size();
    for(i=0;i<spalte.size();i++){
      int zahl=spalte.at(i);

      if(last!=zahl) {
        int count = std::count(spalte.begin(),spalte.end(),spalte.at(i));
        //cout<<"\nZahl "<<spalte.at(i)<<" kommt " << count << " mal vor";
          if(count>max){
            max=count;
            haeufigste=spalte.at(i);
          }
          count=0;//counter für die nächste  zählung zurücksetzten
      }
      last=zahl;//sicherung, damit kein wert doppelt gezählt wird
    }
    //cout<<"check";
    spalte.clear();//spaltenvector leeren, da ansonst alle anderen spalten dazugesepcihert werden;
    //cout<< "\nhaeufigste Zahl: "<<haeufigste<< endl;
    bestGuess.push_back(haeufigste);
    //cout<<"c"<<endl;
  }//+++++++++++++++++++++++++++++END OF FOR


	cout <<"bestGuess " <<endl;
	




	guess = "";
	for (int i = 0; i < bestGuess.size(); i++)
	  {
	  	 //	cout << bestGuess.at(i) << " " <<endl;
	  		guess.append(to_string(bestGuess[i]));
	  }
cout<<"bestGuess" << guess <<endl;




	return guess;

	/*cout<<"\nColors of numbers in bestGuess:\n";
	for (int i = 0; i < bestGuess.size(); i++)
		cout << getColor(bestGuess[i]) << " ";*/

	/*cout<<"\nPosArray \n";
	for (int i = 0; i < bestGuess.size(); i++)
				cout << posArray[i] << " ";*/

}

//-------------------------BayesGuesser----------------------//


//-----------------------------------------------//
//---------------- Switch Edges -----------------//
//-----------------------------------------------//

void Cube::switchEdges(int top, bool direction){ //destroys corners!!!!
	//direction - 0 left; 1 right

	if(top==0) //orientiere Cube mit benötigter Fläche oben
		; //nothing;
	else if(top==1){
		globalRotationR();
		globalRotationU();
	}
	else if(top==2){
		globalRotationU();
	}
	else if(top==3){
		globalRotationL();
		globalRotationU();
	}
	else if(top==4){
		globalRotationR();
		globalRotationR();
		globalRotationU();
	}
	else if(top==5){
		globalRotationU();
		globalRotationU();
	}

	if(direction==0){ // left
		r();
		u();
		ri();
		u();
		r();
		u();
		u();
		ri();
		u();
	}
	else if(direction==1){ //right
		l();
		ui();
		li();
		ui();
		l();
		ui();
		ui();
		li();
		ui();
	}

	if(top==0) //Bringe Cube in globale Ausgangslage zurück
		; //nothing;
	else if(top==1){
		globalRotationD();
		globalRotationL();
	}
	else if(top==2){
		globalRotationD();
	}
	else if(top==3){
		globalRotationD();
		globalRotationR();
	}
	else if(top==4){
		globalRotationD();
		globalRotationL();
		globalRotationL();
	}
	else if(top==5){
		globalRotationU();
		globalRotationU();
	}
}

bool Cube::isCorrectEdge(int position){
	//return 1 wenn edge an richtiger position
	//return 0 wenn edge an falscher position
	switch(position){
		case 1:
			if(getColor(1) == getColor(4) && getColor(37) == getColor(40))
				return 1;
			else return 0;
			break;
		case 3:
			if(getColor(3) == getColor(4) && getColor(10) == getColor(13))
				return 1;
			else return 0;
			break;
		case 5:
			if(getColor(5) == getColor(4) && getColor(28) == getColor(31))
				return 1;
			else return 0;
			break;
		case 7:
			if(getColor(7) == getColor(4) && getColor(19) == getColor(22))
				return 1;
			else return 0;
			break;
		case 10:
			if(getColor(10) == getColor(13) && getColor(3) == getColor(4))
				return 1;
			else return 0;
			break;
		case 12:
			if(getColor(12) == getColor(13) && getColor(41) == getColor(40))
				return 1;
			else return 0;
			break;
		case 14:
			if(getColor(14) == getColor(13) && getColor(21) == getColor(22))
				return 1;
			else return 0;
			break;
		case 16:
			if(getColor(16) == getColor(13) && getColor(48) == getColor(49))
				return 1;
			else return 0;
			break;
		case 19:
			if(getColor(19) == getColor(22) && getColor(7) == getColor(4))
				return 1;
			else return 0;
			break;
		case 21:
			if(getColor(21) == getColor(22) && getColor(14) == getColor(13))
				return 1;
			else return 0;
			break;
		case 23:
			if(getColor(23) == getColor(22) && getColor(30) == getColor(31))
				return 1;
			else return 0;
			break;
		case 25:
			if(getColor(25) == getColor(22) && getColor(46) == getColor(49))
				return 1;
			else return 0;
			break;
		case 28:
			if(getColor(28) == getColor(31) && getColor(5) == getColor(4))
				return 1;
			else return 0;
			break;
		case 30:
			if(getColor(30) == getColor(31) && getColor(23) == getColor(22))
				return 1;
			else return 0;
			break;
		case 32:
			if(getColor(32) == getColor(31) && getColor(39) == getColor(40))
				return 1;
			else return 0;
			break;
		case 34:
			if(getColor(34) == getColor(31) && getColor(50) == getColor(49))
				return 1;
			else return 0;
			break;
		case 37:
			if(getColor(37) == getColor(40) && getColor(1) == getColor(4))
				return 1;
			else return 0;
			break;
		case 39:
			if(getColor(39) == getColor(40) && getColor(32) == getColor(31))
				return 1;
			else return 0;
			break;
		case 41:
			if(getColor(41) == getColor(40) && getColor(12) == getColor(13))
				return 1;
			else return 0;
			break;
		case 43:
			if(getColor(43) == getColor(40) && getColor(52) == getColor(49))
				return 1;
			else return 0;
			break;
		case 46:
			if(getColor(46) == getColor(49) && getColor(25) == getColor(22))
				return 1;
			else return 0;
			break;
		case 48:
			if(getColor(48) == getColor(49) && getColor(16) == getColor(13))
				return 1;
			else return 0;
			break;
		case 50:
			if(getColor(50) == getColor(49) && getColor(34) == getColor(31))
				return 1;
			else return 0;
			break;
		case 52:
			if(getColor(52) == getColor(49) && getColor(43) == getColor(40))
				return 1;
			else return 0;
			break;
		default:
			return -1;
	}
}

void Cube::findSwitchableEdges(){
	int cnt = 0;
	int positions[4] = {-1};
	int pos = 0;

	for(int i=0; i<6; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				cnt ++;
				if(isKante(cnt) == 1 && _cube[i][j][k]!=-1 && isCorrectEdge(cnt) == 0){
					cout << "got it at " << cnt << endl;
					positions[pos] = cnt;
					pos++;
					//Do the moves
				}
				cnt ++;
			}
		}
	}
}


int Cube::findTopEdgePos(int side, int pos){
	int s, p;
	for (s = 1; s < 6; s++)
	{
		if (_cube[s][0][1] == 0)
		{
			p = 1;
			return p;
			break;
		}
		else if (_cube[s][1][2] == 0)
		{
			p = 2;
			return p;
			break;
		}
		else if (_cube[s][2][1] == 0)
		{
			p = 3;
			return p;
			break;
		}
		else if (_cube[s][1][0] == 0)
		{
			p = 4;
			return p;
			break;
		}
	}
}
int Cube::findTopEdgeSide(int side, int pos){
	int s, p;
	for (s = 1; s < 6; s++)
	{
		if (_cube[s][0][1] == 0)
		{
			p = 1;
			return s;
			break;
		}
		else if (_cube[s][1][2] == 0)
		{
			p = 2;
			return s;
			break;
		}
		else if (_cube[s][2][1] == 0)
		{
			p = 3;
			return s;
			break;
		}
		else if (_cube[s][1][0] == 0)
		{
			p = 4;
			return s;
			break;
		}
	}
}

void Cube::moveToTopCross(){
	moveTopEdges();

	for (int i = 1; i < 5; i++)
	{
		int side = 0; //side that the yellow sticker is on
		int pos = 0; //position (1-4) of the yellow sticker
		pos = findTopEdgePos(side, pos);
		side = findTopEdgeSide(side, pos);
		//cout << side << " " << pos << endl;
		int numTurns = 0; //keeps track of how many times we turn the cube to put pieces on the bottom layer so we can undo the turns
		if (side == 1)
		{
			while (_cube[5][1][0] == 0)
			{
				d();
			}
			while (_cube[0][1][0] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				l();
				l();
			}
			else if (pos == 2)
			{
				l();
			}
			else if (pos == 4)
			{
				li();
			}
		}
		else if (side == 2)
		{
			while (_cube[5][0][1] == 0)
			{
				d();
			}
			while (_cube[0][2][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				f();
				f();
			}
			else if (pos == 2)
			{
				f();
			}
			else if (pos == 4)
			{
				fi();
			}
			di();
		}
		else if (side == 3)
		{
			while (_cube[5][1][2] == 0)
			{
				d();
			}
			while (_cube[0][1][2] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				r();
				r();
			}
			else if (pos == 2)
			{
				r();
			}
			else if (pos == 4)
			{
				ri();
			}
			d();
			d();
		}
		else if (side == 4)
		{
			while (_cube[5][2][1] == 0)
			{
				d();
			}
			while (_cube[0][0][1] == 0)
			{
				u();
				numTurns++;
			}
			if (pos == 1)
			{
				b();
				b();
			}
			else if (pos == 2)
			{
				b();
			}
			else if (pos == 4)
			{
				bi();
			}
			d();
		}
		else if (side == 5)
		{
			for (int j = 0; j < 4 - pos; j++)
			{
				d();
			}
		}

		for (int j = 0; j < numTurns; j++)
		{
			ui();
		}

		if (side == 5) //algorithm for when the sticker is on the bottom
		{
			int color = i;
			for (int a = 1; a < color; a++) //set-up so that the edge goes into the right spot
			{
				u();
			}
			l();
			l();
			for (int a = 1; a < color; a++) //undo set-up
			{
				ui();
			}
		}
		else //algorithm for when th esticker is not on the bottom
		{
			int color = i;
			if (color < 4) //set-up so that the sticker goes into the right spot
			{
				for (int a = 1; a < color + 1; a++)
				{
					u();
				}
			}
			l();
			bi();
			li();
			if (color < 4) //undo set-up
			{
				for (int a = 1; a < color + 1; a++)
				{
					ui();
				}
			}
		}
	}
}

void Cube::switchEdgesTopCross(){
	/*
		Überall wo "MASTERMIND" steht muss die Bedingung des
		Masterminds eingesetzt werden
	*/
	int cnt = 0;
	while(cnt < 12){
		if(getColor(10) == getColor(13)){ // <- MASTERMIND
			//cout << "correct color 1"<< endl;
			globalRotationL();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40); // <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationR();
			//printCube();
			break;
		}
		else if(getColor(19) == getColor(22)){ // <- MASTERMIND
			//cout << "correct color 2"<< endl;
			globalRotationR();
			globalRotationR();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2xx " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						//cout << feedback << endl;
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationL();
			globalRotationL();
			break;
		}
		else if(getColor(28) == getColor(31)){ // <- MASTERMIND
			//cout << "correct color 3"<< endl;
			globalRotationR();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationL();
			//printCube();
			break;
		}
		else if(getColor(37) == getColor(40)){ // <- MASTERMIND
			//cout << "correct color 4"<< endl;
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			//printCube();
			break;
		}
		switchEdges(0, 0);
		u();
		cnt ++;
		//cout << "TRY " << cnt << endl;
		//printCube();
	}
}

void Cube::MoveSecondLayer(){
	int color = getColor(25);
	//cout << color << endl;;
	while(color == 5){
		d();
		color = getColor(25);
	}
	//printCube();
	switch (color) {
		case 1:
			di();
			if(getColor(48) == getColor(22)){
				switchEdges(1,1);
				//cout << "1 right" << endl;
			}
			else if(getColor(48)==getColor(40)){
				switchEdges(1,0);
				//cout << "1 left" << endl;
			}
			else d();
			break;
		case 2:
			if(getColor(46) == getColor(13)){
				switchEdges(2,0);
				//cout << "2 left" << endl;
			}
			else if(getColor(46)==getColor(31)){
				switchEdges(2,1);
				//cout << "2 right" << endl;
				//printCube();
			}
			else d();
			break;
		case 3:
			d();
			if(getColor(50) == getColor(22)){
				switchEdges(3,0);
				//cout << "3 left" << endl;
			}
			else if(getColor(50)==getColor(40)){
				switchEdges(3,1);
				//cout << "3 right" << endl;
			}
			else d();
			break;
		case 4:
			d();
			d();
			if(getColor(52) == getColor(31)){
				switchEdges(4,0);
				//cout << "4 left" << endl;
			}
			else if(getColor(52) == getColor(13)){
				switchEdges(4,1);
				//cout << "4 right" << endl;
				//printCube();
			}
			else d();
			break;
		default:
			d();
			//cout << "default" << endl;
			break;
	}
}


bool Cube::checkSecondLayer(){
	if(isCorrectEdge(12) != 1){
		return 0;
	}
	if(isCorrectEdge(14) != 1){
		return 0;
	}
	if(isCorrectEdge(21) != 1){
		return 0;
	}
	if(isCorrectEdge(23) != 1){
		return 0;
	}
	if(isCorrectEdge(30) != 1){
		return 0;
	}
	if(isCorrectEdge(32) != 1){
		return 0;
	}
	if(isCorrectEdge(39) != 1){
		return 0;
	}
	if(isCorrectEdge(41) != 1){
		return 0;
	}
	return 1;

}



void Cube::solveSecondLayer(){
	for(int i=0; i<10; i++){
		if(getColor(12) != getColor(13)){
			if(getColor(12) != getColor(49)){
				switchEdges(1,0);
			}
			else{
				switchEdges(4,1);
			}
			//cout << "got it at 12" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(14) != getColor(13)){
			if(getColor(14) != getColor(49)){
				switchEdges(2,0);
			}
			else{
				switchEdges(1,1);
			}
			//cout << "got it at 14" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(21) != getColor(22)){
			if(getColor(21) != getColor(49)){
				switchEdges(2,0);
			}
			else{
				switchEdges(1,1);
			}
			//cout << "got it at 21" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(23) != getColor(22)){
			if(getColor(23) != getColor(49)){
				switchEdges(2,1);
			}
			else{
				switchEdges(3,0);
			}
			//cout << "got it at 23" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(30) != getColor(31)){
			if(getColor(30) != getColor(49)){
				switchEdges(3,0);
			}
			else{
				switchEdges(2,1);
			}
			//cout << "got it at 30" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(32) != getColor(31)){
			if(getColor(32) != getColor(49)){
				switchEdges(3,1);
			}
			else{
				switchEdges(4,0);
			}
			//cout << "got it at 32" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(39) != getColor(40)){
			if(getColor(39) != getColor(49)){
				switchEdges(3,1);
			}
			else{
				switchEdges(4,0);
			}
			//cout << "got it at 39" << endl;
			MoveSecondLayer();
			//printCube();
		}
		else if(getColor(41) != getColor(40)){
			if(getColor(41) != getColor(49)){
				switchEdges(4,1);
			}
			else{
				switchEdges(1,0);
			}
			//cout << "got it at 41" << endl;
			MoveSecondLayer();
			//printCube();
		}
	}


		if(checkSecondLayer() == 0){
		cout << "Second Layer FAILED!" << endl;
		scramble();
		cout << endl << "Kantenfelder: " << endl;
		printCube();
		moveToTopCross();
		switchEdgesTopCross();
		cout << endl << "Topcross:" << endl;
		printCube();
		solveSecondLayer();
		cout << endl << "Second Layer:" << endl;
		printCube();
	}
}

void Cube::moveToBottomCross(){
	globalRotationD();
	globalRotationD();

	for(int i=0; i<8; i++){
		//cout << getColor(7) << getColor(4) << endl;
		if(getColor(7) == getColor(4)){
			u();
			//cout << "u" << endl;
		}
		else{
			//cout << "else" << endl;
			f();
			r();
			u();
			ri();
			ui();
			fi();
		}
	}
	globalRotationD();
	globalRotationD();
}


void Cube::switchEdgesBottomCross(){
	/*
		Überall wo "MASTERMIND" steht muss die Bedingung des
		Masterminds eingesetzt werden
	*/
	globalRotationD();
	globalRotationD();

	int cnt = 0;
	while(cnt < 12){
		if(getColor(10) == getColor(13)){ // <- MASTERMIND
			//cout << "correct color 1"<< endl;
			globalRotationL();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40); // <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(19) != getColor(22) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationR();
			//printCube();
			break;
		}
		else if(getColor(19) == getColor(22)){ // <- MASTERMIND
			//cout << "correct color 2"<< endl;
			globalRotationR();
			globalRotationR();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2xx " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						//cout << feedback << endl;
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(28) != getColor(31) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationL();
			globalRotationL();
			break;
		}
		else if(getColor(28) == getColor(31)){ // <- MASTERMIND
			//cout << "correct color 3"<< endl;
			globalRotationR();
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(37) != getColor(40);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			globalRotationL();
			//printCube();
			break;
		}
		else if(getColor(37) == getColor(40)){ // <- MASTERMIND
			//cout << "correct color 4"<< endl;
			int i=1;
			int cnt2=0;
			bool feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
			//cout << "Feedback = " << feedback << endl;
			while(feedback != 0){
				switch(i){
					case 0:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=1;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
						cnt2++;
						break;
					case 1:
						switchEdges(0,i);
						//cout << "cnt2 " << cnt2 << endl;
						//printCube();
						i=0;
						feedback = getColor(10) != getColor(13) || getColor(19) != getColor(22) || getColor(28) != getColor(31);// <- MASTERMIND
						cnt2++;
						break;
				}
			}
			//printCube();
			break;
		}
		switchEdges(0, 0);
		u();
		cnt ++;
		//cout << "TRY " << cnt << endl;
		//printCube();
	}
	globalRotationD();
	globalRotationD();
}
//-----------------------------------------------//
//--------------- Switch Corners ----------------//
//-----------------------------------------------//

//erster Teil: bringe die Corner-Steine auf die richtige Seite, es gibt 8 Corner-Steine, 4 befinden sich oben am Cube (die Steine der 0er Seite) und vier unten am Cube (die Steine der 5er Seite), damit die Algorithmen für Positionierung und Orientierung funktioniern müssen sich die Steine auf der richtigen Seite befinden
//übereinanderliegende Corner-Steine austauschen um sie auf die richtige Seite zu bringen (Achtung: es werden in Folge dessen auch immer Corner-Steine innerhalb ihrer Seite ausgetauscht, befinden sich zwei Corners die ausgetauscht werden müssen deshalb nicht übereinander müssen die Corners der oberen Seite zwischendurch mit "switchThreeCorners" gedreht werden)
void Cube::switchTwoCorners(int direction){

	if(direction==0){	/*	+ *  ->  + *
							# -      # a	*/
		ri();
		di();
		r();
		d();

		ri();
		di();
		r();
		d();

		ri();
		di();
		r();
		d();

	}
	else if(direction==1){	/*	+ *  ->  + b
								# -      # -	*/
		bi();
		di();
		b();
		d();

		bi();
		di();
		b();
		d();

		bi();
		di();
		b();
		d();
	
	}
	else if(direction==2){	/*	+ *  ->  c *
								# -      # -	*/
		li();
		di();
		l();
		d();

		li();
		di();
		l();
		d();

		li();
		di();
		l();
		d();

	}
	else if(direction==3){	/*	+ *  ->  + *
								# -      d -	*/
		fi();
		di();
		f();
		d();

		fi();
		di();
		f();
		d();

		fi();
		di();
		f();
		d();

	}

}


//zweiter Teil: bringe Corner Steine an die richtige Position (Achtung: die Farben sind nicht richtig)
void Cube::switchThreeCorners(int top, int direction){
	
	if(top==0){ //orientiere Cube mit benötigter Fläche oben
		; //nothing;
	}else if(top==5){
		globalRotationU();
		globalRotationU();
	}


	if(direction==0){ 		/*	+ *  ->  * #
								# -      + -	*/
		u();
		r();
		ui();
		li();
		u();
		ri();
		ui();
		l();


	}
	else if(direction==1){ 	/*	+ *  ->  - *
								# -      + #	*/
		u();
		b();
		ui();
		fi();
		u();
		bi();
		ui();
		f();
	
	}
	else if(direction==2){ 	/*	+ *  ->  + -
								# -      * #	*/
		u();
		l();
		ui();
		ri();
		u();
		li();
		ui();
		r();

	}
	else if(direction==3){ 	/*	+ *  ->  * -
								# -      # +	*/
		u();
		f();
		ui();
		bi();
		u();
		fi();
		ui();
		b();

	}


	if(top==0){ //Bringe Cube in globale Ausgangslage zurück
		; //nothing;
	}else if(top==5){
		globalRotationU();
		globalRotationU();
	}

}

//dritter Teil: Orientiere die vorher an die richtige Position gebrachten Corner Steine so, dass die Farben stimmen, Achtung: diese Funktion muss nacheinander für alle vier Corners ausgeführt werden sonst wird der Cube zerstört! Ist ein Corner an der richtigen Position wird mit der Funktion "orientCornersNextCorner" der nächste Corner ausgewählt (sie führt leiglich eine "u" Drehung aus)
void Cube::orientCorners(int top, int direction){

	if(top==0){ //orientiere Cube mit benötigter Fläche oben
		; //nothing;
	}else if(top==5){
		globalRotationU();
		globalRotationU();
	}

	if(direction==0){	/*	+ *  ->  + *
							# -      # a	*/
		ri();
		di();
		r();
		d();

		ri();
		di();
		r();
		d();

	}
	else if(direction==1){	/*	+ *  ->  + b
								# -      # -	*/
		bi();
		di();
		b();
		d();

		bi();
		di();
		b();
		d();


	}
	else if(direction==2){	/*	+ *  ->  c *
								# -      # -	*/
		li();
		di();
		l();
		d();

		li();
		di();
		l();
		d();


	}
	else if(direction==3){	/*	+ *  ->  + *
								# -      d -	*/
		fi();
		di();
		f();
		d();

		fi();
		di();
		f();
		d();

	}

	if(top==0){ //Bringe Cube in globale Ausgangslage zurück
		; //nothing;
	}else if(top==5){
		globalRotationU();
		globalRotationU();
	}

}

void Cube::orientCornersNextCorner(int top){

	if(top==0){ //orientiere Cube mit benötigter Fläche oben
		; //nothing;
	}else if(top==5){
		globalRotationU();
		globalRotationU();
	}

	u();

	if(top==0){ //Bringe Cube in globale Ausgangslage zurück
		; //nothing;
	}else if(top==5){
		globalRotationU();
		globalRotationU();
	}

}

bool Cube::isCorrectCornerSide(int position){
	//return 1 wenn Corner-Stein auf richtiger Seite
	//return 0 wenn Corner-Stein an falscher Seite
	switch(position){
		case 0:
			if(getColor(0) == getColor(4) || getColor(9) == getColor(4) ||  getColor(38) == getColor(4)){
				return 1;
			}
			else return 0;
			break;
		case 2:
			if(getColor(2) == getColor(4) ||  getColor(29) == getColor(4) || getColor(36) == getColor(4))
				return 1;
			else return 0;
			break;
		case 6:
			if(getColor(6) == getColor(4) ||  getColor(11) == getColor(4) || getColor(18) == getColor(4))
				return 1;
			else return 0;
			break;
		case 8:
			if(getColor(8) == getColor(4) || getColor(20) == getColor(4) ||  getColor(27) == getColor(4))
				return 1;
			else return 0;
			break;
		case 45:
			if(getColor(45) == getColor(49) || getColor(17) == getColor(49) || getColor(24) == getColor(49))
				return 1;
			else return 0;
			break;
		case 47:
			if(getColor(47) == getColor(49) || getColor(26) == getColor(49) || getColor(33) == getColor(49))
				return 1;
			else return 0;
			break;
		case 51:
			if(getColor(51) == getColor(49) || getColor(15) == getColor(49) || getColor(44) == getColor(49))
				return 1;
			else return 0;
			break;
		case 53:
			if(getColor(53) == getColor(49) || getColor(35) == getColor(49) || getColor(42) == getColor(49))
				return 1;
			else return 0;
			break;
		default:
			return 0;
	}
}

bool Cube::isCorrectCornerPosition(int position){
	//return 1 wenn Corner-Stein an richtiger Position
	//return 0 wenn Corner-Stein an falscher Position
	switch(position){
		case 0:
			if((getColor(0) == getColor(4) || getColor(0) == getColor(13) || getColor(0) == getColor(40)) && (getColor(9) == getColor(4) || getColor(9) == getColor(13) || getColor(9) == getColor(40)) && (getColor(38) == getColor(4) || getColor(38) == getColor(13) || getColor(38) == getColor(40)))
				return 1;
			else return 0;
			break;
		case 2:
			if((getColor(2) == getColor(4) || getColor(2) == getColor(31) || getColor(2) == getColor(40)) && (getColor(29) == getColor(4) || getColor(29) == getColor(31) || getColor(29) == getColor(40)) && (getColor(36) == getColor(4) || getColor(36) == getColor(31) || getColor(36) == getColor(40)))
				return 1;
			else return 0;
			break;
		case 6:
			if((getColor(6) == getColor(4) || getColor(6) == getColor(13) || getColor(6) == getColor(22)) && (getColor(11) == getColor(4) || getColor(11) == getColor(13) || getColor(11) == getColor(22)) && (getColor(18) == getColor(4) || getColor(18) == getColor(13) || getColor(18) == getColor(22)))
				return 1;
			else return 0;
			break;
		case 8:
			if((getColor(8) == getColor(4) || getColor(8) == getColor(22) || getColor(8) == getColor(31)) && (getColor(20) == getColor(4) || getColor(20) == getColor(22) || getColor(20) == getColor(31)) && (getColor(27) == getColor(4) || getColor(27) == getColor(22) || getColor(27) == getColor(31)))
				return 1;
			else return 0;
			break;
		case 45:
			if((getColor(45) == getColor(49) || getColor(45) == getColor(13) || getColor(45) == getColor(22)) && (getColor(17) == getColor(49) || getColor(17) == getColor(13) || getColor(17) == getColor(22)) && (getColor(24) == getColor(49) || getColor(24) == getColor(13) || getColor(24) == getColor(22)))
				return 1;
			else return 0;
			break;
		case 47:
			if((getColor(47) == getColor(49) || getColor(47) == getColor(22) || getColor(47) == getColor(31)) && (getColor(26) == getColor(49) || getColor(26) == getColor(22) || getColor(26) == getColor(31)) && (getColor(33) == getColor(49) || getColor(33) == getColor(22) || getColor(33) == getColor(31)))
				return 1;
			else return 0;
			break;
		case 51:
			if((getColor(51) == getColor(49) || getColor(51) == getColor(13) || getColor(51) == getColor(40)) && (getColor(15) == getColor(49) || getColor(15) == getColor(13) || getColor(15) == getColor(40)) && (getColor(44) == getColor(49) || getColor(44) == getColor(13) || getColor(44) == getColor(40)))
				return 1;
			else return 0;
			break;
		case 53:
			if((getColor(53) == getColor(49) || getColor(53) == getColor(31) || getColor(53) == getColor(40)) && (getColor(35) == getColor(49) || getColor(35) == getColor(31) || getColor(35) == getColor(40)) && (getColor(42) == getColor(49) || getColor(42) == getColor(31) || getColor(42) == getColor(40)))
				return 1;
			else return 0;
			break;
		default:
			return 0;
	}
}

bool Cube::isCorrectCornerOrientation(int position){
	//return 1 wenn Corner richtige Orientierung hat
	//return 0 wenn Corner falsche Orientierung hat
	switch(position){
		case 0:
			if(getColor(0) == getColor(4) && getColor(9) == getColor(13) && getColor(38) == getColor(40))
				return 1;
			else return 0;
			break;
		case 2:
			if(getColor(2) == getColor(4) && getColor(29) == getColor(31) && getColor(36) == getColor(40))
				return 1;
			else return 0;
			break;
		case 6:
			if(getColor(6) == getColor(4) && getColor(11) == getColor(13) && getColor(18) == getColor(22))
				return 1;
			else return 0;
			break;
		case 8:
			if(getColor(8) == getColor(4) && getColor(20) == getColor(22) && getColor(27) == getColor(31))
				return 1;
			else return 0;
			break;
		case 45:
			if(getColor(45) == getColor(49) && getColor(17) == getColor(13) && getColor(24) == getColor(22))
				return 1;
			else return 0;
			break;
		case 47:
			if(getColor(47) == getColor(49) && getColor(26) == getColor(22) && getColor(33) == getColor(31))
				return 1;
			else return 0;
			break;
		case 51:
			if(getColor(51) == getColor(49) && getColor(15) == getColor(13) && getColor(44) == getColor(40))
				return 1;
			else return 0;
			break;
		case 53:
			if(getColor(53) == getColor(49) && getColor(35) == getColor(31) && getColor(42) == getColor(40))
				return 1;
			else return 0;
			break;
		default:
			return 0;
	}

}

void Cube::moveToTopCorners()
{
	int count2 = 0;

	while(isCorrectCornerSide(0) != 1 || isCorrectCornerSide(2) != 1 || isCorrectCornerSide(6) != 1 || isCorrectCornerSide(8) != 1){ //Solange nichr alle Corner-Steine auf der richtigen Seite

		while(isCorrectCornerSide(0) != 1)	//solange Corner-Stein 0 nicht auf richtiger Seite
		{
			cout << "isCorrectCornerSide(0)" << endl;
			if(isCorrectCornerSide(51) != 1)	//ist darunterliegender Corner-Stein 51 nicht auf richtiger Seite?
			{
			//Ja -> Austauschen; switchTwoCorners(direction)
				cout << "switchTwoCorners(2)" << endl;
				switchTwoCorners(2);
			} else
			{
			//Nein -> rotiere oberen Corner-Stein im Uhrzeigersinn einen Platz weiter; switchThreeCorners(int top, int direction), //Achtung! wenn ich die Corner-Steine rotiere ist am 6er das was vorher am 0er war und ja schon richtig ist -> ändern! while Schleife über alles bis alle richtig sind
				cout << "switchThreeCorners(0,0)" << endl;
				switchThreeCorners(0, 0);
			}		

			if(count2 > 30)
			{
				solveCube();
			}
		}

		while(isCorrectCornerSide(2) != 1)
		{	
			cout << "isCorrectCornerSide(2)" << endl;
			if(isCorrectCornerSide(53) != 1)
			{
				cout << "switchTwoCorners(1)" << endl;
				switchTwoCorners(1);
			} else
			{
				cout << "switchThreeCorners(0,3)" << endl;
				switchThreeCorners(0, 3);
			}		

			if(count2 > 30)
			{
				solveCube();
			}		
		}

		while(isCorrectCornerSide(6) != 1) 
		{	
			cout << "isCorrectCornerSide(6)" << endl;
			if(isCorrectCornerSide(45) != 1)
			{
				cout << "switchTwoCorners(3)" << endl;
				switchTwoCorners(3);
			} else
			{
				cout << "switchThreeCorners(0,1)" << endl;
				switchThreeCorners(0, 1);
			}	

			if(count2 > 30)
			{
				solveCube();
			}	
		}		

		while(isCorrectCornerSide(8) != 1)
		{	
			cout << "isCorrectCornerSide(8)" << endl;
			if(isCorrectCornerSide(47) != 1)
			{
				cout << "switchTwoCorners(0)" << endl;
				switchTwoCorners(0);
			} else
			{
				cout << "switchThreeCorners(0,2)" << endl;
				switchThreeCorners(0, 2);
			}	

			if(count2 > 30)
			{
				solveCube();
			}			
		}
	}
}

void Cube::solvePositionCorners(){

	int count = 0;
	int count2 = 0;
	//cout<< "in solvePositionCorners" << endl;

	while(isCorrectCornerPosition(0) != 1 || isCorrectCornerPosition(2) != 1 || isCorrectCornerPosition(6) != 1 || isCorrectCornerPosition(8) != 1)	//solange alle Corner-Steine nicht auf richtiger Position
	{

		//cout<< "in while 1" << endl;
		//ist einer der Corner-Stein auf richtiger Position?
		if(isCorrectCornerPosition(0) == 1 && isCorrectCornerPosition(2) != 1 && isCorrectCornerPosition(6) != 1 && isCorrectCornerPosition(8) != 1)	//Ja -> um diesen Stein rotieren (direction) bis die anderen auch an richtiger Position sind
		{
			//cout<< "in 0" << endl;
			switchThreeCorners(0,2);

		}else if(isCorrectCornerPosition(0) != 1 && isCorrectCornerPosition(2) == 1 && isCorrectCornerPosition(6) != 1 && isCorrectCornerPosition(8) != 1)
		{
			//cout<< "in 2" << endl;
			switchThreeCorners(0,1);

		}else if(isCorrectCornerPosition(0) != 1 && isCorrectCornerPosition(2) != 1 && isCorrectCornerPosition(6) == 1 && isCorrectCornerPosition(8) != 1)
		{
			//cout<< "in 6" << endl;
			switchThreeCorners(0,3);

		}else if(isCorrectCornerPosition(0) != 1 && isCorrectCornerPosition(2) != 1 && isCorrectCornerPosition(6) != 1 && isCorrectCornerPosition(8) == 1)
		{
			//cout<< "in 8" << endl;
			switchThreeCorners(0,0);

		}else{ //Nein -> einmal mit direction 0 rotieren, dann sollte einer in richtiger Postion sein
			//cout<< "in else" << endl;
			switchThreeCorners(0,count);
			count++;
			count2++;
			if(count == 4){
				count = 0;
			}
		}

		if(count2 > 30){
			//cout<< "in solveCube()" << endl;
			solveCube();

		}

	}


	count = 0;
	while(isCorrectCornerPosition(45) != 1 || isCorrectCornerPosition(47) != 1 || isCorrectCornerPosition(51) != 1 || isCorrectCornerPosition(53) != 1)
	{
		//cout<< "in while 2" << endl;
		//ist einer der Corner-Stein auf richtiger Position?
		if(isCorrectCornerPosition(45) == 1 && isCorrectCornerPosition(47) != 1 && isCorrectCornerPosition(51) != 1 && isCorrectCornerPosition(53) != 1)	//Ja -> um diesen Stein rotieren (direction) bis die anderen auch an richtiger Position sind
		{
			//cout<< "in 45" << endl;
			switchThreeCorners(5,2);

		}else if(isCorrectCornerPosition(45) != 1 && isCorrectCornerPosition(47) == 1 && isCorrectCornerPosition(51) != 1 && isCorrectCornerPosition(53) != 1)
		{
			//cout<< "in 47" << endl;
			switchThreeCorners(5,1);

		}else if(isCorrectCornerPosition(45) != 1 && isCorrectCornerPosition(47) != 1 && isCorrectCornerPosition(51) == 1 && isCorrectCornerPosition(53) != 1)
		{
			//cout<< "in 51" << endl;
			switchThreeCorners(5,3);

		}else if(isCorrectCornerPosition(45) != 1 && isCorrectCornerPosition(47) != 1 && isCorrectCornerPosition(51) != 1 && isCorrectCornerPosition(53) == 1)
		{
			//cout<< "in 53" << endl;
			switchThreeCorners(5,0);

		}else{ //Nein -> einmal mit direction 0 rotieren, dann sollte einer in richtiger Postion sein
			//cout<< "in else 2" << endl;
			switchThreeCorners(5,count);
			count++;
			count2++;
			if(count == 4){
				count = 0;
			}
		}

		if(count2 > 30){
			//cout<< "in solveCube() 2" << endl;
			solveCube();

		}

	}

}




void Cube::solveOrientationCorners(){

	int direction = 0;
	int field = 0;
	int test;

	if(isCorrectCornerOrientation(0) != 1){

		direction = 2;
		field = 0;
	}else if(isCorrectCornerOrientation(2) != 1){

		direction = 1;
		field = 2;
	}else if(isCorrectCornerOrientation(6) != 1){

		direction = 3;
		field = 6;
	}else if(isCorrectCornerOrientation(8) != 1){

		direction = 0;
		field = 8;
	}

	cout << "solveOrientationCorners" << endl;
	while(isCorrectCornerOrientation(0) != 1 || isCorrectCornerOrientation(2) != 1 || isCorrectCornerOrientation(6) != 1 || isCorrectCornerOrientation(8) != 1)	//solange nicht alle Corner-Steine die richtige Orientierung haben
	{
		cout << "while 1" << endl;
		while(getColor(field) != getColor(4)){ //Corner richtig orientieren
			cout << "orientCorners(0, " << direction << ")" << endl;
			orientCorners(0, direction);
			printCube();
			//cout << "Test:" << endl;
			////cin >> test;
		}

		if(isCorrectCornerOrientation(0) != 1 || isCorrectCornerOrientation(2) != 1 || isCorrectCornerOrientation(6) != 1 || isCorrectCornerOrientation(8) != 1)
		{
			cout << "orientCornersNextCorner(0)" << endl;
			orientCornersNextCorner(0);	//nächsten Corner nehmen
			printCube();
			//cout << "Test:" << endl;
			//cin >> test;
		}
	}


	if(isCorrectCornerOrientation(45) != 1){

		direction = 2;
		field = 45;
	}else if(isCorrectCornerOrientation(47) != 1){

		direction = 1;
		field = 47;
	}else if(isCorrectCornerOrientation(51) != 1){

		direction = 3;
		field = 51;
	}else if(isCorrectCornerOrientation(53) != 1){

		direction = 0;
		field = 53;
	}

	while(isCorrectCornerOrientation(45) != 1 || isCorrectCornerOrientation(47) != 1 || isCorrectCornerOrientation(51) != 1 || isCorrectCornerOrientation(53) != 1)	//solange nicht alle Corner-Steine die richtige Orientierung haben
	{
		cout << "while 2" << endl;
		while(getColor(field) != getColor(49)){ //Corner richtig orientieren
			cout << "orientCorners(5)" << endl;
			orientCorners(5, direction);
		}
		if(isCorrectCornerOrientation(45) != 1 || isCorrectCornerOrientation(47) != 1 || isCorrectCornerOrientation(51) != 1 || isCorrectCornerOrientation(53) != 1)
		{
			cout << "orientCornersNextCorner(5)" << endl;
			orientCornersNextCorner(5);	//nächsten Corner nehmen
		}
	}



}

void Cube::solveCorners(){

	moveToTopCorners();
	solvePositionCorners();
	solveOrientationCorners();
}


bool Cube::isCubeSolved(){

	if(	isCorrectEdge(1) != 1 || isCorrectEdge(3) != 1 || isCorrectEdge(5) != 1 || isCorrectEdge(7) != 1 ||
		isCorrectEdge(10) != 1 || isCorrectEdge(12) != 1 || isCorrectEdge(14) != 1 || isCorrectEdge(16) != 1 ||
		isCorrectEdge(19) != 1 || isCorrectEdge(21) != 1 || isCorrectEdge(23) != 1 || isCorrectEdge(25) != 1 ||
		isCorrectEdge(28) != 1 || isCorrectEdge(30) != 1 || isCorrectEdge(32) != 1 || isCorrectEdge(34) != 1 ||
		isCorrectEdge(37) != 1 || isCorrectEdge(39) != 1 || isCorrectEdge(41) != 1 || isCorrectEdge(43) != 1 ||
		isCorrectEdge(46) != 1 || isCorrectEdge(48) != 1 || isCorrectEdge(50) != 1 || isCorrectEdge(52) != 1 ||
		isCorrectCornerOrientation(0) != 1 || isCorrectCornerOrientation(2) != 1 || isCorrectCornerOrientation(6) != 1 ||
		isCorrectCornerOrientation(8) != 1 || isCorrectCornerOrientation(45) != 1 || isCorrectCornerOrientation(47) != 1 ||
		isCorrectCornerOrientation(51) != 1 || isCorrectCornerOrientation(53) != 1)
	{
		return 1;
	} else{
		return 0;
	}

}





//-----------------------------------------------//
//------------------Sonstiges--------------------//
//-----------------------------------------------//

void Cube::writeCube(int position, int color){
	int cnt = 0;
	for(int a=0; a<6; a++){ //Seite
		for(int b=0; b<3; b++){ //Zeile
			for(int c=0; c<3; c++){ //Spalten
				if(cnt == position){
					_cube[a][b][c] = color;
				}
				cnt++;
				//else break;
			}
		}
	}
}