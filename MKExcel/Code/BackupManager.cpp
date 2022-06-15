

#include <BackupManager.hpp>


namespace MKExcel
{
	void BackupManager::SetBackupManager(std::string base, std::string backup)
	{
		BackupManager::basePath = base;
		BackupManager::backupPath = backup;
	}

	BackupManager::BackupManager()
	{		
		listManager = new BackupListManager(&backupPath);
	}

	void BackupManager::NewBackup()
	{
		std::string key = listManager->GenerateKey();

		if (!std::filesystem::exists(backupPath))
		{
			std::filesystem::create_directory(backupPath);
		}

		const auto copyOptions = std::filesystem::copy_options::recursive;

		std::filesystem::copy(basePath, backupPath + "/" + key, copyOptions);

		listManager->AddKey(key);
	}

	std::string BackupManager::BackupList()
	{
		keys = listManager->GetAllKeys();
		return keys;
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

	std::string BackupManager::LastBackup()
	{
		return listManager->GetLastKey();
	}
}