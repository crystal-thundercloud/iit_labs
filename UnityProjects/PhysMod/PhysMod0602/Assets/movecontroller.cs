using UnityEngine;
using UnityEngine.UI;

public class movecontroller : MonoBehaviour
{
    public Text timetext;
    public InputField angletext, vtext;
    public Toggle movable;
    public Text outvtext, boosttext;

    [SerializeField]
    private GameObject[] obstackles;

    public GameObject hole;
    GameObject[] createdObstackles = new GameObject[10];

    Rigidbody2D rb;

    float time, maxv = 0;
    Vector2 vel;
    bool applied = false;
    void Start()
    {
        time = 0f;
        rb = GetComponent<Rigidbody2D>();
        hole.transform.position = new Vector2(Random.Range(12.7f, 14.3f), Random.Range(-9f, 3f));

       for (int i = 0; i < 10; i++) {
            var ob = Instantiate(obstackles[Random.Range(0, 4)]);

            ob.transform.position = new Vector2(Random.Range(-10.5f, 10.5f), Random.Range(-8.5f, 8.5f));
            ob.transform.Rotate(new Vector3(0, 0, Random.Range(0, 360)));

            createdObstackles[i] = ob;
        }
    }

    void Update()
    {
        movable.onValueChanged.AddListener(delegate {
            for (int i = 0; i < 10; i++) {
                var ob = createdObstackles[i];
                Rigidbody2D obrb = ob.GetComponent<Rigidbody2D>();

                if (movable.isOn && Random.Range(1, 10) >= 5) {
                    obrb.bodyType = RigidbodyType2D.Dynamic;
                    ob.GetComponent<SpriteRenderer>().color = new Color(110f/255f, 0f/255f, 255f/255f);
                }

                else {
                    obrb.bodyType = RigidbodyType2D.Static;
                    ob.GetComponent<SpriteRenderer>().color = new Color(255f/255f, 1f/255f, 120f/255f);
                }
            }
        });
    }

    void FixedUpdate()
    {
        float.TryParse(angletext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float angle);

        float.TryParse(vtext.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float v);

        if (Time.timeScale!=0)
        {
            if (!applied) {
                rb.AddForce(new Vector2(Mathf.Cos(angle * Mathf.PI / 180)*v, Mathf.Sin(angle * Mathf.PI / 180)*v), ForceMode2D.Impulse);
                applied = true;
            }

            // иногда при застревании шарик теряет скорость. этот код возвращает ему максимальную из предыдущих скоростей
            vel = rb.velocity;
            if (Mathf.Round(vel.magnitude)>maxv) maxv = vel.magnitude;
            else rb.velocity *= maxv / vel.magnitude;


            time += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(time / 60F);
            int seconds = Mathf.FloorToInt(time % 60F);
            int milliseconds = Mathf.FloorToInt((time * 100F) % 100F);
            timetext.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");

            outvtext.text = Mathf.Round(rb.velocity.magnitude).ToString();
        }
    }

    private void OnCollisionEnter2D(Collision2D other) {
        rb.velocity = Vector2.Reflect(vel, other.contacts[0].normal);
        if (other.rigidbody.bodyType == RigidbodyType2D.Static && Random.Range(1, 10) >= 5) {
            rb.velocity *= 1.1f;
            boosttext.text = "Boost!";
        }
        else boosttext.text = "";
    }
}
