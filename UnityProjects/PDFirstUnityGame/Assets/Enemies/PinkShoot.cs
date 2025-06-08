using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PinkShoot : MonoBehaviour
{
    public Transform atkpoint;
    public GameObject atksprite;

    void Start()
    {
        InvokeRepeating("Attack", 1, 2);
    }

    // Update is called once per frame
    void Attack()
    {
        Instantiate(atksprite, atkpoint.position, atkpoint.rotation);
    }
}
