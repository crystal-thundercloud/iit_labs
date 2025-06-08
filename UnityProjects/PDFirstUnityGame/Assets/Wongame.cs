using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wongame : MonoBehaviour
{
    public GameObject scrnmngr;

    private void OnTriggerEnter2D(Collider2D col)
    {
        if (col.CompareTag("Player")) scrnmngr.SendMessage("Wongame");
    }
}
