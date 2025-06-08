using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class btns : MonoBehaviour
{
    public Text pausebtn;
    
    private void Start()
    {
        Time.timeScale = 0f;
    }

    public void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }

    public void PauseResume()
    {
        if (Time.timeScale == 1f)
        {
            Time.timeScale = 0f;
            pausebtn.text = "Старт";
        }

        else
        {
            Time.timeScale = 1f;
            pausebtn.text = "Пауза";
        }
    }
}
