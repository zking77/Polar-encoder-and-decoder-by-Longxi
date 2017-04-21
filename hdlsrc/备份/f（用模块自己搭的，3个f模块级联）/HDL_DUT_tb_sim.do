onbreak resume
onerror resume
vsim -novopt work.HDL_DUT_tb
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in1
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in2
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in3
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in4
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out1
add wave sim:/HDL_DUT_tb/out1_ref
run -all
