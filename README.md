# unit_converter

To build and run:

    `cd unit_converter`
    `make`
    `./UnitConverter`

    To run unit tests
    `./UnitConverter TEST

How I would further improve the code with more time:

    * Would implement proper argument parsing rather than cin, removing the need for if/else statements which are checking for valid input (getopt would be an option).

    * The above would make it easier to implement better error handling also.

    * The amount of if statements would be less as with proper arugment handling, by the time the arguments get to the methods which do the work, we can trust that they are valid, thus wont need to do so many checks.

    * Compile tests seperately and not have them run from main method

Easy to extend?

    Extending without the above argument handling would be slightly tedious as there would be multiple spots in the code that new if else statements would be required when checking conversion types.

    If adding a new type ( not volume / temperature ) you would need to create a new function, along with the inline functions, and add the new function to the switch statement checks in "parse" function 

    If adding a new conversion type (ie US tea spoon), you would need to create the inline function with the math, then add an extra set of if/else statements for all its possible conversions (as well as updating the other unit's statements... the tedious part...)

Changes:

    Originally my code wasn't testable due to the way I wrote my functions. Did a quick refactor and made all fucntions require arguments. Now they can easily be tested.