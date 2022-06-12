

#include <Utils.hpp>

#include <BackupListManager.hpp>
#include <chrono>

#include <iomanip>
#include <ctime>
#include <sstream>

#include <iostream>
#include <fstream>
#include <string>

namespace MKExcel
{
	BackupListManager::BackupListManager(std::string path)
	{
		this->path = path + "/backuplist.txt";
	}

	std::string BackupListManager::GenerateKey()
	{
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
		return oss.str();
	}

	void BackupListManager::AddKey(std::string key)
	{
		std::ofstream list;
		std::string oldContent;
		list.open(path, std::ios_base::app);
		list << key << ",";		
		list.close();
	}

	std::string BackupListManager::GetAllKeys()
	{
		std::string keys;
		std::fstream list;
		list.open(path, std::ios::in);
		if (list.is_open())
		{
			while (getline(list, keys)) {}
			list.close();
		}
		return keys;
	}

	std::string BackupListManager::GetLastKey()
	{
		std::string keys = GetAllKeys();
		if (keys == "") return keys;
		std::vector<std::string> splitKeys = Utils::Split(keys, ",");
		return splitKeys[splitKeys.size() - 1];
	}
}