using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class laserCast : MonoBehaviour
{
    public GameObject rayOutPointGO;
    LineRenderer lineR;
    public InputField ina, inObjNum, inPosGlass0;
    public Slider posx;
    public GameObject glassPrefab, glassParamsPrefab;
    public GameObject panel;

    Vector2 rayOut, direction, direction0, hitPoint;
    RaycastHit2D hit0, hit;
    float angle0, angle, n1, n2;


    int objectsCount;
    List<GameObject> glassArr = new List<GameObject>();
    List<GameObject> glassParamsArr = new List<GameObject>();
    int crntGlasses;

    private void Start()
    {
        rayOut = rayOutPointGO.transform.position;

        lineR = GetComponent<LineRenderer>();
        lineR.positionCount = 2;

        n1 = 1;

        Physics2D.queriesStartInColliders = false; //чтобы луч, начатый внутри коллайдера, игнорировал этот коллайдер

        crntGlasses = 0;
    }

    private void Update() {
        float.TryParse(inObjNum.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float objNum);
        objectsCount = ((int)objNum);

        //перемещение лазера и первых двух точек line renderer
        float.TryParse(ina.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out angle0);
        transform.position = new Vector2(posx.value, transform.position.y);
        transform.rotation = Quaternion.Euler(0, 0, angle0);
        
        direction0 = new Vector2(Mathf.Sin(angle0 * Mathf.PI / 180), -Mathf.Cos(angle0 * Mathf.PI / 180));

        rayOut = rayOutPointGO.transform.position;
        lineR.SetPosition(0, rayOut);
            
        hit0 = Physics2D.Raycast(rayOut, direction0, 100);
        if (hit0) lineR.SetPosition(1, hit0.point);

        //создание и расположение сред
        if (crntGlasses < objectsCount) {
            for (int i = 0; i < objectsCount; i++) {
                var glass = Instantiate(glassPrefab);
                Color colo = new Color(Random.Range(0f, 255f)/255f, Random.Range(0, 255)/255f, Random.Range(0, 255)/255f, 0.5f);
                glass.GetComponent<SpriteRenderer>().color = colo;
                if (i > 0) glass.transform.position = new Vector3(0, glassArr[i - 1].transform.position.y - glassArr[i - 1].transform.localScale.y - 0.3f , 0);
                glassArr.Add(glass);

                var glassParam = Instantiate(glassParamsPrefab);
                glassParam.transform.SetParent(panel.transform, false);
                
                Text[] txt = glassParam.GetComponentsInChildren<Text>();
                txt[0].text = "#" + (i+1);

                Image[] clr = glassParam.GetComponentsInChildren<Image>();
                if (i > 0) glassParam.transform.localPosition = new Vector3(glassParam.transform.localPosition.x, glassParamsArr[i-1].transform.localPosition.y - 80, 0);
                foreach (Image col in clr) {
                    col.color = new Color(colo.r, colo.g, colo.b, 1f);
                }
                foreach (Text text in txt) {
                    if (colo.r < 0.6f && colo.g < 0.6f || colo.r < 0.6f && colo.b < 0.6f || colo.g < 0.6f && colo.b < 0.6f) text.color = Color.white;
                }
                glassParamsArr.Add(glassParam);

                crntGlasses++;
            }
        }
        
        else if (crntGlasses > objectsCount) {
            for (int i = crntGlasses - 1; i >= objectsCount; i--) {
                Destroy(glassArr[i]);
                Destroy(glassParamsArr[i]);
                glassArr.RemoveAt(i);
                glassParamsArr.RemoveAt(i);
                crntGlasses--;
            }
        }

        float.TryParse(inPosGlass0.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float posGlass0);

        for (int i = 0; i < objectsCount; i++) {
            var refrTxt = glassParamsArr[i].transform.Find("Inn").GetComponent<InputField>().text;
            float.TryParse(refrTxt, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float refr);
            if (refr == 0) refr = 1;
            glassArr[i].GetComponent<glass>().refraction = refr;

            var sizeTxt = glassParamsArr[i].transform.Find("Ins").GetComponent<InputField>().text;
            float.TryParse(sizeTxt, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float size);
            if (size==0) size = 1;
            glassArr[i].GetComponent<glass>().size = size;
            
            if (i == 0) glassArr[i].transform.position = new Vector3(0, posGlass0, 0);
            if (i > 0) glassArr[i].transform.position = new Vector3(0, glassArr[i - 1].transform.position.y - glassArr[i - 1].transform.localScale.y / 2 - glassArr[i].transform.localScale.y / 2 - 0.3f , 0);
        }
    }
    private void FixedUpdate() {
        if (Time.timeScale != 0f) {
            lineR.positionCount = 2 + objectsCount*2;

            for (int i = 2; i < 2 + objectsCount*2; i++) {
                if (i == 2) {
                    hitPoint = hit0.point;
                    if (hit0 && hit0.collider.TryGetComponent<glass>(out glass comp0)) n2 = comp0.refraction;
                    angle = Mathf.Asin(Mathf.Sin(angle0 * Mathf.PI / 180) / (n2 / n1)) * Mathf.Rad2Deg;
                }
                else {
                    hitPoint = hit.point;
                    if (hit && hit.collider.TryGetComponent<glass>(out glass comp)) n2 = comp.refraction;
                    angle = Mathf.Asin(Mathf.Sin(angle * Mathf.PI / 180) / (n2 / n1)) * Mathf.Rad2Deg;
                }
                n1 = n2;
                direction = new Vector2(Mathf.Sin(angle * Mathf.PI / 180), -Mathf.Cos(angle * Mathf.PI / 180));

                hitPoint -= new Vector2(0, 0.01f);
                hit = Physics2D.Raycast(hitPoint, direction, 100);
                if (hit) lineR.SetPosition(i, hit.point);
            }
        }
    }
}
