using UnityEngine;
using UnityEngine.UI;

public class CatchBall : MonoBehaviour
{
    public GameObject flag, flagspawn;
    public Text status;
    bool applied = false;
    private void OnTriggerEnter2D(Collider2D other) {
        if (other.CompareTag("Player")&&!applied) {
            var flg = Instantiate(flag, flagspawn.transform);
            status.text = "Попадание!";
            status.color = Color.green;
            applied = true;
            Time.timeScale = 0f;
        }
    }
}
