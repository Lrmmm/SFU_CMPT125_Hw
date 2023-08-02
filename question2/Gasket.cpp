#include "Gasket.h"
#include "Colour.h"

double GASKET_SIDE_TO_HEIGHT = 0.86666666;


void Gasket::GasketDivide(Triangle* listOfSubTriangles, int trianglesIn)
{
	if(trianglesIn <= 0  || trianglesIn >= static_cast<int>(pow(3,iterations) ) )
	{
		cerr << " illegal number of triangle in Gasket Divide";
		exit(1);
	}
	else
	{
		for (int k = trianglesIn-1; k >= 0; k--)
		{
			listOfSubTriangles[k].TriangleDivide(&listOfSubTriangles[k*3] );
		}
	}
}


// Requested Get of accessors (Get functions)
// to Get the values of each of the
// variable members of the class Gasket





// Requested Set functions to Set each of the variable members
// of class Gasket from outside of class Gasket.
// There is interaction between the members length width and area
// so Setting the variable member itself is not always adequate
// other calculations may be needded to maintain the consistancy
// of the instance of the class (the object)

void Gasket::SetIterations( const int iterationsValue)
{
    iterations = iterationsValue;
	lenSubTriList = static_cast<int> ( pow( 3.0, iterations ) );
	delete [] listOfSubTriangles;
	listOfSubTriangles = NULL;
	listOfSubTriangles = new Triangle[lenSubTriList];
	listOfSubTriangles[0]= Triangle(xLocation, yLocation, sideLength, gasketColour);
	for (int k=1; k <= iterations; k++)
	{
		GasketDivide(listOfSubTriangles, lenSubTriList / 3 );
	}
}

void Gasket::SetSideLength(const int sideLengthValue)
{
	int height = 0;
    sideLength = sideLengthValue;
	//Check if the change in sideLiength makes the
	//Triangle extend beyond any edge of the page
	if(sideLength < 1)  sideLength = 1;
	if( xLocation + sideLength > pageWidth )
	{
		sideLength = pageWidth - xLocation;
	}
	height = static_cast<int> (sideLength * GASKET_SIDE_TO_HEIGHT);
	if( yLocation + height > pageLength )
	{
		sideLength = static_cast<int>( (pageLength - yLocation) / GASKET_SIDE_TO_HEIGHT );
	}
	listOfSubTriangles[0]= Triangle(xLocation, yLocation, sideLength, gasketColour);
	for (int k=1; k <= iterations; k++)
	{
		GasketDivide(listOfSubTriangles, lenSubTriList / 3 );
	}
}
