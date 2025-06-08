using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HeroAttack : MonoBehaviour
{
    public Transform atkpoint;
    public Transform rngatkpoint;
    public float atkrange = 1f;
    public LayerMask enemies;

    public GameObject rangedAttack;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Q) || Input.GetKeyDown(KeyCode.Mouse0))
        {
            AttackMelee();
        }

        else if (Input.GetKeyDown(KeyCode.E) || Input.GetKeyDown(KeyCode.Mouse1))
        {
            AttackRanged();
        }
    }

    void AttackMelee()
    {
        Collider2D[] hit = Physics2D.OverlapCircleAll(atkpoint.position, atkrange, enemies);

        foreach (Collider2D enemy in hit)
        {
            Debug.Log("Hit " + enemy.name);
        }
    }

    void AttackRanged()
    {
        Instantiate(rangedAttack, rngatkpoint.position, rngatkpoint.rotation);
    }

    private void OnDrawGizmosSelected() //рисуем окружность вокруг центра атаки, чтобы видеть радиус
    {
       if (atkpoint != null) Gizmos.DrawWireSphere(atkpoint.position, atkrange);
    }
}
