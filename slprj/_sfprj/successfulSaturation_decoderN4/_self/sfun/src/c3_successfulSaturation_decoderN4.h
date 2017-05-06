#ifndef __c3_successfulSaturation_decoderN4_h__
#define __c3_successfulSaturation_decoderN4_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_successfulSaturation_decoderN4InstanceStruct
#define typedef_SFc3_successfulSaturation_decoderN4InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_successfulSaturation_decoderN4;
  uint8_T c3_state_reg;
  boolean_T c3_state_reg_not_empty;
  int8_T c3_LLR1_reg;
  boolean_T c3_LLR1_reg_not_empty;
  int8_T c3_LLR2_reg;
  boolean_T c3_LLR2_reg_not_empty;
  int8_T c3_LLR3_reg;
  boolean_T c3_LLR3_reg_not_empty;
  int8_T c3_LLR4_reg;
  boolean_T c3_LLR4_reg_not_empty;
  int8_T c3_L21y12_reg;
  boolean_T c3_L21y12_reg_not_empty;
  int8_T c3_L21y34_reg;
  boolean_T c3_L21y34_reg_not_empty;
  int8_T c3_L41y14_reg;
  boolean_T c3_L41y14_reg_not_empty;
  int8_T c3_L42y14u11_reg;
  boolean_T c3_L42y14u11_reg_not_empty;
  int8_T c3_L22y12u12_reg;
  boolean_T c3_L22y12u12_reg_not_empty;
  int8_T c3_L22y34u2_reg;
  boolean_T c3_L22y34u2_reg_not_empty;
  int8_T c3_L43y14u12_reg;
  boolean_T c3_L43y14u12_reg_not_empty;
  int8_T c3_L44y14u13_reg;
  boolean_T c3_L44y14u13_reg_not_empty;
  boolean_T c3_u1_reg;
  boolean_T c3_u1_reg_not_empty;
  int8_T c3_soft1_reg;
  boolean_T c3_soft1_reg_not_empty;
  boolean_T c3_u2_reg;
  boolean_T c3_u2_reg_not_empty;
  int8_T c3_soft2_reg;
  boolean_T c3_soft2_reg_not_empty;
  boolean_T c3_u3_reg;
  boolean_T c3_u3_reg_not_empty;
  int8_T c3_soft3_reg;
  boolean_T c3_soft3_reg_not_empty;
  boolean_T c3_u4_reg;
  boolean_T c3_u4_reg_not_empty;
  int8_T c3_soft4_reg;
  boolean_T c3_soft4_reg_not_empty;
  boolean_T c3_FZlookup[4];
  boolean_T c3_FZlookup_not_empty;
  int8_T *c3_LLR1;
  boolean_T *c3_u1;
  boolean_T *c3_u2;
  boolean_T *c3_u3;
  boolean_T *c3_u4;
  int8_T *c3_soft1;
  int8_T *c3_LLR2;
  int8_T *c3_LLR3;
  int8_T *c3_LLR4;
  int8_T *c3_soft2;
  int8_T *c3_soft3;
  int8_T *c3_soft4;
} SFc3_successfulSaturation_decoderN4InstanceStruct;

#endif                                 /*typedef_SFc3_successfulSaturation_decoderN4InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_successfulSaturation_decoderN4_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_successfulSaturation_decoderN4_get_check_sum(mxArray *plhs[]);
extern void c3_successfulSaturation_decoderN4_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
