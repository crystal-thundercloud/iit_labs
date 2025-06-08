using UnityEngine;

public class postprCamera : MonoBehaviour
{
    [SerializeField]
    private Material postprocessMaterial;

    void OnRenderImage(RenderTexture source, RenderTexture destination){
        Graphics.Blit(source, destination, postprocessMaterial);
    }
}
