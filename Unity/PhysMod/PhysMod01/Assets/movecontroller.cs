using System.Collections;
using System;
using UnityEngine;
using UnityEngine.UI;

public class movecontroller : MonoBehaviour
{
    public Animator animator;
    public Rigidbody2D rb;

    public Text time;

    public Text inputspeedX;
    public Text inputspeedY;

    public Text inputboostX;
    public Text inputboostY;

    public Text inputposX;
    public InputField inputposxfield;
    public Text inputposY;
    public InputField inputposyfield;

    public Text speedXtxt;
    public Text speedYtxt;

    public Text posxtxt;
    public Text posytxt;

    public Text fullpathtxt;

    float timef=0;
    float timeboostx=0f;
    float timeboosty=0f;

    float crntspeedx=0f;
    float crntspeedy=0f;

    float boostx=1f;
    float boosty=1f;

    float fullpath=0f;

    Vector3 prevloc;
    bool posapplied=false;

    void Start()
    {
        crntspeedx = 0f;
        crntspeedy = 0f;

        posapplied = false;

        boostx = 0f;
        boosty = 0f;

        timeboostx = 0f;
        timeboosty = 0f;

        fullpath = 0f;

        prevloc = new Vector3(0, 0, 0);
    }

    private void FixedUpdate()
    {
        //получение введённой скорости по Х
        if (float.TryParse(inputspeedX.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float spx))
        {
            crntspeedx = spx;
            //crntspeedx = float.Parse(inputspeedX.text.Replace(".", ","));
        }

        else crntspeedx = 0f;

        //получение введённой скорости по У
        if (float.TryParse(inputspeedY.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float spy))
        {
            crntspeedy = spy;
        }

        else crntspeedy = 0f;

        //получение ускорения по Х
        if (float.TryParse(inputboostX.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float box))
        {
            boostx = box;
            timeboostx += Time.fixedDeltaTime; //ускорение будет умножаться на время, прошедшее с момента применения ускорения, а не на всё время
        }
        else timeboostx = 0f;

        //получение ускорения по У
        if (float.TryParse(inputboostY.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float boy))
        {
            boosty = boy;
            timeboosty += Time.fixedDeltaTime; //ускорение будет умножаться на время, прошедшее с момента применения ускорения, а не на всё время
        }
        else timeboosty = 0f;

        crntspeedx += boostx * timeboostx;
        crntspeedy += boosty * timeboosty;

        //время будет считаться только если объект движется (задана хотя бы какая-то скорость или ускорение)
        if (crntspeedx != 0f || crntspeedy != 0f)
        {
            timef += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(timef / 60F);
            int seconds = Mathf.FloorToInt(timef % 60F);
            int milliseconds = Mathf.FloorToInt((timef * 100F) % 100F);
            time.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");
        }

        //из-за умножения на time мышь бежит слишком быстро, поэтому само перемещение будет в 50 раз медленнее (не повлияет на рассчитанные параметры)
        transform.position += new Vector3(crntspeedx/50, crntspeedy/50, 0);

        //если ни одна из скоростей не задана или равняется нулю, мышь не бежит
        if (crntspeedx == 0 && crntspeedy == 0) animator.SetBool("running", false);
        else animator.SetBool("running", true);

        //вывод скорости на экран
        speedXtxt.text = crntspeedx.ToString();
        speedYtxt.text = crntspeedy.ToString();

        //вывод позиции на экран
        posxtxt.text = transform.position.x.ToString();
        posytxt.text = transform.position.y.ToString();

        //подсчёт и вывод пройденного расстояния на экран
        fullpath += Vector3.Distance(transform.position, prevloc);
        prevloc = transform.position;
        fullpathtxt.text = fullpath.ToString(); 
    }
}
