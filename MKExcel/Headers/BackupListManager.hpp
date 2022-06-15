

#pragma once

#include <iostream>
#include <vector>


namespace MKExcel
{
	class BackupListManager
	{
	protected:
		std::string* path;
	public:
		std::string GenerateKey();
		BackupListManager(std::string* path);
		void AddKey(std::string key);
		std::string GetLastKey();
		std::string GetAllKeys();
	};
}