
#ifndef MUSICGENERATOR_NOTELIBRARY_H
#define MUSICGENERATOR_NOTELIBRARY_H


#include <string>
#include <map>
#include "Note.h"

struct NoteComparator {
	bool operator () (const std::string &lhs, const std::string &rhs) const {
		// Assumes lhs and rhs are something like N#n or Nn where N is the note letter
		// and n is the octave.

		// Figuring out lesser octave.
		if ( lhs[ lhs.size() - 1 ] != rhs[ rhs.size() - 1 ] ) {
			return lhs[ lhs.size() - 1 ] < rhs[ rhs.size() - 1 ];
		} else if ( lhs[ 0 ] != rhs[ 0 ] ) {
			// We already know the octaves are the same.
			// Now we're figuring out if the notes are the same.
			return lhs < rhs;
		}
		// We know the notes are within a half step of each other.
		// So pick the one who is natural.
		return lhs.size() < rhs.size();
	}
};

class NoteLibrary {

private:
	std::map < std::string, Note *, NoteComparator > notes;

	NoteLibrary ( );

public:
	static NoteLibrary *getInstance ( );
	~NoteLibrary ( );


	void initializeLibrary (int num_of_octaves);

	int getSize ( ) const;

	Note *getNote (const std::string &note) const;
	Note *getMiddleC ( ) const;


	void addNote (Note *note);
	void addNote (const std::string &name, const int &octave, const double &frequency);

	void printAll ( ) const;

};


#endif //MUSICGENERATOR_NOTELIBRARY_H
