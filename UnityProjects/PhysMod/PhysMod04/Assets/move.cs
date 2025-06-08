using Cinemachine;
using System;
using UnityEngine;
using UnityEngine.UI;

public class move : MonoBehaviour
{
    public CinemachineVirtualCamera cam;
    public Text time;

    public InputField speedtxt;
    public InputField rtxt;
    public InputField atxt;
    public InputField btxt;
    public InputField ttxt;
    public InputField t1txt;

    public Text stxt;
    public Text posxtxt;
    public Text posytxt;
    public Text posztxt;

    float timef = 0;
    float linearspeed = 0f;
    float speed = 0f;
    float r, a, b, aab = 0f;
    float t, t1, dt = 0f;

    float rf, rt, h = 0f;

    float s = 0f;

    bool apl = false;

    void Start()
    {
        timef = 0;

        speed = 0f;
        linearspeed = 0f;
        r = 0f;
        a = b = aab = 0f;

        t = t1 = dt = 0f;

        rf = rt = h = 0f;

        s = 0f;

        apl = false;

        InvokeRepeating("camMove", 0f, 1.5f);

    }

    void FixedUpdate()
    {
        if (Time.timeScale != 0)
        {

            if (float.TryParse(speedtxt.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float sp))
            {
                speed = sp;
            }

            else speed = 0;

            if (float.TryParse(rtxt.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float rr))
            {
                r = rr;
            }

            else r = 0;

            if (float.TryParse(atxt.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float aa))
            {
                a = aa;
            }

            else a = 0;

            if (float.TryParse(btxt.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float bb))
            {
                b = bb;
            }

            else b = 0;

            if (float.TryParse(ttxt.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float tt))
            {
                t = tt;
            }

            else t = 0;

            if (float.TryParse(t1txt.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float tt1))
            {
                t1 = tt1;
            }

            else t1 = 0;

            timef += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(timef / 60F);
            int seconds = Mathf.FloorToInt(timef % 60F);
            int milliseconds = Mathf.FloorToInt((timef * 100F) % 100F);
            time.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");

            if (timef >= t)
            {
                dt += Time.fixedDeltaTime;

                aab = a + (b * dt);

                linearspeed = speed + (aab * dt);

                transform.position = new Vector3(r*Mathf.Sin((linearspeed/r)*timef), (linearspeed/r) * timef, r*Mathf.Cos((linearspeed / r) * timef));
                
            }

            if (t1!=0)
            {
                if (timef>=t1&&!apl)
                {
                    Time.timeScale = 0f;
                    apl = true;
                }
            }
            posxtxt.text = transform.position.x.ToString();
            posytxt.text = transform.position.y.ToString();
            posztxt.text = transform.position.z.ToString();

            //частота вращения из формулы линейной скорости (2 + пи * р * частота вращения)
            rf = linearspeed / (2*Mathf.PI*r);

            //число оборотов
            rt = rf * (timef - t);

            if (rt < 1)
            {
                //Debug.Log("time: "+timef+"rt: "+rt);
                h = transform.position.y;
            }
            else s = Mathf.Sqrt(Mathf.Pow(2 * (float)Math.PI * r, 2) + Mathf.Pow(h, 2)) * rt;

            stxt.text = s.ToString();
        }
    }

    void camMove()
    {
        cam.transform.position = new Vector3(0, transform.position.y + 15, -((r * 2) + 10));
    }
}
