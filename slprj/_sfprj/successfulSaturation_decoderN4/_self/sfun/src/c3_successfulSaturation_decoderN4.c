/* Include files */

#include "successfulSaturation_decoderN4_sfun.h"
#include "c3_successfulSaturation_decoderN4.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "successfulSaturation_decoderN4_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[40] = { "S1", "S2", "S3", "S4", "S5",
  "nargin", "nargout", "LLR1", "LLR2", "LLR3", "LLR4", "u1", "u2", "u3", "u4",
  "soft1", "soft2", "soft3", "soft4", "state_reg", "LLR1_reg", "LLR2_reg",
  "LLR3_reg", "LLR4_reg", "L21y12_reg", "L21y34_reg", "L41y14_reg",
  "L42y14u11_reg", "L22y12u12_reg", "L22y34u2_reg", "L43y14u12_reg",
  "L44y14u13_reg", "u1_reg", "soft1_reg", "u2_reg", "soft2_reg", "u3_reg",
  "soft3_reg", "u4_reg", "soft4_reg" };

static const mxArray *c3_eml_mx;
static const mxArray *c3_b_eml_mx;
static const char * c3_b_debug_family_names[5] = { "nargin", "nargout", "in1",
  "in2", "out" };

static const char * c3_c_debug_family_names[6] = { "nargin", "nargout", "soft",
  "position", "out", "FZlookup" };

static const char * c3_d_debug_family_names[6] = { "nargin", "nargout", "in1",
  "in2", "b", "out" };

/* Function Declarations */
static void initialize_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void initialize_params_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void enable_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void disable_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void set_sim_state_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_st);
static void finalize_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void sf_gateway_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void mdl_start_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void c3_chartstep_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void initSimStructsc3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int8_T c3_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_soft4_reg, const char_T *c3_identifier, boolean_T *c3_svPtr);
static int8_T c3_b_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_u4_reg, const char_T *c3_identifier, boolean_T *c3_svPtr);
static boolean_T c3_d_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_state_reg, const char_T *c3_identifier, boolean_T *c3_svPtr);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_g_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_soft4, const char_T *c3_identifier);
static int8_T c3_h_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_i_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_u4, const char_T *c3_identifier);
static boolean_T c3_j_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_k_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_l_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_FZlookup, const char_T *c3_identifier, boolean_T *c3_svPtr,
   boolean_T c3_y[4]);
static void c3_m_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr,
   boolean_T c3_y[4]);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static int8_T c3_f(SFc3_successfulSaturation_decoderN4InstanceStruct
                   *chartInstance, int8_T c3_in1, int8_T c3_in2);
static boolean_T c3_decide(SFc3_successfulSaturation_decoderN4InstanceStruct
  *chartInstance, int8_T c3_soft, real_T c3_position);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_n_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_o_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_is_active_c3_successfulSaturation_decoderN4, const char_T
   *c3_identifier);
static uint8_T c3_p_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_successfulSaturation_decoderN4(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_state_reg_not_empty = false;
  chartInstance->c3_LLR1_reg_not_empty = false;
  chartInstance->c3_LLR2_reg_not_empty = false;
  chartInstance->c3_LLR3_reg_not_empty = false;
  chartInstance->c3_LLR4_reg_not_empty = false;
  chartInstance->c3_L21y12_reg_not_empty = false;
  chartInstance->c3_L21y34_reg_not_empty = false;
  chartInstance->c3_L41y14_reg_not_empty = false;
  chartInstance->c3_L42y14u11_reg_not_empty = false;
  chartInstance->c3_L22y12u12_reg_not_empty = false;
  chartInstance->c3_L22y34u2_reg_not_empty = false;
  chartInstance->c3_L43y14u12_reg_not_empty = false;
  chartInstance->c3_L44y14u13_reg_not_empty = false;
  chartInstance->c3_u1_reg_not_empty = false;
  chartInstance->c3_soft1_reg_not_empty = false;
  chartInstance->c3_u2_reg_not_empty = false;
  chartInstance->c3_soft2_reg_not_empty = false;
  chartInstance->c3_u3_reg_not_empty = false;
  chartInstance->c3_soft3_reg_not_empty = false;
  chartInstance->c3_u4_reg_not_empty = false;
  chartInstance->c3_soft4_reg_not_empty = false;
  chartInstance->c3_FZlookup_not_empty = false;
  chartInstance->c3_is_active_c3_successfulSaturation_decoderN4 = 0U;
  sf_mex_assign(&c3_b_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "numerictype", 1U, 14U, 15, "SignednessBool", 3, false, 15, "Signedness", 15,
    "Unsigned", 15, "WordLength", 6, 3.0, 15, "FractionLength", 6, 0.0, 15,
    "BinaryPoint", 6, 0.0, 15, "Slope", 6, 1.0, 15, "FixedExponent", 6, 0.0),
                true);
  sf_mex_assign(&c3_eml_mx, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "fimath", 1U, 42U, 15, "RoundMode", 15, "floor", 15, "RoundingMethod", 15,
    "Floor", 15, "OverflowMode", 15, "wrap", 15, "OverflowAction", 15, "Wrap",
    15, "ProductMode", 15, "FullPrecision", 15, "ProductWordLength", 6, 32.0, 15,
    "MaxProductWordLength", 6, 128.0, 15, "ProductFractionLength", 6, 30.0, 15,
    "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "FullPrecision", 15,
    "SumWordLength", 6, 32.0, 15, "MaxSumWordLength", 6, 128.0, 15,
    "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0, 15,
    "SumSlope", 6, 9.3132257461547852E-10, 15, "SumSlopeAdjustmentFactor", 6,
    1.0, 15, "SumBias", 6, 0.0, 15, "CastBeforeSum", 3, true), true);
}

static void initialize_params_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int8_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  int8_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  int8_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  int8_T c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  boolean_T c3_e_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  boolean_T c3_f_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  boolean_T c3_g_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  boolean_T c3_h_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  const mxArray *c3_j_y = NULL;
  int8_T c3_i_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  int8_T c3_j_hoistedGlobal;
  const mxArray *c3_l_y = NULL;
  int8_T c3_k_hoistedGlobal;
  const mxArray *c3_m_y = NULL;
  int8_T c3_l_hoistedGlobal;
  const mxArray *c3_n_y = NULL;
  int8_T c3_m_hoistedGlobal;
  const mxArray *c3_o_y = NULL;
  int8_T c3_n_hoistedGlobal;
  const mxArray *c3_p_y = NULL;
  int8_T c3_o_hoistedGlobal;
  const mxArray *c3_q_y = NULL;
  int8_T c3_p_hoistedGlobal;
  const mxArray *c3_r_y = NULL;
  int8_T c3_q_hoistedGlobal;
  const mxArray *c3_s_y = NULL;
  int8_T c3_r_hoistedGlobal;
  const mxArray *c3_t_y = NULL;
  int8_T c3_s_hoistedGlobal;
  const mxArray *c3_u_y = NULL;
  int8_T c3_t_hoistedGlobal;
  const mxArray *c3_v_y = NULL;
  int8_T c3_u_hoistedGlobal;
  const mxArray *c3_w_y = NULL;
  int8_T c3_v_hoistedGlobal;
  const mxArray *c3_x_y = NULL;
  int8_T c3_w_hoistedGlobal;
  const mxArray *c3_y_y = NULL;
  int8_T c3_x_hoistedGlobal;
  const mxArray *c3_ab_y = NULL;
  uint8_T c3_y_hoistedGlobal;
  const mxArray *c3_bb_y = NULL;
  uint8_T c3_u;
  const mxArray *c3_cb_y = NULL;
  boolean_T c3_ab_hoistedGlobal;
  const mxArray *c3_db_y = NULL;
  boolean_T c3_bb_hoistedGlobal;
  const mxArray *c3_eb_y = NULL;
  boolean_T c3_cb_hoistedGlobal;
  const mxArray *c3_fb_y = NULL;
  boolean_T c3_db_hoistedGlobal;
  const mxArray *c3_gb_y = NULL;
  uint8_T c3_eb_hoistedGlobal;
  const mxArray *c3_hb_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(31, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_soft1;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 2, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_soft2;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 2, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *chartInstance->c3_soft3;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 2, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *chartInstance->c3_soft4;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_hoistedGlobal, 2, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *chartInstance->c3_u1;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *chartInstance->c3_u2;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *chartInstance->c3_u3;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *chartInstance->c3_u4;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_j_y = NULL;
  if (!chartInstance->c3_FZlookup_not_empty) {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_j_y, sf_mex_create("y", chartInstance->c3_FZlookup, 11, 0U,
      1U, 0U, 1, 4), false);
  }

  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_i_hoistedGlobal = chartInstance->c3_L21y12_reg;
  c3_k_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_i_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_j_hoistedGlobal = chartInstance->c3_L21y34_reg;
  c3_l_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_j_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_k_hoistedGlobal = chartInstance->c3_L22y12u12_reg;
  c3_m_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_k_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_l_hoistedGlobal = chartInstance->c3_L22y34u2_reg;
  c3_n_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_l_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_m_hoistedGlobal = chartInstance->c3_L41y14_reg;
  c3_o_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_m_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_n_hoistedGlobal = chartInstance->c3_L42y14u11_reg;
  c3_p_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_p_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_n_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_o_hoistedGlobal = chartInstance->c3_L43y14u12_reg;
  c3_q_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_q_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_o_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_p_hoistedGlobal = chartInstance->c3_L44y14u13_reg;
  c3_r_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_p_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_q_hoistedGlobal = chartInstance->c3_LLR1_reg;
  c3_s_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_q_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_r_hoistedGlobal = chartInstance->c3_LLR2_reg;
  c3_t_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_r_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_s_hoistedGlobal = chartInstance->c3_LLR3_reg;
  c3_u_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_s_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_t_hoistedGlobal = chartInstance->c3_LLR4_reg;
  c3_v_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_v_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_t_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 20, c3_v_y);
  c3_u_hoistedGlobal = chartInstance->c3_soft1_reg;
  c3_w_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_w_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_u_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 21, c3_w_y);
  c3_v_hoistedGlobal = chartInstance->c3_soft2_reg;
  c3_x_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_x_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_v_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 22, c3_x_y);
  c3_w_hoistedGlobal = chartInstance->c3_soft3_reg;
  c3_y_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_y_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_w_hoistedGlobal, 2, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 23, c3_y_y);
  c3_x_hoistedGlobal = chartInstance->c3_soft4_reg;
  c3_ab_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_ab_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_x_hoistedGlobal, 2, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 24, c3_ab_y);
  c3_y_hoistedGlobal = chartInstance->c3_state_reg;
  c3_bb_y = NULL;
  if (!chartInstance->c3_state_reg_not_empty) {
    sf_mex_assign(&c3_bb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    c3_u = c3_y_hoistedGlobal;
    c3_cb_y = NULL;
    sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
    sf_mex_assign(&c3_bb_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
      sf_mex_dup(c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_b_eml_mx), 15,
      "simulinkarray", 14, c3_cb_y, 15, "fimathislocal", 3, true), false);
  }

  sf_mex_setcell(c3_y, 25, c3_bb_y);
  c3_ab_hoistedGlobal = chartInstance->c3_u1_reg;
  c3_db_y = NULL;
  if (!chartInstance->c3_u4_reg_not_empty) {
    sf_mex_assign(&c3_db_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_db_y, sf_mex_create("y", &c3_ab_hoistedGlobal, 11, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 26, c3_db_y);
  c3_bb_hoistedGlobal = chartInstance->c3_u2_reg;
  c3_eb_y = NULL;
  if (!chartInstance->c3_u4_reg_not_empty) {
    sf_mex_assign(&c3_eb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_eb_y, sf_mex_create("y", &c3_bb_hoistedGlobal, 11, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 27, c3_eb_y);
  c3_cb_hoistedGlobal = chartInstance->c3_u3_reg;
  c3_fb_y = NULL;
  if (!chartInstance->c3_u4_reg_not_empty) {
    sf_mex_assign(&c3_fb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_fb_y, sf_mex_create("y", &c3_cb_hoistedGlobal, 11, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 28, c3_fb_y);
  c3_db_hoistedGlobal = chartInstance->c3_u4_reg;
  c3_gb_y = NULL;
  if (!chartInstance->c3_u4_reg_not_empty) {
    sf_mex_assign(&c3_gb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_gb_y, sf_mex_create("y", &c3_db_hoistedGlobal, 11, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 29, c3_gb_y);
  c3_eb_hoistedGlobal =
    chartInstance->c3_is_active_c3_successfulSaturation_decoderN4;
  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y", &c3_eb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 30, c3_hb_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[4];
  int32_T c3_i0;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_soft1 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft1", c3_u, 0)), "soft1");
  *chartInstance->c3_soft2 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft2", c3_u, 1)), "soft2");
  *chartInstance->c3_soft3 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft3", c3_u, 2)), "soft3");
  *chartInstance->c3_soft4 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft4", c3_u, 3)), "soft4");
  *chartInstance->c3_u1 = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u1", c3_u, 4)), "u1");
  *chartInstance->c3_u2 = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u2", c3_u, 5)), "u2");
  *chartInstance->c3_u3 = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u3", c3_u, 6)), "u3");
  *chartInstance->c3_u4 = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u4", c3_u, 7)), "u4");
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("FZlookup",
    c3_u, 8)), "FZlookup", &chartInstance->c3_FZlookup_not_empty, c3_bv0);
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    chartInstance->c3_FZlookup[c3_i0] = c3_bv0[c3_i0];
  }

  chartInstance->c3_L21y12_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("L21y12_reg", c3_u, 9)), "L21y12_reg",
    &chartInstance->c3_L21y12_reg_not_empty);
  chartInstance->c3_L21y34_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("L21y34_reg", c3_u, 10)), "L21y34_reg",
    &chartInstance->c3_L21y34_reg_not_empty);
  chartInstance->c3_L22y12u12_reg = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("L22y12u12_reg", c3_u, 11)), "L22y12u12_reg",
    &chartInstance->c3_L22y12u12_reg_not_empty);
  chartInstance->c3_L22y34u2_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("L22y34u2_reg", c3_u, 12)), "L22y34u2_reg",
    &chartInstance->c3_L22y34u2_reg_not_empty);
  chartInstance->c3_L41y14_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("L41y14_reg", c3_u, 13)), "L41y14_reg",
    &chartInstance->c3_L41y14_reg_not_empty);
  chartInstance->c3_L42y14u11_reg = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("L42y14u11_reg", c3_u, 14)), "L42y14u11_reg",
    &chartInstance->c3_L42y14u11_reg_not_empty);
  chartInstance->c3_L43y14u12_reg = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("L43y14u12_reg", c3_u, 15)), "L43y14u12_reg",
    &chartInstance->c3_L43y14u12_reg_not_empty);
  chartInstance->c3_L44y14u13_reg = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("L44y14u13_reg", c3_u, 16)), "L44y14u13_reg",
    &chartInstance->c3_L44y14u13_reg_not_empty);
  chartInstance->c3_LLR1_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LLR1_reg", c3_u, 17)), "LLR1_reg",
    &chartInstance->c3_LLR1_reg_not_empty);
  chartInstance->c3_LLR2_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LLR2_reg", c3_u, 18)), "LLR2_reg",
    &chartInstance->c3_LLR2_reg_not_empty);
  chartInstance->c3_LLR3_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LLR3_reg", c3_u, 19)), "LLR3_reg",
    &chartInstance->c3_LLR3_reg_not_empty);
  chartInstance->c3_LLR4_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LLR4_reg", c3_u, 20)), "LLR4_reg",
    &chartInstance->c3_LLR4_reg_not_empty);
  chartInstance->c3_soft1_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft1_reg", c3_u, 21)), "soft1_reg",
    &chartInstance->c3_soft1_reg_not_empty);
  chartInstance->c3_soft2_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft2_reg", c3_u, 22)), "soft2_reg",
    &chartInstance->c3_soft2_reg_not_empty);
  chartInstance->c3_soft3_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft3_reg", c3_u, 23)), "soft3_reg",
    &chartInstance->c3_soft3_reg_not_empty);
  chartInstance->c3_soft4_reg = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("soft4_reg", c3_u, 24)), "soft4_reg",
    &chartInstance->c3_soft4_reg_not_empty);
  chartInstance->c3_state_reg = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("state_reg", c3_u, 25)), "state_reg",
    &chartInstance->c3_state_reg_not_empty);
  chartInstance->c3_u1_reg = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u1_reg", c3_u, 26)), "u1_reg",
    &chartInstance->c3_u1_reg_not_empty);
  chartInstance->c3_u2_reg = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u2_reg", c3_u, 27)), "u2_reg",
    &chartInstance->c3_u2_reg_not_empty);
  chartInstance->c3_u3_reg = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u3_reg", c3_u, 28)), "u3_reg",
    &chartInstance->c3_u3_reg_not_empty);
  chartInstance->c3_u4_reg = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("u4_reg", c3_u, 29)), "u4_reg",
    &chartInstance->c3_u4_reg_not_empty);
  chartInstance->c3_is_active_c3_successfulSaturation_decoderN4 =
    c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c3_successfulSaturation_decoderN4", c3_u, 30)),
    "is_active_c3_successfulSaturation_decoderN4");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_successfulSaturation_decoderN4(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  (void)chartInstance;
  sf_mex_destroy(&c3_eml_mx);
  sf_mex_destroy(&c3_b_eml_mx);
}

static void sf_gateway_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_LLR4, 3U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_LLR3, 2U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_LLR2, 1U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_LLR1, 0U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_successfulSaturation_decoderN4(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_successfulSaturation_decoderN4MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_u1, 4U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_u2, 5U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_u3, 6U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_u4, 7U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_soft1, 8U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_soft2, 9U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_soft3, 10U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_soft4, 11U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
}

static void mdl_start_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chartstep_c3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  int8_T c3_hoistedGlobal;
  int8_T c3_b_hoistedGlobal;
  int8_T c3_c_hoistedGlobal;
  int8_T c3_d_hoistedGlobal;
  int8_T c3_b_LLR1;
  int8_T c3_b_LLR2;
  int8_T c3_b_LLR3;
  int8_T c3_b_LLR4;
  uint32_T c3_debug_family_var_map[40];
  real_T c3_S1;
  real_T c3_S2;
  real_T c3_S3;
  real_T c3_S4;
  real_T c3_S5;
  real_T c3_nargin = 4.0;
  real_T c3_nargout = 8.0;
  boolean_T c3_b_u1;
  boolean_T c3_b_u2;
  boolean_T c3_b_u3;
  boolean_T c3_b_u4;
  int8_T c3_b_soft1;
  int8_T c3_b_soft2;
  int8_T c3_b_soft3;
  int8_T c3_b_soft4;
  int8_T c3_e_hoistedGlobal;
  int8_T c3_f_hoistedGlobal;
  int8_T c3_g_hoistedGlobal;
  int8_T c3_h_hoistedGlobal;
  int8_T c3_i_hoistedGlobal;
  int8_T c3_j_hoistedGlobal;
  boolean_T c3_k_hoistedGlobal;
  boolean_T c3_l_hoistedGlobal;
  boolean_T c3_m_hoistedGlobal;
  int8_T c3_in1;
  boolean_T c3_n_hoistedGlobal;
  int8_T c3_b_in1;
  real_T c3_d0;
  int8_T c3_in2;
  boolean_T c3_s;
  int8_T c3_b_in2;
  boolean_T c3_b;
  boolean_T c3_t;
  boolean_T c3_b_b;
  real_T c3_d1;
  real_T c3_d2;
  uint32_T c3_b_debug_family_var_map[6];
  boolean_T c3_y;
  real_T c3_b_nargin = 3.0;
  int8_T c3_c_in1;
  real_T c3_c_nargin = 3.0;
  real_T c3_d3;
  real_T c3_b_nargout = 1.0;
  int8_T c3_c_in2;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_b;
  real_T c3_d_nargin = 3.0;
  int8_T c3_out;
  real_T c3_d_nargout = 1.0;
  int8_T c3_b_out;
  int8_T c3_c_out;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T c3_d4;
  int8_T c3_o_hoistedGlobal;
  int8_T c3_p_hoistedGlobal;
  real_T c3_d5;
  boolean_T c3_q_hoistedGlobal;
  int8_T c3_d_in1;
  int8_T c3_d_in2;
  boolean_T c3_d_b;
  real_T c3_e_nargin = 3.0;
  real_T c3_e_nargout = 1.0;
  int8_T c3_d_out;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_d6;
  real_T c3_d7;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_LLR1;
  c3_b_hoistedGlobal = *chartInstance->c3_LLR2;
  c3_c_hoistedGlobal = *chartInstance->c3_LLR3;
  c3_d_hoistedGlobal = *chartInstance->c3_LLR4;
  c3_b_LLR1 = c3_hoistedGlobal;
  c3_b_LLR2 = c3_b_hoistedGlobal;
  c3_b_LLR3 = c3_c_hoistedGlobal;
  c3_b_LLR4 = c3_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 40U, 40U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_S1, 0U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_S2, 1U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_S3, 2U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_S4, 3U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_S5, 4U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 5U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 6U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_LLR1, 7U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_LLR2, 8U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_LLR3, 9U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_LLR4, 10U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_u1, 11U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_u2, 12U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_u3, 13U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_u4, 14U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_soft1, 15U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_soft2, 16U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_soft3, 17U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_soft4, 18U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_state_reg, 19U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_LLR1_reg, 20U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_LLR2_reg, 21U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_LLR3_reg, 22U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_LLR4_reg, 23U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L21y12_reg, 24U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L21y34_reg, 25U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L41y14_reg, 26U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L42y14u11_reg, 27U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L22y12u12_reg, 28U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L22y34u2_reg, 29U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L43y14u12_reg, 30U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_L44y14u13_reg, 31U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_u1_reg, 32U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_soft1_reg, 33U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_u2_reg, 34U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_soft2_reg, 35U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_u3_reg, 36U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_soft3_reg, 37U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_u4_reg, 38U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_soft4_reg, 39U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_state_reg_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
    chartInstance->c3_state_reg = 0U;
    chartInstance->c3_state_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
    chartInstance->c3_LLR1_reg = c3_b_LLR1;
    chartInstance->c3_LLR1_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
    chartInstance->c3_LLR2_reg = c3_b_LLR2;
    chartInstance->c3_LLR2_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
    chartInstance->c3_LLR3_reg = c3_b_LLR3;
    chartInstance->c3_LLR3_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
    chartInstance->c3_LLR4_reg = c3_b_LLR4;
    chartInstance->c3_LLR4_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
    chartInstance->c3_L21y12_reg = 0;
    chartInstance->c3_L21y12_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
    chartInstance->c3_L21y34_reg = 0;
    chartInstance->c3_L21y34_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
    chartInstance->c3_L41y14_reg = 0;
    chartInstance->c3_L41y14_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
    chartInstance->c3_L42y14u11_reg = 0;
    chartInstance->c3_L42y14u11_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
    chartInstance->c3_L22y12u12_reg = 0;
    chartInstance->c3_L22y12u12_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
    chartInstance->c3_L22y34u2_reg = 0;
    chartInstance->c3_L22y34u2_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
    chartInstance->c3_L43y14u12_reg = 0;
    chartInstance->c3_L43y14u12_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
    chartInstance->c3_L44y14u13_reg = 0;
    chartInstance->c3_L44y14u13_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
    chartInstance->c3_u1_reg = false;
    chartInstance->c3_u1_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
    chartInstance->c3_soft1_reg = 0;
    chartInstance->c3_soft1_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
    chartInstance->c3_u2_reg = false;
    chartInstance->c3_u2_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
    chartInstance->c3_soft2_reg = 0;
    chartInstance->c3_soft2_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
    chartInstance->c3_u3_reg = false;
    chartInstance->c3_u3_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
    chartInstance->c3_soft3_reg = 0;
    chartInstance->c3_soft3_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
    chartInstance->c3_u4_reg = false;
    chartInstance->c3_u4_reg_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
    chartInstance->c3_soft4_reg = 0;
    chartInstance->c3_soft4_reg_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
  c3_S1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
  c3_S2 = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 64);
  c3_S3 = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
  c3_S4 = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
  c3_S5 = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 68);
  c3_b_soft1 = chartInstance->c3_soft1_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 69);
  c3_b_u1 = chartInstance->c3_u1_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 70);
  c3_b_soft2 = chartInstance->c3_soft2_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 71);
  c3_b_u2 = chartInstance->c3_u2_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
  c3_b_soft3 = chartInstance->c3_soft3_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 73);
  c3_b_u3 = chartInstance->c3_u3_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 74);
  c3_b_soft4 = chartInstance->c3_soft4_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 75);
  c3_b_u4 = chartInstance->c3_u4_reg;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 78);
  switch ((int32_T)sf_integer_check(chartInstance->S, 1U, 1489U, 9U, (real_T)
           chartInstance->c3_state_reg)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 80);
    chartInstance->c3_L21y12_reg = c3_f(chartInstance,
      chartInstance->c3_LLR1_reg, chartInstance->c3_LLR2_reg);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
    chartInstance->c3_L21y34_reg = c3_f(chartInstance,
      chartInstance->c3_LLR3_reg, chartInstance->c3_LLR4_reg);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 82);
    c3_d0 = muDoubleScalarFloor(c3_S2);
    if (muDoubleScalarIsNaN(c3_d0) || muDoubleScalarIsInf(c3_d0)) {
      c3_d1 = 0.0;
    } else {
      c3_d1 = muDoubleScalarRem(c3_d0, 8.0);
    }

    chartInstance->c3_state_reg = (uint8_T)((uint8_T)(int8_T)muDoubleScalarFloor
      (c3_d1) & 7U);
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 84);
    chartInstance->c3_L41y14_reg = c3_f(chartInstance,
      chartInstance->c3_L21y12_reg, chartInstance->c3_L21y34_reg);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
    chartInstance->c3_soft1_reg = chartInstance->c3_L41y14_reg;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 86);
    chartInstance->c3_u1_reg = c3_decide(chartInstance, c3_b_soft1, 1.0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 87);
    c3_d2 = muDoubleScalarFloor(c3_S3);
    if (muDoubleScalarIsNaN(c3_d2) || muDoubleScalarIsInf(c3_d2)) {
      c3_d3 = 0.0;
    } else {
      c3_d3 = muDoubleScalarRem(c3_d2, 8.0);
    }

    chartInstance->c3_state_reg = (uint8_T)((uint8_T)(int8_T)muDoubleScalarFloor
      (c3_d3) & 7U);
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 89);
    c3_e_hoistedGlobal = chartInstance->c3_L21y12_reg;
    c3_h_hoistedGlobal = chartInstance->c3_L21y34_reg;
    c3_k_hoistedGlobal = chartInstance->c3_u1_reg;
    c3_in1 = c3_e_hoistedGlobal;
    c3_in2 = c3_h_hoistedGlobal;
    c3_b = c3_k_hoistedGlobal;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_d_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_in1, 2U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_in2, 3U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b, 4U, c3_e_sf_marshallOut,
      c3_e_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 5U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    CV_EML_FCN(0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, (real_T)c3_b, 0.0, -1,
          0U, !c3_b))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
      c3_i2 = c3_in1 + c3_in2;
      if (c3_i2 > 127) {
        CV_SATURATION_EVAL(4, 0, 5, 0, 1);
        c3_i2 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 5, 0, c3_i2 < -128)) {
          c3_i2 = -128;
        }
      }

      c3_out = (int8_T)c3_i2;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 142U);
      c3_i1 = -c3_in1;
      if (c3_i1 > 127) {
        CV_SATURATION_EVAL(4, 0, 6, 0, 1);
        c3_i1 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 6, 0, c3_i1 < -128)) {
          c3_i1 = -128;
        }
      }

      c3_i7 = (int8_T)c3_i1 + c3_in2;
      if (c3_i7 > 127) {
        CV_SATURATION_EVAL(4, 0, 7, 0, 1);
        c3_i7 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 7, 0, c3_i7 < -128)) {
          c3_i7 = -128;
        }
      }

      c3_out = (int8_T)c3_i7;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -142);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_L42y14u11_reg = c3_out;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 90);
    chartInstance->c3_soft2_reg = chartInstance->c3_L42y14u11_reg;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 91);
    chartInstance->c3_u2_reg = c3_decide(chartInstance,
      chartInstance->c3_soft2_reg, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 92);
    c3_d4 = muDoubleScalarFloor(c3_S4);
    if (muDoubleScalarIsNaN(c3_d4) || muDoubleScalarIsInf(c3_d4)) {
      c3_d5 = 0.0;
    } else {
      c3_d5 = muDoubleScalarRem(c3_d4, 8.0);
    }

    chartInstance->c3_state_reg = (uint8_T)((uint8_T)(int8_T)muDoubleScalarFloor
      (c3_d5) & 7U);
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 94);
    c3_f_hoistedGlobal = chartInstance->c3_LLR1_reg;
    c3_i_hoistedGlobal = chartInstance->c3_LLR2_reg;
    c3_l_hoistedGlobal = chartInstance->c3_u1_reg;
    c3_n_hoistedGlobal = chartInstance->c3_u2_reg;
    c3_s = c3_l_hoistedGlobal;
    c3_t = c3_n_hoistedGlobal;
    c3_y = ((uint8_T)((uint8_T)c3_s ^ (uint8_T)c3_t) != 0);
    c3_c_in1 = c3_f_hoistedGlobal;
    c3_c_in2 = c3_i_hoistedGlobal;
    c3_c_b = c3_y;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_d_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_in1, 2U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_in2, 3U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_b, 4U, c3_e_sf_marshallOut,
      c3_e_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 5U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    CV_EML_FCN(0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, (real_T)c3_c_b, 0.0, -1,
          0U, !c3_c_b))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
      c3_i6 = c3_c_in1 + c3_c_in2;
      if (c3_i6 > 127) {
        CV_SATURATION_EVAL(4, 0, 5, 0, 1);
        c3_i6 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 5, 0, c3_i6 < -128)) {
          c3_i6 = -128;
        }
      }

      c3_c_out = (int8_T)c3_i6;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 142U);
      c3_i5 = -c3_c_in1;
      if (c3_i5 > 127) {
        CV_SATURATION_EVAL(4, 0, 6, 0, 1);
        c3_i5 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 6, 0, c3_i5 < -128)) {
          c3_i5 = -128;
        }
      }

      c3_i9 = (int8_T)c3_i5 + c3_c_in2;
      if (c3_i9 > 127) {
        CV_SATURATION_EVAL(4, 0, 7, 0, 1);
        c3_i9 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 7, 0, c3_i9 < -128)) {
          c3_i9 = -128;
        }
      }

      c3_c_out = (int8_T)c3_i9;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -142);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_L22y12u12_reg = c3_c_out;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 95);
    c3_o_hoistedGlobal = chartInstance->c3_LLR3_reg;
    c3_p_hoistedGlobal = chartInstance->c3_LLR4_reg;
    c3_q_hoistedGlobal = chartInstance->c3_u2_reg;
    c3_d_in1 = c3_o_hoistedGlobal;
    c3_d_in2 = c3_p_hoistedGlobal;
    c3_d_b = c3_q_hoistedGlobal;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_d_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_in1, 2U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_in2, 3U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_b, 4U, c3_e_sf_marshallOut,
      c3_e_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 5U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    CV_EML_FCN(0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, (real_T)c3_d_b, 0.0, -1,
          0U, !c3_d_b))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
      c3_i11 = c3_d_in1 + c3_d_in2;
      if (c3_i11 > 127) {
        CV_SATURATION_EVAL(4, 0, 5, 0, 1);
        c3_i11 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 5, 0, c3_i11 < -128)) {
          c3_i11 = -128;
        }
      }

      c3_d_out = (int8_T)c3_i11;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 142U);
      c3_i10 = -c3_d_in1;
      if (c3_i10 > 127) {
        CV_SATURATION_EVAL(4, 0, 6, 0, 1);
        c3_i10 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 6, 0, c3_i10 < -128)) {
          c3_i10 = -128;
        }
      }

      c3_i12 = (int8_T)c3_i10 + c3_d_in2;
      if (c3_i12 > 127) {
        CV_SATURATION_EVAL(4, 0, 7, 0, 1);
        c3_i12 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 7, 0, c3_i12 < -128)) {
          c3_i12 = -128;
        }
      }

      c3_d_out = (int8_T)c3_i12;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -142);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_L22y34u2_reg = c3_d_out;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 96);
    chartInstance->c3_L43y14u12_reg = c3_f(chartInstance,
      chartInstance->c3_L22y12u12_reg, chartInstance->c3_L22y34u2_reg);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 97);
    chartInstance->c3_soft3_reg = chartInstance->c3_L43y14u12_reg;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 98);
    chartInstance->c3_u3_reg = c3_decide(chartInstance,
      chartInstance->c3_soft3_reg, 3.0);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 99);
    c3_d6 = muDoubleScalarFloor(c3_S5);
    if (muDoubleScalarIsNaN(c3_d6) || muDoubleScalarIsInf(c3_d6)) {
      c3_d7 = 0.0;
    } else {
      c3_d7 = muDoubleScalarRem(c3_d6, 8.0);
    }

    chartInstance->c3_state_reg = (uint8_T)((uint8_T)(int8_T)muDoubleScalarFloor
      (c3_d7) & 7U);
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 101);
    c3_g_hoistedGlobal = chartInstance->c3_L22y12u12_reg;
    c3_j_hoistedGlobal = chartInstance->c3_L22y34u2_reg;
    c3_m_hoistedGlobal = chartInstance->c3_u3_reg;
    c3_b_in1 = c3_g_hoistedGlobal;
    c3_b_in2 = c3_j_hoistedGlobal;
    c3_b_b = c3_m_hoistedGlobal;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_d_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_f_sf_marshallOut,
      c3_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_in1, 2U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_in2, 3U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_b, 4U, c3_e_sf_marshallOut,
      c3_e_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 5U, c3_d_sf_marshallOut,
      c3_d_sf_marshallIn);
    CV_EML_FCN(0, 3);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 138U);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, (real_T)c3_b_b, 0.0, -1,
          0U, !c3_b_b))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
      c3_i4 = c3_b_in1 + c3_b_in2;
      if (c3_i4 > 127) {
        CV_SATURATION_EVAL(4, 0, 5, 0, 1);
        c3_i4 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 5, 0, c3_i4 < -128)) {
          c3_i4 = -128;
        }
      }

      c3_b_out = (int8_T)c3_i4;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 142U);
      c3_i3 = -c3_b_in1;
      if (c3_i3 > 127) {
        CV_SATURATION_EVAL(4, 0, 6, 0, 1);
        c3_i3 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 6, 0, c3_i3 < -128)) {
          c3_i3 = -128;
        }
      }

      c3_i8 = (int8_T)c3_i3 + c3_b_in2;
      if (c3_i8 > 127) {
        CV_SATURATION_EVAL(4, 0, 7, 0, 1);
        c3_i8 = 127;
      } else {
        if (CV_SATURATION_EVAL(4, 0, 7, 0, c3_i8 < -128)) {
          c3_i8 = -128;
        }
      }

      c3_b_out = (int8_T)c3_i8;
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -142);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_L44y14u13_reg = c3_b_out;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 102);
    chartInstance->c3_soft4_reg = chartInstance->c3_L44y14u13_reg;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 103);
    chartInstance->c3_u4_reg = c3_decide(chartInstance,
      chartInstance->c3_soft4_reg, 4.0);
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -103);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_u1 = c3_b_u1;
  *chartInstance->c3_u2 = c3_b_u2;
  *chartInstance->c3_u3 = c3_b_u3;
  *chartInstance->c3_u4 = c3_b_u4;
  *chartInstance->c3_soft1 = c3_b_soft1;
  *chartInstance->c3_soft2 = c3_b_soft2;
  *chartInstance->c3_soft3 = c3_b_soft3;
  *chartInstance->c3_soft4 = c3_b_soft4;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_successfulSaturation_decoderN4
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_soft4_reg_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_soft4_reg, const char_T *c3_identifier, boolean_T *c3_svPtr)
{
  int8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_soft4_reg),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_soft4_reg);
  return c3_y;
}

static int8_T c3_b_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr)
{
  int8_T c3_y;
  int8_T c3_i13;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i13, 1, 2, 0U, 0, 0U, 0);
    c3_y = c3_i13;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_soft4_reg;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_b_soft4_reg = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_soft4_reg_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_soft4_reg),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_soft4_reg);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_u4_reg_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_u4_reg, const char_T *c3_identifier, boolean_T *c3_svPtr)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u4_reg),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_u4_reg);
  return c3_y;
}

static boolean_T c3_d_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
    c3_y = c3_b0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u4_reg;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_b_u4_reg = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_u4_reg_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u4_reg),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_u4_reg);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  uint8_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  if (sf_debug_check_fi_license()) {
    c3_u = *(uint8_T *)c3_inData;
    c3_y = NULL;
    if (!chartInstance->c3_state_reg_not_empty) {
      sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                    false);
    } else {
      c3_b_u = c3_u;
      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0),
                    false);
      sf_mex_assign(&c3_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14,
        sf_mex_dup(c3_eml_mx), 15, "numerictype", 14, sf_mex_dup(c3_b_eml_mx),
        15, "simulinkarray", 14, c3_b_y, 15, "fimathislocal", 3, true), false);
    }

    sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  } else {
    sf_mex_assign(&c3_mxArrayOutData, sf_mex_create("mxArrayOutData",
      "Cannot display value.", 15, 0U, 0U, 0U, 2, 1, strlen(
      "Cannot display value.")), false);
  }

  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_state_reg, const char_T *c3_identifier, boolean_T *c3_svPtr)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_state_reg),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_state_reg);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr)
{
  uint8_T c3_y;
  const mxArray *c3_mxFi = NULL;
  const mxArray *c3_mxInt = NULL;
  uint8_T c3_u0;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_check_fi(c3_parentId, c3_u, false, 0U, NULL, c3_eml_mx, c3_b_eml_mx);
    sf_mex_assign(&c3_mxFi, sf_mex_dup(c3_u), false);
    sf_mex_assign(&c3_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
      (c3_mxFi)), false);
    sf_mex_import(c3_parentId, sf_mex_dup(c3_mxInt), &c3_u0, 1, 3, 0U, 0, 0U, 0);
    sf_mex_destroy(&c3_mxFi);
    sf_mex_destroy(&c3_mxInt);
    c3_y = c3_u0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_state_reg;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  if (sf_debug_check_fi_license()) {
    c3_b_state_reg = sf_mex_dup(c3_mxArrayInData);
    c3_identifier = c3_varName;
    c3_svPtr = &chartInstance->c3_state_reg_not_empty;
    c3_thisId.fIdentifier = c3_identifier;
    c3_thisId.fParent = NULL;
    c3_thisId.bParentIsCell = false;
    c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_state_reg),
      &c3_thisId, c3_svPtr);
    sf_mex_destroy(&c3_b_state_reg);
    *(uint8_T *)c3_outData = c3_y;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_g_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_soft4, const char_T *c3_identifier)
{
  int8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_soft4), &c3_thisId);
  sf_mex_destroy(&c3_b_soft4);
  return c3_y;
}

static int8_T c3_h_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i14;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i14, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i14;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_soft4;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_b_soft4 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_soft4), &c3_thisId);
  sf_mex_destroy(&c3_b_soft4);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_i_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_u4, const char_T *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u4), &c3_thisId);
  sf_mex_destroy(&c3_b_u4);
  return c3_y;
}

static boolean_T c3_j_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b1, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u4;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_b_u4 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u4), &c3_thisId);
  sf_mex_destroy(&c3_b_u4);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_k_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d8;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d8, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d8;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i15;
  const mxArray *c3_y = NULL;
  boolean_T c3_u[4];
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_u[c3_i15] = (*(boolean_T (*)[4])c3_inData)[c3_i15];
  }

  c3_y = NULL;
  if (!chartInstance->c3_FZlookup_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 11, 0U, 1U, 0U, 1, 4), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_l_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_FZlookup, const char_T *c3_identifier, boolean_T *c3_svPtr,
   boolean_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_FZlookup), &c3_thisId,
                        c3_svPtr, c3_y);
  sf_mex_destroy(&c3_b_FZlookup);
}

static void c3_m_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr,
   boolean_T c3_y[4])
{
  boolean_T c3_bv1[4];
  int32_T c3_i16;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 4);
    for (c3_i16 = 0; c3_i16 < 4; c3_i16++) {
      c3_y[c3_i16] = c3_bv1[c3_i16];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_FZlookup;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y[4];
  int32_T c3_i17;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_b_FZlookup = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_FZlookup_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_FZlookup), &c3_thisId,
                        c3_svPtr, c3_y);
  sf_mex_destroy(&c3_b_FZlookup);
  for (c3_i17 = 0; c3_i17 < 4; c3_i17++) {
    (*(boolean_T (*)[4])c3_outData)[c3_i17] = c3_y[c3_i17];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_successfulSaturation_decoderN4_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static int8_T c3_f(SFc3_successfulSaturation_decoderN4InstanceStruct
                   *chartInstance, int8_T c3_in1, int8_T c3_in2)
{
  int8_T c3_out;
  uint32_T c3_debug_family_var_map[5];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int8_T c3_x;
  int8_T c3_b_x;
  int8_T c3_c_x;
  int8_T c3_d_x;
  int8_T c3_e_x;
  int8_T c3_f_x;
  int32_T c3_i18;
  int32_T c3_i19;
  int8_T c3_y;
  int8_T c3_b_y;
  int8_T c3_g_x;
  int8_T c3_h_x;
  int8_T c3_i_x;
  int8_T c3_j_x;
  int8_T c3_k_x;
  int8_T c3_l_x;
  int32_T c3_i20;
  int32_T c3_i21;
  int8_T c3_c_y;
  int8_T c3_d_y;
  int8_T c3_varargin_1;
  int8_T c3_b_varargin_1;
  int8_T c3_varargin_2;
  int8_T c3_b_varargin_2;
  int8_T c3_c_varargin_2;
  int8_T c3_d_varargin_2;
  int8_T c3_varargin_3;
  int8_T c3_b_varargin_3;
  int8_T c3_m_x;
  int8_T c3_n_x;
  int8_T c3_e_y;
  int8_T c3_f_y;
  int8_T c3_o_x;
  int8_T c3_p_x;
  int8_T c3_g_y;
  int8_T c3_h_y;
  int8_T c3_q_x;
  int8_T c3_r_x;
  int8_T c3_i_y;
  int8_T c3_j_y;
  int8_T c3_minval;
  int32_T c3_i22;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_in1, 2U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_in2, 3U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 4U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, MAX_int8_T);
  if ((CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 2, (real_T)c3_in1, 0.0,
         -1, 4U, (real_T)c3_in1 > 0.0)) && CV_EML_COND(0, 1, 1,
        CV_RELATIONAL_EVAL(4U, 0U, 3, (real_T)c3_in2, 0.0, -1, 4U, (real_T)
         c3_in2 > 0.0))) || (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 4,
         (real_T)c3_in1, 0.0, -1, 2U, (real_T)c3_in1 < 0.0)) && CV_EML_COND(0, 1,
        3, CV_RELATIONAL_EVAL(4U, 0U, 5, (real_T)c3_in2, 0.0, -1, 2U, (real_T)
         c3_in2 < 0.0)))) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 4, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 128U);
    c3_x = c3_in1;
    c3_c_x = c3_x;
    c3_e_x = c3_c_x;
    c3_i18 = -c3_e_x;
    if (c3_i18 > 127) {
      CV_SATURATION_EVAL(4, 0, 0, 0, 1);
      c3_i18 = 127;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c3_i18 < -128)) {
        c3_i18 = -128;
      }
    }

    if ((real_T)c3_e_x < 0.0) {
      c3_y = (int8_T)c3_i18;
    } else {
      c3_y = c3_e_x;
    }

    c3_g_x = c3_in2;
    c3_i_x = c3_g_x;
    c3_k_x = c3_i_x;
    c3_i20 = -c3_k_x;
    if (c3_i20 > 127) {
      CV_SATURATION_EVAL(4, 0, 1, 0, 1);
      c3_i20 = 127;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 1, 0, c3_i20 < -128)) {
        c3_i20 = -128;
      }
    }

    if ((real_T)c3_k_x < 0.0) {
      c3_c_y = (int8_T)c3_i20;
    } else {
      c3_c_y = c3_k_x;
    }

    c3_varargin_1 = c3_y;
    c3_varargin_2 = c3_c_y;
    c3_c_varargin_2 = c3_varargin_1;
    c3_varargin_3 = c3_varargin_2;
    c3_m_x = c3_c_varargin_2;
    c3_e_y = c3_varargin_3;
    c3_o_x = c3_m_x;
    c3_g_y = c3_e_y;
    c3_q_x = c3_o_x;
    c3_i_y = c3_g_y;
    c3_out = muIntScalarMin_sint8(c3_q_x, c3_i_y);
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 4, false);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 131U);
    c3_b_x = c3_in1;
    c3_d_x = c3_b_x;
    c3_f_x = c3_d_x;
    c3_i19 = -c3_f_x;
    if (c3_i19 > 127) {
      CV_SATURATION_EVAL(4, 0, 3, 0, 1);
      c3_i19 = 127;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 3, 0, c3_i19 < -128)) {
        c3_i19 = -128;
      }
    }

    if ((real_T)c3_f_x < 0.0) {
      c3_b_y = (int8_T)c3_i19;
    } else {
      c3_b_y = c3_f_x;
    }

    c3_h_x = c3_in2;
    c3_j_x = c3_h_x;
    c3_l_x = c3_j_x;
    c3_i21 = -c3_l_x;
    if (c3_i21 > 127) {
      CV_SATURATION_EVAL(4, 0, 4, 0, 1);
      c3_i21 = 127;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 4, 0, c3_i21 < -128)) {
        c3_i21 = -128;
      }
    }

    if ((real_T)c3_l_x < 0.0) {
      c3_d_y = (int8_T)c3_i21;
    } else {
      c3_d_y = c3_l_x;
    }

    c3_b_varargin_1 = c3_b_y;
    c3_b_varargin_2 = c3_d_y;
    c3_d_varargin_2 = c3_b_varargin_1;
    c3_b_varargin_3 = c3_b_varargin_2;
    c3_n_x = c3_d_varargin_2;
    c3_f_y = c3_b_varargin_3;
    c3_p_x = c3_n_x;
    c3_h_y = c3_f_y;
    c3_r_x = c3_p_x;
    c3_j_y = c3_h_y;
    c3_minval = muIntScalarMin_sint8(c3_r_x, c3_j_y);
    c3_i22 = -c3_minval;
    if (c3_i22 > 127) {
      CV_SATURATION_EVAL(4, 0, 2, 0, 1);
      c3_i22 = 127;
    } else {
      if (CV_SATURATION_EVAL(4, 0, 2, 0, c3_i22 < -128)) {
        c3_i22 = -128;
      }
    }

    c3_out = (int8_T)c3_i22;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -131);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_out;
}

static boolean_T c3_decide(SFc3_successfulSaturation_decoderN4InstanceStruct
  *chartInstance, int8_T c3_soft, real_T c3_position)
{
  boolean_T c3_out;
  uint32_T c3_debug_family_var_map[6];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i23;
  boolean_T c3_b2;
  static boolean_T c3_bv2[4] = { false, false, true, true };

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_soft, 2U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_position, 3U, c3_f_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 4U, c3_e_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c3_FZlookup, 5U,
    c3_g_sf_marshallOut, c3_g_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 110);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 111);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c3_FZlookup_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 112);
    for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
      chartInstance->c3_FZlookup[c3_i23] = c3_bv2[c3_i23];
    }

    chartInstance->c3_FZlookup_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 114);
  c3_b2 = chartInstance->c3_FZlookup[sf_eml_array_bounds_check
    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2541, 18, MAX_uint32_T,
     (int32_T)sf_integer_check(chartInstance->S, 1U, 2541U, 18U, c3_position), 1,
     4) - 1];
  if (CV_EML_IF(0, 1, 2, c3_b2)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 115);
    if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)c3_soft, 0.0,
          -1, 4U, (real_T)c3_soft > 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 116);
      c3_out = false;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 118);
      c3_out = true;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 121);
    c3_out = chartInstance->c3_FZlookup[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 2689, 18, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 2689U, 18U, c3_position),
       1, 4) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -121);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_out;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_n_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i24;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i24, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i24;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_o_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_b_is_active_c3_successfulSaturation_decoderN4, const char_T
   *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_successfulSaturation_decoderN4), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_successfulSaturation_decoderN4);
  return c3_y;
}

static uint8_T c3_p_emlrt_marshallIn
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_b_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b_u1, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_b_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance)
{
  chartInstance->c3_LLR1 = (int8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_u1 = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_u2 = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_u3 = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_u4 = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_soft1 = (int8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_LLR2 = (int8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_LLR3 = (int8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_LLR4 = (int8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_soft2 = (int8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_soft3 = (int8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_soft4 = (int8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_successfulSaturation_decoderN4_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3897447338U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1670917219U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(656120083U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2435587466U);
}

mxArray* sf_c3_successfulSaturation_decoderN4_get_post_codegen_info(void);
mxArray *sf_c3_successfulSaturation_decoderN4_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("t9xOBLJhwORyLyc2wFikYF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_successfulSaturation_decoderN4_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_successfulSaturation_decoderN4_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_successfulSaturation_decoderN4_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_successfulSaturation_decoderN4_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_successfulSaturation_decoderN4_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_successfulSaturation_decoderN4
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[25],T\"soft1\",},{M[1],M[33],T\"soft2\",},{M[1],M[35],T\"soft3\",},{M[1],M[37],T\"soft4\",},{M[1],M[5],T\"u1\",},{M[1],M[32],T\"u2\",},{M[1],M[34],T\"u3\",},{M[1],M[36],T\"u4\",},{M[4],M[0],T\"FZlookup\",S'l','i','p'{{M1x2[2463 2471],M[0],}}},{M[4],M[0],T\"L21y12_reg\",S'l','i','p'{{M1x2[308 318],M[0],}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"L21y34_reg\",S'l','i','p'{{M1x2[331 341],M[0],}}},{M[4],M[0],T\"L22y12u12_reg\",S'l','i','p'{{M1x2[403 416],M[0],}}},{M[4],M[0],T\"L22y34u2_reg\",S'l','i','p'{{M1x2[429 441],M[0],}}},{M[4],M[0],T\"L41y14_reg\",S'l','i','p'{{M1x2[354 364],M[0],}}},{M[4],M[0],T\"L42y14u11_reg\",S'l','i','p'{{M1x2[377 390],M[0],}}},{M[4],M[0],T\"L43y14u12_reg\",S'l','i','p'{{M1x2[454 467],M[0],}}},{M[4],M[0],T\"L44y14u13_reg\",S'l','i','p'{{M1x2[480 493],M[0],}}},{M[4],M[0],T\"LLR1_reg\",S'l','i','p'{{M1x2[224 232],M[0],}}},{M[4],M[0],T\"LLR2_reg\",S'l','i','p'{{M1x2[245 253],M[0],}}},{M[4],M[0],T\"LLR3_reg\",S'l','i','p'{{M1x2[266 274],M[0],}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"LLR4_reg\",S'l','i','p'{{M1x2[287 295],M[0],}}},{M[4],M[0],T\"soft1_reg\",S'l','i','p'{{M1x2[526 535],M[0],}}},{M[4],M[0],T\"soft2_reg\",S'l','i','p'{{M1x2[567 576],M[0],}}},{M[4],M[0],T\"soft3_reg\",S'l','i','p'{{M1x2[608 617],M[0],}}},{M[4],M[0],T\"soft4_reg\",S'l','i','p'{{M1x2[649 658],M[0],}}},{M[4],M[0],T\"state_reg\",S'l','i','p'{{M1x2[202 211],M[0],}}},{M[4],M[0],T\"u1_reg\",S'l','i','p'{{M1x2[507 513],M[0],}}},{M[4],M[0],T\"u2_reg\",S'l','i','p'{{M1x2[548 554],M[0],}}},{M[4],M[0],T\"u3_reg\",S'l','i','p'{{M1x2[589 595],M[0],}}},{M[4],M[0],T\"u4_reg\",S'l','i','p'{{M1x2[630 636],M[0],}}}}",
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_successfulSaturation_decoderN4\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 31, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_successfulSaturation_decoderN4_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance =
      (SFc3_successfulSaturation_decoderN4InstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _successfulSaturation_decoderN4MachineNumber_,
           3,
           1,
           1,
           0,
           12,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_successfulSaturation_decoderN4MachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _successfulSaturation_decoderN4MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _successfulSaturation_decoderN4MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"LLR1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"LLR2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"LLR3");
          _SFD_SET_DATA_PROPS(3,1,1,0,"LLR4");
          _SFD_SET_DATA_PROPS(4,2,0,1,"u1");
          _SFD_SET_DATA_PROPS(5,2,0,1,"u2");
          _SFD_SET_DATA_PROPS(6,2,0,1,"u3");
          _SFD_SET_DATA_PROPS(7,2,0,1,"u4");
          _SFD_SET_DATA_PROPS(8,2,0,1,"soft1");
          _SFD_SET_DATA_PROPS(9,2,0,1,"soft2");
          _SFD_SET_DATA_PROPS(10,2,0,1,"soft3");
          _SFD_SET_DATA_PROPS(11,2,0,1,"soft4");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,4,0,6,0,8,1,0,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2415);
        _SFD_CV_INIT_EML_FCN(0,1,"decide",2415,-1,2725);
        _SFD_CV_INIT_EML_FCN(0,2,"f",2725,-1,2907);
        _SFD_CV_INIT_EML_FCN(0,3,"g",2907,-1,3138);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,2809,-1,2817);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,2818,-1,2826);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,2859,-1,2882);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,2864,-1,2872);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,2873,-1,2881);
        _SFD_CV_INIT_EML_SATURATION(0,1,5,2964,-1,2973);
        _SFD_CV_INIT_EML_SATURATION(0,1,6,3008,-1,3012);
        _SFD_CV_INIT_EML_SATURATION(0,1,7,3008,-1,3018);
        _SFD_CV_INIT_EML_IF(0,1,0,662,683,-1,1318);
        _SFD_CV_INIT_EML_IF(0,1,1,2473,2493,-1,2537);
        _SFD_CV_INIT_EML_IF(0,1,2,2538,2567,2675,2712);
        _SFD_CV_INIT_EML_IF(0,1,3,2572,2583,2642,2674);
        _SFD_CV_INIT_EML_IF(0,1,4,2758,2796,2846,2904);
        _SFD_CV_INIT_EML_IF(0,1,5,2943,2954,2994,3137);

        {
          static int caseStart[] = { -1, 1504, 1625, 1771, 1934, 2210 };

          static int caseExprEnd[] = { 8, 1511, 1632, 1778, 1941, 2217 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,1481,1499,2352,6,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 2762, 2771, 2781, 2790 };

          static int condEnd[] = { 2767, 2776, 2786, 2795 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,2761,2796,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,2575,2583,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,2762,2767,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,2771,2776,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,2781,2786,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,2790,2795,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,2947,2953,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)c3_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)c3_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)c3_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)c3_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _successfulSaturation_decoderN4MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance =
      (SFc3_successfulSaturation_decoderN4InstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_LLR1);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_u1);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_u2);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_u3);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_u4);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c3_soft1);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_LLR2);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_LLR3);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_LLR4);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_soft2);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_soft3);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c3_soft4);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "swkO1ydYWztKepYKgAzph9";
}

static void sf_opaque_initialize_c3_successfulSaturation_decoderN4(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_successfulSaturation_decoderN4InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
  initialize_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_successfulSaturation_decoderN4(void
  *chartInstanceVar)
{
  enable_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_successfulSaturation_decoderN4(void
  *chartInstanceVar)
{
  disable_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_successfulSaturation_decoderN4(void
  *chartInstanceVar)
{
  sf_gateway_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_successfulSaturation_decoderN4
  (SimStruct* S)
{
  return get_sim_state_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_successfulSaturation_decoderN4(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_successfulSaturation_decoderN4(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_successfulSaturation_decoderN4InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_successfulSaturation_decoderN4_optimization_info();
    }

    finalize_c3_successfulSaturation_decoderN4
      ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_successfulSaturation_decoderN4
    ((SFc3_successfulSaturation_decoderN4InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_successfulSaturation_decoderN4(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_successfulSaturation_decoderN4
      ((SFc3_successfulSaturation_decoderN4InstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_successfulSaturation_decoderN4(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_successfulSaturation_decoderN4_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,8);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(532584486U));
  ssSetChecksum1(S,(2195761593U));
  ssSetChecksum2(S,(1186619686U));
  ssSetChecksum3(S,(2200836372U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_successfulSaturation_decoderN4(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_successfulSaturation_decoderN4(SimStruct *S)
{
  SFc3_successfulSaturation_decoderN4InstanceStruct *chartInstance;
  chartInstance = (SFc3_successfulSaturation_decoderN4InstanceStruct *)utMalloc
    (sizeof(SFc3_successfulSaturation_decoderN4InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc3_successfulSaturation_decoderN4InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_successfulSaturation_decoderN4;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_successfulSaturation_decoderN4(chartInstance);
}

void c3_successfulSaturation_decoderN4_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_successfulSaturation_decoderN4(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_successfulSaturation_decoderN4(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_successfulSaturation_decoderN4(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_successfulSaturation_decoderN4_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
