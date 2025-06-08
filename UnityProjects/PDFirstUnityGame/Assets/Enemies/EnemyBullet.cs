using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyBullet : MonoBehaviour
{
    public float bltspeed = 4f;
    public int damage = 10;
    public Rigidbody2D rb;

    private void Start()
    {
        rb.velocity = transform.right * bltspeed;
        Destroy(gameObject, 2f);
    }

    private void OnTriggerEnter2D(Collider2D col)
    {
        if (col.CompareTag("Player")) col.SendMessage("TakeDamage", damage);
        Destroy(gameObject);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(gameObject);
    }
}
