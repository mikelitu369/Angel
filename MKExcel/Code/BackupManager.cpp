

#include <BackupManager.hpp>


namespace MKExcel
{
	BackupManager::BackupManager(std::string base, std::string backup)
	{
		basePath = base;
		backupPath = backup;
		listManager = new BackupListManager(backup);
	}

	void BackupManager::NewBackup()
	{
		std::string key = listManager->GenerateKey();

		std::filesystem::copy(basePath, backupPath + "/" + key);

		listManager->AddKey(key);
	}

	std::string BackupManager::BackupList()
	{
		return listManager->GetAllKeys();
	}

	void BackupManager::RestoreBackup(std::string key)
	{
		if (std::filesystem::exists(backupPath + "/" + key))
		{
			std::filesystem::remove_all(basePath);
			std::filesystem::copy(backupPath + "/" + key, basePath);
			listManager->AddKey(key);
		}
	}
}