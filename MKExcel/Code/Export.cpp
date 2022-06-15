



#include <Exports.hpp>


using namespace MKExcel;


void CreateBackupManager(char* basePath, char* backupPath)
{
	std::string backup = backupPath;
	BackupManager::SetBackupManager(basePath, backup + "/Backup");
}

void NewBackup()
{
	BackupManager::instance().NewBackup();
}

char* BackupList()
{
	BackupManager::instance().BackupList();
	return &BackupManager::keys[0];
}

void RestoreBackup(char* id)
{
	BackupManager::instance().RestoreBackup(id);
}