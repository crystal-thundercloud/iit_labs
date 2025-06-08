Shader "Custom/ImmaShaderSevenStandart"
{
	Properties{
		_FromColor("From Color", Color) = (1, 1, 1, 1)
		_ToColor("To Color", Color) = (1,1,1,1)
		_ColorStart("ColorStart", Range(0, 1)) = 0
		_ColorEnd("ColorEnd", Range(0, 1)) = 1
	}

	SubShader{

		Tags{ "RenderType" = "Opaque" "Queue" = "Geometry"}

		Pass{
			CGPROGRAM

			#pragma vertex vert
			#pragma fragment frag

			#include "UnityCG.cginc"

			fixed4 _FromColor;
			fixed4 _ToColor;
			fixed _ColorStart;
			fixed _ColorEnd;

			struct MeshData {
				float4 vertex : POSITION;
				float3 normal: NORMAL;
				float4 uv0 : TEXCOORD0;
			};

			struct Interpolator {
				float4 vertex : SV_POSITION;
				float3 normal: TEXCOORD0;
				float4 uv : TEXCOORD1;
			};

			Interpolator vert(MeshData v) {
				Interpolator o;
				o.vertex = UnityObjectToClipPos(v.vertex);
				o.normal = UnityObjectToClipPos(v.normal);
				o.uv = v.uv0;
				return o;
			}

			float InverseLerp(float a, float b, float v) {
				return (v-a)/(b-a);
			}

			float4 frag(Interpolator i) : SV_Target{
				float t = InverseLerp(_ColorStart, _ColorEnd, i.uv.x);
				float4 col = lerp(_FromColor, _ToColor, t);
				return col;
			}

			ENDCG
		}
	}
}
