
#ifndef MUSICGENERATOR_NOTELIBRARY_H
#define MUSICGENERATOR_NOTELIBRARY_H


#include <string>
#include <map>
#include "Note.h"

class NoteLibrary {

private:
	std::map < std::string, const Note * > notes;

	NoteLibrary ( );

public:
	static NoteLibrary *getInstance ( );

	const Note *getNote (const std::string &note) const;
	const Note *getMiddleC ( ) const;


	void addNote (const Note *note);
	void addNote (const std::string &name, const int &octave, const double &frequency);


};


#endif //MUSICGENERATOR_NOTELIBRARY_H
