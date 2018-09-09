
#ifndef MUSICGENERATOR_NOTELIBRARY_H
#define MUSICGENERATOR_NOTELIBRARY_H


#include <string>
#include <map>
#include "Note.h"

class NoteLibrary {

private:
	const Note **notes;

	NoteLibrary ( );

public:
	static NoteLibrary *getInstance ( );

	Note *getNote (const std::string &note) const;

	void addNote (const Note *note);
	void addNote (const std::string &name, const int &octave, const double &frequency);


};


#endif //MUSICGENERATOR_NOTELIBRARY_H
