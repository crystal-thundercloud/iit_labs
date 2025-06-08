using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CircleMove : MonoBehaviour
{
    [SerializeField] Transform center;
    [SerializeField] float radius = 4f, angularSpeed = 1f;

    float posX, posY, angle = 0f;


    // Update is called once per frame
    void Update()
    {
        posX = center.position.x + Mathf.Cos(angle)*radius;
        posY = center.position.y + Mathf.Sin(angle)*radius;

        transform.position = new Vector2(posX, posY);
        angle += Time.deltaTime * angularSpeed;

        if (angle >= 2 * Mathf.PI) angle -= 2 * Mathf.PI;
        //if (angularSpeed > 0 && angle >= 360) angle -= 360;
        //else if (angularSpeed< 0 && angle <= 0) angle += 360;
    }
}
