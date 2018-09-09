
#include <iostream>
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
		this->notes[ note->getName() ] = note;
	}
}

void NoteLibrary::addNote (const std::string &name, const int &octave, const double &frequency) {
	this->addNote( new Note( name, octave, frequency ) );
}

Note *NoteLibrary::getMiddleC ( ) const {
	return this->getNote( "C3" );
}

int NoteLibrary::getSize ( ) const {
	return this->notes.size();
}
