//
// Copyright (c) 2009-2015 Glen Berseth, Mubbasir Kapadia, Shawn Singh, Petros Faloutsos, Glenn Reinman
// See license.txt for complete license.
// Copyright (c) 2015 Mahyar Khayatkhoei
//

#include <algorithm>
#include <vector>
#include <util/Geometry.h>
#include <util/Curve.h>
#include <util/Color.h>
#include <util/DrawLib.h>
#include "Globals.h"

using namespace Util;

Curve::Curve(const CurvePoint& startPoint, int curveType) : type(curveType)
{
	controlPoints.push_back(startPoint);
}

Curve::Curve(const std::vector<CurvePoint>& inputPoints, int curveType) : type(curveType)
{
	controlPoints = inputPoints;
	sortControlPoints();
}

// Add one control point to the vector controlPoints
void Curve::addControlPoint(const CurvePoint& inputPoint)
{
	controlPoints.push_back(inputPoint);
	sortControlPoints();
}

// Add a vector of control points to the vector controlPoints
void Curve::addControlPoints(const std::vector<CurvePoint>& inputPoints)
{
	for (int i = 0; i < inputPoints.size(); i++)
		controlPoints.push_back(inputPoints[i]);
	sortControlPoints();
}

// Draw the curve shape on screen, usign window as step size (bigger window: less accurate shape)
void Curve::drawCurve(Color curveColor, float curveThickness, int window)
{
#ifdef ENABLE_GUI

	//================DELETE THIS PART AND THEN START CODING===================
	static bool flag = false;
	if (!flag)
	{
		std::cerr << "ERROR>>>>Member function drawCurve is not implemented!" << std::endl;
		flag = true;
	}
	//=========================================================================

	// Robustness: make sure there is at least two control point: start and end points
	// Move on the curve from t=0 to t=finalPoint, using window as step size, and linearly interpolate the curve points
	// Note that you must draw the whole curve at each frame, that means connecting line segments between each two points on the curve
	
	return;
#endif
}

//Sorting function
bool comparingCurvePoints (Util::CurvePoint a, Util::CurvePoint b) {
	return (a.time < b.time);
}


// Sort controlPoints vector in ascending order: min-first
void Curve::sortControlPoints()
{
	//Print the vector
	//comment out later..............................................................
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "We are printing the control Points:" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (std::vector<Util::CurvePoint>::iterator it = controlPoints.begin(); it != controlPoints.end(); ++it) {
		Util::CurvePoint currentIteration = *it;
		std::cout<<currentIteration.time<<std::endl;
	} 
	//...............................................................................
	
	//CurvePoint parts:
	//Point position;Vector tangent;float time;

	//SORT
	std::sort(controlPoints.begin(), controlPoints.end(), comparingCurvePoints);

	//Print the vector
	//comment out later..............................................................
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "We are printing the sorted! control Points:" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (std::vector<Util::CurvePoint>::iterator it = controlPoints.begin(); it != controlPoints.end(); ++it) {
		Util::CurvePoint currentIteration = *it;
		std::cout << currentIteration.time << std::endl;
	}
	//...............................................................................

	return;
}

// Calculate the position on curve corresponding to the given time, outputPoint is the resulting position
// Note that this function should return false if the end of the curve is reached, or no next point can be found
bool Curve::calculatePoint(Point& outputPoint, float time)
{
	// Robustness: make sure there is at least two control point: start and end points
	if (!checkRobust())
		return false;

	// Define temporary parameters for calculation
	unsigned int nextPoint;

	// Find the current interval in time, supposing that controlPoints is sorted (sorting is done whenever control points are added)
	// Note that nextPoint is an integer containing the index of the next control point
	if (!findTimeInterval(nextPoint, time))
		return false;

	// Calculate position at t = time on curve given the next control point (nextPoint)
	if (type == hermiteCurve)
	{
		outputPoint = useHermiteCurve(nextPoint, time);
	}
	else if (type == catmullCurve)
	{
		outputPoint = useCatmullCurve(nextPoint, time);
	}

	// Return
	return true;
}

// Check Roboustness
bool Curve::checkRobust()
{
	//================DELETE THIS PART AND THEN START CODING===================
	static bool flag = false;
	if (!flag)
	{
		std::cerr << "ERROR>>>>Member function checkRobust is not implemented!" << std::endl;
		flag = true;
	}
	//=========================================================================


	return true;
}

// Find the current time interval (i.e. index of the next control point to follow according to current time)
bool Curve::findTimeInterval(unsigned int& nextPoint, float time)
{
	//Print the time
	//comment out later..............................................................
	std::cout << "the time we are looking for is " << time << std::endl;
	//...............................................................................

	//if time is negative, return false
	if (time < 0) {
		return 0;
	}
	//if the time is past the last element, return false
	if (controlPoints.back().time < time) {
		return false;
	}
	//iterate over all the control points and see when time is greater, at which point return 
	for (int i = 1; i < controlPoints.size(); i++) {
		if (time <= controlPoints[i].time) {
			//std::cout << "the time we are looking for is definitely " << time << std::endl;
			std::cout << "the controlPoint time at " << i << " is " << controlPoints[i].time <<  std::endl;
			nextPoint = i;
			std::cout << "the next point is " << nextPoint <<  std::endl;
			return true;
		}
	}

	/*if (time > controlPoints.back().time) {
		return false;
	}
	else {
		for (int i = 1; i < controlPoints.size(); i++) {
			if()
		}
	}*/

	return false;
}

// Implement Hermite curve
Point Curve::useHermiteCurve(const unsigned int nextPoint, const float time)
{
	Point newPosition;
	float normalTime, intervalTime;

	//================DELETE THIS PART AND THEN START CODING===================
	static bool flag = false;
	if (!flag)
	{
		std::cerr << "ERROR>>>>Member function useHermiteCurve is not implemented!" << std::endl;
		flag = true;
	}
	//=========================================================================

	// Calculate position at t = time on Hermite curve

	// Return result
	return newPosition;
}

// Implement Catmull-Rom curve
Point Curve::useCatmullCurve(const unsigned int nextPoint, const float time)
{
	Point newPosition;

	//================DELETE THIS PART AND THEN START CODING===================
	static bool flag = false;
	if (!flag)
	{
		std::cerr << "ERROR>>>>Member function useCatmullCurve is not implemented!" << std::endl;
		flag = true;
	}
	//=========================================================================

	// Calculate position at t = time on Catmull-Rom curve
	
	// Return result
	return newPosition;
}