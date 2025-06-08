using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HealthBar : MonoBehaviour
{
    public Slider hpslider;

    public Image fill;
    public Gradient gradient;
    
    public void SetMaxHealth(int hp)
    {
        hpslider.maxValue = hp;
        hpslider.value = hp;
        
        fill.color = gradient.Evaluate(1f);
    }

    public void SetHealth(int hp)
    {
        hpslider.value = hp;
        fill.color = gradient.Evaluate(hpslider.normalizedValue);
    }
}
