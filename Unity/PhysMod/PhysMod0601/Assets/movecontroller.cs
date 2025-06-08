using UnityEngine;
using UnityEngine.UI;

public class movecontroller : MonoBehaviour
{
    public Text timetext;
    public InputField v1text, m1text, m2text, v2text;
    public Slider heightSlider;
    public Text heightText;
    public Toggle drag;
    public Text outv1text, outv2text;

    public Rigidbody2D other;
    Rigidbody2D rb;

    float time;

    bool applied = false;
    void Start()
    {
        time = 0f;
        heightText.text = heightSlider.value.ToString();
        rb = GetComponent<Rigidbody2D>();
    }

    void Update() {
        heightText.text = heightSlider.value.ToString();
        if (!applied) {
            rb.transform.position = new Vector3(transform.position.x, heightSlider.value, 0);
        }
    }

    void FixedUpdate()
    {
        float.TryParse(v1text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float v1);

        float.TryParse(m1text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float m1);
        if (m1==0) m1 = 1;

        float.TryParse(m2text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float m2);
        if (m2==0) m2 = 1;

        float.TryParse(v2text.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float v2);

        if (Time.timeScale!=0)
        {
            if (!applied) {
                rb.mass = m1;
                other.mass = m2;
                rb.AddForce(new Vector2(v1*m1, 0), ForceMode2D.Impulse);
                other.AddForce(new Vector2(v2*m2, 0), ForceMode2D.Impulse);
                if (drag.isOn) {
                    rb.drag = 0.5f;
                    other.drag = 0.5f;
                }
                applied = true;
            }

            time += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(time / 60F);
            int seconds = Mathf.FloorToInt(time % 60F);
            int milliseconds = Mathf.FloorToInt((time * 100F) % 100F);
            timetext.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");

            outv1text.text = Mathf.Sqrt(rb.velocity.x*rb.velocity.x+rb.velocity.y*rb.velocity.y).ToString();
            outv2text.text = Mathf.Sqrt(other.velocity.x*other.velocity.x+other.velocity.y*other.velocity.y).ToString();
        }
    }

    public void heightReset() {
        heightSlider.value = 0;
    }
}
