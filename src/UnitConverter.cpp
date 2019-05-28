#include <iostream>

// Write some unit tests to show how you would test your unit converter.

using namespace std;

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

float temperature(){

    float temp = 0;
    char currentType;
    char newType;
    

    cout << "\nEnter the temperature, followed by the current unit, then the unit to convert to\n";
    cout << "F  - Farenheit\n";
    cout << "C  - Celcius\n";
    cout << "K  - Kelvin\n";
    cout << "Exmaple conversion from Celcius to Farenheit:   100 C F\n";

    cin >> temp >> currentType >> newType;

    //Convert from farenheit
    if( currentType == 'F'){

        if( newType == 'C'){
            temp = FAREN_TO_CEL(temp);
        }
        else if( newType == 'K'){
            temp = FAREN_TO_KEL(temp);
        }
        else{
            //Error invalid type
            cout << "Not a convertable type\n";
        }
    }
    //Convert from celcius
    else if( currentType == 'C'){
        if( newType == 'F'){
            temp = CEL_TO_FAREN(temp);
        }
        else if( newType == 'K'){
            temp = CEL_TO_KEL(temp);
        }
        else{
            cout << "Not a convertable type\n";
        }

    }
    //convert from kelvin
    else if ( currentType == 'K'){
        if( newType == 'F'){
            temp = KEL_TO_FAREN(temp);
        }
        else if( newType == 'C'){
            temp = KEL_TO_CEL(temp);
        }
        //Error invalid type
        else{
            cout << "Not a convertable type\n";
        }
    }
    //error invalid type
    else{
        cout << "Not a convertable type\n";
    }
    return temp;
}

float volume(){

    float vol = 0;
    char currentType;
    char newType;

    cout << "\nEnter the volume, followed by it's current unit, then the unit to convert to\n";
    cout << "l  - Litre\n";
    cout << "m  - Millilitre\n";
    cout << "g  - US liquid gallon\n";
    cout << "Exmaple conversion from Litre to Millilitre:   100 l m\n";

    cin >> vol >> currentType >> newType;
    //Convert from farenheit
    if( currentType == 'l'){

        if( newType == 'm'){
            vol = LITRE_TO_MILLI(vol);
        }
        else if( newType == 'g'){
            vol = LITRE_TO_GAL(vol);
        }
        else{
            //Error invalid type
            cout << "Not a convertable type\n";
        }
    }
    //Convert from celcius
    else if( currentType == 'm'){
        if( newType == 'l'){
            vol = MILLI_TO_LITRE(vol);
        }
        else if( newType == 'g'){
            vol = MILLI_TO_GAL(vol);
        }
        else{
            cout << "Not a convertable type\n";
        }

    }
    //convert from kelvin
    else if ( currentType == 'g'){
        if( newType == 'l'){
            vol = GAL_TO_LITRE(vol);
        }
        else if( newType == 'm'){
            vol = GAL_TO_MILLI(vol);
        }
        //Error invalid type
        else{
            cout << "Not a convertable type\n";
        }
    }
    //error invalid type
    else{
        cout << "Not a convertable type\n";
    }
    return vol;
}

int parse(){

    char input;
    float output;

    cout << "\nWhat are you converting? (Press the letter relevant to you)\n";
    cout << "t  - temprature\n";
    cout << "v  - Volume\n";
    cout << "\nq  - QUIT\n";

    cin >> input;

    //Switch between valid types
    switch(input){
        case 't':
            output = temperature();
            break;
        case 'v':
            output = volume();
            break;
        case 'q':
            return 1;
        default:
            cout << "Sorry that wasn't a valid case, try again.\n";
    }
        
    //Output red result
    cout << "\033[1;31m=== Result: " << output << " ===\033[0m\n";
    return 0;
}

int main(){

    int err = 0;

    //Run
    while( err == 0 )
    {
        err = parse();
    }

    return 0;
}