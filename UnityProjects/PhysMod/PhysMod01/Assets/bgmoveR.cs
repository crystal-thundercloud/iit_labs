using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bgmoveR : MonoBehaviour
{
    public GameObject bg;
    public GameObject sqL, sqU, sqD;

    private void OnTriggerEnter2D(Collider2D col)
    {
        if (col.CompareTag("Player"))
        {
            bg.transform.position += new Vector3(100f, 0f, 0f);
            transform.position += new Vector3(100f, 0f, 0f);

            sqL.transform.position += new Vector3(100f, 0f, 0f);
            sqU.transform.position += new Vector3(100f, 0f, 0f);
            sqD.transform.position += new Vector3(100f, 0f, 0f);
        };
    }
}
