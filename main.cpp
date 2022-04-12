/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1) Concert
5 properties:
    1) number of musicians (int)
    2) the amount of ticket income (float)
    3) number of audience (int)
    4) the number of vendors around (int)
    5) number of bands attend (int)
3 things it can do:
    1) perform many songs 
    2) attract different audience
    3) charge audience
 */

/* Basketball Game
Thing 2)
5 properties:
    1) number of players (int)
    2) number of coaching staff (int)
    3) price of the ticket (double)
    4) number of referee (int)
    5) number of monitors (int)
3 things it can do:
    1) show different angle to audience
    2) host the game
    3) make profit
 */

/*
Thing 3) Product Manufacturing
5 properties:
    1) number of production line (int)
    2) number of operators (int)
    3) number of engineers (int)
    4) the amount of products made per week (int)
    5) number of devices (int)
3 things it can do:
    1) assemble the products
    2) solve engineering problems
    3) increase the production rate
 */

/*
Thing 4) Guitar Tone Setting
5 properties:
    1) the value of amp gain (float)
    2) the number of guitar pedals (int)
    3) the drive level of a overdrive pedal (float)
    4) the number of reverb and delay pedals (int)
    5) the number of different types of guitars (int)
3 things it can do:
    1) level up the guitar sound
    2) make different sound effect
    3) create more playing style
 */

/*
Thing 5)
5 properties: transmitter
    1) hieght in m (int)
    2) width in m (int)
    3) distance in m (double)
    4) amount of power consumed (float)
    5) bandwidth (float)
3 things it can do:
    1) affect the data rate
    2) increase battery usage
    3) contain more frequency range
 */

/*
Thing 6)
5 properties: channel
    1) bit rate (float)
    2) number of ports (int)
    3) block size (double)
    4) number of packets dropped (int)
    5) channel IP address (float)
3 things it can do:
    1) affect the transmitted signal
    2) affect the data rate
    3) decrease interference
 */

/*
Thing 7)
5 properties: converter
    1) number of analog to digital converter (int)
    2) number of digital to analog converter (int)
    3) amount of power consumed (double)
    4) number of circuits (int)
    5) the amount of the cost (double)
3 things it can do:
    1) convert analog signal to digital signal
    2) convert digital signal to analog signal
    3) construct the converter structure
 */

/*
Thing 8)
5 properties: modulation
    1) number of signal pilots (int)
    2) number of alphabets (int)
    3) bit rate (float)
    4) number of filters (int)
    5) the amount of access bandwidth (double)
3 things it can do:
    1) calculate the spectral efficiency
    2) estimate the unknown channels
    3) avoid signal aliasing
 */

/*
Thing 9)
5 properties: receiver
    1) height in m (double)
    2) width in m (double)
    3) distance in m (double)
    4) number of detections
    5) number of equalizers
3 things it can do:
    1) estimate the unknown channels
    2) calculate the bit error rate
    3) encode the signal
 */

/*
Thing 10)
5 properties: Communication System
    1) transmitters 
    2) channels
    3) converter
    4) modulation
    5) receiver
3 things it can do:
    1) transmit the signals
    2) modulate the signals
    3) receive the signals
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
