#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

typedef float* ptrtoar;

class Song {
	public:
        string name1;
        string name2;
		ptrtoar note;
        ptrtoar beat;
        float tempo;
        int length;

        Song (string in_name1, string in_name2, ptrtoar in_note, ptrtoar in_beat, float in_tempo, int in_length){
            name1 = in_name1;
            name2 = in_name2;
            note = in_note;
            beat = in_beat;
            tempo = in_tempo;
            length = in_length;
        }
        
};

#endif
