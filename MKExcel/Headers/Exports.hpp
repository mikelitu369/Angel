#pragma once

#ifdef DLLPROJECT_EXPORTS
#   define EXPORT __declspec(dllexport)
#else
#   define EXPORT __declspec(dllimport)
#endif

#include <iostream>
#include <BackupManager.hpp>

using namespace MKExcel;

std::string BackupManager::basePath = "";
std::string BackupManager::backupPath = "";
std::string BackupManager::keys = "";

extern "C" EXPORT void CreateBackupManager(char* basePath, char* backupPath);
extern "C" EXPORT void NewBackup();
extern "C" EXPORT char* BackupList();
extern "C" EXPORT void RestoreBackup(char* id);
