
#ifndef MUSICGENERATOR_NOTELIBRARY_H
#define MUSICGENERATOR_NOTELIBRARY_H


#include <string>
#include <map>
#include "Note.h"

class NoteLibrary {

private:
	std::map < std::string, Note * > notes;

	NoteLibrary ( );

public:
	static NoteLibrary *getInstance ( );

	int getSize ( ) const;

	Note *getNote (const std::string &note) const;
	Note *getMiddleC ( ) const;


	void addNote (Note *note);
	void addNote (const std::string &name, const int &octave, const double &frequency);

	void printAll ( ) const;

};


#endif //MUSICGENERATOR_NOTELIBRARY_H
