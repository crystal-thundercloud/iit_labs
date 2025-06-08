using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bgmoveU : MonoBehaviour
{
    public GameObject bg;
    public GameObject sqR, sqL, sqD;

    private void OnTriggerEnter2D(Collider2D col)
    {
        if (col.CompareTag("Player"))
        {
            bg.transform.position += new Vector3(0f, 62f, 0f);
            transform.position += new Vector3(0f, 62f, 0f);

            sqR.transform.position += new Vector3(0f, 62f, 0f);
            sqL.transform.position += new Vector3(0f, 62f, 0f);
            sqD.transform.position += new Vector3(0f, 62f, 0f);
        }
    }
}
