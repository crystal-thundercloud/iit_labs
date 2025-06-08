using UnityEngine;
using UnityEngine.UI;

public class movecontroller : MonoBehaviour
{
    public Animator animator;
    public Text timetext;
    public GameObject land1, land2, land3;
    public GameObject touch1, touch3;

    public InputField inm, inu1, inu2, inu3, inangle, inf0, ina, int1;
    public Toggle ex2;
    public Text ismovingtext;



    float time, t, u1, u2, u3;
    bool applied;
    Rigidbody2D rb;
    void Start()
    {
        time = t = 0f;
        applied = false;
        rb = GetComponent<Rigidbody2D>();
    }

    private void Update() {
        if (!applied) {
            float.TryParse(inangle.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float angle);

            land2.transform.rotation = Quaternion.Euler(0, 0, angle);

            //перемещение платформ 1 и 3 в зависимости от положение платформы 2 (число взято из длины платформ)
            land1.transform.position = touch1.transform.position + new Vector3(17.251f, 0, 0);
            land3.transform.position = touch3.transform.position - new Vector3(17.251f, 0, 0);

            if (ex2.isOn) transform.position = touch1.transform.position + new Vector3(-1, 2f, 0);
            else transform.position = touch1.transform.position + new Vector3(10, 2f, 0);
        }
    }

    void FixedUpdate()
    {
        if (Time.timeScale!=0f) {
            float.TryParse(inm.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float m);
            if (m==0) m = 1;
            float.TryParse(inu1.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out u1);
            float.TryParse(inu2.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out u2);
            float.TryParse(inu3.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out u3);
            float.TryParse(inf0.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float f0);
            float.TryParse(ina.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float a);
            float.TryParse(int1.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float t1);

            rb.mass = m;
            land1.GetComponent<Collider2D>().sharedMaterial.friction = u1;
            land2.GetComponent<Collider2D>().sharedMaterial.friction = u2;
            land3.GetComponent<Collider2D>().sharedMaterial.friction = u3;


            time += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(time / 60F);
            int seconds = Mathf.FloorToInt(time % 60F);
            int milliseconds = Mathf.FloorToInt((time * 100F) % 100F);
            timetext.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");

            if (time>=t1) {
                applied = true;
                rb.AddForce(new Vector2(-(((f0 + a * t) * m) + rb.velocity.x), 0));
                t += Time.deltaTime;

                if (rb.velocity != new Vector2(0 ,0)) {
                    animator.SetBool("isMoving", true);
                    ismovingtext.text = "Есть движение";
                    ismovingtext.color = new Color(0, 212 / 255f, 2 / 255f);
                }

                else {
                    animator.SetBool("isMoving", false);
                    ismovingtext.text = "Нет движения";
                    ismovingtext.color = new Color(212f / 255f, 11f / 255f, 0);
                }
                
            }

        }
    }

    private void OnCollisionEnter2D(Collision2D other) {
        if (other.gameObject.CompareTag("land1")) rb.drag = rb.angularDrag = u1;
        else if (other.gameObject.CompareTag("land2")) rb.drag = rb.angularDrag = u2;
        else if (other.gameObject.CompareTag("land3")) rb.drag = rb.angularDrag = u3;
    }
}
