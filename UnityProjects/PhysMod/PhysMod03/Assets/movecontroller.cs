using System;
using UnityEngine;
using UnityEngine.UI;

public class movecontroller : MonoBehaviour
{
    public Text timetext;

    public Text atext, btext; //x
    public Text ctext, dtext; //y

    public Text t1text, t2text, t3text;

    public Text speedxtext, speedytext;
    public Text boostxtext, boostytext;

    public Text speedAlltext;

    public Text fullpathtext;

    float a, b, c, d, t1, t2, t3, time, dt;
    float ax, ay, axtext, aytext;
    float vx, vy, vxtext, vytext;
    float speedAll;
    float fullpath;

    Vector3 prevloc;
    
    // Start is called before the first frame update
    void Start()
    {
        a = b = c = d = 0;
        t1 = t2 = t3 = 0;
        time = 0;
        ax = ay = 0;
        vx = vy = 0;
        speedAll = 0;
        fullpath = 0;

        prevloc = transform.position;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        transform.Rotate(0, 0, 0.1f);


        if (Time.timeScale!=0)
        {

            if (float.TryParse(atext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float af))
            {
                a = af;
            }

            if (float.TryParse(btext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float bf))
            {
                b = bf;
            }

            if (float.TryParse(ctext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float cf))
            {
                c = cf;
            }

            if (float.TryParse(dtext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float df))
            {
                d = df;
            }

            if (float.TryParse(t1text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float t1f))
            {
                t1 = t1f;
            }

            if (float.TryParse(t2text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float t2f))
            {
                t2 = t2f;
            }

            if (float.TryParse(t3text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float t3f))
            {
                t3 = t3f;
            }

            time += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(time / 60F);
            int seconds = Mathf.FloorToInt(time % 60F);
            int milliseconds = Mathf.FloorToInt((time * 100F) % 100F);
            timetext.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");

            if (time >= t1)
            {
                dt += Time.fixedDeltaTime;

                ax = a + b*dt;
                ay = c + d*dt;

                vx = ax * dt;
                vy = ay * dt;


                transform.position += new Vector3(vx * Time.fixedDeltaTime, vy * Time.fixedDeltaTime, 0);

                if (time<=t3)
                {
                    axtext = ax;
                    aytext = ay;

                    vxtext = vx;
                    vytext = vy;

                    speedAll = Mathf.Sqrt(vx*vx + vy*vy);
                }

            }

            if (time >= t3)
            {
                speedxtext.text = vxtext.ToString();
                speedytext.text = vytext.ToString();

                boostxtext.text = axtext.ToString();
                boostytext.text = aytext.ToString();

                speedAlltext.text = speedAll.ToString();

            }


            if (time >= t2)
            {
                fullpath += Vector3.Distance(transform.position, prevloc);
                prevloc = transform.position;
                fullpathtext.text = fullpath.ToString();
                Time.timeScale = 0;
            }


        }
    }
}
