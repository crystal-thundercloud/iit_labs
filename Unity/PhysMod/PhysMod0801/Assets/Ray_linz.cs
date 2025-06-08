using UnityEngine;
using UnityEngine.UI;

public class Ray_linz : MonoBehaviour
{
    public LineRenderer line;
    RaycastHit2D hit;
    public GameObject lens;
    GameObject convexLens;

    public Text InAngle, InWhere, InFocus, InScale;
    public Slider posx;
    float angle, where, focus, Scale;
    Vector2 Focuspoint;
    bool created;

    void Start()
    {
        angle = 0f;
        where = 0f;
        focus = 10f;
        created = false;
    }

    private void Update() {
        float.TryParse(InAngle.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out angle);
        transform.position = new Vector2(posx.value, transform.position.y);
        transform.rotation = Quaternion.Euler(0, 0, angle);
    }

    void FixedUpdate()
    {
        if (Time.timeScale != 0f){
            float.TryParse(InAngle.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out angle);
            float.TryParse(InWhere.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out where);
            float.TryParse(InScale.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out Scale);
            float.TryParse(InFocus.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out focus);
            line.positionCount = 4;

            if (!created) {
                convexLens = Instantiate(lens, new Vector3(where, 0, 0), lens.transform.rotation);
                created = true;
            }

            if (focus > 0) focus = -focus;

            convexLens.transform.position = new Vector3(where, 0, 0);
            convexLens.GetComponent<glass>().size = Scale;
            Focuspoint = new Vector2( where, focus);
            convexLens.transform.localScale = new Vector3(convexLens.transform.localScale.x, Scale, convexLens.transform.localScale.z);

            line.SetPosition(0, transform.position);
            Ray2D ray2D = new Ray2D(new Vector2(transform.position.x, transform.position.y), new Vector2(Mathf.Sin(angle * Mathf.PI / 180), -Mathf.Cos(angle * Mathf.PI / 180)));
            hit = Physics2D.Raycast(ray2D.origin, ray2D.direction);
            if (hit.point == new Vector2(0, 0)){
                line.SetPosition(1, ray2D.direction * 100);
                line.SetPosition(2, ray2D.direction * 100);
                line.SetPosition(3, ray2D.direction * 100);
            }
            else {
                line.SetPosition(1, hit.point);
                ray2D.origin = new Vector2(hit.point.x + (hit.point.y - 0) * Mathf.Tan(angle * Mathf.PI / 180), 0);
                ray2D.direction = Focuspoint - ray2D.origin;
                hit = Physics2D.Raycast(ray2D.origin, ray2D.direction);
                line.SetPosition(2, hit.point);
                line.SetPosition(3, ray2D.direction * 100);
            }
        }
    }
}