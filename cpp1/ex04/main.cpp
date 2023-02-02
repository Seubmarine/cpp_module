#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>

bool is_file(std::string pathname) {
	struct stat info;

	if( stat( pathname.c_str(), &info ) != 0 )
	{
		std::cout << "cannot access " << pathname << std::endl;
		return false;
	}
	else if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows 
		return false;
	else
		return true;
}

int main(int argc, char const *argv[])
{
	if (argc < 4) {
		std::cerr << "Not enought args" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string original_str = argv[2];
	std::string replace_str = argv[3];

	std::ifstream original_file(filename.c_str());
	if (!original_file.is_open() || !is_file(filename)) {
		std::cerr << "Couldn't open file " << filename << std::endl;
		return (1);
	}
	filename.append(".replace");
	std::ofstream replace_file(filename.c_str());
	
	std::stringstream buffer;
	buffer << original_file.rdbuf(); //put file into a buffer
	std::string buffer_str = buffer.str();
	
	//We check from each character in the original file if we find a correspondance with the string to replace
	//If we found a corresponance we write the string to replace and advance in the original file
	//if no correspondance is found we write the current char and advance by one
	size_t i = 0;
	while ( i < buffer_str.length()) {
		if (buffer_str.compare(i, original_str.length(), original_str) == 0) {
			replace_file << replace_str;
			i += original_str.length();
		}
		else {
			replace_file << buffer_str[i];
			i++;
		}
	}

	replace_file.close();
	original_file.close();

	return 0;
}
