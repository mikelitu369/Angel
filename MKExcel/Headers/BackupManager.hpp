

#pragma once

#include <iostream>
#include <BackupListManager.hpp>
#include <filesystem>

namespace MKExcel
{
	class BackupManager
	{
	protected:
		static std::string basePath;
		static std::string backupPath;
		BackupListManager* listManager;

	public:
		static std::string keys;
		static BackupManager& instance()
		{
			static BackupManager backupManager;
			return backupManager;
		}
		static void SetBackupManager(std::string base, std::string backup);
		BackupManager();
		void NewBackup();
		std::string BackupList();
		std::string LastBackup();
		void RestoreBackup(std::string key);
	};
}
