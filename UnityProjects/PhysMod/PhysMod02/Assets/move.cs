using System.Collections;
using System;
using UnityEngine;
using UnityEngine.UI;

public class move : MonoBehaviour
{
    public Text time;

    public InputField inputRadius;
    public InputField inputRotationFrequincy;

    public Text rotationsCounttxt;
    public Text rotationAngletxt;
    public Text angularSpeedtxt;
    public Text linearSpeedtxt;
    public Text posxtxt;
    public Text posytxt;
    public Text fullpathtxt;

    float timef = 0;

    float radius = 0f;
    float rotationFrequincy = 0f;

    float rotationsCount = 0f;
    float rotationAngle = 0f;
    float angularSpeed = 0f;
    float linearSpeed = 0f;

    float fullpath = 0f;

    Vector3 prevloc;

    void Start()
    {
        timef = 0;

        radius = 0f;
        rotationFrequincy = 0f;

        rotationsCount = 0f;
        rotationAngle = 0f;
        angularSpeed = 0f;
        linearSpeed = 0f;

        fullpath = 0f;
    }

    private void FixedUpdate()
    {
        //��������� �������
        if (float.TryParse(inputRadius.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float r))
        {
            radius = r;
        }

        else radius = 0;
        
        //��������� ������� ��������
        if (float.TryParse(inputRotationFrequincy.text, System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float rf))
        {
            rotationFrequincy = rf;
        }

        else rotationFrequincy = 0;

        //������� � ����� ������� ��������
        angularSpeed = 2 * (float)Math.PI * rotationFrequincy;
        angularSpeedtxt.text = angularSpeed.ToString();

        //������� � ����� �������� ��������
        linearSpeed = 2 * (float)Math.PI * radius * rotationFrequincy;
        linearSpeedtxt.text = linearSpeed.ToString();

        //����� ����� ��������� ������ ���� ������ ������� ��������
        if (rotationFrequincy != 0f)
        {
            timef += Time.fixedDeltaTime;
            int minutes = Mathf.FloorToInt(timef / 60F);
            int seconds = Mathf.FloorToInt(timef % 60F);
            int milliseconds = Mathf.FloorToInt((timef * 100F) % 100F);
            time.text = minutes.ToString("00") + ":" + seconds.ToString("00") + ":" + milliseconds.ToString("00");
        }

        //������� � ����� ���� ��������
        rotationAngle += angularSpeed * Time.fixedDeltaTime * Mathf.Rad2Deg * 2;
        rotationAngle %= 360f;
        rotationAngletxt.text = rotationAngle.ToString();

        transform.position = new Vector3(Convert.ToSingle(radius * Math.Cos(Convert.ToDouble(angularSpeed * timef))), Convert.ToSingle(radius * Math.Sin(Convert.ToDouble(angularSpeed * timef))), 0);
        //transform.Rotate(0, 0, angularSpeed);

        //����� ������� �� �����
        posxtxt.text = transform.position.x.ToString();
        posytxt.text = transform.position.y.ToString();

        //������� � ����� ����� ��������
        rotationsCount = timef * rotationFrequincy;
        //if (fullpath != 0)  //rotationsCount = fullpath / (2 * (float)Math.PI * radius);
        //else rotationsCount = 0;
        rotationsCounttxt.text = rotationsCount.ToString();

        //������� � ����� ����������� ���������� �� �����
        fullpath = 2 * Mathf.PI * radius * rotationsCount;
        //fullpath += Vector3.Distance(transform.position, prevloc);
        //prevloc = transform.position;
        fullpathtxt.text = fullpath.ToString();
    }
}