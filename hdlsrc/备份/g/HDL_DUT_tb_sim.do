onbreak resume
onerror resume
vsim -novopt work.HDL_DUT_tb
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in1
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in2
add wave sim:/HDL_DUT_tb/u_HDL_DUT/in3
add wave sim:/HDL_DUT_tb/u_HDL_DUT/out_rsvd
add wave sim:/HDL_DUT_tb/out_rsvd_ref
run -all
