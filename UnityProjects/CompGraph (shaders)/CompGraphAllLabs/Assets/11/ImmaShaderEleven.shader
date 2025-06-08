Shader "Custom/ImmaShaderEleven"
{
    Properties
    {
        _Color ("Color", Color) = (1,1,1,1)
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
        _Smoothness("Smoothness", Range(0,1)) = 0.5
        _Metallic ("Metallic", Range(0,1)) = 0.0
        [HDR] _Emission("Emission", color) = (0,0,0)
        _OutlineColor("OutlineColor", Color) = (0,0,0,1)
        _OutlineThickness("Outline Thickness", Range(0,1)) = 0.2
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" "Queue"="Geometry"}

        CGPROGRAM

        #pragma surface surf Standard fullforwardshadows
        #pragma target 3.0

        sampler2D _MainTex;
        fixed4 _Color;
        
        half _Smoothness;
        half _Metallic;
        half3 _Emission;

        struct Input
        {
            float2 uv_MainTex;
        };

        void surf (Input i, inout SurfaceOutputStandard o)
        {
            fixed4 c = tex2D (_MainTex, i.uv_MainTex) * _Color;
            o.Albedo = c.rgb;
            o.Metallic = _Metallic;
            o.Smoothness = _Smoothness;
            o.Emission = _Emission;
        }
        ENDCG

        Pass{
            Cull Front
            CGPROGRAM

            #include "UnityCG.cginc"
            #pragma vertex MyVertexProgram 
            #pragma fragment MyFragmentProgram 

            fixed4 _OutlineColor;
            float _OutlineThickness;

            struct VertexData {
                float4 position : POSITION;
                float4 normal : NORMAL;
            };

            struct Interpolators {
                float4 position : SV_POSITION;
            };

            Interpolators MyVertexProgram(VertexData v) {
                Interpolators i;
                i.position = UnityObjectToClipPos(v.position + normalize(v.normal) * _OutlineThickness);
                return i;
            }

            fixed4 MyFragmentProgram(Interpolators i) : SV_TARGET{
                return _OutlineColor;
            }

            ENDCG
        }
    }
    FallBack "Standard"
}

