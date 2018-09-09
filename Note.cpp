//
// Created by trystanmay on 9/8/18.
//

#include "Note.h"

Note::Note ( ) {
	// Middle C
	this->name      = "C";
	this->octave    = 3;
	this->frequency = 261.625565;
}

Note::Note (const std::string &name, const int &octave, const double &frequency) {
	this->name      = name;
	this->octave    = octave;
	this->frequency = frequency;
}

const std::string &Note::getName ( ) const {
	return this->name;
}

double Note::getFrequency ( ) const {
	return this->frequency;
}

int Note::getOctave ( ) const {
	return this->octave;
}

std::string Note::getRepresentation ( ) const {
	// Middle C would be "C3"
	return this->getName() + std::to_string( this->getOctave() );
}

Note::operator std::string ( ) const {
	return this->getRepresentation();
}


