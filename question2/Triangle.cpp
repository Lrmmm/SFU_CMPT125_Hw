#include "Triangle.h"
#include "Colour.h"
#include <iomanip>

int Triangle::TrianglesExisting;
int Triangle::TrianglesCreated;
double TRIANGLE_SIDE_TO_HEIGHT = 0.86666666;

void Triangle::TriangleDisplay(BMP& myImageValue, string theOutputFile)
 {
	int yHeight = 0;
	double offset = 0;
	int t1 = 0; 
	int t2 = 0;
    yHeight = static_cast<int> (sideLength * sqrt(3.0)/2.0 );
    if(yLocation < 0|| yLocation > pageLength ||
        yLocation + yHeight > pageLength)
    {
        cerr << "point may be located outside of plotting page\n"
            << endl;
        return;
    }
    
    if(xLocation < 0|| xLocation >= pageWidth || 
        xLocation + sideLength > pageWidth )
    {
        cerr << "point may be located outside of plotting page\n"
            << endl;
        return;
    }
    
    // each pixel within the Triangle must be Set to the correct colour
    // myImageValue(i,j) is pixel j in row i
    // each value in the Colour object is Set for each pixel in 
    // the Triangle
	yHeight = static_cast<int> (sideLength * sqrt(3.0)/2.0 );
    for(int j=yLocation; j<(yLocation+yHeight); j++)
    {
		offset = static_cast<double>(sideLength) / yHeight/ 2.0;
		t1 = static_cast<int>( ceil( (j-yLocation+1) * offset) );
		t2 = static_cast<int>( floor( (j-yLocation+1) * offset) );
        for (int i=0; i < sideLength; i++)
        {
			if( i < t1 || i > sideLength - t2) continue;
            myImageValue(i+xLocation,j)->Red = triangColour.GetRedNumber();
            myImageValue(i+xLocation,j)->Blue = triangColour.GetBlueNumber();
            myImageValue(i+xLocation,j)->Green = triangColour.GetGreenNumber();
            myImageValue(i+xLocation,j)->Alpha = triangColour.GetAlphaNumber();
        }
    }
    
    //write generated bitmap image to a file
    myImageValue.WriteToFile(theOutputFile.c_str());
}

void Triangle::TriangleDivide(Triangle* TriList)
{
	int halfSide;
	int yHalf;
	halfSide = sideLength / 2;
	// constant below is  = sqrt(3.0)/4 * sidelength
	yHalf = static_cast<int> (halfSide * TRIANGLE_SIDE_TO_HEIGHT);
	TriList[2] = Triangle(xLocation + halfSide / 2, yLocation + yHalf, halfSide, triangColour);
	TriList[1] = Triangle(xLocation + halfSide, yLocation, halfSide, triangColour);
	TriList[0] = Triangle(xLocation, yLocation, halfSide, triangColour);
}

Triangle::Triangle()
{
    sideLength = 10;
    xLocation = 0;
    yLocation = 0;
    TrianglesCreated++;
    TrianglesExisting++;
    triangColour.SetRedNumber(0);
    triangColour.SetGreenNumber(0);
    triangColour.SetBlueNumber(0);
    triangColour.SetAlphaNumber(255);
}

Triangle::Triangle(int xLocationValue, int yLocationValue, 
    int sideLengthValue, Colour blockColourValue)
{
    xLocation = xLocationValue;
    yLocation = yLocationValue;
    sideLength = sideLengthValue;
    triangColour = blockColourValue;
    TrianglesCreated++;
    TrianglesExisting++;

    if (xLocation < 0 || xLocation >= pageWidth || yLocation < 0 || yLocation > pageLength)
    {
        cout<<"x position = "<<xLocation<<" and / or y position = "<<yLocation<<" of Triangle object is off the page"<<endl;
        cout<<"x position and y position have been reset to 0"<<endl;
        xLocation = 0;
        yLocation = 0;
    }

    if (xLocation + sideLength > pageWidth)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"xlocation is "<<xLocation<<endl;
        int newSideLength = pageWidth - xLocation;
        cout<<" sideLength was "<<sideLength<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }

    int yHeight = static_cast<int> (sideLength * sqrt(3.0)/2.0 );
    if (yLocation + yHeight > pageLength)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"ylocation is "<<yLocation<<endl;
        int newSideLength = static_cast<int> ((pageLength - yLocation) / sqrt(3.0) * 2.0);
        cout<<" sideLength was "<<sideLength<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }
}

Triangle::Triangle(int xLocationValue, int yLocationValue,
    Colour blockColourValue)
{
    xLocation = xLocationValue;
    yLocation = yLocationValue;
    sideLength = 10;
    triangColour = blockColourValue;
    TrianglesCreated++;
    TrianglesExisting++;

    if (xLocation < 0 || xLocation >= pageWidth || yLocation < 0 || yLocation > pageLength)
    {
        cout<<"x position = "<<xLocation<<" and / or y position = "<<yLocation<<" of Triangle object is off the page"<<endl;
        cout<<"x position and y position have been reset to 0"<<endl;
        xLocation = 0;
        yLocation = 0;
    }

    if (xLocation + sideLength > pageWidth)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"xlocation is "<<xLocation<<endl;
        int newSideLength = pageWidth - xLocation;
        cout<<" sideLength was "<<sideLength<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }

    int yHeight = static_cast<int> (sideLength * sqrt(3.0)/2.0 );
    if (yLocation + yHeight > pageLength)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"ylocation is "<<yLocation<<endl;
        int newSideLength = static_cast<int> ((pageLength - yLocation) / sqrt(3.0) * 2.0);
        cout<<" sideLength was "<<sideLength<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }
}

Triangle::Triangle(const Triangle& toBeCopied)
{
    this->sideLength = toBeCopied.sideLength;
    this->xLocation = toBeCopied.xLocation;
    this->yLocation = toBeCopied.yLocation;
    this->triangColour = toBeCopied.triangColour;
    TrianglesCreated++;
    TrianglesExisting++;
}

Triangle::~Triangle()
{
    TrianglesExisting--;
}

int Triangle::GetSideLength() const
{
    return sideLength;
}

int Triangle::GetXLocation() const
{
    return xLocation;
}

int Triangle::GetYLocation() const
{
    return yLocation;
}

Colour Triangle::GetTriangColour() const
{
    return triangColour;
}

int Triangle::GetTrianglesCreated()
{
    return TrianglesCreated;
}

int Triangle::GetTrianglesExisting()
{
    return TrianglesExisting;
}

void Triangle::SetTriangColour(const Colour blockColorValue)
{
    triangColour = blockColorValue;
}
void Triangle::SetSideLength(const int setSideLengthValue)
{
    sideLength = setSideLengthValue;
    if (xLocation + sideLength > pageWidth)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"sideLength reset to assure the whole triangle is on the page"<<endl;
        int newSideLength = pageWidth - xLocation;
        cout<<"xLocation is "<<xLocation<<" sideLength was "<<sideLength<<endl;
        cout<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }

    int yHeight = static_cast<int> (sideLength * sqrt(3.0)/2.0 );
    if (yLocation + yHeight > pageLength)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"sideLength reset to assure the whole triangle is on the page"<<endl;
        int newSideLength = static_cast<int> ((pageLength - yLocation) / sqrt(3.0) * 2.0);
        cout<<"ylocation is "<<yLocation<<" sideLength was "<<sideLength<<endl;
        cout<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }

}
void Triangle::SetXLocation(const int xLocationValue)
{
    xLocation = xLocationValue;

    if (xLocation < 0 || xLocation >= pageWidth || yLocation < 0 || yLocation > pageLength)
    {
        xLocation = 0;
        yLocation = 0;
        cout<<"x position = "<<xLocation<<" or y position = "<<yLocation<<" of Triangle object is off the page"<<endl;
        cout<<"x position and y position have been reset to 0"<<endl;
    }

    if (xLocation + sideLength > pageWidth)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"sideLength reset to assure the whole triangle is on the page"<<endl;
        int newSideLength = pageWidth - xLocation;
        cout<<"xLocation is "<<xLocation<<" sideLength was "<<sideLength<<endl;
        cout<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }
}
void Triangle::SetYLocation(const int yLocationValue)
{
    yLocation = yLocationValue;
    if (xLocation < 0 || xLocation >= pageWidth || yLocation < 0 || yLocation > pageLength)
    {
        xLocation = 0;
        yLocation = 0;
        cout<<"x position = "<<xLocation<<" or y position = "<<yLocation<<" of Triangle object is off the page"<<endl;
        cout<<"x position and y position have been reset to 0"<<endl;
    }

    int yHeight = static_cast<int> (sideLength * sqrt(3.0)/2.0 );
    if (yLocation + yHeight > pageLength)
    {
        cout<<"Triangle object partially off the page"<<endl;
        cout<<"sideLength reset to assure the whole triangle is on the page"<<endl;
        int newSideLength = static_cast<int> ((pageLength - yLocation) / sqrt(3.0) * 2.0);
        cout<<"ylocation is "<<yLocation<<" sideLength was "<<sideLength<<endl;
        cout<<" sideLength is "<<newSideLength<<endl;
        sideLength = newSideLength;
    }
}

void Triangle::SetTrianglesCreated(int numberCreated)
{
    TrianglesCreated = numberCreated;
}
void Triangle::SetTrianglesExisting(int numberExisting)
{
    TrianglesExisting = numberExisting;
}

ostream& operator << (ostream& os, const Triangle& myTriangle)
{
    os << std::right;
    os << setw(20) << "sideLength " << setw(9) << myTriangle.sideLength << endl;
    os << setw(20) << "xLocation " << setw(9) << myTriangle.xLocation << endl;
    os << setw(20) << "yLocation " << setw(9) << myTriangle.yLocation << endl;
    os << setw(20) << "TrianglesCreated " << setw(9) << myTriangle.TrianglesCreated << endl;
    os << setw(20) << "TrianglesExisting " << setw(9) << myTriangle.TrianglesExisting << endl;
    os << setw(20) << "triangColour " << setw(9) << myTriangle.triangColour << endl;
    os << setw(0);
    os << std::left;
    return os;
}

void Triangle::TrianglePrint()
{
    std::cout << std::right;
    cout << setw(20) << "sideLength " << setw(9) << sideLength << endl;
    cout << setw(20) << "xLocation " << setw(9) << xLocation << endl;
    cout << setw(20) << "yLocation " << setw(9) << yLocation << endl;
    cout << setw(20) << "TrianglesCreated " << setw(9) << TrianglesCreated << endl;
    cout << setw(20) << "TrianglesExisting " << setw(9) << TrianglesExisting << endl;
    cout << setw(20) << "triangColour" << setw(9) << triangColour << endl;
    std::cout << setw(0);
    std::cout << std::left;
}

const Triangle& Triangle::operator = (const Triangle& Triangle2)
{
    if (this == &Triangle2)
    {
        return *this;
    }

    this->sideLength = Triangle2.sideLength;
    this->xLocation = Triangle2.xLocation;
    this->yLocation = Triangle2.yLocation;
    this->triangColour = Triangle2.triangColour;

    return *this;
}

bool Triangle::operator==(const Triangle& Triangle2) const
{
    return (sideLength == Triangle2.sideLength && xLocation == Triangle2.xLocation && 
            yLocation == Triangle2.yLocation && triangColour == Triangle2.triangColour);
}