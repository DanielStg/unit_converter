#include <iostream>

// Can you write a unit converter that can do the following:

// Convert between the following temperature units: Kelvin (K), Celsius (°C) and Fahrenheit (°F).
// Convert between the following volume units: Litre (l), Millilitre (ml), US liquid gallon (US gal).
// Expected interface:

// Input parameters: input value, input unit, output unit
// Return: output value
// Mixing unit types should not be allowed, e.g. temperature units cannot be converted to volume units.
// Design it in such a way that it can easily be extended to other unit types and units in future.
// Write some unit tests to show how you would test your unit converter.

//Create macros for the temp conversions
//Create macros for the volume conversions
using namespace std;

/* Inline temperature functions with the math */
inline float FAREN_TO_CEL(float temp){ return (temp - 32) * double(5)/double(9); }
inline float FAREN_TO_KEL(float temp){ return (temp - 32) * double(5)/double(9) + 273.15; }

inline float CEL_TO_FAREN(float temp){ return (temp * 9/5 ) + 32; }
inline float CEL_TO_KEL(float temp){ return temp + 273.15; }

inline float KEL_TO_CEL(float temp){ return temp - 273.15; }
inline float KEL_TO_FAREN( float temp){ return (temp - 273.15) * double(9)/double(5) + 32; }

/* Inline Volume functions with the math */

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

    return 0;  
}

int parse(){

    char input;
    float output;

    cout << "What are you converting? (Press the letter relevant to you)\n";
    cout << "t  - temprature\n";
    cout << "v  - Volume\n";
    cin >> input;

    switch(input){
        case 't':
            output = temperature();
            break;
        case 'v':
            volume();
            break;
        default:
            cout << "Sorry that wasn't a valid case, try again.\n";
            return 1;
    }
        
    cout << "Result: " << output << endl;
    return 0;
}

int main(){

    int err = 1;
    std::cout << "hello, lets convert!" << std::endl;

    while( err != 0 )
    {
        err = parse();
    }

    return 0;
}