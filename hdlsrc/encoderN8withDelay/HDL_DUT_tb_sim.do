onbreak resume
onerror resume
vsim -novopt work.HDL_DUT_tb
add wave sim:/HDL_DUT_tb/u_HDL_DUT/clk
add wave sim:/HDL_DUT_tb/u_HDL_DUT/reset
add wave sim:/HDL_DUT_tb/u_HDL_DUT/clk_enable
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in1
add wave sim:/HDL_DUT_tb/u_HDL_DUT/ce_out
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out1
add wave sim:/HDL_DUT_tb/out1_ref
run -all
