using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public float bltspeed = 20f;
    public int damage = 10;

    public LayerMask enemies;
    public Rigidbody2D rb;

    private void Start()
    {
        rb.velocity = transform.right * bltspeed;
    }

    void Update()
    {
        Destroy(gameObject, 1f);
    }

    private void OnTriggerEnter2D(Collider2D col)
    {
        Collider2D[] hit = Physics2D.OverlapCircleAll(rb.position, 1, enemies);

        foreach (Collider2D enemy in hit)
        {
            enemy.SendMessage("TakeDamage", damage);
        }

        Destroy(gameObject);
    }
}
