//Jay Rosen
//This program reads rain2014.txt into an array and calculates the total, average, maximum, and minimum rainfall for the year.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// RainFall class declaration
class RainFall
{
private:
	string name;									//Store the array for the named months
	float rain;										//Store the array for the rainfall float data
	float total, average, min, max;					//Variables to be calculated
	int indexMin, indexMax;							//Hold the index locations for array
	void driestMonth(float[], int, string[]);		//Function to calculate the driest month utilizing the float data array, number of months, and array of monthly names
	void wettestMonth(float[], int, string[]);		//Function to calculate the driest month utilizing the float data array, number of months, and array of monthly names
	void totalRainfall(float[], int);				//Function to calculate total rainfall,  passing the float data array and number of months
	void averageRainfall(float, int);			    //Function to calculate the average rainfall, passing the float total and number of months

public:
	void displayReport();							//Function to open txt file, read data into array, call and display the results of all other RainFall members		
	ifstream txt;								    //Store 2014rain.txt file

}; // End RainFall class declaration


   // Program that uses the RainFall class

   /**************************************************************
   *               RainFall::displayReport                       *
   * This function reads the data of 2014rain.txt                *
   * and initalizes the parallel arrays for both the name of the *
   * month and the corresponding rainfall for that month.        *
   * The parallel arrays are then passed to the rest of RainFall *
   **************************************************************/
void RainFall::displayReport()
{
	// The number of months of the year
	const int MONTHS = 12;

	// name is an array of 12 strings, initalized to the named months of the year
	string name[MONTHS] =
	{ "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December" };

	//rain is an array of 12 floats
	float rain[MONTHS];
	int count = 0;

	//open and check if the 2014rain.txt file is accessible to program
	ifstream txt;
	txt.open("rain2014.txt");
	if (!txt)
		cout << "Error opening data file\n";

	//initalize the rain array with the 12 line items of the 2014rain.txt
	else
	{
		while (count < MONTHS && txt >> rain[count])
			count++;
		txt.close();

		cout << "\n\n";
		cout << "\t\t+-------------------------------------+\n";
		cout << "\t\t| 2014 Rain Report for Alachua County |\n";
		cout << "\t\t+-------------------------------------+\n";

		//Display the parallel arrays for name of month and monthly rainfall after reading the file
		for (count = 0; count < MONTHS; count++)
		{
			cout << "\t\t|\t" << name[count] << setw(6) << "\t" << setprecision(3) << rain[count] << "\t      |" << endl;
		}
		cout << "\t\t+-------------------------------------+\n\n\t";
	}

	totalRainfall(rain, MONTHS);     //calculate and display the total and average

	driestMonth(rain, MONTHS, name);  //calculate the driest month
	cout << "\tThe least amount of rain fell in " << name[indexMin] << " with " << min << " inches \n\n";

	wettestMonth(rain, MONTHS, name);  //calculate the wettest month
	cout << "\tThe most rain fell in " << name[indexMax] << " with " << max << " inches \n\n";

}

/**************************************************************
*               RainFall::totalRainfall                       *
* This function sums up the total rainfall for the            *
* year using the data in the rain array. The paramater array  *
* holds the rainfall data, and the parameter size holds months *
**************************************************************/
void RainFall::totalRainfall(float array[], int size)
{
	float total = 0.0;
	for (int count = 0; count < size; count++)		//Loop to accumulate the running total
		total += array[count];
	cout << "Total Rainfall  " << total << " inches \n\n";

	averageRainfall(total, size);  //calculate and display the average
}

/**************************************************************
*               RainFall::averageRainfall                     *
*  This function averages up the total rainfall for the       *
* year using the data in the rain array. The paramater sum    *
* holds the total, and the parameter size holds months        *
**************************************************************/
void RainFall::averageRainfall(float sum, int size)
{
	average = sum / size;
	cout << "\tAverage Rainfall  " << average << " inches \n\n";
}


/*************************************************************
*                  RainFall::driestMonth                         *
* This function determines the lowest number in the rain array   *
* Parameter array holds the rainfall data						 *
* Parameter size holds the number of elements in the array.      *
* Parameter name holds the array for months						 *
*************************************************************/
void RainFall::driestMonth(float array[], int size, string name[])
{
	int k;
	min = array[0];
	for (k = 1; k < size; k++)
	{
		if (array[k] < min)
		{
			min = array[k];
			indexMin = k;
		}
	}
}

/*************************************************************
*                  RainFall::wettestMonth                        *
* This function determines the highest number in the rain array  *
* Parameter array holds the rainfall data						 *
* Parameter size holds the number of elements in the array.      *
* Parameter name holds the array for months						 *
*************************************************************/
void RainFall::wettestMonth(float array[], int size, string name[])
{
	int j;
	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
		{
			max = array[j];
			indexMax = j;
		}
	}
}

//Drier Program
int main()
{
	RainFall AnnualRainfall;		//Create AnnualRainfall object of the RainFall class

	cout << "\n\t This program calculates the Annual Rainfall Report.";
	cout << "\n\t Make sure 'rain2014.txt' is located in the current directory.";
	cout << "\n\n\t Press ENTER to continue . . .";
	cin.get();

	AnnualRainfall.displayReport();	//Call displayReport member of RainFall class

	cout << "\n\n\t\t";

	system("pause");
	return 0;
}



