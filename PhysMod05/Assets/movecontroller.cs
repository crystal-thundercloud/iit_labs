using UnityEngine;
using UnityEngine.UI;

public class movecontroller : MonoBehaviour
{
    public Text timetext;

    public InputField vtext, htext, ttext;
    public InputField Atext, angletext;
    public Toggle Atoggle;

    public Text flytime;
    public Text speedflytext, speedendtext;
    public Text distancetext, fullpathtext;

    float v, h, t, A, angle, anglerad, time, dt;

    float distance, posx, fullpath;

    float x, y, vx, vy, t1, t2, bx, by;
    const float g = 9.81f;

    Vector3 prevloc;
    
    void Start()
    {
        v = h = t = A = angle = time = dt = 0;
        prevloc = transform.position;
    }

    void FixedUpdate()
    {
        if (Time.timeScale!=0)
        {
            float.TryParse(vtext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float v);

            float.TryParse(htext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float h);

            float.TryParse(ttext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float t);

            float.TryParse(Atext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float A);

            float.TryParse(angletext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float angle);

            time += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(time / 60F);
            int seconds = Mathf.FloorToInt(time % 60F);
            int milliseconds = Mathf.FloorToInt((time * 100F) % 100F);
            timetext.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");

            if (time <= t) transform.position = new Vector3(0, h, 0);

            else if (time >= t)
            {
                dt += Time.fixedDeltaTime;
                anglerad = angle*Mathf.PI/180;
                prevloc = transform.position;
                
                if (A==0) {
                    Debug.Log("01");
                    x = v*dt;
                    y = h - v*dt-(dt*dt*g/2);
                    transform.position = new Vector3(x, y, 0);
                    posx = 0;

                    if (transform.position.y <= 0) {
                        Time.timeScale = 0;
                        distance += Mathf.Abs(transform.position.x-posx);
                        distancetext.text = distance.ToString();
                    }
                }

                else {

                    if (!Atoggle.isOn) {
                        Debug.Log("02");
                        v = A;
                        x = v*Mathf.Cos(anglerad)*dt;
                        //y = x*Mathf.Tan(anglerad)-(g*x*x/2*v*v*Mathf.Cos(anglerad)*Mathf.Cos(anglerad));
                        y = h+v*Mathf.Sin(anglerad)*dt-(g*dt*dt)/2;
                        
                        distance = v*v*Mathf.Sin(2*anglerad)/g;

                        if (transform.position.y >= h) {
                            vx = v*Mathf.Cos(anglerad);
                            vy = v*Mathf.Sin(anglerad)-g*dt;
                            posx = transform.position.x;
                            t1 = 2*v*Mathf.Sin(anglerad)/g;
                        }

                        else t2 = Mathf.Sqrt(2*h/g);

                        if (transform.position.y <= 0) {
                            Time.timeScale = 0;
                            distance += Mathf.Abs(transform.position.x-posx);
                            distancetext.text = distance.ToString();
                            flytime.text = (t1+t2).ToString();
                            speedflytext.text = (fullpath/(t1+t2)).ToString();
                            speedendtext.text = Mathf.Sqrt(vx*vx+(0-vy-g*dt)*(0-vy-g*dt)).ToString();
                        }
                    }

                    else {
                        Debug.Log("03");
                        bx = A*Mathf.Cos(anglerad);
                        by = A*Mathf.Sin(anglerad) - g;
                        x = bx*dt*dt/2;
                        y = h+dt*dt*by/2;

                        distance = bx*dt*dt/2;

                        if (transform.position.y <= 0) {
                            Time.timeScale = 0;
                            distance += Mathf.Abs(transform.position.x-posx);
                            distancetext.text = distance.ToString();
                            flytime.text = dt.ToString();
                            speedflytext.text = (fullpath/time).ToString();
                            speedendtext.text = Mathf.Sqrt(bx*bx*dt*dt+by*by*dt*dt).ToString();
                        }
                    }
                    transform.position = new Vector3(x, y, 0);
                }

                fullpath += Vector3.Distance(transform.position, prevloc);
                fullpathtext.text = fullpath.ToString();
            }
        }
    }
}
