/*Prog Name: vehicle.cpp
 * Author: Jacob Geddings
 * Date: 1/29/2016
 * Desc: Parent to car and bike
 * Input: Data types for vehicles
 * Output: Default constructor/child data
 */
#include "vehicle.h"

/*Func: Vehicle
 * desc: Default constructor
 * Para: None
 * PreC: Called directly or through children
 * PostC: Output generic filler for data types
 */
Vehicle::Vehicle(){
	lot = 0;
	mile = 0;
	mpg = 0;
	price = 0;	
	make = "Company";
	model = "Variant";
	color = "Exterior";
}
