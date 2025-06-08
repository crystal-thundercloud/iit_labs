using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class btns : MonoBehaviour
{
    public Text pausebtn;

    bool ispaused = false;
    private void Start()
    {
        ispaused = true;
        Time.timeScale = 0f;
    }

    public void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }

    public void PauseResume()
    {
        if (!ispaused)
        {
            Time.timeScale = 0f;
            pausebtn.text = "Старт";
            ispaused = true;
        }

        else
        {
            Time.timeScale = 1f;
            pausebtn.text = "Пауза";
            ispaused = false;
        }
    }

    public void Exit() {
        Application.Quit();
    }
}
