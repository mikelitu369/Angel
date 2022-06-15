using UnityEditor;
using UnityEngine;

namespace MKExcel
{
    public class BackupTool : EditorWindow
    {
        string[] keys;
        string lastKey;
        bool init = false;

        string path;

        [MenuItem("Tools/Backup Manager")]
        public static void ShowWindow()
        {
            GetWindow(typeof(BackupTool));
        }

        [System.Obsolete]
        private void OnGUI()
        {
            GUILayout.Label("Backup Manager", EditorStyles.boldLabel);
            path = EditorGUILayout.TextField("Backup Path", path);
            if(init)
            {
                if (path != DllManager.backupPath) init = false;
                if(DllManager.AnyKeys())
                {
                    keys = DllManager.GetBackupList();
                    if (keys.Length != 0)
                    {
                        lastKey = DllManager.GetLastBackup();
                    }
                    GUILayout.Label("Last Backup: " + lastKey, EditorStyles.boldLabel);
                }
                if(GUILayout.Button("New Backup"))
                {
                    Backup();
                }

            }
            else
            {
                GUILayout.Label("Writte path to make backups and init manager");

                if (GUILayout.Button("Init"))
                {
                    Init();
                }
            }
        }
        private void Init()
        {
            if (path == "") return;
            DllManager.Init(path);
            init = true;
        }
        private void Backup()
        {
            DllManager.CreateBackup();
        }
    }
}
