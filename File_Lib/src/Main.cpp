#include <iostream>

#include "FileUtil.h"

const std::string currentDir = "./assets";
const std::string newDir = "./assets/new";

void setup()
{
	FileUtil file;
	file.deleteFile(currentDir + "/test.txt");
	file.deleteFile(currentDir + "/test(copy).txt");
	file.rmdir(newDir);
}

int main()
{
	setup();

	FileUtil file;
	if (file.exists(currentDir + "/test.txt"))
	{
		std::cout << file.getContents(currentDir + "/test.txt") << std::endl;
	}
	else
	{
		file.write(currentDir + "/test.txt", "Hello World");
		std::cout << file.getContents(currentDir + "/test.txt") << std::endl;
	}

	file.copy(currentDir + "/test.txt", currentDir + "/test(copy).txt");

	file.mkdir(newDir);
	file.move(currentDir + "/test(copy).txt", newDir + "/test.txt");

	return EXIT_SUCCESS;
}
