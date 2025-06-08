using UnityEngine;

public class lens : MonoBehaviour
{
    public float size;
    public float focal;
    public GameObject focalPoint;
    public string type;
    Collider2D col;
    private void Update() {
        transform.parent.localScale = new Vector3(size, size, 0);
        col = GetComponent<Collider2D>();
        if (col.GetType() == typeof(EdgeCollider2D)) {
            GetComponent<EdgeCollider2D>().points[0] = new Vector2(-0.5f, 0.5f);
            GetComponent<EdgeCollider2D>().points[0] = new Vector2(-0.500001f, 0.5f);
        }
        else if (col.GetType() == typeof(BoxCollider2D)) {
            GetComponent<BoxCollider2D>().size = new Vector2(1.001f, 1);
            GetComponent<BoxCollider2D>().size = new Vector2(1, 1);
        }
        else if (col.GetType() == typeof(PolygonCollider2D)) {
            GetComponent<PolygonCollider2D>().offset = new Vector2(0.0001f, 0f);
            GetComponent<PolygonCollider2D>().offset = new Vector2(0f, 0f);
        }

        if (type == "concave") {
            if (name == "back") focalPoint.transform.localPosition = new Vector2(-focal, transform.localPosition.y);
            else if (name == "front") focalPoint.transform.localPosition = new Vector2(focal, transform.localPosition.y);
        }
        else {
            if (name == "back") focalPoint.transform.localPosition = new Vector2(focal, transform.localPosition.y);
            else if (name == "front") focalPoint.transform.localPosition = new Vector2(-focal, transform.localPosition.y);
        }
    }
}
