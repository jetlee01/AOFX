#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions: 
//
// cbuffer CB_INPUT_DATA
// {
//
//   struct AO_InputData
//   {
//       
//       uint2 m_OutputSize;            // Offset:    0
//       float2 m_OutputSizeRcp;        // Offset:    8
//       uint2 m_InputSize;             // Offset:   16
//       float2 m_InputSizeRcp;         // Offset:   24
//       float m_ZFar;                  // Offset:   32
//       float m_ZNear;                 // Offset:   36
//       float m_CameraQ;               // Offset:   40
//       float m_CameraQTimesZNear;     // Offset:   44
//       float m_CameraTanHalfFovHorizontal;// Offset:   48
//       float m_CameraTanHalfFovVertical;// Offset:   52
//       float m_DepthUpsampleThreshold;// Offset:   56
//       float m_NormalScale;           // Offset:   60
//       float m_Scale;                 // Offset:   64
//       float m_ScaleRcp;              // Offset:   68
//       float m_ViewDistanceFade;      // Offset:   72
//       float m_ViewDistanceDiscard;   // Offset:   76
//
//   } g_cbInputData;                   // Offset:    0 Size:    80
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_ssPointClamp                    sampler      NA          NA    0        1
// g_ssLinearClamp                   sampler      NA          NA    1        1
// g_t2dDepth                        texture   float          2d    0        1
// g_t2dAO                           texture   float          2d    2        1
// g_t2dOutput                           UAV   float          2d    0        1
// CB_INPUT_DATA                     cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[4], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t2
dcl_uav_typed_texture2d (float,float,float,float) u0
dcl_input vThreadIDInGroup.xy
dcl_input vThreadID.xy
dcl_temps 4
dcl_tgsm_structured g0, 768, 32
dcl_thread_group 32, 32, 1
utof r0.xy, vThreadID.xyxx
add r0.xy, r0.xyxx, l(0.500000, 0.500000, 0.000000, 0.000000)
mov r1.yw, l(0,0,0,0)
mov r0.zw, l(0,0,0,-5)
loop 
  ilt r2.x, l(37), r0.w
  breakc_nz r2.x
  itof r1.x, r0.w
  add r2.xy, r0.xyxx, r1.xyxx
  mul r2.xy, r2.xyxx, cb0[0].zwzz
  sample_l_indexable(texture2d)(float,float,float,float) r2.z, r2.xyxx, t2.zwxy, s1, l(0.000000)
  sample_l_indexable(texture2d)(float,float,float,float) r1.x, r2.xyxx, t0.xyzw, s0, l(0.000000)
  add r1.x, r1.x, -cb0[2].z
  div r2.w, -cb0[2].w, r1.x
  mov r1.z, r0.z
  iadd r1.xz, r1.zzwz, vThreadIDInGroup.xxyx
  ishl r1.x, r1.x, l(3)
  store_structured g0.xy, r1.z, r1.x, r2.zwzz
  iadd r0.zw, r0.zzzw, l(0, 0, 32, 32)
endloop 
sync_g_t
ult r0.xy, vThreadID.xyxx, cb0[0].xyxx
and r0.x, r0.y, r0.x
if_nz r0.x
  ishl r0.x, vThreadIDInGroup.x, l(3)
  iadd r0.xyz, r0.xxxx, l(40, 56, 72, 0)
  iadd r0.w, r0.x, l(4)
  ld_structured r1.xyzw, vThreadIDInGroup.y, r0.x, g0.xyzw
  iadd r2.xyzw, vThreadIDInGroup.xyxy, l(1, 0, 2, 0)
  ishl r2.xz, r2.xxzx, l(3, 0, 3, 0)
  ld_structured r2.xy, r2.y, r2.x, g0.xyxx
  add r0.x, r1.y, -r2.y
  lt r2.y, |r0.x|, cb0[3].z
  and r2.y, r2.y, l(0x3ed27d4f)
  mul r0.x, r0.x, r0.x
  div r0.x, -r0.x, cb0[3].z
  mul r0.x, r0.x, l(1.442695)
  exp r0.x, r0.x
  ld_structured r2.zw, r2.w, r2.z, g0.xxxy
  add r2.w, r1.y, -r2.w
  lt r3.x, |r2.w|, cb0[3].z
  and r3.x, r3.x, l(0x3f1b4598)
  mul r2.w, r2.w, r2.w
  div r2.w, -r2.w, cb0[3].z
  mul r2.w, r2.w, l(1.442695)
  exp r2.w, r2.w
  mul r2.z, r2.z, r3.x
  mad r2.x, r2.x, r2.y, r2.z
  mul r2.z, r2.w, r3.x
  mad r0.x, r2.y, r0.x, r2.z
  iadd r3.xyzw, vThreadIDInGroup.xyxy, l(3, 0, 4, 0)
  ishl r2.yz, r3.xxzx, l(0, 3, 3, 0)
  ld_structured r2.yw, r3.y, r2.y, g0.xxxy
  add r2.w, r1.y, -r2.w
  lt r3.x, |r2.w|, cb0[3].z
  and r3.x, r3.x, l(0x3f4cfd20)
  mul r2.w, r2.w, r2.w
  div r2.w, -r2.w, cb0[3].z
  mul r2.w, r2.w, l(1.442695)
  exp r2.w, r2.w
  mad r2.x, r2.y, r3.x, r2.x
  mad r0.x, r3.x, r2.w, r0.x
  ld_structured r2.yz, r3.w, r2.z, g0.xxyx
  add r2.z, r1.y, -r2.z
  lt r2.w, |r2.z|, cb0[3].z
  and r2.w, r2.w, l(0x3f722a66)
  mul r2.z, r2.z, r2.z
  div r2.z, -r2.z, cb0[3].z
  mul r2.z, r2.z, l(1.442695)
  exp r2.z, r2.z
  mad r2.x, r2.y, r2.w, r2.x
  mad r0.x, r2.w, r2.z, r0.x
  ld_structured r0.w, vThreadIDInGroup.y, r0.w, g0.xxxx
  add r0.w, -r0.w, r1.y
  lt r2.y, |r0.w|, cb0[3].z
  and r2.y, r2.y, l(0x3f800000)
  mul r0.w, r0.w, r0.w
  div r0.w, -r0.w, cb0[3].z
  mul r0.w, r0.w, l(1.442695)
  exp r0.w, r0.w
  mad r1.x, r1.x, r2.y, r2.x
  mad r0.x, r2.y, r0.w, r0.x
  add r0.w, -r1.w, r1.y
  lt r1.w, |r0.w|, cb0[3].z
  and r1.w, r1.w, l(0x3f722a66)
  mul r0.w, r0.w, r0.w
  div r0.w, -r0.w, cb0[3].z
  mul r0.w, r0.w, l(1.442695)
  exp r0.w, r0.w
  mad r1.x, r1.z, r1.w, r1.x
  mad r0.x, r1.w, r0.w, r0.x
  ld_structured r2.xyzw, vThreadIDInGroup.y, r0.y, g0.xyzw
  add r0.yw, r1.yyyy, -r2.yyyw
  lt r1.zw, |r0.yyyw|, cb0[3].zzzz
  and r1.zw, r1.zzzw, l(0, 0, 0x3f4cfd20, 0x3f1b4598)
  mul r0.yw, r0.yyyw, r0.yyyw
  div r0.yw, -r0.yyyw, cb0[3].zzzz
  mul r0.yw, r0.yyyw, l(0.000000, 1.442695, 0.000000, 1.442695)
  exp r0.yw, r0.yyyw
  mad r1.x, r2.x, r1.z, r1.x
  mad r0.x, r1.z, r0.y, r0.x
  mad r0.y, r2.z, r1.w, r1.x
  mad r0.x, r1.w, r0.w, r0.x
  ld_structured r0.zw, vThreadIDInGroup.y, r0.z, g0.xxxy
  add r0.w, -r0.w, r1.y
  lt r1.x, |r0.w|, cb0[3].z
  and r1.x, r1.x, l(0x3ed27d4f)
  mul r0.w, r0.w, r0.w
  div r0.w, -r0.w, cb0[3].z
  mul r0.w, r0.w, l(1.442695)
  exp r0.w, r0.w
  mad r0.y, r0.z, r1.x, r0.y
  mad r0.x, r1.x, r0.w, r0.x
  div r0.x, r0.y, r0.x
  store_uav_typed u0.xyzw, vThreadID.xyyy, r0.xxxx
endif 
ret 
// Approximately 117 instruction slots used
#endif

const BYTE CS_BILATERAL_BLUR_HORIZONTAL_RADIUS_5_DATA[] =
{
     68,  88,  66,  67, 139, 198, 
    252, 106,  61, 246,  35, 131, 
    250,  55, 254,  21,  90, 236, 
     30,  23,   1,   0,   0,   0, 
    180,  19,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    124,   4,   0,   0, 140,   4, 
      0,   0, 156,   4,   0,   0, 
     24,  19,   0,   0,  82,  68, 
     69,  70,  64,   4,   0,   0, 
      1,   0,   0,   0,  72,   1, 
      0,   0,   6,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0, 129,   0,   0, 
     12,   4,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    252,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  11,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  27,   1, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     38,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  46,   1,   0,   0, 
      4,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  58,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    103,  95, 115, 115,  80, 111, 
    105, 110, 116,  67, 108,  97, 
    109, 112,   0, 103,  95, 115, 
    115,  76, 105, 110, 101,  97, 
    114,  67, 108,  97, 109, 112, 
      0, 103,  95, 116,  50, 100, 
     68, 101, 112, 116, 104,   0, 
    103,  95, 116,  50, 100,  65, 
     79,   0, 103,  95, 116,  50, 
    100,  79, 117, 116, 112, 117, 
    116,   0,  67,  66,  95,  73, 
     78,  80,  85,  84,  95,  68, 
     65,  84,  65,   0,  58,   1, 
      0,   0,   1,   0,   0,   0, 
     96,   1,   0,   0,  80,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 136,   1, 
      0,   0,   0,   0,   0,   0, 
     80,   0,   0,   0,   2,   0, 
      0,   0, 232,   3,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 103,  95,  99,  98, 
     73, 110, 112, 117, 116,  68, 
     97, 116,  97,   0,  65,  79, 
     95,  73, 110, 112, 117, 116, 
     68,  97, 116,  97,   0, 109, 
     95,  79, 117, 116, 112, 117, 
    116,  83, 105, 122, 101,   0, 
    117, 105, 110, 116,  50,   0, 
    171, 171,   1,   0,  19,   0, 
      1,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 176,   1, 
      0,   0, 109,  95,  79, 117, 
    116, 112, 117, 116,  83, 105, 
    122, 101,  82,  99, 112,   0, 
    102, 108, 111,  97, 116,  50, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 236,   1, 
      0,   0, 109,  95,  73, 110, 
    112, 117, 116,  83, 105, 122, 
    101,   0, 109,  95,  73, 110, 
    112, 117, 116,  83, 105, 122, 
    101,  82,  99, 112,   0, 109, 
     95,  90,  70,  97, 114,   0, 
    102, 108, 111,  97, 116,   0, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  58,   2,   0,   0, 
    109,  95,  90,  78, 101,  97, 
    114,   0, 109,  95,  67,  97, 
    109, 101, 114,  97,  81,   0, 
    109,  95,  67,  97, 109, 101, 
    114,  97,  81,  84, 105, 109, 
    101, 115,  90,  78, 101,  97, 
    114,   0, 109,  95,  67,  97, 
    109, 101, 114,  97,  84,  97, 
    110,  72,  97, 108, 102,  70, 
    111, 118,  72, 111, 114, 105, 
    122, 111, 110, 116,  97, 108, 
      0, 109,  95,  67,  97, 109, 
    101, 114,  97,  84,  97, 110, 
     72,  97, 108, 102,  70, 111, 
    118,  86, 101, 114, 116, 105, 
     99,  97, 108,   0, 109,  95, 
     68, 101, 112, 116, 104,  85, 
    112, 115,  97, 109, 112, 108, 
    101,  84, 104, 114, 101, 115, 
    104, 111, 108, 100,   0, 109, 
     95,  78, 111, 114, 109,  97, 
    108,  83,  99,  97, 108, 101, 
      0, 109,  95,  83,  99,  97, 
    108, 101,   0, 109,  95,  83, 
     99,  97, 108, 101,  82,  99, 
    112,   0, 109,  95,  86, 105, 
    101, 119,  68, 105, 115, 116, 
     97, 110,  99, 101,  70,  97, 
    100, 101,   0, 109,  95,  86, 
    105, 101, 119,  68, 105, 115, 
    116,  97, 110,  99, 101,  68, 
    105, 115,  99,  97, 114, 100, 
      0, 171, 171, 171, 163,   1, 
      0,   0, 184,   1,   0,   0, 
      0,   0,   0,   0, 220,   1, 
      0,   0, 244,   1,   0,   0, 
      8,   0,   0,   0,  24,   2, 
      0,   0, 184,   1,   0,   0, 
     16,   0,   0,   0,  36,   2, 
      0,   0, 244,   1,   0,   0, 
     24,   0,   0,   0,  51,   2, 
      0,   0,  64,   2,   0,   0, 
     32,   0,   0,   0, 100,   2, 
      0,   0,  64,   2,   0,   0, 
     36,   0,   0,   0, 108,   2, 
      0,   0,  64,   2,   0,   0, 
     40,   0,   0,   0, 118,   2, 
      0,   0,  64,   2,   0,   0, 
     44,   0,   0,   0, 138,   2, 
      0,   0,  64,   2,   0,   0, 
     48,   0,   0,   0, 167,   2, 
      0,   0,  64,   2,   0,   0, 
     52,   0,   0,   0, 194,   2, 
      0,   0,  64,   2,   0,   0, 
     56,   0,   0,   0, 219,   2, 
      0,   0,  64,   2,   0,   0, 
     60,   0,   0,   0, 233,   2, 
      0,   0,  64,   2,   0,   0, 
     64,   0,   0,   0, 241,   2, 
      0,   0,  64,   2,   0,   0, 
     68,   0,   0,   0, 252,   2, 
      0,   0,  64,   2,   0,   0, 
     72,   0,   0,   0,  15,   3, 
      0,   0,  64,   2,   0,   0, 
     76,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,  20,   0, 
      0,   0,  16,   0,  40,   3, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    150,   1,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  54,  46,  51, 
     46,  57,  54,  48,  48,  46, 
     49,  54,  51,  56,  52,   0, 
    171, 171,  73,  83,  71,  78, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     79,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  83,  72, 
     69,  88, 116,  14,   0,   0, 
     80,   0,   5,   0, 157,   3, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      1,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   2,   0, 
      0,   0,  85,  85,   0,   0, 
    156,  24,   0,   4,   0, 224, 
     17,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  95,   0, 
      0,   2,  50,  32,   2,   0, 
     95,   0,   0,   2,  50,   0, 
      2,   0, 104,   0,   0,   2, 
      4,   0,   0,   0, 160,   0, 
      0,   5,   0, 240,  17,   0, 
      0,   0,   0,   0,   0,   3, 
      0,   0,  32,   0,   0,   0, 
    155,   0,   0,   4,  32,   0, 
      0,   0,  32,   0,   0,   0, 
      1,   0,   0,   0,  86,   0, 
      0,   4,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
      2,   0,   0,   0,   0,  10, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  63, 
      0,   0,   0,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   8, 162,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   8, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    251, 255, 255, 255,  48,   0, 
      0,   1,  34,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
     37,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      3,   0,   4,   3,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     43,   0,   0,   5,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   7, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   8,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0, 230, 138,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  72,   0,   0, 141, 
    194,   0,   0, 128,  67,  85, 
     21,   0,  66,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   2,   0,   0,   0, 
    230, 116,  16,   0,   2,   0, 
      0,   0,   0,  96,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     72,   0,   0, 141, 194,   0, 
      0, 128,  67,  85,  21,   0, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     42, 128,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  14,   0, 
      0,   9, 130,   0,  16,   0, 
      2,   0,   0,   0,  58, 128, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   5,  66,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     30,   0,   0,   6,  82,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  11,  16,   0,   1,   0, 
      0,   0,   6,  33,   2,   0, 
     41,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      3,   0,   0,   0, 168,   0, 
      0,   9,  50, 240,  17,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0, 230,  10,  16,   0, 
      2,   0,   0,   0,  30,   0, 
      0,  10, 194,   0,  16,   0, 
      0,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     32,   0,   0,   0,  32,   0, 
      0,   0,  22,   0,   0,   1, 
    190,  24,   0,   1,  79,   0, 
      0,   7,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
      2,   0,  70, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     41,   0,   0,   6,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  32,   2,   0,   1,  64, 
      0,   0,   3,   0,   0,   0, 
     30,   0,   0,  10, 114,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
     40,   0,   0,   0,  56,   0, 
      0,   0,  72,   0,   0,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   4,   0, 
      0,   0, 167,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  26,  32,   2,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  70, 254,  17,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  36, 
      2,   0,   2,  64,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,  41,   0, 
      0,  10,  82,   0,  16,   0, 
      2,   0,   0,   0,   6,   2, 
     16,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 240,  17,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  49,   0, 
      0,   9,  34,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16, 128, 129,   0,   0,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   7,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,  79, 125, 
    210,  62,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     14,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
     59, 170, 184,  63,  25,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
    167,   0,   0,   9, 194,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,   6, 244, 
     17,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  49,   0,   0,   9, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16, 128, 
    129,   0,   0,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0, 152,  69,  27,  63, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  14,   0, 
      0,   9, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,  59, 170, 
    184,  63,  25,   0,   0,   5, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     30,   0,   0,   9, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  36,   2,   0,   2,  64, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     41,   0,   0,  10,  98,   0, 
     16,   0,   2,   0,   0,   0, 
      6,   2,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   9, 162,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,   6, 244,  17,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   8, 130,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     49,   0,   0,   9,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16, 128, 129,   0, 
      0,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   7,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
     32, 253,  76,  63,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  14,   0,   0,   9, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,  59, 170, 184,  63, 
     25,   0,   0,   5, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     98,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
      6, 241,  17,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,  49,   0, 
      0,   9, 130,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16, 128, 129,   0,   0,   0, 
      2,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   7, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0, 102,  42, 
    114,  63,  56,   0,   0,   7, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     14,   0,   0,   9,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
     59, 170, 184,  63,  25,   0, 
      0,   5,  66,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  42,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
    167,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     26,  32,   2,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  49,   0, 
      0,   9,  34,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16, 128, 129,   0,   0,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   7,  34,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  56,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     14,   0,   0,   9, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
     59, 170, 184,  63,  25,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  49,   0,   0,   9, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
    129,   0,   0,   0,   0,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0, 102,  42, 114,  63, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  59, 170, 
    184,  63,  25,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   8, 242,   0,  16,   0, 
      2,   0,   0,   0,  26,  32, 
      2,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  70, 254, 
     17,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 162,   0, 
     16,   0,   0,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,  86,  13,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  49,   0,   0,   9, 
    194,   0,  16,   0,   1,   0, 
      0,   0,  86,  13,  16, 128, 
    129,   0,   0,   0,   0,   0, 
      0,   0, 166, 138,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,  10, 
    194,   0,  16,   0,   1,   0, 
      0,   0, 166,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  32, 253, 
     76,  63, 152,  69,  27,  63, 
     56,   0,   0,   7, 162,   0, 
     16,   0,   0,   0,   0,   0, 
     86,  13,  16,   0,   0,   0, 
      0,   0,  86,  13,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   9, 162,   0,  16,   0, 
      0,   0,   0,   0,  86,  13, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0, 166, 138, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  56,   0, 
      0,  10, 162,   0,  16,   0, 
      0,   0,   0,   0,  86,  13, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,  59, 170, 184,  63, 
      0,   0,   0,   0,  59, 170, 
    184,  63,  25,   0,   0,   5, 
    162,   0,  16,   0,   0,   0, 
      0,   0,  86,  13,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9,  34,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   8, 194,   0,  16,   0, 
      0,   0,   0,   0,  26,  32, 
      2,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   6, 244, 
     17,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  49,   0,   0,   9, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16, 128, 
    129,   0,   0,   0,   0,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,  79, 125, 210,  62, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  59, 170, 
    184,  63,  25,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9,  34,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0, 164,   0,   0,   6, 
    242, 224,  17,   0,   0,   0, 
      0,   0,  70,   5,   2,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  21,   0,   0,   1, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
    117,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  72,   0, 
      0,   0,  11,   0,   0,   0, 
     10,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0
};
