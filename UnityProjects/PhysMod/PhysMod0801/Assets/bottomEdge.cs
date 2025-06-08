using UnityEngine;
public class bottomEdge : MonoBehaviour
{
    public GameObject lens;
    void Update()
    {
        transform.position = lens.transform.position - new Vector3(0, lens.transform.localScale.y / 2, 0);
    }
}
