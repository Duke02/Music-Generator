//
// Created by trystanmay on 9/8/18.
//

#include "Note.h"

Note::Note ( ) {
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


