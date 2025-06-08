using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyTakeDamage : MonoBehaviour
{
    public int health = 30;
    
    public void TakeDamage(int damage)
    {
        health -= damage;
        if (health <= 0) Die();
    }

    void Die()
    {
        Destroy(gameObject);
    }
}
