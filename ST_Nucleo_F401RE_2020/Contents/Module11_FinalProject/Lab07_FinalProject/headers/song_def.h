#ifndef SONG_DEF
#define SONG_DEF

# include "song.h"
# include <string>
using namespace std;

//Define songs below

//Define the frequency of basic music notes
# define So__1      5.102
# define Si__1      4.059

# define Do         3.822
# define DoD        3.608
# define Re         3.405
# define ReD        3.214
# define Mi         3.033
# define Fa         2.863
# define FaD        2.702
# define So         2.551
# define SoD        2.407
# define La         2.272
# define LaD        2.145
# define Si         2.024

# define Do_2       1.911
# define DoD_2      1.803
# define Re_2       1.702
# define ReD_2      1.607
# define Mi_2       1.516
# define Fa_2       1.431
# define FaD_2      1.351
# define So_2       1.275
# define SoD_2      1.204
# define La_2       1.136
# define LaD_2      1.073
# define Si_2       1.012

# define Do_3       0.955
# define DoD_3      0.901
# define Re_3       0.853
# define No         0

//Define the beat length (e.g. whole note, half note)
# define b0     1
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075

//Define the musical piece

//Für Elise - Beethoven
float Fur_Elise_note[] = {Mi_2,ReD_2, Mi_2,ReD_2,Mi_2,Si,Re_2,Do_2, La,No,Do,Do,Mi,La, Si,No,Mi,Mi,SoD,Si, Do_2,No,Mi,Mi,Mi_2,ReD_2, Mi_2,ReD_2,Mi_2,Si,Re_2,Do_2, La,No,Do,Do,Mi,La, Si,No,Mi,Mi,Do_2,Si, La,No,Si,Si,Do_2,Re_2, Mi_2,No,So,So,Fa_2,Mi_2, Re_2,No,Fa,Fa,Mi_2,Re_2, Do_2,No,Mi,Mi,Re_2,Do_2, Si,Mi, Mi_2,ReD_2};
float Fur_Elise_beat[] = {b3,b3,      b3,b3,b3,b3,b3,b3,            b2,b3,b4,b3,b3,b3, b2,b3,b4,b3,b3,b3,  b2,b3,b4,b3,b3,b3,        b3,b3,b3,b3,b3,b3,            b2,b3,b4,b3,b3,b3, b2,b3,b4,b3,b3,b3,    b2,b3,b4,b3,b3,b3,    b2,b3,b4,b3,b3,b3,       b2,b3,b4,b3,b3,b3,       b2,b3,b4,b3,b3,b3,       b2,b1, b1,b3};
float Fur_Elise_tempo =0.18;


//Canon In D - Pachebelbel
float Canon_In_D_note [] = {FaD_2,DoD_2,Re_2,FaD,Mi_2,La,So,La, Re_2,No,Re_2,DoD_2,Si,DoD_2,FaD_2,La_2,Si_2, So_2,FaD_2,Mi_2,So_2,FaD_2,Mi_2,Re_2,DoD_2, Si,La,Si,Re_2,No,Re_2,DoD_2, La_2,FaD_2,So_2,La_2,FaD_2,So_2,La_2,La,Si,DoD_2,Re_2,Mi_2,FaD_2,So_2, FaD_2,Re_2,Mi_2,FaD_2,FaD,So,La,Si,La,So,La,FaD,So,La, So,Si,La,So,FaD,Mi,FaD,Mi,Re,Mi,FaD,So,La,Si, So,Si,La,Si,DoD_2,Re_2,DoD_2,Si,La,Si,DoD_2,Re_2,Mi_2,FaD_2};
float Canon_In_D_beat [] = {b2,b2,b2,b2,b2,b2,b2,b2, b3,b4,b2,b2,b2,b2,b2,b2,b2, b2,b2,b2,b2,b2,b2,b2,b2, b2,b2,b2,b3,b4,b1,b1, b2,b3,b3,b2,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3, b2,b3,b3,b2,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3, b2,b3,b3,b2,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3, b2,b3,b3,b2,b3,b3,b3,b3,b3,b3,b3,b3,b3,b3};
float Canon_In_D_tempo = 0.41;

// Minuet in G major - Bach
float Minuet_In_G_major_note [] = {Re_2,Re_2,So,La,Si,Do_2, Re_2,Re_2,So,No,So,No, Mi_2,Mi_2,Do_2,Re_2,Mi_2,FaD_2, So_2,So_2,So,No,So,No, Do_2,Do_2,Re_2,Do_2,Si,La, Si,Si,Do_2,Si,La,So, FaD,FaD,So,La,Si,So, Si,La,La, Re_2,Re_2,So,La,Si,Do_2, Re_2,Re_2,So,No,So,No, Mi_2,Mi_2,Do_2,Re_2,Mi_2,FaD_2, So_2,So_2,So,No,So,No, Do_2,Do_2,Re_2,Do_2,Si,La, Si,Si,Do_2,Si,La,So, La,La,Si,La,So,FaD, So,So,No};
float Minuet_In_G_major_beat [] = {b1,b4,b2,b2,b2,b2, b1,b4,b1,b4,b1,b4, b1,b4,b2,b2,b2,b2, b1,b4,b1,b4,b1,b4, b1,b4,b2,b2,b2,b2, b1,b4,b2,b2,b2,b2, b1,b4,b2,b2,b2,b2, b2,b1,b1, b1,b4,b2,b2,b2,b2, b1,b4,b1,b4,b1,b4, b1,b4,b2,b2,b2,b2, b1,b4,b1,b4,b1,b4, b1,b4,b2,b2,b2,b2, b1,b4,b2,b2,b2,b2, b1,b4,b2,b2,b2,b2, b1,b1,b1};
float Minuet_In_G_major_tempo = 0.13;

// Turkish March - Mozart
float Turkish_March_note [] = {Si,La,SoD,La, Do_2,Do_2,No,Re_2,Do_2,Si,Do_2, Mi_2,Mi_2,No,Fa_2,Mi_2,ReD_2,Mi_2, Si_2,La_2,SoD_2,La_2,Si_2,La_2,SoD_2,La_2, Do_3,Do_3,No,La_2,No,Do_3,No, Si_2,No,La_2,No,So_2,No,La_2,No, Si_2,No,La_2,No,So_2,No,La_2,No, Si_2,No,La_2,No,So_2,No,FaD_2,No, Mi_2,No,Mi_2,No,Fa_2,No, So_2,No,So_2,No,La_2,So_2,Fa_2,Mi_2, Re_2,Re_2,No,Mi_2,No,Fa_2,No, So_2,No,So_2,No,La_2,So_2,Fa_2,Mi_2, Re_2,Re_2,No,Do_2,No,Re_2,No, Mi_2,No,Mi_2,No,Fa_2,Mi_2,Re_2,Do_2, Si,Si,No,Do_2,No,Re_2,No, Mi_2,No,Mi_2,No,Fa_2,Mi_2,Re_2,Do_2, Si,Si,No,Si,La,SoD,La, Do_2,Do_2,No,Re_2,Do_2,Si,Do_2, Mi_2,Mi_2,No,Fa_2,Mi_2,ReD_2,Mi_2, Si_2,La_2,SoD_2,La_2,Si_2,La_2,SoD_2,La_2, Do_3,Do_3,No,La_2,No,Si_2,No, Do_3,No,Si_2,No,La_2,No,SoD_2,No, La_2,No,Mi_2,No,Fa_2,No,Re_2,No, Do_2,Do_2,No,Si,La,Si, La,La};
float Turkish_March_beat [] = {b3,b3,b3,b3,    b2,b2,b2,b3,b3,b3,b3,            b2,b2,b2,b3,b3,b3,b3,                b3,b3,b3,b3,b3,b3,b3,b3,                b2,b2,b2,b3,b3,b3,b3,        b3,b3,b3,b3,b3,b3,b3,b3,         b3,b3,b3,b3,b3,b3,b3,b3,        b3,b3,b3,b3,b3,b3,b3,b3,          b1,b1,b3,b3,b3,b3,       b3,b3,b3,b3,b3,b3,b3,b3,               b2,b2,b2,b3,b3,b3,b3,          b3,b3,b3,b3,b3,b3,b3,b3,             b2,b2,b2,b3,b3,b3,b3,       b3,b3,b3,b3,b3,b3,b3,b3,              b2,b2,b2,b3,b3,b3,b3,        b3,b3,b3,b3,b3,b3,b3,b3,         b2,b2,b2,b3,b3,b3,b3,      b2,b2,b2,b3,b3,b3,b3,     b2,b2,b2,b3,b3,b3,b3,            b3,b3,b3,b3,b3,b3,b3,b3,                         b2,b2,b2,b3,b3,b3,b3,         b3,b3,b3,b3,b3,b3,b3,b3,        b3,b3,b3,b3,b3,b3,b3,b3,      b2,b2,b2,b2,b3,b3, b1,b1};
float Turkish_March_tempo = 0.15;

// Nocturne in E flat - Chopin
float Nocturne_in_E_flat_note [] = {LaD, So_2,So_2,So_2, So_2,Fa_2,So_2, Fa_2,Fa_2,Fa_2, ReD_2,ReD_2,LaD, So_2,So_2,Do_2, Do_3,Do_3,So_2, LaD_2,LaD_2,LaD_2, SoD_2,SoD_2,So_2, Fa_2,Fa_2,Fa_2, So_2,So_2,Re_2, ReD_2,ReD_2,ReD_2, Do_2,Do_2,Do_2, LaD,Re_3,Do_3, LaD_2,SoD_2,So_2,SoD_2,Do_2,Re_2, ReD_2,ReD_2,ReD_2, No,No,LaD, So_2,So_2,So_2, Fa_2,So_2,Fa_2,Mi_2,Fa_2,So_2, Fa_2,ReD_2,ReD_2, ReD_2,Fa_2,ReD_2,Re_2,ReD_2,Fa_2, So_2,Si,Do_2,DoD_2,Do_2,Fa_2, Mi_2,SoD_2,So_2,DoD_3,Do_3,So_2, LaD_2,LaD_2,LaD_2 ,SoD_2,SoD_2,So_2, Fa_2,Fa_2,Mi_2,Fa_2, So_2,So_2,Re_2, ReD_2,ReD_2,ReD_2, Do_2,Do_2,Do_2, LaD,Re_3,Do_3,LaD_2,SoD_2,So_2,SoD_2,Do_2,Re_2, ReD_2,ReD_2,ReD_2, No,No,No};
float Nocturne_in_E_flat_beat [] = {b0,  b0,b0,b0,          b0,b0,b0,      b0,b0,b0,      b0,b0,b0,       b0,b0,b0,       b0,b0,b0,        b0,b0,b0,           b0,b0,b0,       b0,b0,b0,       b0,b0,b0,       b0,b0,b0,          b0,b0,b0,       b0,b0,b0,       b1,b1,b1,b1,b1,b1,b1,b1,b1,      b0,b0,b0,          b0,b0,b0,  b0,b0,b0,       b1,b1,b1,b1,b1,b1,              b0,b0,b0,         b1,b1,b1,b1,b1,b1,                   b1,b1,b1,b1,b1,b1,            b1,b1,b1,b1,b1,b1,             b0,b0,b0,         b0,b0,b0,        b0,b0,b1,b1,          b0,b0,b0,       b0,b0,b0,           b0,b0,b0,      b1,b1,b1,b1,b1,b1,                              b0,b0,b0,           b0,b0,b0};
float Nocturne_in_E_flat_tempo = 0.31;

// Waltz No. 2 - Shostakovich
float Waltz_No2_note [] = {So,So,So, ReD,ReD,Re, Do,Do,Do, No,Do,Re, ReD,Do,ReD, So,So,SoD, So,So,So, Fa,Fa,Fa, No,Fa,Fa,Fa, Re,Re,Do, Si__1,Si__1,Si__1, Si__1,So__1,Si__1, Re,Si__1,Re, Fa,So,SoD, FaD,FaD,FaD, So,So,So, ReD_2,ReD_2,ReD_2, Re_2,Re_2,Do_2, LaD,LaD,SoD, Fa,Fa,Fa, Re_2,Re_2,Re_2, Do_2,Do_2,LaD, No,LaD,LaD,LaD, So,So,So, No,ReD,No,Fa,No, So,No,So,No,Fa,No,So,No,SoD,No, Fa,No,Fa,No,ReD,No,Fa,No,So,No, ReD,No,No,So,No, No,Do_2,No,Re_2,No, ReD_2,No,ReD_2,No,Re_2,No,ReD_2,No,Fa_2,No, Re_2,No,Re_2,No,Do_2,No,Re_2,No,ReD_2,No, Do_2,Do_2,Do_2, No,No,No};
float Waltz_No2_beat [] = {b1,b1,b1, b1,b1,b1,   b1,b1,b1, b1,b1,b1, b1,b1,b1,   b1,b1,b1,  b1,b1,b1, b1,b1,b1, b4,b1,b1,b1, b1,b1,b1, b1,b1,b1,          b1,b1,b1,          b1,b1,b1,    b1,b1,b1,  b1,b1,b1,    b1,b1,b1, b1,b1,b1,          b1,b1,b1,       b1,b1,b1,    b1,b1,b1, b1,b1,b1,       b1,b1,b1,      b4,b1,b1,b1,    b1,b1,b1, b1,b2,b2,b2,b2,  b2,b3,b3,b3,b3,b3,b3,b3,b3,b3,  b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,  b2,b2,b1,b2,b2,  b1,b2,b2,b2,b2,     b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,              b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,            b1,b1,b1,    b1,b1,b1};
float Waltz_No2_tempo = 0.1;

// Nocturne in C sharp minor - Chopin
float Nocturne_in_C_sharp_minor_note [] = {SoD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2,FaD_2,SoD_2, Mi_2,FaD_2,SoD_2,DoD_2, DoD_3,DoD_3,DoD_3,Si_2,DoD_3,Si_2,La_2, No,La_2,No, SoD_2,ReD_2, Mi_2,FaD_2,DoD_2,DoD_2, No,DoD_2,ReD_2,No,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,Mi_2,ReD_2,DoD_2, ReD_2,SoD, SoD,No};
float Nocturne_in_C_sharp_minor_beat [] = {b0,b0,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,                                                       b3,b3,b0,b0,            b0,b3,b4,b4,b3,b3,b3,                   b4,b0,b0,   b0,b0,       b0,b1,b1,b1,         b4,b2,b2,b2,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b4,b2,b2,                                                     b0,b0,     b0,b0};
float Nocturne_in_C_sharp_minor_tempo = 0.13;

// Symphony No. 40 - Mozart 
float Symphony_No40_note [] = {ReD_2,No,Re_2,No, Re_2,No,ReD_2,No,Re_2,No,Re_2,No,ReD_2,No,Re_2,No, Re_2,No,LaD_2,No,No,LaD_2,No,La_2,No, So_2,No,So_2,No,Fa_2,No,ReD_2,No,ReD_2,No,Re_2,No, Do_2,No,Do_2,No,No,Re_2,No,Do_2,No, Do_2,No,Re_2,No,Do_2,No,Do_2,No,Re_2,No,Do_2,No, Do_2,No,La_2,No,No,La_2,No,So_2,No, FaD_2,No,FaD_2,No,ReD_2,No,Re_2,No,Re_2,No,Do_2,No, LaD,No,LaD,No,No,LaD_2,No,La_2,No, La_2,No,Do_3,No,FaD_2,No,La_2,No, So_2,No,Re_2,No,No,LaD_2,No,La_2,No, La_2,No,Do_3,No,FaD_2,No,La_2,No, So_2,No,LaD_2,No,La_2,No,So_2,Fa_2,No,ReD_2,No, No,FaD_2,No,So_2,No,La_2,No, LaD_2,No,Do_3,No,LaD_2,No,La_2,No,So_2,No, FaD_2,No,No,DoD_3,No, Re_3,No,No,DoD_3,No, Re_3,No,No,DoD_3,No, Re_3,No,DoD_3,No,Re_3,No,DoD_3,No, Re_3,Re_3,No,No};
float Symphony_No40_beat [] = {b3,b3,b3,b3,      b2,b2,b3,b3,b3,b3,b2,b2,b3,b3,b3,b3,               b2,b2,b2,b2,b1,b3,b3,b3,b3,           b2,b2,b3,b3,b3,b3,b2,b2,b3,b3,b3,b3,               b2,b2,b2,b2,b1,b3,b3,b3,b3,         b2,b2,b3,b3,b3,b3,b2,b2,b3,b3,b3,b3,             b2,b2,b2,b2,b1,b3,b3,b3,b3,         b2,b2,b3,b3,b3,b3,b2,b2,b3,b3,b3,b3,                b2,b2,b2,b2,b1,b3,b3,b3,b3,        b2,b2,b2,b2,b2,b2,b2,b2,          b2,b2,b2,b2,b1,b3,b3,b3,b3,          b2,b2,b2,b2,b2,b2,b2,b2,          b2,b2,b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,            b1,b2,b2,b2,b2,b2,           b2,b2,b3,b3,b3,b3,b2,b2,b2,b2,             b2,b2,b1,b1,b1,       b2,b2,b1,b1,b1,      b2,b2,b1,b1,b1,      b2,b2,b2,b2,b2,b2,b2,b2,           b1,b1,b1,b0};
float Symphony_No40_tempo = 0.1;

// Symphony No. 5 - Beethoven 
float Symphony_No5_note [] = {No,Mi,No,Mi,No,Mi,No, Do,Do, No,Re,No,Re,No,Re,No, Si__1, Si__1,Si__1, No,Mi,No,Mi,No,Mi,No, Do,No,Fa,No,Fa,No,Fa,No, Mi,No,Do_2,No,Do_2,No,Do_2,No, La,La, No,Mi,No,Mi,No,Mi,No, Si__1,No,Fa,No,Fa,No,Fa,No, Mi,No,Re_2,No,Re_2,No,Re_2,No, Si,Si, Si,No,Mi_2,No,Mi_2,No,Re_2,No, Do_2,No,Do,No,Do,No,Re,No, Mi,No,Mi_2,No,Mi_2,No,Re_2,No, Do_2,No,Do,No,Do,No,Re,No, Mi,No,Mi_2,No,Mi_2,No,Re_2,No, Do_2,No, La,No, Mi_2,Mi_2, No};
float Symphony_No5_beat [] = {b3,b4,b4,b4,b4,b4,b4, b1,b1, b3,b4,b4,b4,b4,b4,b4, b1,    b1,b1,       b3,b4,b4,b4,b4,b4,b4, b4,b4,b4,b4,b4,b4,b4,b4, b4,b4,b4,b4,b4,b4,b4,b4,       b1,b1, b3,b4,b4,b4,b4,b4,b4, b4,b4,b4,b4,b4,b4,b4,b4,    b4,b4,b4,b4,b4,b4,b4,b4,       b1,b1, b4,b4,b4,b4,b4,b4,b4,b4,       b4,b4,b4,b4,b4,b4,b4,b4,   b4,b4,b4,b4,b4,b4,b4,b4,       b4,b4,b4,b4,b4,b4,b4,b4,   b4,b4,b4,b4,b4,b4,b4,b4,       b2,b2,   b2,b2,  b1,b1, b1};
float Symphony_No5_tempo = 0.07;

// Eine Kleine Nachtamusik - Mozart 
float Eine_Kleine_Nachtamusik_note [] = {Do_2,Do_2,No,So,No, Do_2,Do_2,No,So,No, Do_2,No,So,No,Do_2,No,Mi_2,No, So_2,So_2,No, Fa_2,Fa_2,No,Re_2,No, Fa_2,Fa_2,No,Re_2,No, Fa_2,No,Re_2,No,Si,No,Re_2,No, So,So,No, Do_2,No,Do_2,No, No,Mi_2,No,Re_2,No,Do_2,No, Do_2,No,Si,No,Si,No, No,Re_2,No,Fa_2,No,Si,No, Re_2,No,Do_2,No,Do_2,No, No,Mi_2,No,Re_2,No,Do_2,No, Do_2,No,Si,No,Si, No,Re_2,No,Fa_2,No,Si,No, Do_2,No,Do_2,No,Do_2,No,Si,No,La,No,Si,No, Do_2,No,Do_2,No,Mi_2,No,Re_2,No,Do_2,No,Re_2,No, Mi_2,No,Mi_2,No,So_2,No,Fa_2,No,Mi_2,No,Fa_2,No, So_2,So_2,No, So_2,So_2,No, La_2,La_2,No, So_2,No,Fa_2,No,Fa_2,No,Fa_2,No, Fa_2,No,Mi_2,No,Mi_2,No,Mi_2,No, Mi_2,No,Re_2,No,Re_2,No,Re_2,No, Do_2,No,Si,No,La,No,Si,No, Do_2,Mi_2, Do_2,Do_2,No};
float Eine_Kleine_Nachtamusik_beat [] = {b2,b3,b4,b3,b4,     b2,b3,b4,b3,b4,     b3,b4,b3,b4,b3,b4,b3,b4,       b1,b3,b4,     b2,b3,b4,b3,b4,       b2,b3,b4,b3,b4,       b3,b4,b3,b4,b3,b4,b3,b4,       b1,b4,b4, b2,b4,b2,b4,     b3,b3,b4,b3,b4,b3,b4,       b3,b4,b3,b4,b2,b4,   b3,b3,b4,b3,b4,b3,b4,     b3,b4,b3,b4,b2,b4,       b3,b3,b4,b3,b4,b2,b4,       b3,b4,b3,b4,b3,   b3,b3,b4,b3,b4,b3,b4,     b3,b4,b3,b4,b4,b4,b4,b4,b4,b4,b4,b4,       b3,b4,b3,b4,b4,b4,b4,b4,b4,b4,b4,b4,             b3,b4,b3,b4,b4,b4,b4,b4,b4,b4,b4,b4,             b2,b3,b4,     b1,b3,b4,     b1,b3,b4,     b3,b4,b3,b4,b3,b4,b3,b4,         b3,b4,b3,b4,b3,b4,b3,b4,         b3,b4,b3,b4,b3,b4,b3,b4,         b3,b4,b3,b4,b3,b4,b3,b4,   b2,b2,     b2,b3,b2};
float Eine_Kleine_Nachtamusik_tempo = 0.08;


// Creating the musical piece
Song FUR_ELISE = Song (string("Fur Elise -"), string("Beethoven"), &Fur_Elise_note [0], &Fur_Elise_beat [0], Fur_Elise_tempo, 72);
Song CANNON_IN_D = Song(string("Canon In D - "), string("Pachebelbel"), &Canon_In_D_note [0], &Canon_In_D_beat [0], Canon_In_D_tempo, 88);
Song MINUET_IN_G_MAJOR = Song(string("Minuet in G"), string("major - Bach"), &Minuet_In_G_major_note [0], &Minuet_In_G_major_beat [0], Minuet_In_G_major_tempo, 90);
Song TURKISH_MARCH = Song(string("Turkish March - "), string(" Mozart"), &Turkish_March_note [0], &Turkish_March_beat [0], Turkish_March_tempo, 176);
Song NOCTRUNE_IN_E_FLAT = Song(string("Nocturne in E "), string("flat -Chopin"), &Nocturne_in_E_flat_note [0], &Nocturne_in_E_flat_beat [0], Nocturne_in_E_flat_tempo, 116);
Song WALTZ_NO2 = Song(string("Waltz No. 2 - "), string("Shostakovich"), &Waltz_No2_note [0], &Waltz_No2_beat [0], Waltz_No2_tempo, 135);
Song NOCTRUNE_IN_C_SHARP_MAJOR = Song(string("Nocturne in C "), string("sharp - Chopin"), &Nocturne_in_C_sharp_minor_note [0], &Nocturne_in_C_sharp_minor_beat [0], Nocturne_in_C_sharp_minor_tempo, 64);
Song SYMPHONY_NO40 = Song(string("Symphony No. 40 "), string("- Mozart"), &Symphony_No40_note [0], &Symphony_No40_beat [0], Symphony_No40_tempo, 168);
Song SYMPHONY_NO5 = Song(string("Symphony No. 5 -"), string("Beethoven "), &Symphony_No5_note [0], &Symphony_No5_beat [0], Symphony_No5_tempo, 116);
Song EINE_KLEINE_NACHTAMUSIK = Song(string("Eine Kleine "), string("Nachtamusik"), &Eine_Kleine_Nachtamusik_note [0], &Eine_Kleine_Nachtamusik_beat [0], Eine_Kleine_Nachtamusik_tempo, 173);

#endif