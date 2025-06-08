Shader "Custom/ImmaShaderToo"
{
    Properties
    {
        _Color ("Color", Color) = (1,1,1,1)
        _MainTex ("Main Texture", 2D) = "white" {}
		_Smoothness("Smoothness", Range(0,1)) = 0.5
        _Metallic ("Metallic", Range(0,1)) = 0.0
		_Emission("Emission", Color) = (0, 0, 0)
		_BackgroundTex("Background", 2D) = "white" {}
		_BGColor("BGColor", Color) = (1,1,1,1)
		_BGSmoothness("BGSmoothness", Range(0,1)) = 0.5
		_BGMetallic("BGMetallic", Range(0,1)) = 0.0
		_BGEmission("BGEmission", Color) = (0, 0, 0)
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" "Queue" = "Geometry"}

        CGPROGRAM

        #pragma surface surf Standard fullforwardshadows
        #pragma target 3.0

        sampler2D _MainTex, _BackgroundTex;
		fixed4 _Color, _BGColor;

		half _Smoothness, _Metallic, _BGSmoothness, _BGMetallic;
		half3 _Emission, _BGEmission;

        struct Input
        {
            float2 uv_MainTex, uv_MainBG;
        };

        void surf (Input i, inout SurfaceOutputStandard o)
        {
            fixed4 col = tex2D (_MainTex, i.uv_MainTex);
            fixed4 bg = tex2D (_BackgroundTex, i.uv_MainTex);
			col *= _Color;
			bg *= _BGColor;
			o.Albedo = col.rgb*col.a+(1-col.a)*bg.rgb;
            o.Metallic = _Metallic*col.a + _BGMetallic*(1-col.a);
            o.Emission = _Emission*col.a + _BGEmission * (1-col.a);
        }
        ENDCG
    }
    FallBack "Standard"
}


