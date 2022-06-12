#pragma once

#ifdef DLLPROJECT_EXPORTS
#   define EXPORT __declspec(dllexport)
#else
#   define EXPORT __declspec(dllimport)
#endif

#include <iostream>
#include <BackupManager.hpp>

using namespace MKExcel;

extern "C" EXPORT BackupManager * CreateBackupManager(std::string basePath, std::string backupPath);
extern "C" EXPORT void NewBackup(BackupManager * manager);
extern "C" EXPORT std::string BackupList(BackupManager * manager);
extern "C" EXPORT void RestoreBackup(BackupManager * manager, std::string id);
