onbreak resume
onerror resume
vsim -novopt work.HDL_DUT_tb
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in1
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in2
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out1
add wave sim:/HDL_DUT_tb/out1_ref
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out2
add wave sim:/HDL_DUT_tb/out2_ref
run -all
