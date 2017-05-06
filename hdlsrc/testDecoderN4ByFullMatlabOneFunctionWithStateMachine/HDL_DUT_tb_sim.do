onbreak resume
onerror resume
vsim -novopt work.HDL_DUT_tb
add wave sim:/HDL_DUT_tb/u_HDL_DUT/clk
add wave sim:/HDL_DUT_tb/u_HDL_DUT/reset
add wave sim:/HDL_DUT_tb/u_HDL_DUT/clk_enable
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in1
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in2
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in3
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in4
add wave sim:/HDL_DUT_tb/u_HDL_DUT/ce_out
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out1
add wave sim:/HDL_DUT_tb/out1_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out2
add wave sim:/HDL_DUT_tb/out2_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out3
add wave sim:/HDL_DUT_tb/out3_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out4
add wave sim:/HDL_DUT_tb/out4_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out5
add wave sim:/HDL_DUT_tb/out5_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out6
add wave sim:/HDL_DUT_tb/out6_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out7
add wave sim:/HDL_DUT_tb/out7_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out8
add wave sim:/HDL_DUT_tb/out8_ref
run -all
