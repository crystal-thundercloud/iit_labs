Shader "Custom/ImmaShaderTenToo"
{
    Properties{
        _Color ("Color", Color) = (0, 0, 0, 1)
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
        _Cutoff ("Alpha Cutoff", Range(0, 1)) = 0.5
        _Threshold ("Threshold", Range(0., 1.)) = 0
    }

    SubShader{
        Tags {
            "Queue" = "AlphaTest"
            "RenderType" = "TransparentCutout"
            "IgnoreProjector" ="True"
        }

        LOD 200
        Cull Back
       
        CGPROGRAM

        #pragma surface surf Lambert alphatest:_Cutoff
        #pragma target 3.0

        sampler2D _MainTex;
        float _Threshold;

        struct Input{
            float2 uv_MainTex;
        };

        fixed4 _Color;

        UNITY_INSTANCING_BUFFER_START(Props)
        UNITY_INSTANCING_BUFFER_END(Props)

        void surf(Input IN, inout SurfaceOutput o) {
            fixed4 c = tex2D(_MainTex, IN.uv_MainTex) * _Color;
            c.rgb = abs(_Threshold - c.rgb);
            o.Albedo = c.rgb;
            o.Alpha = c.a;
        }

        ENDCG
    }
}
