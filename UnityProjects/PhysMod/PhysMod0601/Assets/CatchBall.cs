using UnityEngine;

public class CatchBall : MonoBehaviour
{
    public GameObject pnl;
    public GameObject nicetext, oopstxt;
    private void OnTriggerEnter2D(Collider2D other) {
        Destroy(other.gameObject);
        if (other.CompareTag("Player")) {
            var oopstext = Instantiate(oopstxt, pnl.transform);
            oopstext.transform.SetParent(pnl.transform);
        }
        else if (other.CompareTag("Enemy")) {
            var nicetxt = Instantiate(nicetext, pnl.transform);
            nicetxt.transform.SetParent(pnl.transform);
        }
    }
}
