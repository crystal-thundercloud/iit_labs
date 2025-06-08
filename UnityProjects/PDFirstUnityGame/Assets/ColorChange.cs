using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorChange : MonoBehaviour
{
    [SerializeField] [Range(0f, 1f)] float time;
    [SerializeField] Color[] SwitchColors;
    int i = 0;
    int len;
    float t = 1f;
    void Start()
    {
        len = SwitchColors.Length;
        t = 1f;
    }

    void Update()
    {
        GetComponent<SpriteRenderer>().color = Color.Lerp(GetComponent<SpriteRenderer>().color, SwitchColors[i], time*Time.deltaTime);

        t = Mathf.Lerp(t, 1f, time*Time.deltaTime);
        if (t>.9f) {
            t = 0f;
            i++;
            if (i == len) i = 0;
        }
    }
}

