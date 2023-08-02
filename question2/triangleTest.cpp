#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
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
    {

    //Please note that this is the correct location for BMP myImage
    //The program will work if you make this declaration global (as indicated in lab writeup)
    //However global variables should not be used as arguments of functions
    BMP myImage;
    Colour C1(0, 0, 255, 255);     //blue rectangle R2
    Colour C2(0, 0, 0, 255);	   //large black rectangle R3
    Colour CB(0, 255, 0, 255);     //green background
    Colour C3(255,0,0,255);		   //red rectangle R4
    Colour C4(128,128,128,128);	   //small grey rectangle R1
    Colour C5( 100, 200, 255, 170);//light blue rectangle R5
    Colour C6( 255, 0, 255, 255);  //Purple
	Colour C7( 255, 255, 0, 255 ); //Yellow

    cout << "BEGIN TRIANGLE TEST" << endl << endl;
    Triangle T1, T6;
    Triangle T2( 240, 580, C2);
    Triangle T3( 150, 300, 375,  C3 );
    Triangle T4( 90, 400, 210,  C4);
    Triangle T5( 195, 540, 230,  C5);

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
    cout << "triangle to copy" << endl;
    T6.TrianglePrint();
    Triangle T9(T6);
    cout << "copied triangle" << endl;
    T9.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING GETTERS" << endl;
    cout << endl;
    cout << "Getting Width " << T1.GetSideLength() << endl;
    cout << "Getting xLocation " << T1.GetXLocation() << endl;
    cout << "Getting yLocation " << T1.GetYLocation() << endl;
    cout << "Getting trianglesCreated " << T1.GetTrianglesCreated()<< endl;
    cout << "Getting trianglesExisting " << T1.GetTrianglesExisting() << endl;
    cout << "Getting blockColour" << T1.GetTriangColour() << endl;
    cout << endl << endl << endl;


    cout << "TESTING SETTERS: changing default values in T1 and T2" << endl;
    T1.SetSideLength(120);
    T1.SetXLocation(225);
    T1.SetYLocation(520);
    T1.SetTriangColour(C1);
    T2.SetSideLength(50);
    T2.SetTriangColour(C6);

    T1.TrianglePrint();
    cout << endl;
    T2.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING DISPLAY OF TRIANGLES" << endl;
    T4.TriangleDisplay(myImage, "triangleTest.bmp");
    T3.TriangleDisplay(myImage, "triangleTest.bmp");
    T5.TriangleDisplay(myImage, "triangleTest.bmp");
    T1.TriangleDisplay(myImage, "triangleTest.bmp");
    T2.TriangleDisplay(myImage, "triangleTest.bmp");
    cout << endl << endl << endl;

    cout << endl;
    cout << "TESTING TRIANGLES OVERLAPPING EDGES OF PAGE" << endl;
    cout << "AND TESTING TRIANGLES OUTSIDE THE PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    cout << "TRIANGLE BOTH xLocation AND yLocation OFF THE PAGE";
    cout << ": plotted Red" << endl;
    Triangle T10( 610, 823, 300, C3 );
    cout << endl;
    T10.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T10.TrianglePrint();
    cout << endl << "TRIANGLE, yLocation OFF THE PAGE";
    cout << ": plotted Black" << endl;
    Triangle T11( 100, -5, 230, C2);
    cout << endl;
    T11.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T11.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Triangle T12( -5, 100, 190, C4);
    cout << endl;
    T12.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T12.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << ": plotted Dark Blue" << endl;
    Triangle T13( 400, 50, 200, C1);
    cout << endl;
    T13.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T13.TrianglePrint();
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Triangle T14( 300, 700, 230, C4);
    cout << endl;
    T14.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T14.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation+height off page after scaling for x";
    cout << ": plotted Light Blue" << endl;
    Triangle T15( 450, 680, 210, C6);
    cout << endl;
    T15.TrianglePrint();
    T15.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation+height on page after scaling for x";
    cout << ": plotted Light Blue" << endl;
    Triangle T16( 300,300,400, C5);
    cout << endl;
    T16.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T16.TrianglePrint();
    cout << endl << "TRIANGLE: move T15 so xLocation is off page";
    cout << endl << ": plotted light blue" << endl;
    T15.SetXLocation(650);
    T15.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T15.TrianglePrint();
    cout << endl << "TRIANGLE: move T15, change sideLength so off page in y";
    cout << endl << ": plotted Grey" << endl;
    T15.SetXLocation(150);
    T15.SetYLocation(650);
    T15.SetSideLength(350);	cout << endl;
    T15.TrianglePrint();
    T15.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

    cout << "TESTING TRIANGLE DIVIDE" << endl;
    Triangle *TList = NULL;
    TList = new Triangle[3];
    Triangle T17( 10,350,300, C1);
    T17.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T17.SetTriangColour(C4);
    T17.TriangleDivide ( TList );
    for( int i=0; i<3; i++)
    {
        TList[i].TriangleDisplay(myImage, "triangleTestOut.bmp");
        TList[i].TrianglePrint();
        cout << endl;
    }
    delete [] TList;
    cout << endl << endl << endl;

    cout << "TESTING = OPERATOR"<< endl;
    T4 = T3;
    cout << "printing T3"<< endl;
    T3.TrianglePrint();
    cout << "printing T4 after T4=T3"<< endl;
    T4.TrianglePrint();
    cout << endl << endl << endl;

    cout << "TESTING THE << OPERATOR" << endl;
    cout << "T5" << endl << T5;
    cout << endl << endl << endl;


}
    return 0;
}


