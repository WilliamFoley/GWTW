//Shawn Cherry
// cs-365
//Fall 2015
//Gone With the Wind

#include "input.h"

class movement
{
	enum move;
public:
	movement(input input) {}
	move up()		{ pitch_ += .03; }
	move down()		{ pitch_ -= .03; }
	move left()		{ angle_ += .03; }
	move right()	{ angle_ -= .03; }
	move menu()		{ openMenu(); }
	move attack()	{ shootMissle(); }

	virtual ~movement(){}
	
private:
	
};



