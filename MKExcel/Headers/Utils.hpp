

#pragma once

#include <vector>
#include <iostream>


namespace MKExcel
{
	class Utils
	{
	public:
		static std::vector<std::string> Split(std::string string, const char* splitter);
	};
}