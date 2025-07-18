using UnityEngine;
public class ApplyShader : MonoBehaviour
{
    public int SphereAmount = 17;
    public ComputeShader Shader;

    public GameObject[] Prefab;

    ComputeBuffer resultBuffer;
    int kernel;
    uint threadGroupSize;
    Vector3[] output;

    Transform[] instances;

    void Start() {
        kernel = Shader.FindKernel("Spheres");
        Shader.GetKernelThreadGroupSizes(kernel, out threadGroupSize, out _, out _);

        resultBuffer = new ComputeBuffer(SphereAmount, sizeof(float) * 3);
        output = new Vector3[SphereAmount];

        instances = new Transform[SphereAmount];
        for (int i = 0; i < SphereAmount; i++) {
            instances[i] = Instantiate(Prefab[Random.Range(0, 4)], transform).transform;
        }
    }

    void Update() {
        Shader.SetFloat("Time", Time.time);
        Shader.SetBuffer(kernel, "Result", resultBuffer);
        int threadGroups = (int) ((SphereAmount + (threadGroupSize - 1)) / threadGroupSize);
        Shader.Dispatch(kernel, threadGroups, 1, 1);
        resultBuffer.GetData(output);

        for (int i = 0; i < instances.Length; i++) instances[i].localPosition = output[i];
    }

    void OnDestroy() {
        resultBuffer.Dispose();
    }
}