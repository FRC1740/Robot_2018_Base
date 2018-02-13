#ifndef autoNearSwitch_H
#define autoNearSwitch_H

#include <WPILib.h>
#include <Commands/CommandGroup.h>

class autoNearSwitch : public CommandGroup
{
public:
	autoNearSwitch(char); // Go for the near switch. Argument is either 'L' or 'R' for which side we're on.
};

#endif  // autoNearSwitch_H
