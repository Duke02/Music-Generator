
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "NoteLibrary.h"

NoteLibrary::NoteLibrary ( ) {
	this->notes[ "C3" ] = new Note();
}

NoteLibrary *NoteLibrary::getInstance ( ) {
	// When this function is first called, set instance to be null.
	// When this function is called again, instance will not be null.
	static NoteLibrary *instance = nullptr;

	// If it's the first time we're calling this function (because instance is null)...
	if ( instance == nullptr ) {
		// initialize it to a new instance of this class.
		instance = new NoteLibrary();
	}

	// Return the ONLY instance of this class.
	return instance;
}

Note *NoteLibrary::getNote (const std::string &note) const {
	// If we can find the given note in the thing...
	if ( this->notes.find( note ) != this->notes.end() ) {
		// output the note.
		return this->notes.at( note );
	}
	// If we can't find it,
	// then just return null.
	return nullptr;

}

void NoteLibrary::addNote (Note *note) {
	// If we can't find the note in our already existing library...
	if ( this->notes.find( note->getRepresentation() ) == this->notes.end() ) {
		// Add it.
		this->notes[ note->getRepresentation() ] = note;
	}
}

void NoteLibrary::addNote (const std::string &name, const int &octave, const double &frequency) {
	this->addNote( new Note( name, octave, frequency ) );
}

Note *NoteLibrary::getMiddleC ( ) const {
	return this->getNote( "C3" );
}

int NoteLibrary::getSize ( ) const {
	return static_cast<int>(this->notes.size());
}

void NoteLibrary::printAll ( ) const {
	for ( auto i = this->notes.begin(); i != this->notes.end(); i++ ) {
		std::cout << i->second->getInfo() << std::endl;
	}
}

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

void NoteLibrary::initializeLibrary (int num_of_octaves) {

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

	const Note  *middle_c  = this->getMiddleC();
	int         middle_c_n = middle_c->getOctave() * 12 + getNoteIndex( middle_c->getName() );
	double      frequency;
	std::string note_name;
	int         octave;

	const int MAX_NUM_OF_NOTES = num_of_octaves * 12;

	const double a = std::pow( 2, 1.0 / 12.0 );

	// We want to generate 8 octaves worth of notes.
	// Thus the 8 * 12. (0th indexing for the 8, 12 for the number of notes)
	for ( int n = 0; n < MAX_NUM_OF_NOTES; n++ ) {
		if ( n - middle_c_n == 0 ) {
			continue;
		}
		frequency = middle_c->getFrequency() * std::pow( a, ( double ) (n - middle_c_n) );
		octave    = n / 12;
		note_name = getNoteName( n );

		this->addNote( note_name, octave, frequency );
	}
}

NoteLibrary::~NoteLibrary ( ) {
	for ( int i = 0; i < this->getSize(); i++ ) {
		delete this->getNote( getNoteRepresentation( i ) );
	}
}
