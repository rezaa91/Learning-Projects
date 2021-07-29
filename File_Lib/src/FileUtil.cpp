#include "FileUtil.h"

#include <fstream>
#include <sstream>
#include <filesystem>
#include <exception>

namespace fs = std::filesystem;

std::string FileUtil::getContents(const std::string& path) const
{
	try {
		std::ifstream file(path);
		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cerr << "Error reading file: " << e.what() << std::endl;
	}
}

bool FileUtil::exists(const std::string& path) const
{
	try {
		return fs::exists(path);
	}
	catch (fs::filesystem_error& e)
	{
		std::cerr << "Error checking if file exists: " << e.what() << std::endl;
		return false;
	}
}

void FileUtil::write(const std::string& path, const std::string& contents) const
{
	try {
		std::ofstream file(path);
		file << contents;
	}
	catch (std::ofstream::failure& e)
	{
		std::cerr << "Error writing to file: " << e.what() << std::endl;
	}
}

void FileUtil::copy(const std::string& src, const std::string& dest) const
{
	try {
		fs::copy(src, dest);
	}
	catch (fs::filesystem_error& e)
	{
		std::cerr << "Unable to copy file\n" << e.what() << std::endl << "CODE: (" << e.code() << ")\n";
	}
}

void FileUtil::mkdir(const std::string& path) const
{
	try {
		fs::create_directory(path);
	}
	catch (fs::filesystem_error& e)
	{
		std::cerr << "Error creating dir: " << e.what() << std::endl;
	}
}

void FileUtil::rmdir(const std::string& path) const
{
	try {
		fs::remove_all(path);
	}
	catch (fs::filesystem_error& e)
	{
		std::cerr << "Error removing dir: " << e.what() << std::endl;
	}
}

void FileUtil::move(const std::string& src, const std::string& dest) const
{
	try {
		fs::rename(src, dest);
	}
	catch (fs::filesystem_error& e)
	{
		std::cerr << "Error moving file: " << e.what() << std::endl;
	}
}

void FileUtil::deleteFile(const std::string& path) const
{
	try {
		fs::remove(path);
	}
	catch (fs::filesystem_error& e)
	{
		std::cerr << "Error deleting file: " << e.what() << std::endl;
	}
}
