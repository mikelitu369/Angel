using UnityEngine;
using System.Runtime.InteropServices;
using System;

namespace MKExcel
{
    public class DllManager
    {
        [DllImport("MKExcel")]
        public static extern void CreateBackupManager([MarshalAs(UnmanagedType.LPStr)] string basePath, [MarshalAs(UnmanagedType.LPStr)] string backupPath);

        [DllImport("MKExcel")]
        public static extern void NewBackup();

        [DllImport("MKExcel")]
        public static extern IntPtr BackupList();

        [DllImport("MKExcel")]
        public static extern IntPtr RestoreBackup([MarshalAs(UnmanagedType.LPStr)] string id);

        public static string backupPath;
        static IntPtr manager;

        static string ParseString(IntPtr ptr)
        {
            return Marshal.PtrToStringAnsi(ptr);
        }

        public static void Init(string path)
        {
            string backupP = "C:/Users/Usuario/Desktop/Angel/MKExcel/Proyect";
            backupPath = path;
            CreateBackupManager(Application.dataPath, backupP);
        }

        public static void CreateBackup()
        {
            NewBackup();
        }

        public static string[] GetBackupList()
        {
            return ParseString(BackupList()).Split(',');
        }

        public static string GetLastBackup()
        {
            string[] list = GetBackupList();
            return list[list.Length - 1];
        }

        public static void Restore(string id)
        {
            RestoreBackup(id);
        }

        public static bool AnyKeys()
        {
            return GetLastBackup() != "empty";
        }
    }
}