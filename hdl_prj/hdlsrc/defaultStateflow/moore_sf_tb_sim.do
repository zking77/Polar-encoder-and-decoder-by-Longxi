onbreak resume
onerror resume
vsim -novopt work.moore_sf_tb
add wave sim:/moore_sf_tb/u_moore_sf/clk
add wave sim:/moore_sf_tb/u_moore_sf/reset
add wave sim:/moore_sf_tb/u_moore_sf/get_going
add wave sim:/moore_sf_tb/u_moore_sf/ready
add wave sim:/moore_sf_tb/ready_ref
add wave sim:/moore_sf_tb/u_moore_sf/enable
add wave sim:/moore_sf_tb/enable_ref
run -all
