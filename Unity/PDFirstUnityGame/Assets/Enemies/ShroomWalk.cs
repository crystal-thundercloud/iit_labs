using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShroomWalk : MonoBehaviour
{
    public int speed = 3;

    [SerializeField]
    private Vector3[] positions;

    private int i;

    // Update is called once per frame
    void Update()
    {
        transform.position = Vector2.MoveTowards(transform.position, positions[i], Time.deltaTime*speed);

        if (transform.position == positions[i])
        {
            if (i == positions.Length - 1)
            {
                i = 0;
                Flip();
            }
            else
            {
                i++;
                Flip();
            }
        }

    }

    void Flip()
    {
        transform.Rotate(0f, 180f, 0f);
    }
}
