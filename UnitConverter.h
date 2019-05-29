#ifndef UNIT_H
#define UNIT_H

float temperature(float temp, char currentType, char newType);
float volume(float vol, char currentType, char newType);

/* Inline temperature functions with the math */
inline float FAREN_TO_CEL(float temp){ return (temp - 32) * double(5)/double(9); }
inline float FAREN_TO_KEL(float temp){ return (temp - 32) * double(5)/double(9) + 273.15; }

inline float CEL_TO_FAREN(float temp){ return (temp * 9/5 ) + 32; }
inline float CEL_TO_KEL(float temp){ return temp + 273.15; }

inline float KEL_TO_CEL(float temp){ return temp - 273.15; }
inline float KEL_TO_FAREN( float temp){ return (temp - 273.15) * double(9)/double(5) + 32; }

/* Inline Volume functions with the math */
inline float LITRE_TO_MILLI(float vol){ return vol * 1000; }
inline float LITRE_TO_GAL(float vol){ return vol / 3.785; }

inline float MILLI_TO_LITRE(float vol){ return vol / 1000; }
inline float MILLI_TO_GAL(float vol){ return vol / 3785.412;  }

inline float GAL_TO_LITRE(float vol){ return vol * 3.785; }
inline float GAL_TO_MILLI(float vol){ return vol * 3785.412; } 

#endif
