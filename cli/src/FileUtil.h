#pragma once

#include <iostream>

class FileUtil
{
public:
	FileUtil() = default;

	std::string getContents(const std::string& path) const;
	bool exists(const std::string& path) const;
	void write(const std::string& path, const std::string& contents) const;
	void copy(const std::string& src, const std::string& dest) const;
	void mkdir(const std::string& path) const;
	void rmdir(const std::string& path) const;
	void move(const std::string& src, const std::string& dest) const;
	void deleteFile(const std::string& src) const;
};

