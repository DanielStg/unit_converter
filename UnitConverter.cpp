#include <iostream>
#include <string.h>
#include "tests.h"
#include "UnitConverter.h"

using namespace std;

/* Inline temperature functions with the math */

float temperature(float temp, char currentType, char newType)
{

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
            cerr << "Not a convertable type\n";
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
            cerr << "Not a convertable type\n";
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
        cerr << "Not a convertable type\n";
    }
    return temp;
}

float volume(float vol, char currentType, char newType)
{
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
            cerr << "Not a convertable type\n";
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
            cerr << "Not a convertable type\n";
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
            cerr << "Not a convertable type\n";
        }
    }
    //error invalid type
    else{
        cerr << "Not a convertable type\n";
    }
    return vol;
}

void print_type()
{
    cout << "\nWhat are you converting? (Press the letter relevant to you)\n";
    cout << "t  - temprature\n";
    cout << "v  - Volume\n";
    cout << "\nq  - QUIT\n";
}

void print_temp()
{
    cout << "\nEnter the temperature, followed by the current unit, then the unit to convert to\n";
    cout << "F  - Farenheit\n";
    cout << "C  - Celcius\n";
    cout << "K  - Kelvin\n";
    cout << "Exmaple conversion from Celcius to Farenheit:   100 C F\n";
}

void print_vol(){
    cout << "\nEnter the volume, followed by it's current unit, then the unit to convert to\n";
    cout << "l  - Litre\n";
    cout << "m  - Millilitre\n";
    cout << "g  - US liquid gallon\n";
    cout << "Exmaple conversion from Litre to Millilitre:   100 l m\n";
}

int main(int argc, char **argv)
{

    int err = 0;
    char inputType;

    float unit = 0;
    char curr_type;
    char new_type;

    float output;

    if ( argc > 1){
        if( strcmp(argv[1], "TEST") == 0 ){

            err = run_tests();

            if( err == 0 ){
                cout << "ALL TESTS PASSED\n";
                return 0;
            }
            else{
                cout << "1 OR MORE TESTS FAILED\n";
                return 1;
            }
        }
    }

    //Run
    while( true )
    {
        print_type();
        cin >> inputType;

        switch(inputType){
            case 'q':
                return 0;
            case 't':
                print_temp();
                cin >> unit >> curr_type >> new_type;
                output = temperature(unit, curr_type, new_type);
                cout << "\033[1;31m=== Result: " << output << " ===\033[0m\n";
                continue;
            case 'v':
                print_vol();
                cin >> unit >> curr_type >> new_type;
                output = volume(unit, curr_type, new_type);
                cout << "\033[1;31m=== Result: " << output << " ===\033[0m\n";
                continue;
            default:
                cerr << "Invalid type\n";
                continue;

        }
    }
    return 0;
}