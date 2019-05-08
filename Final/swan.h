#ifndef SWAN_H
#define SWAN_H

#include "actor.h"

#include <time.h>
#include <stdlib.h>


using namespace std;

class Swan : public Actor{
	protected:
	
	public:
		void setPos(int c, int r);
		void move(int c, int r, char** m);
		int getRow();
		int getCol();


};

#endif
