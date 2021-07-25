#pragma once

using AppDetails_t = std::unordered_map<std::string, std::string>;

class Application
{
public:
	Application() = default;
	void run() const;
	AppDetails_t details() const;
};

