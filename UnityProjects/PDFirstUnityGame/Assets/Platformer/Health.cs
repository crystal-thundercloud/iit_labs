using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Health : MonoBehaviour
{
    public Rigidbody2D rb;
    public Transform respPoint;

    public GameObject scrnmngr;
    public HealthBar healthbar;

    public Text lives;

    public int maxhealth;
    public int curhealth;
    public int hrts;
    string strhrts;

    bool triggered = false; //фиксим баг с двойным триггером из-за двух коллайдеров

    // Start is called before the first frame update
    void Start()
    {
        maxhealth = 100;
        curhealth = maxhealth;
        healthbar.SetMaxHealth(maxhealth);
        hrts = 3;
        strhrts = hrts.ToString();
        lives.text = strhrts;
    }

    void Update()
    {
        if (curhealth <= 0) Die();
        healthbar.SetHealth(curhealth);
        strhrts = hrts.ToString();
        lives.text = strhrts;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
         if (collision.collider.gameObject.layer == LayerMask.NameToLayer("Enemies"))
         {
            if (!triggered)
            {
                TakeDamage(20);
                triggered = true;
            }
         }

        if (collision.collider.gameObject.layer == LayerMask.NameToLayer("DieLine")) Die();
    }

    public void OnCollisionExit2D(Collision2D collision)
    {
        triggered = false;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("ExtraLife")&&!triggered)
        {
            Extralife();
            triggered = true;
        }
        if (collision.CompareTag("Enemy")&&!triggered)
        {
            TakeDamage(20);
            triggered = true;
        }
    }

    public void OnTriggerExit2D(Collider2D collision)
    {
        triggered = false;
    }

    void TakeDamage(int damage)
    {
        curhealth -= damage;
        healthbar.SetHealth(curhealth);
        rb.velocity = transform.right * -50;
    }

    void Die()
    {
        hrts -= 1;
        strhrts = hrts.ToString();
        lives.text = strhrts;
        if (hrts >=0) Respawn();
        else scrnmngr.SendMessage("Lostgame");
    }

    void Respawn()
    {
        transform.position = respPoint.position;
        curhealth = 100;
        healthbar.SetHealth(curhealth);
    }

    void Extralife()
    {
        hrts++;
    }

}
