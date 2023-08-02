#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "EasyBMP.h"
#include "Colour.h"
#include "Triangle.h"
#include "Gasket.h"
#include "DisplayBackground.h"
using namespace std;


// main program to test class Rectangle
// Creates and prints a rectangle
int main()
{
    //Please note that this is the correct location for BMP myImage
    //The program will work if you make this declaration global (as indicated in lab writeup)
    //However global variables should not be used as arguments of functions
    BMP myImage;
    Colour C1(0, 0, 255, 255);     //dark blue
    Colour C2(0, 0, 0, 255);	   //black
    Colour CB(0, 255, 0, 255);     //green
    Colour C3(255,0,0,255);		   //red
    Colour C4(128,128,128,128);	   //grey
    Colour C5( 100, 200, 255, 170);//light blue
    Colour C6( 255, 0, 255, 255);  //Pink
	Colour C7( 255, 255, 0, 255 ); //Yellow
	Colour C8( 155, 155,255,255);  //Purple

    cout << "BEGIN GASKET TEST" << endl << endl;

    //Gasket test here




    cout << "TESTING CONSTRUCTORS: ON AND OFF PAGE" << endl;
    InitBackground(myImage, CB, 600, 800);
    cout << endl << "Constructor 4 arguments, xLocation off page:: RED" << endl;
	cout << "create g6" << endl;
    Gasket G6(2, 606, 300, 480, C3);
    G6.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G6.GasketPrint();
    cout << endl << "Constructor 4 arguments, yLocation off page:: LIGHT BLUE" << endl;
	cout << "create g7" << endl;
    Gasket G7(0, 300, 811, 321, C5);
    G7.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G7.GasketPrint();
    cout << endl << "Contructor with 4 arguments x and y off page: YELLOW" << endl;
	cout << "create G1" << endl;
    Gasket G0(1, -1, -1, 270, C7);
	G0.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
	G0.GasketPrint();
	cout << "create G0" << endl;
	cout << endl << "Default constructor: BLACK" << endl;
	Gasket G1;
    G1.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G1.GasketPrint();
    cout << endl << "Constructor with 4 arguments on page: PURPLE" << endl;
	cout << "create G2" << endl;
    Gasket G2(0, 50, 480, 340, C8);
    G2.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G2.GasketPrint();
    cout << endl << "Constructor 4 arguments, sidelength (x) beyond edge of page: GREY" << endl;
	cout << "create G3" << endl;
    Gasket G3(1, 350, 330, 280, C4);
    G3.GasketDisplay(myImage, 1, "GasketConstructors.bmp");
    G3.GasketPrint();
    cout << endl << "Constructor 4 arguments, sideLength (y) beyond edge of page: DARK BLUE" << endl;
	cout << "create g5" << endl;
    Gasket G5(1, 40, 700, 200, C1);
    G5.GasketDisplay(myImage, 1, "GasketConstructors.bmp");
    G5.GasketPrint();
	cout << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: YELLOW" << endl;
	cout << "create G8" << endl;
	Gasket G8( 1, 400, 600, 300, C7);
	G8.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G8.GasketPrint();
	cout << endl << endl << endl;
	cout << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: GREY" << endl;
	cout << "create G9" << endl;
	Gasket G9( 1, 400, 700, 300, C4);
	G9.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G9.GasketPrint();
	cout << endl << endl << endl;

    cout << "TESTING COPY CONSTRUCTOR" << endl;
    cout << "gasket to copy" << endl;
    G5.GasketPrint();
    Gasket G10(G5);
    cout << "copied gasket" << endl;
    G10.GasketPrint();
    cout << endl << endl << endl;


    ResetBackground(myImage, CB, 600, 800);
    cout << endl << "changing side length of G0 from 270 to 150: ";
	cout << " :displayed in YELLOW" << endl;
    G0.SetSideLength(150);
    G0.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G0.GasketPrint();
    cout << endl << "changing xlocation and ylocation of G1"<< endl;
	cout << "xlocation to 150 ylocation to 200: "  << endl;
	cout << "displayed in BLACK" << endl;
    G1.SetXLocation(100);
    G1.SetYLocation(200);
    G1.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G1.GasketPrint();
    cout << "moving y location of G7 so gasket is partially off the page" << endl;
    cout << "yLocation set to 675: displayed in LIGHT BLUE" << endl;
    G7.SetYLocation( 675 );
    G7.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G7.GasketPrint();
	cout << "moving y location of G7 and increasing sideLength" << endl;
    cout << "yLocation set to 575 sideLength to 300: displayed in LIGHT BLUE" << endl;
    G7.SetYLocation( 575 );
	G7.SetSideLength(300);
    G7.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G7.GasketPrint();
	cout << "TESTING MUTATORS" << endl;
    cout << "changing G2 colour from light blue: ";
    cout << "displayed in RED" << endl;
    G2.SetGasketColour(C3);
    G2.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G2.GasketPrint();
    cout << "changing G2 number of iterations from 1 to 3: " ;
    cout << "displayed in YELLOW" << endl;
    G2.SetGasketColour(C7);
    G2.SetIterations(3);
    G2.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G2.GasketPrint();
    cout << "moving xLocation of G6 so gasket is partially off the page" << endl;
    cout << "xLocaton set to 300: displayed in RED" << endl;
    G6.SetXLocation(300);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();
	cout << "moving yLocation of G6 to 250, changing colour: " << endl;
    cout << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(250);
	G6.SetGasketColour(C1);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();
	cout << "moving yLocation of G6 to 375, changing iterations to 0: " << endl;
    cout << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(375);
	G6.SetIterations(0);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();
	cout << "moving yLocation of G6 to 675, xLocation to 475: " << endl;
    cout << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(675);
	G6.SetXLocation(375);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();



    cout << "Producing on page gaskets for 2 to 4 iterations";
    for (int k=2; k <= 5; k++)
    {
		string myFileName;
    	ostringstream numString;
    	numString << k;

        myFileName="BitFileG";
        myFileName += numString.str();
        myFileName += ".bmp";
        Gasket G4(k, 50, 200, 500, C2);
        ResetBackground(myImage,C3, 600, 800);
        G4.GasketDisplay(myImage, 0, myFileName);
    }

    return 0;
}


