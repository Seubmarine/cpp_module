#ifndef HARL_H
#define HARL_H
#include <string>
class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl();
	~Harl();
	void complain(std::string level);
};

struct HarlHelper
{
	const char *level_name;
	void (Harl::*level_function)();
};


#endif