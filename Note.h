
#ifndef MUSICGENERATOR_NOTE_H
#define MUSICGENERATOR_NOTE_H

#include <string>

class Note {

private:
	std::string name;
	double      frequency;
	int         octave;

public:
	Note ( );
	Note (const std::string &name, const int &octave, const double &frequency);
	Note (const Note &note);
	~Note ( ) = default;

	const std::string &getName ( ) const;
	double getFrequency ( ) const;
	int getOctave ( ) const;

	std::string getRepresentation ( ) const;
	explicit operator std::string ( ) const;


	Note (const Note *note);
};


#endif //MUSICGENERATOR_NOTE_H
