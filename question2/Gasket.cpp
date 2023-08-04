#include "Gasket.h"
#include "Colour.h"
#include <iomanip>


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
int Gasket::GetIterations() const
{
	return iterations;
}
int Gasket::GetXLocation() const
{
	return xLocation;
}
int Gasket::GetYLocation() const
{
	return yLocation;
}
int Gasket::GetSideLength() const
{
	return sideLength;
}
Colour Gasket::GetGasketColour() const
{
	return gasketColour;
}




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

void Gasket::SetXLocation(const int xLocationValue)
{
	xLocation = xLocationValue;
	if (xLocation < 0 || xLocation >= pageWidth)
    {
        xLocation = 0;
        yLocation = 0;
    }

	if( xLocation + sideLength > pageWidth )
	{
		int newsideLength = pageWidth - xLocation;
		sideLength = newsideLength;
	}

	listOfSubTriangles[0]= Triangle(xLocation, yLocation, sideLength, gasketColour);
	for (int k=1; k <= iterations; k++)
	{
		GasketDivide(listOfSubTriangles, lenSubTriList / 3 );
	}

}
void Gasket::SetYLocation(const int yLocationValue)
{
	yLocation = yLocationValue;
	if (yLocation < 0 || yLocation > pageLength)
	{
        xLocation = 0;
        yLocation = 0;
	}

	int height = static_cast<int> (sideLength * GASKET_SIDE_TO_HEIGHT);
	if( yLocation + height > pageLength )
	{
		int newsideLength = static_cast<int>( (pageLength - yLocation) / GASKET_SIDE_TO_HEIGHT );
		sideLength = newsideLength;
	}

	listOfSubTriangles[0]= Triangle(xLocation, yLocation, sideLength, gasketColour);
	for (int k=1; k <= iterations; k++)
	{
		GasketDivide(listOfSubTriangles, lenSubTriList / 3 );
	}

}
void Gasket::SetGasketColour(const Colour gasketColorValue)
{
	gasketColour = gasketColorValue;

	// listOfSubTriangles[0]= Triangle(xLocation, yLocation, sideLength, gasketColour);
	// for (int k=1; k <= iterations; k++)
	// {
	// 	GasketDivide(listOfSubTriangles, static_cast<int> ( pow( 3.0, k-1 ) ) );
	// }
	for (int i = lenSubTriList - 1; i >= 0; i--)
	{
		listOfSubTriangles[i].SetTriangColour(gasketColour);
	}
	
}

void Gasket::GasketDisplay(BMP& myImageValue, int thisIter, string theOutputFile)
{
	for (int i = 0; i < lenSubTriList; i++)
	{
		listOfSubTriangles[i].TriangleDisplay(myImageValue, theOutputFile);
	}
}

void Gasket::GasketPrint()
{
    std::cout << std::right;
    cout << setw(20) << "iterations " << setw(9) << iterations << endl;
    cout << setw(20) << "xLocation " << setw(9) << xLocation << endl;
    cout << setw(20) << "yLocation " << setw(9) << yLocation << endl;
    cout << setw(20) << "sideLength" << setw(9) << sideLength << endl;
    cout << setw(20) << "gasketColour" << setw(9) << gasketColour << endl;
    cout << setw(20) << "lenSubTriList" << setw(9) << lenSubTriList << endl;
	cout << endl;
	for (int i = lenSubTriList - 1; i >= 0; i--)
	{
		listOfSubTriangles[i].TrianglePrint();
		cout <<endl;
	}
    std::cout << setw(0);
    std::cout << std::left;
}




Gasket::Gasket()
{
	sideLength = 100;
	xLocation = 0;
	yLocation = 0;
	iterations = 0;
	lenSubTriList = 1;
	listOfSubTriangles = new Triangle[1];
	gasketColour.SetAlphaNumber(255);
	gasketColour.SetRedNumber(0);
	gasketColour.SetGreenNumber(0);
	gasketColour.SetBlueNumber(0);
	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
}

Gasket::Gasket( int iterationsValue, int xLocationValue, int yLocationValue,
                int sideLengthValue, Colour gasketColourValue)
{
	iterations = iterationsValue;
	xLocation = xLocationValue;
	yLocation = yLocationValue;
	sideLength = sideLengthValue;
	gasketColour = gasketColourValue;

	if (xLocation < 0 || xLocation >= pageWidth)
    {
        cout<<"x position of Gasket object is off the page"<<endl;
        cout<<"x position and y position have been reset to 0"<<endl;
        xLocation = 0;
        yLocation = 0;
    }
	else if (yLocation < 0 || yLocation > pageLength)
	{
		cout<<"y position of Gasket object is off the page"<<endl;
        cout<<"x position and y position have been reset to 0"<<endl;
        xLocation = 0;
        yLocation = 0;
	}

	if( xLocation + sideLength > pageWidth )
	{
		cout <<"scaling in x"<<endl;
		int newsideLength = pageWidth - xLocation;
		cout <<"sideLength was "<<sideLength<<" sideLength now is "<<newsideLength<<endl;
		sideLength = newsideLength;
	}

	int height = static_cast<int> (sideLength * GASKET_SIDE_TO_HEIGHT);
	if( yLocation + height > pageLength )
	{
		cout <<"scaling in y"<<endl;
		int newsideLength = static_cast<int>( (pageLength - yLocation) / GASKET_SIDE_TO_HEIGHT );
		cout <<"sideLength was "<<sideLength<<" sideLength now is "<<newsideLength<<endl;
		sideLength = newsideLength;
	}

	lenSubTriList = static_cast<int> ( pow( 3.0, iterations ) );
	listOfSubTriangles = new Triangle[lenSubTriList];
	listOfSubTriangles[0]= Triangle(xLocation, yLocation, sideLength, gasketColour);
	for (int k=1; k <= iterations; k++)
	{
		GasketDivide(listOfSubTriangles, static_cast<int> ( pow( 3.0, k-1 ) ) );
		// GasketDivide(listOfSubTriangles, lenSubTriList / 3 );
	}

}

Gasket::Gasket(const Gasket& toBeCopied)
{
	xLocation = toBeCopied.xLocation;
	yLocation = toBeCopied.yLocation;
	iterations = toBeCopied.iterations;
	sideLength = toBeCopied.sideLength;
	gasketColour = toBeCopied.gasketColour;
	lenSubTriList = toBeCopied.lenSubTriList;

	listOfSubTriangles = new Triangle[lenSubTriList];
	for (int i = 0; i < lenSubTriList; i++)
		listOfSubTriangles[i] = toBeCopied.listOfSubTriangles[i];
}

Gasket::~Gasket()
{
	delete[] listOfSubTriangles;
}

