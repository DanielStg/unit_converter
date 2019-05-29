#include <iostream>
#include <string.h>
#include "UnitConverter.h"

#ifndef TESTS_H
#define TESTS_H

using namespace std;

//Example of how I would test the math
int test_math(){

    float litre_in = 1;
    float expected_mil_out = 1000;
    float mil_out = 0;

    mil_out = LITRE_TO_MILLI(litre_in);

    if( mil_out == expected_mil_out )
        return 0;
    else
        return 1;
    
}

//Example of how I would test correct converion types
int test_types_correct(){
    char litre = 'l';
    char milli = 'm';

    char cel = 'C';
    char far = 'F';

    int output_vol = 0;
    int output_temp = 0;

    output_vol = volume(1, litre, milli);
    output_temp = temperature(1, cel, far);

    //The conversion wont take place if types are invalid, so the original unit will be returned.
    if( output_vol != 1 && output_temp != 1)
        return 0;
    else
        return 1;
}

//Exmaple of how I would test incorrect converion types
int test_types_incorrect(){

    char litre = 'l';
    char milli = 'm';

    char cel = 'C';
    char far = 'F';

    int output_vol = 0;
    int output_temp = 0;

    output_vol = volume(1, litre, cel);
    output_temp = temperature(1, cel, milli);

    //The conversion wont take place if types are invalid, so the original unit will be returned.
    if( output_vol == 1 && output_temp == 1)
        return 0;
    else
        return 1;
}

int run_tests(){

    int err = 0;
    cout << "RUNNING TESTS\n";
    if ( test_math() == 0 )
        cout << "test_math PASSED!\n";
    else{
        cout << "test_math FAILED!\n";
        err = 1;
    }

    if ( test_types_correct() == 0 )
        cout << "test_types_correct PASSED!\n";
    else{
        cout << "test_types_correct FAILED!\n";
        err = 1;
    }

    if( test_types_incorrect() == 0)
        cout << "test_types_incorrect PASSED!\n";
    else{
        cout << "test_types_incorrect FAILED!\n";
        err = 1; 
    }
    //call tests
    return err;
}

#endif


