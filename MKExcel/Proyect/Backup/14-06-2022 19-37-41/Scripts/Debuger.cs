using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using MKExcel;

public class Debuger : MonoBehaviour
{
    void Start()
    {
        DllManager.Init("C:/Users/Usuario/Desktop/cosas");
        DllManager.CreateBackup();
    }
}
