 /**
 *Joshua Whiteford
 *Lab 15
 *Sine Wave
 */

/**< Preprocessor Directives */
#include <iostream>
#include <tgmath.h>
#define  PI 3.14159265

using namespace std;

class SineWave
{
    /**< Private sector of the class only acessable by this class */
private:
    double a;
    double Hz;
    double ptch;
    double DCoff;
    double T;
    double Vin;
    double t;
    double Vrms;

    /**< Public sector, this area of the class can be accessed externally, eg from other functions */
public:
    SineWave(void)
    {
        /**< Preset variables */
        a = 1;
        Hz = 1000;
        ptch = 0;
        DCoff = 0;
    }

    /**< Gets the User to enter values for Amplitude, Frequency, angle, DCOffset, Time */
    void Values(void)
    {
            cout << "Enter a value for the Amplitude: " << endl;
			cin >> a;
			cout << "Enter a value for Frequency: " << endl;
			cin >> Hz;
			cout << "Enter a value for angle: " << endl;
			cin >> ptch;
			cout << "Enter value for DCOffset: " << endl;
			cin >> DCoff;
			cout << "Enter value for Time: " << endl;
			cin >> T;
    }


    /**< Part of the class that will calclate Vin, where the user enters in Values to be used! */
    void instantV(double P)
    {
        Vin = a*sin(2*PI*Hz*P + (ptch * PI) / 180.0) + DCoff;

        cout << "Vin: " << Vin << "Volts" << endl;
    }
    /**< Part of the class that will calculat the Period of the Waveform */
    void Period(void)
    {
        t = 1/Hz;

         cout << "The Period is: " << t << "s" << endl;
    }
    /**< Part of the Class that will calculate the RMSVoltage */
    void rmsVolt(void)
    {
        Vrms = a/(sqrt(2));

        cout << "Vrms: " << Vrms << "V" << endl;
    }

};
/**< The main Function */
int main()
{
    /**< Sets up & links the class SineWave to this function and creates two variables, Sine1 & Sine2 */
    SineWave sine1, sine2;
    /**< Variable Decliration  */
    double time;

    /**< Introduces the User and Explains how the Program works */
    cout << "On the First run of the program, Preset Variables will be used! " << endl;

    /**< Getting the User to enter in a Time */
    cout << "Enter a value for time: " << endl;
    cin >> time;

    /**< Calls the Functions in the Class using Sine1 */
    sine1.instantV(time);
    sine1.Period();
    sine1.rmsVolt();

    /**< Calls the functions in the Class using Sine2, also calls the Function in the class that will set the preset variables above to user define values */
    cout << "You will now have to enter in values for the preset values above!: " << endl;
    sine2.Values();
    sine2.instantV(0);
    sine2.Period();
    sine2.rmsVolt();
    return 0;
}
