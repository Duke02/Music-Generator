#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "NoteLibrary.h"

int main ( ) {

	NoteLibrary *noteLibrary = NoteLibrary::getInstance();

	noteLibrary->initializeLibrary( 8 );

	noteLibrary->printAll();

	delete noteLibrary;

	return 0;
}