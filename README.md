# Music Generator 
This is a program that can take in a note letter and an octave and output the corresponding sound.

## How To Use
Input a note in the format of N#O or NO where N is the note letter and O is the octave of the note.
#### Examples
* A#7
* G3
* E0

The program will then output a music file that can be used to hear the sound of the requested note at the octave.

Note that the program does not responds to flats. It is also advised to use octaves that have single digits
(anything less than 10) as the sorting algorithm for the library is not good with multiple digits in the octave.

## Completed
* Note library
* Automatic generation of notes from A0 and above.
  * Sorting the notes however gets clunky at A10 and above. But due to their impracticality, that will 
    not be fixed.


## TODO
* Add note parsing.
* Add sound output (through a file.)
  * Make it so that it can actually play the sound.


## Possible TODO
* Add capability to read from a file of notes
  * Maybe even MIDI?
    * That might be too different from our input.