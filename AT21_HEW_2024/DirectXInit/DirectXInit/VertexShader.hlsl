//--------------------------------------------------------------------------------------
// 頂点シェーダー
//--------------------------------------------------------------------------------------

// 頂点のデータを表す構造体（受け取り用）
struct VS_IN
{
    float4 pos : POSITION;
    float4 col : COLOR0;
    float2 tex : TEX;
};

// 頂点のデータを表す構造体（送信用） 
struct VS_OUT
{
    float4 pos : SV_POSITION;
    float4 col : COLOR0;
    float2 tex : TEXCOORD;
};
 //グローバル変数の宣言
 //定数バッファの受け取り用

cbuffer ConstBuffer : register(b0)
{
    //頂点カラー
    float4 vertexColor;
    //UV座標移動行列
    matrix  matrixTex;
    //投影行列変換
    matrix  matrixProj;
    //ワールド変換行列
    matrix matrixWorld;
}
 
// 頂点シェーダーのエントリポイント 
VS_OUT vs_main(VS_IN input)
{
    VS_OUT output;
 
    //ワールド変換行列を頂点座標にかけて、移動、回転、拡大縮小する
    output.pos = mul(input.pos, matrixWorld);
    //頂点座標に投影行列をかけて、平面上の座標にする
    output.pos = mul(output.pos, matrixProj);   
    //output.pos = input.pos;

      //UV座標を移動させる
    float4 uv;                  
    uv.xy = input.tex;          //行列掛け算のためfloat4型に移す
    uv.z = 0.0f;               
    uv.w = 1.0f;                
    uv = mul(uv, matrixTex);    //UV座標と移動行列を掛け算
    output.tex = uv.xy;         //掛け算の結果を送信用変数にセット


    output.col = input.col * vertexColor;
    return output;
}