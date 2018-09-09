#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "NoteLibrary.h"


int getNoteIndex (const std::string &name) {
	static std::vector < std::string > note_names = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

	return static_cast<int>(std::distance( note_names.begin(),
	                                       std::find( note_names.begin(), note_names.end(), name ) ));
}

std::string getNoteName (const int &note_index) {
	static std::vector < std::string > note_names = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

	return note_names[ note_index % 12 ];
}

std::string getNoteRepresentation (const int &note_index) {
	int         octave    = note_index / 12;
	std::string note_name = getNoteName( note_index );

	return note_name + std::to_string( octave );

}

int main ( ) {

	NoteLibrary *noteLibrary = NoteLibrary::getInstance();

	/*
	 * On how we're figuring out the frequencies for all these notes...
	 *
	 * f_n = f_0 * (a ^ n)
	 *
	 * where...
	 *
	 * f_n = the frequency we're trying to figure out.
	 * f_0 = a fixed note that we already know the frequency is.
	 *       We'll figure out it based on middle C.
	 * n = the number of half steps f_n is from f_0. It can be negative.
	 * a = the 12th root of 2. In other words: 2 ^ (1 / 12)
	 */

	const Note  *middle_c  = noteLibrary->getMiddleC();
	int         middle_c_n = middle_c->getOctave() * 12 + getNoteIndex( middle_c->getName() );
	double      frequency;
	std::string note_name;
	int         octave;

	const int MAX_OCTAVES      = 8;
	const int MAX_NUM_OF_NOTES = MAX_OCTAVES * 12;

	const double a = std::pow( 2, 1.0 / 12.0 );

	// We want to generate 8 octaves worth of notes.
	// Thus the 8 * 12. (0th indexing for the 8, 12 for the number of notes)
	for ( int n = 0; n < MAX_NUM_OF_NOTES; n++ ) {
		frequency = middle_c->getFrequency() * std::pow( a, ( double ) (n - middle_c_n) );
		octave    = n / 12;
		note_name = getNoteName( n );

		noteLibrary->addNote( note_name, octave, frequency );
	}

	noteLibrary->printAll();

	delete noteLibrary;
	delete middle_c;


	return 0;
}