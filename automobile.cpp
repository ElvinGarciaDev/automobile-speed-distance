//          CSC237 Project2: Automobile Speed/Distance Application Program
// Student: Elvin Garcia
// Due date: Saturday, October 16, 2021
// Description:
//      simulates the speed of a car and 
//     calculates the distance traveled over a period of time. 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function prototype
void Accelerate(int& PreviousSpeed, int& CurrentSpeed, int& Delta);
void Break(int& PreviousSpeed, int& CurrentSpeed, int& Delta);
void Cruise(int& PreviousSpeed, int& CurrentSpeed);
void UpdateDistanceTraveled(int& PreviousSpeed, int& CurrentSpeed, double& IntervalFeetTraveled, int& TimeInterval, double& TotalFeetTraveled);
void outputStatusHeader();
void outputStatus(string command, string state, int CurrentSpeed, double IntervalFeetTraveled, double TotalFeetTraveled);
void DisplayHelp();
void Demo(string command, string state, int &CurrentSpeed, double &IntervalFeetTraveled, double &TotalFeetTraveled, int &Delta, int &TimeInterval, int &PreviousSpeed);

int main()
{
    int CurrentSpeed = 0; //Current speed of the car (miles per hour)
    int PreviousSpeed = 0; //Speed of the car at the end of the “previous” time interval (miles per hour)
    double TotalFeetTraveled = 0; // Total feet traveled by the car (since the program started)
    double IntervalFeetTraveled = 0; //Total feet traveled during the most recent time interval
    int TimeInterval = 1;
    int Delta = 5;

    //Variables for command
    string Accelerate = "Accelerate", Break = "Brake", Cruise = "Cruise";
    //Variable for state
    string Accelerating = "Accelerating", Braking = "Braking", Cruising = "Cruising", Stopped = "Stopped";

    outputStatusHeader(); //Print column headings to the console

    bool choice = true; //Control the while loop. 
    while (choice == true) //Runs until choice = false. 
    {
        char Select; //holds the users selection

        cout << "Command: ";
        cin >> Select;

        if (Select == 'a' || Select == 'A')
            Demo(Accelerate, Accelerating, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);

        if (Select == 'b' || Select == 'B')
        {
            if (CurrentSpeed <= 0) //If Current car speed is equal to 0 or less the car can not go in reverse. it will stay stopped
                Demo(Break, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);                        
            else //If car speed is more than 0. 
                Demo(Break, Braking, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
        }

        if (Select == 'c' || Select == 'C')
        {
            if (CurrentSpeed <= 0) //If Current car speed is equal to 0 or less the car can not go into cruise because it is stopped.
                Demo(Cruise, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
            else //If car has a speed greater than 0.
                Demo(Cruise, Cruising, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
        }

        if (Select == 'h' || Select == 'H') //If the user enteres h, it prints the command menu
            DisplayHelp();

        if (Select == 'q' || Select == 'Q')
            choice = false; //If user enteres q, choice will equal false and terminate the loop. 

        if (Select == 'd' || Select == 'D') //If the user enteres d the program execute a predetermined sequence.
        {
            //predetermined sequence
             Demo(Cruise, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Accelerate, Accelerating, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Accelerate, Accelerating, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Accelerate, Accelerating, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Accelerate, Accelerating, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Accelerate, Accelerating, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Cruising, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Cruising, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Cruising, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Cruising, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Cruise, Cruising, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Braking, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Braking, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Braking, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Braking, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);                        
             Demo(Break, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
             Demo(Break, Stopped, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled, Delta, TimeInterval, PreviousSpeed);
        }
    }
    return 0;
}

//************************
//Accelerate Function
//************************
void Accelerate(int& PreviousSpeed, int& CurrentSpeed, int& Delta)
{
    PreviousSpeed = CurrentSpeed;
    CurrentSpeed = CurrentSpeed + Delta; //If accelerating add 5 to the current speed. 
}

//************************
//break Function
//************************
void Break(int& PreviousSpeed, int& CurrentSpeed, int& Delta)
{
    PreviousSpeed = CurrentSpeed;
    CurrentSpeed = CurrentSpeed - Delta; //If breaking, remove 5 from the current speed
}

//************************
//Cruise Function
//************************
void Cruise(int& PreviousSpeed, int& CurrentSpeed)
{
    PreviousSpeed = CurrentSpeed; //If cruising, keep the same speed. 
}

//************************
//Update Distance and 
//intervel traveled
//************************
void UpdateDistanceTraveled(int& PreviousSpeed, int& CurrentSpeed, double& IntervalFeetTraveled, int& TimeInterval, double& TotalFeetTraveled)
{
    //Calculations to update total feet traveled and Interval Feet 
    double averageSpeed;
    double averageSpeed_FeetPerSecond;

    averageSpeed = (PreviousSpeed + CurrentSpeed) / 2.0;
    averageSpeed_FeetPerSecond = averageSpeed * 5280.0 / 3600.0;

    IntervalFeetTraveled = averageSpeed_FeetPerSecond * TimeInterval;
    TotalFeetTraveled = TotalFeetTraveled + IntervalFeetTraveled;
}

//************************
//Display columns
//************************
void outputStatusHeader()
{
    cout << "\t \t Function \t Current State \t \t Curremt Speed \t \t Interval Distance \t \t Total Feet traveled " << endl;
}

//************************
//Display status
//************************
void outputStatus(string command, string state, int CurrentSpeed, double IntervalFeetTraveled, double TotalFeetTraveled)
{
    cout << fixed << showpoint << setprecision(1);
    cout << "\t \t " << command << " \t \t " << state << " \t \t  " << CurrentSpeed << " \t \t \t " << IntervalFeetTraveled << " \t \t \t \t \t " << TotalFeetTraveled << endl;
}

//************************
//Display help
//************************
void DisplayHelp()
{
    cout << "Supported commands: \n"
        << "\t Accelerate \t\t\t accelerate. \n"
        << "\t Break \t\t\t break. \n"
        << "\t Cruise \t\t\t cruise. \n"
        << "\t d \t\t\t demo. \n"
        << "\t h \t\t\t print this help text. \n"
        << "\t q \t\t\t quit. (end the program). \n";
}

//****************************
//Demo function that holds all 
//the caculations together. 
//***************************
void Demo(string command, string state, int &CurrentSpeed, double &IntervalFeetTraveled, double &TotalFeetTraveled, int &Delta, int &TimeInterval, int &PreviousSpeed)
{
             if (command == "Accelerate")
             {
                Accelerate(PreviousSpeed, CurrentSpeed, Delta);
                UpdateDistanceTraveled(PreviousSpeed, CurrentSpeed, IntervalFeetTraveled, TimeInterval, TotalFeetTraveled);
                outputStatus(command, state, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled);
             }

             if (command == "Brake")
            {
                if (CurrentSpeed <= 0)
                {
                IntervalFeetTraveled = 0;
                CurrentSpeed = 0;
                outputStatus(command, state, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled);
                }
                else
                {
                Break(PreviousSpeed, CurrentSpeed, Delta);
                UpdateDistanceTraveled(PreviousSpeed, CurrentSpeed, IntervalFeetTraveled, TimeInterval, TotalFeetTraveled);
                outputStatus(command, state, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled);
                }
            }

            if (command == "Cruise")
            {
                Cruise(PreviousSpeed, CurrentSpeed);
                UpdateDistanceTraveled(PreviousSpeed, CurrentSpeed, IntervalFeetTraveled, TimeInterval, TotalFeetTraveled);
                outputStatus(command, state, CurrentSpeed, IntervalFeetTraveled, TotalFeetTraveled);
            }
}
