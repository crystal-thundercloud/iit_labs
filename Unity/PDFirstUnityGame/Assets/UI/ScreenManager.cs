using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ScreenManager : MonoBehaviour
{
    public static bool gameIsPaused = false;
    public GameObject pauseMenuUI;
    public GameObject wonUI;
    public GameObject lostUI;

    private void Start()
    {
        pauseMenuUI.SetActive(false);
        wonUI.SetActive(false);
        lostUI.SetActive(false);

        Time.timeScale = 1f;
        gameIsPaused = false;
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if (gameIsPaused) Resume();
            else Pause();
        }
    }

    public void Resume()
    {
        pauseMenuUI.SetActive(false);
        Time.timeScale = 1f;
        gameIsPaused = false;
    }

    void Pause()
    {
        pauseMenuUI.SetActive(true);
        Time.timeScale = 0f;
        gameIsPaused = true;
    }

    public void MainMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }

    public void Wongame()
    {
        wonUI.SetActive(true);
        Time.timeScale = 0f;
        gameIsPaused = true;
    }
    public void Lostgame()
    {
        lostUI.SetActive(true);
        Time.timeScale = 0f;
        gameIsPaused = true;
    }

}
