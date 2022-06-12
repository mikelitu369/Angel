

#pragma once

#include <iostream>
#include <BackupListManager.hpp>
#include <filesystem>

namespace MKExcel
{
	class BackupManager
	{
	protected:
		std::string basePath;
		std::string backupPath;
		BackupListManager* listManager;

	public:
		BackupManager(std::string base, std::string backup);
		void NewBackup();
		std::string BackupList();
		void RestoreBackup(std::string key);
	};
}
