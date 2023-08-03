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

    cout << "BEGIN TRIANGLE TEST" << endl << endl;
    Triangle T1;
    Triangle T2( 280, 524, C6);
    Triangle T3( 250, 300, 325,  C3 );
    Triangle T4( 194, 70, 222,  C4);
    Triangle T5( 100, 490,277,  C5);
    Triangle T6(T3);

    cout << "TESTING THREE CONSTRUCTORS: Printing T1(default), T2(3arg) and T3(4arg)" << endl;
    cout << "ALSO TESTING PRINT FUNCTION" << endl;
    InitBackground(myImage, CB, 600, 800);
    T1.TrianglePrint();
    cout << endl;
    T2.TrianglePrint();
    cout << endl;
    T3.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING COPY CONSTRUCTOR" << endl;
    cout << "Triangle to copy" << endl;
    T3.TrianglePrint();
    cout << "Triangle created with copy constructor" << endl;
    T6.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING GETTERS" << endl;
	cout << "getting values from T6" << endl;
    T6.TrianglePrint();
    cout << endl;
    cout << "Getting Width " << T6.GetSideLength() << endl;
    cout << "Getting xLocation " << T6.GetXLocation() << endl;
    cout << "Getting yLocation " << T6.GetYLocation() << endl;
    cout << "Getting trianglesCreated " << T6.GetTrianglesCreated()<< endl;
    cout << "Getting trianglesExisting " << T6.GetTrianglesExisting() << endl;
    cout << "Getting blockColour " << T6.GetTriangColour() << endl;
    cout << endl << endl << endl;


    cout << "TESTING SETTERS: changing default values in T1 and T2" << endl;
        cout << "None of the following 6 changes result in a Triangle that"
	     << endl << " is partially or completely off the page" << endl;
	cout << endl << "T1 before changes" << endl;
	T1.TrianglePrint();
	cout << endl;
	cout << "setting R1.sideLength to 330" << endl;
    T1.SetSideLength(330);
    T1.TriangleDisplay(myImage, "triangleTest.bmp");
    cout << "setting R1.xLocation to 225"  << endl;
    T1.SetXLocation(225);
    T1.TriangleDisplay(myImage, "triangleTest.bmp");
    cout << "setting R1.yLocation to 440"  << endl;
    T1.SetYLocation(440);
    cout << "setting R1.TriangleColour to C7" << endl;
    T1.SetTriangColour(C7);
    cout << "modified R1" << endl;
    T1.TrianglePrint();
    cout << endl;
    cout << "T2 before changes" << endl;
    T2.TrianglePrint();
    T2.TriangleDisplay(myImage, "triangleTest.bmp");
    cout << endl << "setting sideLength to 50" << endl;
    T2.SetSideLength(210);
	cout << "modified R2" << endl;
    T2.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING DISPLAY OF TRIANGLES" << endl;
    T4.TriangleDisplay(myImage, "triangleTest.bmp");
    T3.TriangleDisplay(myImage, "triangleTest.bmp");
    T5.TriangleDisplay(myImage, "triangleTest.bmp");
    T1.TriangleDisplay(myImage, "triangleTest.bmp");
    T2.TriangleDisplay(myImage, "triangleTest.bmp");
    T6.SetSideLength(100);
    T6.SetTriangColour(C8);
    T6.TriangleDisplay(myImage, "triangleTest.bmp");
    cout << endl << endl << endl;


    cout << "TESTING = OPERATOR"<< endl;
    cout << "printing T3"<< endl;
    T3.TrianglePrint();
    cout << "printing T4" << endl;
	T4.TrianglePrint();
	cout << endl;
    cout << "printing T4 after T4=T3"<< endl;
    T4 = T3;
    T4.TrianglePrint();
    cout << endl << endl << endl;

    cout << "TESTING THE << OPERATOR" << endl;
    cout << "T5" << endl << T5;
    cout << endl << endl << endl;

    //Test the == operator
    cout << "Testing == answer should be true (1) " << (T3==T4);
    cout << endl;
    cout << "Testing == answer should be false (0) " << (T3==T1);
    cout << endl << endl << endl;

    cout << endl;
    cout << "TESTING TRIANGLES OVERLAPPING EDGES OF PAGE" << endl;
    cout << "AND TESTING TRIANGLES OUTSIDE THE PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    cout << "TRIANGLE BOTH xLocation AND yLocation OFF THE PAGE";
    cout << ": plotted Red" << endl;
    Triangle T10( -20, -100, 400, C3 );
    cout << endl;
    T10.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T10.TrianglePrint();
    cout << endl << "TRIANGLE, yLocation OFF THE PAGE";
    cout << ": plotted Black" << endl;
    Triangle T11( 140, 900, 300, C2);
    cout << endl;
    T11.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T11.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Triangle T12( 700, 400, 200, C4);
    cout << endl;
    T12.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T12.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << ": plotted Dark Blue" << endl;
    Triangle T13( 400, 50, 250, C1);
    cout << endl;
    T13.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T13.TrianglePrint();
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Triangle T14( 180, 550, 410, C4);
    cout << endl;
    T14.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T14.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation+height off page after scaling for x";
    cout << ": plotted Pink" << endl;
    Triangle T15( 350, 600, 330, C6);
    cout << endl;
    T15.TrianglePrint();
    T15.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation+height on page after scaling for x";
    cout << ": plotted Light Blue" << endl;
    Triangle T16( 300,300,400, C5);
    cout << endl;
    T16.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T16.TrianglePrint();

    // TEST MUTATORS Moving off the page
    cout << "Mutators moving the shape completely or partially off the page" << endl
    << endl;
    cout << endl << "TRIANGLE: move triangle so xLocation=650, off page";
    cout << endl << ": plotted yellow at 0,0" << endl;
	Triangle T17( 420, 400, 120, C7);
    T17.SetXLocation(650);
    T17.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T17.TrianglePrint();

	cout << endl << "move triangle so triangle in y so it is partially off the page \n"
	     << endl << " change ylocation to 530 " << endl;
    cout << endl << ": plotted Purple" << endl;
	Triangle T18( 50, 350, 330, C8);
    T18.SetYLocation(530);
    T18.TrianglePrint();
    T18.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

	cout << endl << "change sidelength so triangle is off the page in y\n"
	     << endl << " change sideLength to 165" << endl << "TRIANGLE: move T15, change sideLength so off page in y";
    cout << endl << ": plotted Black" << endl;
	Triangle T20( 50, 675, 100, C2);
    T20.SetSideLength(165);	cout << endl;
    T20.TrianglePrint();
    T20.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

	cout << endl << "move triangle so triangle in x so it is partially off the page"
	     << endl << " change xlocation to 510 " ;
    cout <<  ": plotted Red" << endl;
	Triangle T21( 450, 230, 130, C3);
    T21.SetXLocation(510);
    T21.TrianglePrint();
    T21.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

	cout << endl << "change sidelength so triangle is off the page in x"
	     << endl << " change sideLength to 165";
    cout << ": plotted Purple" << endl;
	Triangle T22( 470, 475, 100, C8);
    T22.SetSideLength(165);
    T22.TrianglePrint();
    T22.TriangleDisplay(myImage, "triangleTestOut.bmp");

	cout << endl << "change sidelength so triangle is off the page in x and y"
	     << endl << " change sideLength to 165";
    cout << ": plotted Yellow" << endl;
	Triangle T23( 470, 695, 100, C7);
    T23.SetSideLength(165);
    T23.TrianglePrint();
    T23.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

    cout << "TESTING TRIANGLE DIVIDE" << endl;
    Triangle *TList = NULL;
    TList = new Triangle[3];
    // plot the undivided triangle in blue
    Triangle T19( 330,150,140, C1);
    T19.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << "the triangle that will be divided" << endl;
    T19.TrianglePrint();
    // plot the subtriangles in yellow
    T19.SetTriangColour(C7);
    T19.TriangleDivide ( TList );
    cout << "the list of three subtriangles: Plotted Yellow" << endl;
    for( int i=0; i<3; i++)
    {
        TList[i].TriangleDisplay(myImage, "triangleTestOut.bmp");
        TList[i].TrianglePrint();
        cout << endl;
    }
    delete [] TList;
    cout << endl << endl << endl;

        cout << endl << endl << endl;


    cout << "????????????????????????????????????????????????????";


    cout << "BEGIN GASKET TEST" << endl << endl;

    //Gasket test here




    cout << "TESTING CONSTRUCTORS: ON AND OFF PAGE" << endl;

    ResetBackground(myImage, CB, 600, 800);
    cout << endl << "Constructor 4 argument x, y off, then x beyond edge of page:: BLACK" << endl;
	cout << "create G9" << endl;
	Gasket G9( 0, 700, 700, 700, C2);
	G9.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G9.GasketPrint();
    cout << endl << "Constructor with 4 arguments xLocation off page: PURPLE" << endl;
	cout << "create G2" << endl;
    Gasket G2(1, 606, 480, 440, C8);
    G2.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G2.GasketPrint();
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
    cout << endl << "Constructor 4 arguments, sidelength (x) beyond edge of page: GREY" << endl;
	cout << "create G3" << endl;
    Gasket G3(1, 250, 330, 360, C4);
    G3.GasketDisplay(myImage, 1, "GasketConstructors.bmp");
    G3.GasketPrint();
	cout << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: YELLOW" << endl;
	cout << "create G8" << endl;
	Gasket G8( 1, 400, 600, 300, C8);
	G8.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G8.GasketPrint();
	cout << endl << endl << endl;
	cout << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: GREY" << endl;
	cout << "create G10" << endl;
	Gasket G10( 1, 400, 700, 300, C4);
	G10.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G10.GasketPrint();


	cout << endl << endl << endl;

    cout << "TESTING COPY CONSTRUCTOR" << endl;
    cout << "gasket to copy" << endl;
    G10.GasketPrint();
    Gasket G11(G10);
    cout << "copied gasket" << endl;
    G11.GasketPrint();
    cout << endl << endl << endl;
    cout << endl << "Constructor 4 arguments, on page:: RED" << endl;
	cout << "create g6" << endl;
    Gasket G6(3, 206, 200, 370, C3);
    G6.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G6.GasketPrint();
    cout << endl << "Constructor 4 arguments, sideLength (y) beyond edge of page: DARK BLUE" << endl;
	cout << "create g5" << endl;
    Gasket G5(2, 140, 600, 350, C1);
    G5.GasketDisplay(myImage, 1, "GasketConstructors.bmp");
    G5.GasketPrint();

    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    cout << endl << "TESTING MUTATORS" << endl;

    ResetBackground(myImage, CB, 600, 800);
    cout << endl << "changing Xlocation of G0 to 150: ";
	cout << " :displayed in YELLOW" << endl;
    G0.SetXLocation(150);
    G0.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G0.GasketPrint();
    cout << endl << "changing  Xlocation of G1"<< endl;
	cout << "xlocation to 400: "  << endl;
	cout << "displayed in BLACK" << endl;
    G1.SetXLocation(400);
    G1.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G1.GasketPrint();
    cout << "moving x location of G7 so gasket is partially off the page" << endl;
    cout << "yLocation set to 675: displayed in LIGHT BLUE" << endl;
    G7.SetXLocation( 375 );
    G7.SetYLocation(300);
    G7.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G7.GasketPrint();
	cout << "moving x location of G7 and increasing sideLength" << endl;
    cout << "xLocation set to 275 : displayed in LIGHT BLUE" << endl;
    G7.SetXLocation( 375 );
	G7.SetSideLength(200);
	G7.SetYLocation(550);
    G7.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G7.GasketPrint();
    cout << "changing G2 colour from light blue: ";
    cout << "displayed in RED" << endl;
    G2.SetGasketColour(C3);
    G2.SetXLocation(100);
    G2.SetYLocation(350);
    G2.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G2.GasketPrint();
    cout << "changing G2 number of iterations from 1 to 3: " ;
    cout << "displayed in YELLOW" << endl;
    G2.SetIterations(3);
    G2.SetGasketColour(C7);
    G2.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G2.GasketPrint();
    cout << endl << "changing  size y location and iterations of G1"<< endl;
	cout << "7location to 200: "  << endl;
	cout << "displayed in DARK BLUE" << endl;
    G1.SetYLocation(200);
    G1.SetIterations(2);
    G1.SetGasketColour(C1);
    G1.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G1.GasketPrint();

    //Constructor large iter


    return 0;
}


