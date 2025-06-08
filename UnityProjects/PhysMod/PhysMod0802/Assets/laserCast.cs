using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class laserCast : MonoBehaviour
{
    public GameObject rayOutPointGO;
    public InputField ina, Inreflections;
    public Slider posy;
    public GameObject lensParamsPrefab;
    public GameObject panel;
    public Text status;

    LineRenderer lineR;
    Vector2 rayOut, direction, direction0, hitPoint;
    RaycastHit2D hit0, hit;
    float angle;
    int reflections;

    [SerializeField]
    private GameObject[] obstackles;
    List<GameObject> lensArr = new List<GameObject>();
    List<GameObject> lensParamsArr = new List<GameObject>();
    public GameObject target;
    bool isHit;

    private void Start() {
        rayOut = rayOutPointGO.transform.position;

        lineR = GetComponent<LineRenderer>();
        lineR.positionCount = 2;

        Physics2D.queriesStartInColliders = false; //чтобы луч, начатый внутри коллайдера, игнорировал этот коллайдер

        //создание и расположение препятствий
        target.transform.position = new Vector2(Random.Range(12.7f, 14.3f), Random.Range(-7f, 3f));
        target.transform.Rotate(new Vector3(0, 0, Random.Range(-45, 45)));
        
        for (int i = 0; i < 10; i++) {
            Color colo = new Color(Random.Range(0f, 255f)/255f, Random.Range(0, 255)/255f, Random.Range(0, 255)/255f, 0.8f);
            var ob = Instantiate(obstackles[Random.Range(0, 7)]);
            
            ob.transform.position = new Vector2(Random.Range(-10.5f, 10.5f), Random.Range(-8.5f, 8.5f));
            ob.transform.Rotate(new Vector3(0, 0, Random.Range(-180, 180)));

            if (ob.CompareTag("Lens")) {
                ob.GetComponent<SpriteRenderer>().color = colo;

                var lensParam = Instantiate(lensParamsPrefab);
                lensParam.transform.SetParent(panel.transform, false);
                if (lensParamsArr.Count > 0) lensParam.transform.localPosition = new Vector3(lensParam.transform.localPosition.x, lensParamsArr[lensParamsArr.Count - 1].transform.localPosition.y - 80, 0);
                
                Text[] txt = lensParam.GetComponentsInChildren<Text>();
                Image[] clr = lensParam.GetComponentsInChildren<Image>();

                foreach (Image col in clr) {
                    col.color = new Color(colo.r, colo.g, colo.b, 1f);
                }
                foreach (Text text in txt) {
                    if (colo.r < 0.6f && colo.g < 0.6f || colo.r < 0.6f && colo.b < 0.6f || colo.g < 0.6f && colo.b < 0.6f) text.color = Color.white;
                }

                lensArr.Add(ob);
                lensParamsArr.Add(lensParam);
            }
        }
        isHit = false;
    }

    private void Update() {
        float.TryParse(Inreflections.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float objNum);
        reflections = ((int)objNum);

        //перемещение лазера и первых двух точек line renderer
        float.TryParse(ina.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out angle);
        transform.position = new Vector2(transform.position.x, posy.value);
        transform.rotation = Quaternion.Euler(0, 0, angle+90);
        
        direction0 = new Vector2(Mathf.Cos(angle * Mathf.PI / 180), Mathf.Sin(angle * Mathf.PI / 180));

        rayOut = rayOutPointGO.transform.position;
        lineR.SetPosition(0, rayOut);
            
        hit0 = Physics2D.Raycast(rayOut, direction0, 100);
        if (hit0) lineR.SetPosition(1, hit0.point);

        //получение данных линз из соответсвующих элементов UI
        for (int i = 0; i < lensArr.Count; i++) {
            var sizeTxt = lensParamsArr[i].transform.Find("InS").GetComponent<InputField>().text;
            float.TryParse(sizeTxt, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float size);
            size = (size == 0) ? 1 : size;

            var focalTxt = lensParamsArr[i].transform.Find("InF").GetComponent<InputField>().text;
            float.TryParse(focalTxt, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float focal);
            focal = (focal == 0) ? 1 : focal;

            foreach (lens gl in  lensArr[i].GetComponentsInChildren<lens>()) {
                gl.size = size;
                gl.focal = focal;
            }
        }
    }

    private void FixedUpdate() {
        lineR.positionCount = reflections + 2;
        isHit = false;
        for (int i = 2; i < lineR.positionCount; i++) {
            if (i == 2) {
                hitPoint = hit0.point;
                if (hit0.transform.CompareTag("Mirror")) direction = Vector2.Reflect(direction0, hit0.normal);
                else if (hit0.transform.CompareTag("Lens") && hit0.collider.TryGetComponent<lens>(out lens ln)) {
                    Vector2 focalPoint = new Vector2(ln.focalPoint.transform.position.x, ln.focalPoint.transform.position.y);

                    if (ln.type == "convex") direction = focalPoint - hitPoint;
                    else if (ln.type == "concave") direction = hitPoint - focalPoint;
                }
            }
            else {
                hitPoint = hit.point;
                if (hit.transform && hit.transform.CompareTag("Mirror")) direction = Vector2.Reflect(direction, hit.normal);
                else if (hit.transform && hit.transform.CompareTag("Lens") && hit.collider.TryGetComponent<lens>(out lens ln)) {
                    Vector2 focalPoint = new Vector2(ln.focalPoint.transform.position.x, ln.focalPoint.transform.position.y);

                    if (ln.type == "convex") direction = focalPoint - hitPoint;
                    else if (ln.type == "concave") direction = hitPoint - focalPoint;
                }
            }
            hitPoint += direction.normalized;
            hit = Physics2D.Raycast(hitPoint, direction, 100);
            if (hit) lineR.SetPosition(i, hit.point);

            //последующие лучи не выпускаются, если было попадание в цель
            if (hit0.transform && hit0.transform.CompareTag("Finish") || hit.transform && hit.transform.CompareTag("Finish")) {
                isHit = true;
                lineR.positionCount = i + 1;
            }
        }
        
        //проверка на попадание в цель
        if (isHit || hit0.transform && hit0.transform.CompareTag("Finish")) {
            status.text = "Попадание!";
            status.color = Color.green;
        }
        else {
            status.text = "Пока не попал";
            status.color = new Color(1f, 216/255f, 75/255f);
        }
    }
}
