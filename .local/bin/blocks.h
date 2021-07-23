//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},

	{"", "get_battery",					60,		5},
	{"", "get_cputemp",					60,		0},
	{"", "get_temp",					3600,		4},
	{"", "get_disk",					3600,		3},
	{"", "get_pkg",					0,		2},
	{"", "get_volume",					0,		1},
	{" ", "date +'%a %m/%d %H:%M'",					60,		0},
	{"", "TZ=Australia/Sydney date +'%H:%M'",					60,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
//static char delim[] = " | ";
static char delim[] = " ";
static unsigned int delimLen = 5;
