/*
Kyle Free
COSC 1436 - Programming Fundamentals I
4/18/23
Forensics Program

This program uses two functions to return values based on the values of the their parameters.

There is a namespace with one class and two functions. The two functions are the required funtions
    getHairType(float, float) and getHeight(bool, double)
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace WeekSixAssignment {
    // Function prototypes
    bool getHairType(float medullaDiameter, float entireHair);
    float getHeight(bool gender, double femurLength);

    // Forensics class, used to store data about the "case"
    class Forensics {
        public:
        // Attributes
        double
            medullaDiameter,
            entireHair,
            femurLength;

        bool gender; // False for male, True for female

        // Constructor
        Forensics() :
            medullaDiameter(0.0),
            entireHair(0.0),
            femurLength(0.0)
                { Run(); }

        // getHairInfo() starts gets the information for the hair analysis
        void getHairInfo() {

            cout
                << "\nHair Analysis:\n"
                << "Please enter the medulla width in millimeters: ";
            cin >> medullaDiameter;
            inputNumberValidation(medullaDiameter);

            cout
                << "Please enter the entire hair width in millimeters: ";
            cin >> entireHair;
            inputNumberValidation(entireHair);

            cout << endl;
        }

        // getHeightInfo() gets the information for the height analysis
        void getHeightInfo() {
            
            string gender; // temp string variable to store the user input 

            cout
                << "Height Analysis:\n"
                << "Please enter the gender of the person: ";
            cin >> gender;
            inputGenderValidation(gender);

            cout
                << "Please enter the femur length in centimeters: ";
            cin >> femurLength;
            inputNumberValidation(femurLength);

            cout << endl;

            //cout << boolalpha << this->gender << endl;
        }

        // Run() runs the program
        void Run() {

            cout << "Welcome, Inspector!" << endl;

            getHairInfo();
            getHeightInfo();
        }

        private:
        // inputNumberValidation(T) uses the number input reference to check if a value is greater than zero
        template <typename T>
        void inputNumberValidation(T &input) {

            while (input <= 0.0) {

                cout << "Please enter a number greater than 0: ";
                cin >> input;
            }
        }

        // inputGenderValidation(string) uses the string input reference to switch characters to lower case,
        //  and then checks to see if the input matches the available options,
        //  then assigns the gender of the Forensics object
        void inputGenderValidation(string &input) {
            // This loop makes all characters lower case
            for (char &c : input)
                c = tolower(c);

            //cout << input << endl;

            while (input != "male" && input != "female") {

                cout << "Enter either \"male\" or \"female\": ";
                cin >> input;

                for (char &c : input)
                    c = tolower(c);
            }
            // Assign gender
            if (input == "male") this->gender = false;
            else if (input == "female") this->gender = true;
        }
    };

    // getHairType(float, float) returns whether the hair belongs to a human or an animal
    bool getHairType(float medullaDiameter, float entireHair) {
        // if the ratio of the thickness to the length of the hair is greater than or equal to 0.5
        if (medullaDiameter / entireHair >= 0.5)
            return false; // Animal hair
        else
            return true; // Human Hair
    }

    // getHeight(bool, double) returns the calculation of the height based on gender and femur length
    float getHeight(bool gender, double femurLength) {
        // Perform different operations based on the gender
        if (!gender) // if male
            return 69.089 + (2.238 * femurLength);
        else //  else female
            return 61.412 + (2.317 * femurLength);
    }
}

using namespace WeekSixAssignment;

// Driver Function
int main() {

    Forensics run; // Create Forensics object

    cout
        << "The sample provided is from ";
    
    getHairType(run.medullaDiameter, run.entireHair) ? // Check hair type
        cout << "a human." << endl
    :
        cout << "an animal." << endl;

    cout
        << "The height of the ";
    
    (run.gender == 0) ?
        cout << "male "
    :
        cout << "female ";

    cout
        << "is estimated to be "
        << getHeight(run.gender, run.femurLength) // Calculate height
        << " centimeters."
        << endl;

    return 0;
}